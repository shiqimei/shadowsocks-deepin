#include "stdafx.h"
#include "utils.h"
#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "ConfigDialog.h"
#include "PACUrlDialog.h"
#include "ProxyDialog.h"
#include "LogMainWindow.h"
#include "Toolbar.h"
#include "GuiConfig.h"
#include "DDEProxyModeManager.h"
#include "widgets/ProfileView.h"
#include "widgets/ProfileItem.h"
#include "QRCodeCapturer.h"
#include "SSValidator.h"
#include "ShareDialog.h"
#include <DDesktopServices>

MainWindow::MainWindow(QWidget *parent):
DMainWindow(parent),
ui(new Ui::MainWindow) {
    ui->setupUi(this);
    installEventFilter(this);   // add event filter
    GuiConfig::instance()->readFromDisk();
    w = new DMainWindow();
    settings = new Settings(this);
    settings->init();

    // init window size
    int width = Constant::WINDOW_MIN_WIDTH;
    int height = Constant::WINDOW_MIN_HEIGHT;

    if (!settings->getOption("window_width").isNull()) {
        width = settings->getOption("window_width").toInt();
    }

    if (!settings->getOption("window_height").isNull()) {
        height = settings->getOption("window_height").toInt();
    }

    w->resize(width, height);
    rightMenu = new QMenu(this);
    rightMenuBlank = new QMenu(this);
    menuAdd = new QMenu(tr("Add"),this);
    config_view = new ProfileView(getColumnHideFlags());
    // config_view->setColumnSortingAlgorithms(alorithms, getSortingIndex(), getSortingOrder());
    config_view->setSearchAlgorithm(&ProfileItem::search);
    connect(config_view, &ProfileView::rightClickItems, this, &MainWindow::popupMenu);
    connect(config_view, &ProfileView::rightClickBlank, this, &MainWindow::popupMenuBlank);
    w->setCentralWidget(config_view);

    // draw trayIcon
    systemTrayIcon = new QSystemTrayIcon();
    systemTrayIcon->setContextMenu(ui->menuTray);
    systemTrayIcon->setIcon(QIcon(Utils::getIconQrcPath("ssw_auto128.svg")));
    systemTrayIcon->show();


    const auto &titlebar = w->titlebar();
    if (titlebar != nullptr) {
        auto menu = new QMenu();
        menu->setStyle(QStyleFactory::create("dlight"));
        menu->addAction(ui->actionImport_from_gui_config_json);
        menu->addAction(ui->actionExport_as_gui_config_json);
        menu->addSeparator();
        toolbar = new Toolbar();
        titlebar->setCustomWidget(toolbar, Qt::AlignVCenter, false);
        titlebar->setMenu(menu);
        connect(toolbar, &Toolbar::search, config_view, &ProfileView::search, Qt::QueuedConnection);
    }
    proxyManager = new ProxyManager(this);
    const auto &guiConfig = GuiConfig::instance();
    systemProxyModeManager = new DDEProxyModeManager(this);
    if (guiConfig->get("enabled").toBool()) {
        on_actionEnable_System_Proxy_triggered(true);
        if (guiConfig->get("global").toBool()) {
            switchToGlobal();
        } else {
            switchToPacMode();
        }
    }
    in = 0;
    out = 0;
    ins.clear();
    outs.clear();
    auto timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateTrayIcon);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateList);

    //! Do not modify this period
    //! If less than 150ms, the trayicon will be not shown normally.
    timer->start(300);

    // data monitoring
    connect(proxyManager, &ProxyManager::bytesReceivedChanged, [=](quint64 n) {
        // qDebug() << "bytesReceivedChanged" << n;
        term_usage_in = n;
        GuiConfig::instance()->setCurrentTermUsage(term_usage_in + term_usage_out);
    });
    connect(proxyManager, &ProxyManager::bytesSentChanged, [=](quint64 n) {
        // qDebug() << "bytesSentChanged" << n;
        term_usage_out = n;
        GuiConfig::instance()->setCurrentTermUsage(term_usage_in + term_usage_out);
    });
    connect(proxyManager, &ProxyManager::newBytesReceived, [=](quint64 n) {
        // qDebug() << "newBytesReceived" << n;
        in += n;
        GuiConfig::instance()->addTotalUsage(n);
    });
    connect(proxyManager, &ProxyManager::newBytesSent, [=](quint64 n) {
        // qDebug() << "newBytesSent" << n;
        out += n;
        GuiConfig::instance()->addTotalUsage(n);
    });
    updateTrayIcon();
    on_actionStart_on_Boot_triggered(guiConfig->get("autostart").toBool(true));
    updateList();
    updateMenu();
}

MainWindow::~MainWindow() {
    proxyManager->stop();
    systemProxyModeManager->switchToNone();
    delete ui;
}

void MainWindow::switchToPacMode() {
    auto guiConfig = GuiConfig::instance();
    QString online_pac_uri = "https://files.lolimay.cn/autoproxy.pac";
    QString pacURI = "";
    if (guiConfig->get("useOnlinePac").toBool(true)) {
        pacURI = guiConfig->get("pacUrl").toString();
        if (pacURI.isEmpty()) {
            qDebug() << "\033[30mWARNING: online pac uri is empty. we will use default uri.";
            pacURI = online_pac_uri;
            guiConfig->set("pacUrl", pacURI);
        }
    } else {
        QString pac_file = QDir(Utils::configPath()).filePath("autoproxy.pac");
        QFile file(pac_file);
        if (!file.exists()) {
            Utils::warning("local pac is not exist. we will use on pac file. you can change it");
            pacURI = online_pac_uri;
            guiConfig->set("pacUrl", pacURI);
            guiConfig->set("useOnlinePac", true);
        } else {
            pacURI = "file://" + pac_file;
        }
    }
    systemProxyModeManager->switchToAuto(pacURI);
}

void MainWindow::switchToGlobal() {
    auto guiConfig = GuiConfig::instance();
    QString local_address = guiConfig->get("local_address").toString();
    if (local_address.isEmpty()) {
        local_address = "127.0.0.1";
        guiConfig->set("local_address", local_address);
    }
    int local_port = guiConfig->get("local_port").toInt();
    if (local_port == 0) {
        local_port = 1080;
        guiConfig->set("local_port", local_port);
    }
    systemProxyModeManager->switchToManual(local_address, local_port);
}

void MainWindow::contextMenuEvent(QContextMenuEvent *)
{
    qDebug()<<"right click";
}

/**
 * update tray icon
 */
void MainWindow::updateTrayIcon() {
    ins.append(in);
    outs.append(out);
    QString icon = "ssw";
    if (in > 0) {
        icon.append("_in");
    }
    if (out > 0) {
        icon.append("_out");
    }
    in = 0;
    out = 0;
    if (!GuiConfig::instance()->get("enabled").toBool()) {
        icon.append("_none");
    } else if (GuiConfig::instance()->get("global").toBool()) {
        icon.append("_manual");
    } else {
        icon.append("_auto");
    }
    icon.append("128.svg");
    systemTrayIcon->setIcon(QIcon(Utils::getIconQrcPath(icon)));
}

void MainWindow::updateList() {

//    QList<DSimpleListItem *> items;
//    auto configs = GuiConfig::instance()->getConfigs();
//    for (int i = 0; i < configs.size(); i++) {
//        auto it = configs.at(i).toObject();
//        auto item = new ProfileItem(it);
//        items << static_cast<DSimpleListItem *>(item);
//    }
//    // note: this function will delete items in view before  to avoid *MEMORY LEAK*
//    config_view->refreshItems(items);

}

void MainWindow::popupMenu(QPoint pos, QList<DSimpleListItem *> items) {
    if (items.size() == 1) {
        auto item = items.first();
        auto t = static_cast<ProfileItem *>(item);
        QList<QAction *> action_list;
        action_list << ui->actionConnect << ui->actionDisconnect;
        if (GuiConfig::instance()->get("enabled").toBool()) {
            if (t->getId() == GuiConfig::instance()->getCurrentId()) {
                ui->actionConnect->setEnabled(false);
                ui->actionDisconnect->setEnabled(true);
            } else {
                ui->actionConnect->setEnabled(true);
                ui->actionDisconnect->setEnabled(false);
            }
        } else {
            ui->actionConnect->setEnabled(true);
            ui->actionDisconnect->setEnabled(false);
        }
        auto index = GuiConfig::instance()->getIndexById(t->getId());
        connect(ui->actionConnect, &QAction::triggered, [=]() {
            if (index < 0) {
                qDebug() << "no such config id";
            } else {
                GuiConfig::instance()->set("index", index);
                on_actionEnable_System_Proxy_triggered(true);
            }
        });
        rightMenu->clear();
        rightMenu->addActions(action_list);
        rightMenu->exec(pos);
    }
}

void MainWindow::popupMenuBlank()
{
    rightMenuBlank->clear();
    QList<QAction*> action_list;
    menuAdd->clear();
    action_list<<ui->actionImport_from_gui_config_json<<ui->actionScan_QRCode_from_Screen<<ui->actionImport_URL_from_Clipboard;
    menuAdd->addActions(action_list);
    rightMenuBlank->addMenu(menuAdd);
    action_list.clear();
    action_list<<ui->actionEdit_Servers;
    rightMenuBlank->addActions(action_list);
    rightMenuBlank->exec(QCursor::pos());
}

void MainWindow::on_actionEdit_Servers_triggered() {
    ConfigDialog *dialog = new ConfigDialog();

    dialog->exec();
    updateMenu();
}

void MainWindow::on_actionEdit_Online_PAC_URL_triggered() {
    PACUrlDialog *dialog = new PACUrlDialog(this);
    dialog->show();
}

void MainWindow::on_actionForward_Proxy_triggered() {
    ProxyDialog *dialog = new ProxyDialog(this);
    dialog->show();
}

void MainWindow::on_actionShow_Logs_triggered() {
    LogMainWindow *w = new LogMainWindow(this);
    w->show();
}

void MainWindow::updateMenu() {
    const auto &guiConfig = GuiConfig::instance();
    //    qDebug() << guiConfig->getConfigs();
    if (guiConfig->get("enabled").toBool()) {
        ui->actionEnable_System_Proxy->setChecked(true);
        ui->menuMode->setEnabled(true);
    } else {
        ui->actionEnable_System_Proxy->setChecked(false);
        ui->menuMode->setEnabled(false);
    }
    if (guiConfig->get("global").toBool()) {
        ui->actionGlobal->setChecked(true);
        ui->actionPAC->setChecked(false);
    } else {
        ui->actionGlobal->setChecked(false);
        ui->actionPAC->setChecked(true);
    }
    if (guiConfig->get("useOnlinePac").toBool()) {
        ui->actionOnline_PAC->setChecked(true);
        ui->actionLocal_PAC->setChecked(false);
    } else {
        ui->actionOnline_PAC->setChecked(false);
        ui->actionLocal_PAC->setChecked(true);
    }
    if (guiConfig->get("secureLocalPac").toBool()) {
        ui->actionSecure_Local_PAC->setChecked(true);
    } else {
        ui->actionSecure_Local_PAC->setChecked(false);
    }
    if (guiConfig->get("shareOverLan").toBool()) {
        ui->actionAllow_Clients_from_LAN->setChecked(true);
    } else {
        ui->actionAllow_Clients_from_LAN->setChecked(false);
    }
    if (guiConfig->get("isVerboseLogging").toBool()) {
        ui->actionVerbose_Logging->setChecked(true);
    } else {
        ui->actionVerbose_Logging->setChecked(false);
    }
    if (guiConfig->get("autoCheckUpdate").toBool()) {
        ui->actionCheck_for_Updates_at_Startup->setChecked(true);
    } else {
        ui->actionCheck_for_Updates_at_Startup->setChecked(false);
    }
    if (guiConfig->get("checkPreRelease").toBool()) {
        ui->actionCheck_Pre_release_Version->setChecked(true);
    } else {
        ui->actionCheck_Pre_release_Version->setChecked(false);
    }
    if(guiConfig->get("autostart").toBool()){
        ui->actionStart_on_Boot->setChecked(true);
    }else{
        ui->actionStart_on_Boot->setChecked(false);
    }
    auto configs = guiConfig->getConfigs();
    ui->menuServers->clear();
    QList<QAction *> action_list;
    action_list << ui->actionLoad_Balance << ui->actionHigh_Availability << ui->actionChoose_by_statistics;
    ui->menuServers->addActions(action_list);
    ui->menuServers->addSeparator();
    action_list.clear();
    for (int i = 0; i < configs.size(); i++) {
        auto it = configs.at(i);
        QString name = it.toObject().value("remarks").toString();
        auto action = ui->menuServers->addAction(name, [=]() {
            GuiConfig::instance()->set("index", i);
            on_actionEnable_System_Proxy_triggered(true);
        });
        action->setCheckable(true);
        if (guiConfig->get("enabled").toBool() && guiConfig->get("index").toInt() == i) {
            action->setChecked(true);
        }
    }
    ui->menuServers->addSeparator();
    action_list << ui->actionEdit_Servers << ui->actionStatistics_Config<<ui->actionImport_from_gui_config_json<<ui->actionExport_as_gui_config_json;
    ui->menuServers->addActions(action_list);
    ui->menuServers->addSeparator();
    ui->menuServers->addSeparator();
    action_list << ui->actionShare_Server_Config << ui->actionScan_QRCode_from_Screen
                << ui->actionImport_URL_from_Clipboard;
    ui->menuServers->addActions(action_list);
    ui->menuServers->addSeparator();

    ui->menuHelp->menuAction()->setVisible(false);
    // ui->menuPAC->menuAction()->setVisible(false);
}

void MainWindow::on_actionImport_from_gui_config_json_triggered() {
    QString filename = QFileDialog::getOpenFileName(this, tr("choose gui-config.json file"), QDir::homePath(),
                                                    "gui-config.json");
    if (filename.isEmpty()) {
        return;
    }
    GuiConfig::instance()->readFromDisk(filename);
    updateMenu();
}

void MainWindow::on_actionEnable_System_Proxy_triggered(bool flag) {
    auto guiConfig = GuiConfig::instance();
    if (!flag) {
        proxyManager->stop();
        // 又混着了
        systemProxyModeManager->switchToNone();
    } else {
        auto configs = guiConfig->getConfigs();
        auto index = guiConfig->get("index").toInt();
        if (configs.size() < index + 1) {
            //TODO: choose a server to start
            Utils::warning(tr("choose server to start"));
        } else {
            auto config = configs.at(index).toObject();
            guiConfig->updateLastUsed();
            proxyManager->setConfig(config);
            proxyManager->start();
            if(guiConfig->get("global").toBool()){
                switchToGlobal();
            } else{
                switchToPacMode();
            }
        }
    }
    guiConfig->set("enabled", flag);
    updateMenu();
}

void MainWindow::on_actionPAC_triggered(bool checked) {
    qDebug() << "pac" << checked;
    auto guiConfig = GuiConfig::instance();
    if (guiConfig->get("global").toBool() == checked) {
        guiConfig->set("global", !checked);
        switchToPacMode();
    }
    updateMenu();
}

void MainWindow::on_actionGlobal_triggered(bool checked) {
    qDebug() << "global" << checked;
    auto guiConfig = GuiConfig::instance();
    if (guiConfig->get("global").toBool() != checked) {
        guiConfig->set("global", checked);
        switchToGlobal();
    }
    updateMenu();
}

void MainWindow::on_actionStart_on_Boot_triggered(bool checked) {
    // 如果使用flatpak，这里可能有问题
    QString url = "/usr/share/applications/shadowsocks-deepin.desktop";
    if (!checked) {
        QDBusPendingReply<bool> reply = startManagerInter.RemoveAutostart(url);
        reply.waitForFinished();
        if (!reply.isError()) {
            bool ret = reply.argumentAt(0).toBool();
            qDebug() << "remove from startup:" << ret;
        } else {
            qCritical() << reply.error().name() << reply.error().message();
            Utils::critical("change auto boot error");
        }
    } else {
        QDBusPendingReply<bool> reply = startManagerInter.AddAutostart(url);
        reply.waitForFinished();
        if (!reply.isError()) {
            bool ret = reply.argumentAt(0).toBool();
            qDebug() << "add to startup:" << ret;
        } else {
            qCritical() << reply.error().name() << reply.error().message();
            Utils::critical("change auto boot error");
        }
    }
    GuiConfig::instance()->set("autostart", checked);

}

void MainWindow::on_actionQuit_triggered() {
    qApp->exit();
}

QList<bool> MainWindow::getColumnHideFlags() {
    QString processColumns = settings->getOption("config_columns").toString();

    QList<bool> toggleHideFlags;
    toggleHideFlags << processColumns.contains("name");
    toggleHideFlags << processColumns.contains("server");
    toggleHideFlags << processColumns.contains("status");
    toggleHideFlags << processColumns.contains("latency");
    toggleHideFlags << processColumns.contains("local_port");
    toggleHideFlags << processColumns.contains("term_usage");
    toggleHideFlags << processColumns.contains("total_usage");
    toggleHideFlags << processColumns.contains("reset_date");
    toggleHideFlags << processColumns.contains("last_used");

    return toggleHideFlags;
}

bool MainWindow::eventFilter(QObject *, QEvent *event) {
    //    qDebug()<<event->type();
    if (event->type() == QEvent::WindowStateChange) {
        //        adjustStatusBarWidth();
    } else if (event->type() == QEvent::KeyPress) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        if (keyEvent->key() == Qt::Key_F) {
            if (keyEvent->modifiers() == Qt::ControlModifier) {
                toolbar->focusInput();
            }
        }
    } else if (event->type() == QEvent::Close) {
        if (w->rect().width() >= Constant::WINDOW_MIN_WIDTH) {
            settings->setOption("window_width", this->rect().width());
        }

        if (w->rect().height() >= Constant::WINDOW_MIN_HEIGHT) {
            settings->setOption("window_height", this->rect().height());
        }
    }

    return false;
}

int MainWindow::getSortingIndex() {
    QString sortingName = settings->getOption("config_sorting_column").toString();

    QList<QString> columnNames = {
        "name", "server", "status", "latency", "local_port", "term_usage", "total_usage", "reset_date", "last_used"
    };
    qDebug() << "??";
    return columnNames.indexOf(sortingName);
}

bool MainWindow::getSortingOrder() {
    return settings->getOption("config_sorting_order").toBool();
}

void MainWindow::on_actionDisconnect_triggered() {
    on_actionEnable_System_Proxy_triggered(false);
}

void MainWindow::on_actionScan_QRCode_from_Screen_triggered()
{
    QString uri = QRCodeCapturer::scanEntireScreen();
    if (uri.isNull()) {
        QMessageBox::critical(
                    nullptr,
                    tr("QR Code Not Found"),
                    tr("Can't find any QR code image that contains valid URI on your screen(s)."));
    } else {
        qDebug()<<"scan uri"<<uri;
        Utils::info(tr("found URI %1").arg(uri));
        if(uri.startsWith("ss://")){
            qDebug()<<"shadowsocks";
            if(SSValidator::validate(uri)){
                GuiConfig::instance()->addConfig(uri);
                updateMenu();
                on_actionEdit_Servers_triggered();
            }else{
                Utils::info( tr("URI is invalid") );
            }
        }
    }
}

void MainWindow::on_actionImport_URL_from_Clipboard_triggered()
{
    QString uri = QApplication::clipboard()->text();
    if(SSValidator::validate(uri)){
        GuiConfig::instance()->addConfig(uri);
        updateMenu();
        on_actionEdit_Servers_triggered();
    }else{
        QMessageBox::information(
            nullptr,
            tr("info"),
            tr("URI is invalid")
        );
    }
}

void MainWindow::on_actionShare_Server_Config_triggered()
{
    // 这里肯定是有内存泄露的，但是我只要一析构，程序就崩溃了
    // 生成分享的二维码
    ShareDialog* d = new ShareDialog();
    d->exec();
}


/**
 * save gui-config.json
 */
void MainWindow::on_actionExport_as_gui_config_json_triggered()
{
    QString savePath = QStandardPaths::standardLocations(QStandardPaths::DocumentsLocation).first();
    QString filename = QFileDialog::getExistingDirectory(nullptr, tr("Save gui-config.json"), savePath);

    if(filename.isEmpty()){
        return;
    }
    filename = filename + "/gui-config.json";
    GuiConfig::instance()->saveToDisk(filename);
    DDesktopServices::showFileItem(filename);
}
