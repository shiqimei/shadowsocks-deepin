//
// Created by pikachu on 17-8-19.
//

#include <widget/Toolbar.h>
#include <widget/EditHotkeysDialog.h>
#include <widget/EditOnlinePacUrlDialog.h>
#include <widget/ShowLogWidget.h>
#include <util/GfwlistToPacUtil.h>
#include <widget/EditServerDialog.h>
#include <widget/ShareServerConfigWidget.h>
#include <util/SsValidator.h>
#include <util/UriHelper.h>
#include <dao/DBHelper.h>
#include <DWindowManagerHelper>
#include <DDesktopServices>
#include "util/Util.h"
#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "SSProxyManager.h"
#include "DDEProxyModeManager.h"
#include "MultiListView.h"
#include <DTitlebar>
MainWindow::MainWindow(QWidget *parent) :
        DMainWindow(parent),
        ui(new Ui::MainWindow) {
    ui->setupUi(this);
    GUI_CONFIG_PATH = QString("%1/.ss/gui-config.json").arg(QDir::homePath());
    DBHelper::instance();
    readConfig();
    proxyManager = new SSProxyManager(this);
    systemProxyModeManager = new DDEProxyModeManager(this);
//    installEventFilter(this);   // add event filter
    initTheme();
    initMenu();
    initService();
    initCentralWidget();
    reloadMenu();
    systemTrayIcon.setIcon(Util::getIcon(Util::Type::None));
    systemTrayIcon.show();
    connect(&systemTrayIcon,&QSystemTrayIcon::activated,[=](){show();});
}

void MainWindow::initCentralWidget() {
    if (titlebar() != nullptr) {
        toolbar = new Toolbar();
        titlebar()->setCustomWidget(toolbar, Qt::AlignVCenter, false);

        layoutWidget = new QWidget();
        auto layout = new QHBoxLayout(layoutWidget);
        MultiListView *multiListView = new MultiListView();
        layout->addWidget(multiListView);
        // 连接信号 rightClickItems 到 popupMenu 槽
        connect(multiListView, &MultiListView::rightClickItems, this, &MainWindow::popupMenu, Qt::QueuedConnection);
        setCentralWidget(layoutWidget);
    }
}

void MainWindow::initService() {
    auto modeGroup = new QActionGroup(this);
    modeGroup->addAction(ui->actionPAC);
    modeGroup->addAction(ui->actionGlobal);
    auto pacGroup = new QActionGroup(this);
    pacGroup->addAction(ui->actionLocal_PAC);
    pacGroup->addAction(ui->actionOnline_PAC);
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
    saveConfig();
    delete DBHelper::instance();
    delete ui;
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
    serversMenu->addSeparator();
    serversMenu->addAction(ui->actionEdit_Servers);
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
    pacMenu->addAction(ui->actionCopy_Local_PAC_URL);
    pacMenu->addAction(ui->actionEdit_Online_PAC_URL);
    menu->addMenu(pacMenu);
    menu->addSeparator();
    menu->addAction(ui->actionStart_on_Boot);
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
/*
    ui->actionEnable_System_Proxy->setChecked(Util::guiConfig.enabled && !Util::model->getItems().isEmpty());
    modeMenu->setEnabled(Util::guiConfig.enabled && !Util::model->getItems().isEmpty());
    ui->actionPAC->setChecked(!Util::guiConfig.global);
    ui->actionGlobal->setChecked(Util::guiConfig.global);
    ui->actionLocal_PAC->setChecked(!Util::guiConfig.useOnlinePac);
    ui->actionOnline_PAC->setChecked(Util::guiConfig.useOnlinePac);
    ui->actionSecure_Local_PAC->setChecked(Util::guiConfig.secureLocalPac);
    ui->actionStart_on_Boot->setChecked(bootService->isAutoBoot());
    ui->actionAllow_Clients_from_LAN->setChecked(Util::guiConfig.shareOverLan);
    ui->actionVerbose_Logging->setChecked(Util::guiConfig.isVerboseLogging);
    ui->actionCheck_for_Update_at_Startup->setChecked(Util::guiConfig.autoCheckUpdate);
    ui->actionCheck_Pre_release_Version->setChecked(Util::guiConfig.checkPreRelease);
*/

    serversMenu->clear();
    serversMenu->addAction(ui->actionLoad_Balance);
    serversMenu->addAction(ui->actionHigh_Availability);
    serversMenu->addSeparator();
    serversMenu->addSeparator();
    auto actionGroup = new QActionGroup(this);
    actionGroup->addAction(ui->actionLoad_Balance);
    actionGroup->addAction(ui->actionHigh_Availability);

    serversMenu->addAction(ui->actionEdit_Servers);
    serversMenu->addSeparator();
    serversMenu->addAction(ui->actionShare_Server_Config);
    serversMenu->addAction(ui->actionScan_QRCode_from_Screen);
    serversMenu->addAction(ui->actionImport_URL_from_Clipboard);

}

void MainWindow::on_actionEnable_System_Proxy_triggered(bool checked) {
    qDebug()<<"启动代理"<<checked;
    // 检查是否能启动
    if(checked){
        /**
         * 1. 启动Shadowsocks
         * 2. 根据配置文件将系统代理设置为Manual或者Auto
         */
        // 获取到当前的配置
        ProxyConfig* config = new ProxyConfig();
        config->setProperty("local_address","127.0.0.1");
        config->setProperty("local_port","1080");
        config->setProperty("method","chacha20-ietf-poly1305");
        config->setProperty("password","7sapy6mrMkps");
        config->setProperty("server","us2-sta11.3a281.site");
        config->setProperty("server_port","20526");
        config->setProperty("timeout","600");
        // 启动会失败
        proxyManager->startProxy(config);
        if(property("global").toBool()){
            switchToManual();
        } else{
            swtichToAuto();
        }
    } else{
        proxyManager->stopProxy();
        systemProxyModeManager->switchToNone();
    }
}

void MainWindow::swtichToAuto() {
    QString pacURI = "";
    if(property("useOnlinePac").toBool()){
            if(property("pacUrl").toString().isNull()){
                setProperty("pacUrl","https://raw.githubusercontent.com/PikachuHy/ss/master/autoproxy.pac");
            }
            pacURI = property("pacUrl").toString();
        } else{
            pacURI = QString("%1/.ss/autoproxy.pac").arg(QDir::homePath());
        }
    systemProxyModeManager->switchToAuto(pacURI);
}

void MainWindow::switchToManual() {
    systemProxyModeManager->switchToManual("127.0.0.1", property("localPort").toInt());
}

void MainWindow::on_actionEdit_Servers_triggered(bool checked) {
    auto dialog = new EditServerDialog();
    dialog->exec();
    dialog->deleteLater();
}

void MainWindow::on_actionEdit_Local_PAC_File_triggered(bool checked) {
    QString path = QString("%1/.ss/autoproxy.pac").arg(QDir::homePath());
    qDebug() << "path" << path;
    DDesktopServices::showFileItem(path);
}

void MainWindow::on_actionEdit_User_Rule_for_GFWList_triggered(bool checked) {
    QString path = QString("%1/.ss/user-rule.txt").arg(QDir::homePath());
    qDebug() << "path" << path;
    DDesktopServices::showFileItem(path);
}

void MainWindow::on_actionCopy_Local_PAC_URL_triggered(bool checked) {
    QApplication::clipboard()->setText(QString("file://%1/.ss/autoproxy.pac").arg(QDir::homePath()));

}

void MainWindow::on_actionEdit_Online_PAC_URL_triggered(bool checked) {
    auto dialog = new EditOnlinePacUrlDialog();
    dialog->exec();
    dialog->deleteLater();
}

void MainWindow::on_actionShare_Server_Config_triggered(bool checked) {
    auto dialog = new ShareServerConfigWidget();
    dialog->exec();
    dialog->deleteLater();
}

void MainWindow::on_actionScan_QRCode_from_Screen_triggered(bool checked) {
    QString uri;
    QList<QScreen *> screens = qApp->screens();
    for (QList<QScreen *>::iterator sc = screens.begin();
         sc != screens.end();
         ++sc) {
        QImage raw_sc = (*sc)->grabWindow(qApp->desktop()->winId()).toImage();
        QString result = URIHelper::decodeImage(raw_sc);
        if (!result.isNull()) {
            uri = result;
        }
    }
    qDebug() << "扫描到二维码" << uri;
    if (!SSValidator::validate(uri)) {
        QMessageBox::critical(
                nullptr,
                tr("QR Code Not Found"),
                tr("Can't find any QR code image that contains valid URI on your screen(s)."));
    }
}

void MainWindow::on_actionImport_URL_from_Clipboard_triggered(bool checked) {
    QString uri = QApplication::clipboard()->text().trimmed();
    qDebug() << "uri" << uri;
    if (!SSValidator::validate(uri)) {
        QMessageBox::critical(
                nullptr,
                tr("Import URL From Clipboard Error"),
                tr("Can't find valid URI"));
    }
}

void MainWindow::on_actionStart_on_Boot_triggered(bool checked) {
    if (!checked) {
        QDBusPendingReply<bool> reply = startManagerInter.RemoveAutostart(Util::DESKTOP_URL);
        reply.waitForFinished();
        if (!reply.isError()) {
            bool ret = reply.argumentAt(0).toBool();
            qDebug() << "remove from startup:" << ret;
            if (ret) {
            }
        } else {
            qCritical() << reply.error().name() << reply.error().message();
        }
    } else {
        QDBusPendingReply<bool> reply = startManagerInter.AddAutostart(Util::DESKTOP_URL);
        reply.waitForFinished();
        if (!reply.isError()) {
            bool ret = reply.argumentAt(0).toBool();
            qDebug() << "add to startup:" << ret;
            if (ret) {
            }
        } else {
            qCritical() << reply.error().name() << reply.error().message();
        }
    }
}

void MainWindow::on_actionForward_Proxy_triggered(bool checked) {
//    proxyService->editForwardProxy();
}

void MainWindow::on_actionEdit_Hotkeys_triggered(bool checked) {

    auto dialog = new EditHotkeysDialog();
    dialog->exec();
    dialog->deleteLater();
}

void MainWindow::on_actionShow_Logs_triggered(bool checked) {
//    logService->showLog();
}

void MainWindow::on_actionCheck_for_Updates_triggered(bool checked) {
    updateChecker.checkUpdate();
}

void MainWindow::on_actionCheck_for_Update_at_Startup_triggered(bool checked) {
    setProperty("autoCheckUpdate",checked);
}

void MainWindow::on_actionCheck_Pre_release_Version_triggered(bool checked) {
    setProperty("checkPreRelease",checked);
}

void MainWindow::on_actionAbout_triggered(bool checked) {
//    showLogWidget->show();
}

void MainWindow::on_actionQuit_triggered(bool checked) {
    qApp->exit();
}

void MainWindow::on_actionPAC_triggered(bool checked) {
    swtichToAuto();
}

void MainWindow::on_actionGlobal_triggered(bool checked) {
//    proxyService->setProxyMethod(ProxyService::Manual);
    switchToManual();
}

void MainWindow::on_actionLocal_PAC_triggered(bool checked) {
    setProperty("useOnlinePac", true);
}

void MainWindow::on_actionOnline_PAC_triggered(bool checked) {
    setProperty("useOnlinePac", true);
}

void MainWindow::on_actionUpdate_Local_PAC_from_GFWList_triggered(bool checked) {
    auto *gfwlistToPacUtil = new GfwlistToPacUtil();
    connect(gfwlistToPacUtil, &GfwlistToPacUtil::finished, [=]() {
        gfwlistToPacUtil->deleteLater();
    });
    gfwlistToPacUtil->gfwlist2pac();
}

void MainWindow::on_actionSwitch_system_proxy_mode_triggered(bool checked) {
    bool b = property("enabled").toBool();
    if(b){
       setProperty("enabled",!b);
    }
}

void MainWindow::on_actionSwitch_to_next_server_triggered(bool checked) {
//    auto curIndex = property("index").toInt();
}

void MainWindow::on_actionSwitch_to_prev_server_triggered(bool checked) {
    int curIndex = property("index").toInt();
    if(curIndex>0){
        curIndex--;
    }
}

void MainWindow::readConfig() {
    qDebug()<<"read gui config";
    QFile file(GUI_CONFIG_PATH);
    if(!file.exists()){
        file.open(QIODevice::WriteOnly);
        file.close();
    }
    if(file.open(QIODevice::ReadOnly|QIODevice::Text)){
        QJsonDocument jsonDocument = QJsonDocument::fromJson(file.readAll());
        QJsonObject jsonObject = jsonDocument.object();
        QJsonObject::Iterator it;
        for(it=jsonObject.begin();it!=jsonObject.end();it++){
            if(it.key().isNull()){
                qDebug()<<"null "<<it.key()<<it.value();
            }
            const char *key = it.key().toStdString().c_str();
            switch (it.value().type()){
                case QJsonValue::Null:break;
                case QJsonValue::Bool:{
                    setProperty(key, it.value().toBool());
                    break;
                }
                case QJsonValue::Double:{
                    setProperty(key,it.value().toDouble());
                    break;
                }
                case QJsonValue::String:{
                    setProperty(key,it.value().toString());
                    break;
                }
                case QJsonValue::Array:break;
                case QJsonValue::Object:break;
                case QJsonValue::Undefined:break;
            }
        }

    }
}

void MainWindow::saveConfig() {
    QJsonDocument jsonDocument;
    QJsonObject jsonObject;
    auto t = dynamicPropertyNames();
    for(auto& it : t){
        qDebug()<<it;
        const QVariant &value = property(it);
        switch (value.type()){
            case QVariant::Invalid:break;
            case QVariant::Bool:{
                jsonObject.insert(it,value.toBool());
                break;
            }
            case QVariant::Int:
            case QVariant::UInt:
            case QVariant::LongLong:
            case QVariant::ULongLong:
            case QVariant::Double:{
                jsonObject.insert(it,value.toDouble());
                break;
            }
            case QVariant::String:{
                jsonObject.insert(it,value.toString());
                break;
            }
            default:
                break;
        }
    }
    jsonDocument.setObject(jsonObject);
    QFile file(GUI_CONFIG_PATH);
    file.open(QIODevice::WriteOnly);
    file.write(jsonDocument.toJson());
    file.flush();
    file.close();
}

void MainWindow::popupMenu(QPoint pos, QList<DSimpleListItem *> items) {

    QMenu *menu = new QMenu();
    QAction *actionConnect = new QAction("connect",this);
    QAction *actionEdit = new QAction("edit", this);
    QAction *actionShare = new QAction("share",this);
    QAction *actionRemove = new QAction("remove",this);
    QAction *actionTestLatency = new QAction("test latency",this);

    menu->addAction(actionConnect);
    menu->addAction(actionEdit);
    menu->addAction(actionShare);
    menu->addAction(actionRemove);
    menu->addAction(actionTestLatency);

    // 在用户右键的坐标弹出菜单
    menu->exec(pos);
}
