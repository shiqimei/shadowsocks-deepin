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
    Util::readConfig(Util::CONFIG_PATH, this);
//    installEventFilter(this);   // add event filter
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
    // 如果当前没有任何服务器配置，跳出服务器配置界面
    bool flags =  Util::model->getItems().isEmpty();
    if(flags){
        ui->actionEdit_Servers->trigger();
    }
    if (!flags && Util::guiConfig.enabled) {
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
//        connectionView->installEventFilter(this);

        model = new ConnectionTableModel(this);
        for (const auto &it:Util::guiConfig.configs) {
            auto *con = new Connection(SQProfile(it->profile), this);
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
    auto modeGroup = new QActionGroup(this);
    modeGroup->addAction(ui->actionPAC);
    modeGroup->addAction(ui->actionGlobal);
    auto pacGroup = new QActionGroup(this);
    pacGroup->addAction(ui->actionLocal_PAC);
    pacGroup->addAction(ui->actionOnline_PAC);
    connect(proxyService, &ProxyService::requestReloadMenu, this, &MainWindow::reloadMenu);
    connect(serverSerivce, &ServerSerivce::requestReloadMenu, this, &MainWindow::reloadMenu);
    connect(proxyService, &ProxyService::newController, logService, &LogService::newController);
    connect(logService, &LogService::requestUpdateIcon, [=](const QIcon &icon) {
        systemTrayIcon.setIcon(icon);
    });
    connect(updateService, &UpdateService::finishUpdate, &systemTrayIcon, &QSystemTrayIcon::showMessage);
    connect(pacService, &PacService::requestRestartProxy, [=]() {
        proxyService->setProxyEnabled(true);
    });
    connect(hotkeyService,&HotkeyService::requestReloadMenu,this,&MainWindow::reloadMenu);
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
    qDebug()<<watched<<event;
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
    menu = new QMenu(this);
    menu->addAction(ui->actionEnable_System_Proxy);
    ui->actionEnable_System_Proxy->setChecked(false);
    modeMenu = new QMenu(tr("Mode"));
    modeMenu->addAction(ui->actionPAC);
    modeMenu->addAction(ui->actionGlobal);
    menu->addMenu(modeMenu);
    serversMenu = new QMenu(tr("Servers"));
    serversMenu->addAction(ui->actionLoad_Balance);
    serversMenu->addAction(ui->actionHigh_Availability);
//    serversMenu->addAction(ui->actionChoosse_by_statistics);
    serversMenu->addSeparator();
    serversMenu->addAction(ui->actionEdit_Servers);
//    serversMenu->addAction(ui->actionStatistics_Config);
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
    /**
     * 2017年09月13日
     * 不明Acton含义，给用户造成额外的困扰
     *
     */
//    pacMenu->addAction(ui->actionSecure_Local_PAC);
    pacMenu->addAction(ui->actionCopy_Local_PAC_URL);
    pacMenu->addAction(ui->actionEdit_Online_PAC_URL);
    menu->addMenu(pacMenu);
//    menu->addAction(ui->actionForward_Proxy);
    menu->addSeparator();
    menu->addAction(ui->actionStart_on_Boot);
//    menu->addAction(ui->actionAllow_Clients_from_LAN);
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
    addAction(ui->actionEnable_System_Proxy);
    addAction(ui->actionAllow_Clients_from_LAN);
    addAction(ui->actionShow_Logs);
    addAction(ui->actionSwitch_system_proxy_mode);
    addAction(ui->actionSwitch_to_prev_server);
    addAction(ui->actionSwitch_to_next_server);
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
//    serversMenu->addAction(ui->actionChoosse_by_statistics);
    serversMenu->addSeparator();
    serversMenu->addSeparator();
    auto actionGroup = new QActionGroup(this);
    actionGroup->addAction(ui->actionLoad_Balance);
    actionGroup->addAction(ui->actionHigh_Availability);
    ui->actionLoad_Balance->setChecked(Util::guiConfig.strategy=="com.shadowsocks.strategy.balancing");
    ui->actionHigh_Availability->setChecked(Util::guiConfig.strategy=="com.shadowsocks.strategy.ha");
//    actionGroup->addAction(ui->actionChoosse_by_statistics);
    if (!Util::model->getItems().isEmpty()) {
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
        serversMenu->addSeparator();
    } else {
        ui->actionEnable_System_Proxy->setEnabled(false);
    }
    connect(actionGroup, &QActionGroup::triggered, [=](QAction *action) {
        Util::guiConfig.index=-1;
        if(action==ui->actionLoad_Balance){
            Util::guiConfig.strategy="com.shadowsocks.strategy.balancing";
        } else if(action==ui->actionHigh_Availability){
            Util::guiConfig.strategy="com.shadowsocks.strategy.ha";
        } else{
            int index = action->data().toInt();
            Util::guiConfig.index = index;
            Util::guiConfig.strategy="";
//            qDebug()<<"trigger "<<index<<model->getItems().size();
            systemTrayIcon.showMessage(tr("change server"),
                                       tr("use server -> %1").arg(action->text()));
        }
        proxyService->setProxyEnabled(true);
    });
    serversMenu->addAction(ui->actionEdit_Servers);
//    serversMenu->addAction(ui->actionStatistics_Config);
    serversMenu->addSeparator();
    serversMenu->addAction(ui->actionShare_Server_Config);
    serversMenu->addAction(ui->actionScan_QRCode_from_Screen);
    serversMenu->addAction(ui->actionImport_URL_from_Clipboard);


    auto&hotkey=Util::guiConfig.hotkey;
    ui->actionEnable_System_Proxy->setShortcut(QKeySequence(hotkey.switchSystemProxy));
    ui->actionEnable_System_Proxy->setShortcutContext(Qt::ApplicationShortcut);
    ui->actionShow_Logs->setShortcut(QKeySequence(hotkey.showLogs));
    ui->actionShow_Logs->setShortcutContext(Qt::ApplicationShortcut);
    ui->actionAllow_Clients_from_LAN->setShortcut(QKeySequence(hotkey.switchAllowLan));
    ui->actionAllow_Clients_from_LAN->setShortcutContext(Qt::ApplicationShortcut);
    ui->actionSwitch_system_proxy_mode->setShortcut(QKeySequence(hotkey.switchSystemProxyMode));
    ui->actionSwitch_to_prev_server->setShortcut(QKeySequence(hotkey.serverMoveUp));
    ui->actionSwitch_to_next_server->setShortcut(QKeySequence(hotkey.serverMoveDown));
    ui->actionSwitch_to_next_server->setShortcutContext(Qt::ApplicationShortcut);
    ui->actionSwitch_to_prev_server->setShortcutContext(Qt::ApplicationShortcut);
    ui->actionSwitch_system_proxy_mode->setShortcutContext(Qt::ApplicationShortcut);
    qDebug()<<hotkey.switchSystemProxy;
}

void MainWindow::on_actionEnable_System_Proxy_triggered(bool checked) {
    qDebug()<<"启动代理"<<checked;
    // 检查是否能启动
    proxyService->setProxyEnabled(checked);
}

void MainWindow::on_actionEdit_Servers_triggered(bool checked) {
    serverSerivce->editServers();
}

void MainWindow::on_actionEdit_Local_PAC_File_triggered(bool checked) {
    pacService->editLocalPacFile();
}

void MainWindow::on_actionEdit_User_Rule_for_GFWList_triggered(bool checked) {
    pacService->editUserRuleForGFWList();
}

void MainWindow::on_actionCopy_Local_PAC_URL_triggered(bool checked) {
    pacService->copyLocalPacURL();
}

void MainWindow::on_actionEdit_Online_PAC_URL_triggered(bool checked) {
    pacService->editOnlinePacUrl();
}

void MainWindow::on_actionShare_Server_Config_triggered(bool checked) {
    serverSerivce->shareServerConfig();
}

void MainWindow::on_actionScan_QRCode_from_Screen_triggered(bool checked) {
    serverSerivce->scanQRCodeFromScreen();
}

void MainWindow::on_actionImport_URL_from_Clipboard_triggered(bool checked) {
    serverSerivce->importURLfromClipboard();
}

void MainWindow::on_actionStart_on_Boot_triggered(bool checked) {
    bootService->setAutoBoot(checked);
}

void MainWindow::on_actionForward_Proxy_triggered(bool checked) {
    proxyService->editForwardProxy();
}

void MainWindow::on_actionEdit_Hotkeys_triggered(bool checked) {
    hotkeyService->editHotkey();
}

void MainWindow::on_actionShow_Logs_triggered(bool checked) {
    logService->showLog();
}

void MainWindow::on_actionCheck_for_Updates_triggered(bool checked) {
    updateService->checkUpdate();
}

void MainWindow::on_actionCheck_for_Update_at_Startup_triggered(bool checked) {
    updateService->setCheckForUpdatesAtStartup(checked);
}

void MainWindow::on_actionCheck_Pre_release_Version_triggered(bool checked) {
    updateService->setCheckPrereleaseVersion(checked);
}

void MainWindow::on_actionAbout_triggered(bool checked) {
    aboutService->showAbout();
}

void MainWindow::on_actionQuit_triggered(bool checked) {
    qApp->exit();
}

void MainWindow::on_actionPAC_triggered(bool checked) {
    proxyService->setProxyMethod(ProxyService::Auto);
}

void MainWindow::on_actionGlobal_triggered(bool checked) {
    proxyService->setProxyMethod(ProxyService::Manual);
}

void MainWindow::on_actionLocal_PAC_triggered(bool checked) {
    pacService->setUseLocalPac(true);
}

void MainWindow::on_actionOnline_PAC_triggered(bool checked) {
    pacService->setUseLocalPac(false);
}

void MainWindow::on_actionUpdate_Local_PAC_from_GFWList_triggered(bool checked) {
    systemTrayIcon.showMessage(tr("update pac file"), tr("update pac file from gfwlist"));
    updateService->updateLocalPacFromGFWList();
}

void MainWindow::on_actionSwitch_system_proxy_mode_triggered(bool checked) {
    if(Util::guiConfig.enabled){
        Util::guiConfig.global=!Util::guiConfig.global;
        proxyService->setProxyEnabled(true);
    }
}

void MainWindow::on_actionSwitch_to_next_server_triggered(bool checked) {
    int max = Util::model->rowCount();
    auto& curIndex = Util::guiConfig.index;
    if(curIndex<max-1){
        curIndex++;
        proxyService->setProxyEnabled(true);
    }
}

void MainWindow::on_actionSwitch_to_prev_server_triggered(bool checked) {
    int& curIndex = Util::guiConfig.index;
    if(curIndex>0){
        curIndex--;
        proxyService->setProxyEnabled(true);
    }
}
