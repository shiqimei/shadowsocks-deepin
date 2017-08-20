//
// Created by pikachu on 17-8-19.
//

#include <widget/Toolbar.h>
#include <widget/ConnectionView.h>
#include <model/ConnectionItem.h>
#include "util/Util.h"
#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
        DMainWindow(parent),
        ui(new Ui::MainWindow) {
    ui->setupUi(this);

    QDir configDir = QString("%1/.config/shadowsocks-client").arg(QDir::homePath());
    QString configFile = QString("%1/config.ini").arg(configDir.absolutePath());
    if (!configDir.exists()) {
        configDir.mkpath(configDir.absolutePath());
    }
    Util::readConfig(configFile, this);
    installEventFilter(this);   // add event filter
    initTheme();
    initMenu();
    initService();
    initCentralWidget();
    reloadMenu();
    connect(model, &ConnectionTableModel::message, [](const QString &msg) {
        Util::showNotification(msg);
    });
    systemTrayIcon.setIcon(Util::getIcon(Util::Type::None));
    systemTrayIcon.show();
    if (Util::guiConfig.enabled) {
        proxyService->setProxyEnabled(true);
    }
}

void MainWindow::initCentralWidget() {
    if (titlebar() != nullptr) {
        toolbar = new Toolbar();
        titlebar()->setCustomWidget(toolbar, Qt::AlignVCenter, false);

        layoutWidget = new QWidget();
        layout = new QHBoxLayout(layoutWidget);
        ConnectionView *connectionView = new ConnectionView(getColumnHideFlags());
        connectionView->installEventFilter(this);

        model = new ConnectionTableModel(this);
        for (const auto &it:Util::guiConfig.configs) {
            auto *con = new Connection(SQProfile(it.profile), this);
            model->appendConnection(con);
        }
        auto items = model->getItems();
        QList<ListItem *> list;
        for (auto it:items) {
            list.append(it);
        }
        connectionView->addItems(list);
        layout->addWidget(connectionView);
        setCentralWidget(layoutWidget);

        connect(connectionView, &ConnectionView::rightClickItems, this, &MainWindow::popupMenu, Qt::QueuedConnection);
    }
}

void MainWindow::initService() {
    proxyService = new ProxyServiceImpl(this);
    serverSerivce = new ServerSerivceImpl(this);
    pacService = new PacServiceImpl(this);
    logService = new LogServiceImpl(this);
    bootService = new BootServiceImpl(this);
    updateService = new UpdateServiceImpl(this);
    hotkeyService = new HotkeyServiceImpl(this);
    aboutService = new AboutServiceImpl(this);
    connect(ui->actionEnable_System_Proxy, &QAction::triggered, proxyService, &ProxyService::setProxyEnabled);
    auto modeGroup = new QActionGroup(this);
    modeGroup->addAction(ui->actionPAC);
    modeGroup->addAction(ui->actionGlobal);
    connect(modeGroup, &QActionGroup::triggered, [=](QAction *action) {
        auto proxyMethod = action == ui->actionPAC ? ProxyService::Auto : ProxyService::Manual;
        proxyService->setProxyMethod(proxyMethod);
    });
    connect(ui->actionEdit_Servers, &QAction::triggered, serverSerivce, &ServerSerivce::editServers);
    auto pacGroup = new QActionGroup(this);
    pacGroup->addAction(ui->actionLocal_PAC);
    pacGroup->addAction(ui->actionOnline_PAC);
    connect(pacGroup, &QActionGroup::triggered, [=](QAction *action) {
        pacService->setUseLocalPac(action == ui->actionLocal_PAC);
    });
    connect(ui->actionEdit_Local_PAC_File, &QAction::triggered, pacService, &PacService::editLocalPacFile);
    connect(ui->actionUpdate_Local_PAC_from_GFWList, &QAction::triggered, [=]() {
        systemTrayIcon.showMessage(tr("update pac file"), tr("update pac file from gfwlist"));
        updateService->updateLocalPacFromGFWList();
    });
    connect(ui->actionEdit_User_Rule_for_GFWList, &QAction::triggered, pacService, &PacService::editUserRuleForGFWList);
    connect(ui->actionCopy_Local_PAC_URL, &QAction::triggered, pacService, &PacService::copyLocalPacURL);
    connect(ui->actionEdit_Online_PAC_URL, &QAction::triggered, pacService, &PacService::editOnlinePacUrl);
    connect(ui->actionShare_Server_Config, &QAction::triggered, serverSerivce, &ServerSerivce::shareServerConfig);
    connect(ui->actionScan_QRCode_from_Screen, &QAction::triggered, serverSerivce,
            &ServerSerivce::scanQRCodeFromScreen);
    connect(ui->actionImport_URL_from_Clipboard, &QAction::triggered, serverSerivce,
            &ServerSerivce::importURLfromClipboard);
    connect(ui->actionStart_on_Boot, &QAction::triggered, bootService, &BootService::setAutoBoot);
    connect(ui->actionForward_Proxy, &QAction::triggered, proxyService, &ProxyService::editForwardProxy);
    connect(ui->actionEdit_Hotkeys, &QAction::triggered, hotkeyService, &HotkeyService::editHotkey);
    connect(ui->actionShow_Logs, &QAction::triggered, logService, &LogService::showLog);
    connect(ui->actionCheck_for_Updates, &QAction::triggered, updateService, &UpdateService::checkUpdate);
    connect(ui->actionCheck_for_Update_at_Startup, &QAction::triggered, updateService,
            &UpdateService::setCheckForUpdatesAtStartup);
    connect(ui->actionCheck_Pre_release_Version, &QAction::triggered, updateService,
            &UpdateService::setCheckPrereleaseVersion);
    connect(ui->actionAbout, &QAction::triggered, aboutService, &AboutService::showAbout);
    connect(ui->actionQuit, &QAction::triggered, []() {
        qApp->exit();
    });
    connect(proxyService, &ProxyService::requestReloadMenu, this, &MainWindow::reloadMenu);
    connect(proxyService, &ProxyService::newController, logService, &LogService::newController);
    connect(logService, &LogService::requestUpdateIcon, [=](const QIcon &icon) {
        systemTrayIcon.setIcon(icon);
    });
    connect(updateService, &UpdateService::finishUpdate, &systemTrayIcon, &QSystemTrayIcon::showMessage);
    connect(pacService, &PacService::requestRestartProxy, [=]() {
        proxyService->setProxyEnabled(true);
    });
}

void MainWindow::changeTheme(QString theme) {
    if (theme == "light") {
        backgroundColor = "#FFFFFF";

        if (DWindowManagerHelper::instance()->hasComposite()) {
            setBorderColor(QColor(0, 0, 0, 0.15 * 255));
        } else {
            setBorderColor(QColor(217, 217, 217));
        }
    } else {
        backgroundColor = "#0E0E0E";

        if (DWindowManagerHelper::instance()->hasComposite()) {
            setBorderColor(QColor(0, 0, 0, 0.15 * 255));
        } else {
            setBorderColor(QColor(16, 16, 16));
        }
    }

}

void MainWindow::initTheme() {
    changeTheme("light");
}


void MainWindow::paintEvent(QPaintEvent *event) {

    QPainter painter(this);

    QPainterPath path;
    path.addRect(QRectF(rect()));
    painter.setOpacity(1);
    painter.fillPath(path, QColor(backgroundColor));
    QWidget::paintEvent(event);
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event) {
    if (event->type() == QEvent::WindowStateChange) {
//        adjustStatusBarWidth();
    } else if (event->type() == QEvent::KeyPress) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        if (keyEvent->key() == Qt::Key_F) {
            if (keyEvent->modifiers() == Qt::ControlModifier) {
                toolbar->focusInput();
            }
        }
    } else if (event->type() == QEvent::Close) {/*
        if (this->rect().width() > Constant::WINDOW_MIN_WIDTH) {
            settings->setOption("window_width", this->rect().width());
        }

        if (this->rect().height() > Constant::WINDOW_MIN_HEIGHT) {
            settings->setOption("window_height", this->rect().height());
        }*/
    }

    return QObject::eventFilter(watched, event);
}

MainWindow::~MainWindow() {
    delete ui;
}

QList<bool> MainWindow::getColumnHideFlags() {
    QList<bool> toggleHideFlags;
    toggleHideFlags << true;
    toggleHideFlags << true;
    toggleHideFlags << true;
    toggleHideFlags << true;
    toggleHideFlags << true;
    toggleHideFlags << true;
    toggleHideFlags << true;
    toggleHideFlags << true;
    toggleHideFlags << true;

    return toggleHideFlags;
}

void MainWindow::popupMenu(QPoint pos, QList<ListItem *> items) {

    rightMenu->exec(pos);
}

void MainWindow::initMenu() {
    menu = new QMenu();
    menu->addAction(ui->actionEnable_System_Proxy);
    modeMenu = new QMenu(tr("Mode"));
    modeMenu->addAction(ui->actionPAC);
    modeMenu->addAction(ui->actionGlobal);
    menu->addMenu(modeMenu);
    serversMenu = new QMenu(tr("Servers"));
    serversMenu->addAction(ui->actionLoad_Balance);
    serversMenu->addAction(ui->actionHigh_Availability);
    serversMenu->addAction(ui->actionChoosse_by_statistics);
    serversMenu->addSeparator();
    serversMenu->addAction(ui->actionEdit_Servers);
    serversMenu->addAction(ui->actionStatistics_Config);
    serversMenu->addSeparator();
    serversMenu->addAction(ui->actionShare_Server_Config);
    serversMenu->addAction(ui->actionScan_QRCode_from_Screen);
    serversMenu->addAction(ui->actionImport_URL_from_Clipboard);
    menu->addMenu(serversMenu);
    auto pacMenu = new QMenu("PAC");
    pacMenu->addAction(ui->actionLocal_PAC);
    pacMenu->addAction(ui->actionOnline_PAC);
    pacMenu->addSeparator();
    pacMenu->addAction(ui->actionEdit_Local_PAC_File);
    pacMenu->addAction(ui->actionUpdate_Local_PAC_from_GFWList);
    pacMenu->addAction(ui->actionEdit_User_Rule_for_GFWList);
    pacMenu->addAction(ui->actionSecure_Local_PAC);
    pacMenu->addAction(ui->actionCopy_Local_PAC_URL);
    pacMenu->addAction(ui->actionEdit_Online_PAC_URL);
    menu->addMenu(pacMenu);
    menu->addAction(ui->actionForward_Proxy);
    menu->addSeparator();
    menu->addAction(ui->actionStart_on_Boot);
    menu->addAction(ui->actionAllow_Clients_from_LAN);
    menu->addSeparator();
    menu->addAction(ui->actionEdit_Hotkeys);
    auto helpMenu = new QMenu(tr("Help"));
    helpMenu->addAction(ui->actionShow_Logs);
    helpMenu->addAction(ui->actionVerbose_Logging);
    auto updateMenu = new QMenu(tr("Update"));
    updateMenu->addAction(ui->actionCheck_for_Updates);
    updateMenu->addSeparator();
    updateMenu->addAction(ui->actionCheck_for_Update_at_Startup);
    updateMenu->addAction(ui->actionCheck_Pre_release_Version);
    helpMenu->addMenu(updateMenu);
    helpMenu->addAction(ui->actionAbout);
    menu->addMenu(helpMenu);
    menu->addAction(ui->actionQuit);
    systemTrayIcon.setContextMenu(menu);
}

void MainWindow::reloadMenu() {
    ui->actionEnable_System_Proxy->setChecked(proxyService->isProxyEnaled());
    modeMenu->setEnabled(proxyService->isProxyEnaled());
    ui->actionPAC->setChecked(proxyService->isPacMode());
    ui->actionGlobal->setChecked(proxyService->isGlobelMode());
    ui->actionLocal_PAC->setChecked(pacService->isUseLocalPac());
    ui->actionOnline_PAC->setChecked(pacService->isUseOnlinePac());
    ui->actionSecure_Local_PAC->setChecked(pacService->isSecureLocalPac());
    ui->actionStart_on_Boot->setChecked(bootService->isAutoBoot());
    ui->actionAllow_Clients_from_LAN->setChecked(proxyService->isAllowClientsFromLAN());
    ui->actionVerbose_Logging->setChecked(logService->isVerboseLogging());
    ui->actionCheck_for_Update_at_Startup->setChecked(updateService->isCheckForUpdatesAtStartup());
    ui->actionCheck_Pre_release_Version->setChecked(updateService->isCheckPrereleaseVersion());

    serversMenu->clear();
    serversMenu->addAction(ui->actionLoad_Balance);
    serversMenu->addAction(ui->actionHigh_Availability);
    serversMenu->addAction(ui->actionChoosse_by_statistics);
    serversMenu->addSeparator();
    serversMenu->addSeparator();
    if (!Util::model->getItems().isEmpty()) {
        auto actionGroup = new QActionGroup(this);
//        qDebug()<<Util::model->getItems().size()<<" total items";
        for (int i = 0; i < Util::model->getItems().size(); ++i) {
            auto action = new QAction(Util::model->getItem(i)->getConnection()->getName(), this);
//            qDebug()<<action->text();
            action->setData(i);
            action->setCheckable(true);
            action->setChecked(Util::guiConfig.index == i);
            actionGroup->addAction(action);
            serversMenu->addAction(action);
//            qDebug()<<i<<(Util::guiConfig.configs.value(i).getRemarks());
        }
        connect(actionGroup, &QActionGroup::triggered, [=](QAction *action) {
            int index = action->data().toInt();
            Util::guiConfig.index = index;
//            qDebug()<<"trigger "<<index<<model->getItems().size();
            proxyService->setProxyEnabled(true);
            systemTrayIcon.showMessage(tr("change server"),
                                       tr("use server -> %1").arg(action->text()));
        });
        serversMenu->addSeparator();
    } else {
        ui->actionEnable_System_Proxy->setEnabled(false);
    }
    serversMenu->addAction(ui->actionEdit_Servers);
    serversMenu->addAction(ui->actionStatistics_Config);
    serversMenu->addSeparator();
    serversMenu->addAction(ui->actionShare_Server_Config);
    serversMenu->addAction(ui->actionScan_QRCode_from_Screen);
    serversMenu->addAction(ui->actionImport_URL_from_Clipboard);


}
