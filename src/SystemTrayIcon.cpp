//
// Created by pikachu on 17-7-20.
//

#include "SystemTrayIcon.h"
DWIDGET_USE_NAMESPACE
DUTIL_USE_NAMESPACE

SystemTrayIcon::SystemTrayIcon(QObject *parent)
        : QSystemTrayIcon(parent) {
    proxyService = new ProxyServiceImpl(this);
    serverSerivce = new ServerSerivceImpl(this);
    pacService = new PacServiceImpl(this);
    logService = new LogServiceImpl(this);
    bootService = new BootServiceImpl(this);
    updateService = new UpdateServiceImpl(this);
    hotkeyService = new HotkeyServiceImpl(this);
    aboutService = new AboutServiceImpl(this);
    setIcon(QPixmap::fromImage(Util::noProxyIconImage()));
    guiConfigDao = GuiConfigDao::instance();
    guiConfig = guiConfigDao->get();
    menu = new QMenu("menu");
    startSystemAgentAction = new QAction("启动系统代理", this);
    startSystemAgentAction->setCheckable(true);
    menu->addAction(startSystemAgentAction);
    systemAgentModeMenu = new QMenu("系统代理模式", menu);
    QActionGroup *systemAgentModeActionGroup = new QActionGroup(this);
    pacModeAction = new QAction("PAC模式", this);
    globelModeAction = new QAction("全局模式", this);
    systemAgentModeActionGroup->addAction(pacModeAction);
    systemAgentModeActionGroup->addAction(globelModeAction);
    pacModeAction->setCheckable(true);
    globelModeAction->setCheckable(true);
    systemAgentModeMenu->addAction(pacModeAction);
    systemAgentModeMenu->addAction(globelModeAction);
    menu->addMenu(systemAgentModeMenu);

    serverMenu = new QMenu("服务器", menu);
    loadBalancingAction = new QAction("负载均衡", this);
    highAvailabilityAction = new QAction("高可用", this);
    accordingToStatisticsAction = new QAction("根据统计", this);
    serverGroup = new QActionGroup(this);
    editServerAction = new QAction("编辑服务器...", this);
    statisticsConfigurationAction = new QAction("统计配置...", this);
    shareServerConfigurationAction = new QAction("分享服务器配置...", this);
    scanThe2DCodeOnTheScreenAction = new QAction("扫描屏幕上的二维码...", this);
    importTheURLFromTheClipboardAction = new QAction("从剪贴板导入URL...", this);
    menu->addMenu(serverMenu);

    pacMenu = new QMenu("PAC", menu);
    useLocalPacAction = new QAction("使用本地PAC", this);
    useOnlinePacAction = new QAction("使用在线PAC", this);
    useLocalPacAction->setCheckable(true);
    useOnlinePacAction->setCheckable(true);
    QActionGroup *pacGroup = new QActionGroup(this);
    pacGroup->addAction(useLocalPacAction);
    pacGroup->addAction(useOnlinePacAction);
    editLocalPacFileAction = new QAction("编辑本地PAC文件...", this);
    updateLocalPacFromGFWListAction = new QAction("从GFWList更新本地PAC", this);
    editUserRulesForGFWListAction = new QAction("编辑GFWList的用户规则...", this);
    protectLocalPacAction = new QAction("保护本地PAC", this);
    copyLocalPacUrlAction = new QAction("复制本地PAC网址", this);
    editOnlinePacUrlAction = new QAction("编辑在线PAC网址...", this);
    pacMenu->addAction(useLocalPacAction);
    pacMenu->addAction(useOnlinePacAction);
    pacMenu->addSeparator();
    pacMenu->addAction(editLocalPacFileAction);
    pacMenu->addAction(updateLocalPacFromGFWListAction);
    pacMenu->addAction(editUserRulesForGFWListAction);
    pacMenu->addAction(protectLocalPacAction);
    pacMenu->addAction(copyLocalPacUrlAction);
    pacMenu->addAction(editOnlinePacUrlAction);
    menu->addMenu(pacMenu);

    positiveAgentAction = new QAction("正向代理...", this);
    menu->addAction(positiveAgentAction);

    menu->addSeparator();

    bootAction = new QAction("开机启动", this);
    menu->addAction(bootAction);

    allowConnectionsFromTheLANAction = new QAction("允许来自局域网的连接", this);
    menu->addAction(allowConnectionsFromTheLANAction);

    menu->addSeparator();

    editShortcutsAction = new QAction("编辑快捷键...", this);
    menu->addAction(editShortcutsAction);

    helpMenu = new QMenu("帮助", menu);
    showLogAction = new QAction("显示日志", this);
    detailedLogAction = new QAction("详细记录日志", this);
    updateMenu = new QMenu("更新", helpMenu);
    checkForUpdateAction = new QAction("检查更新", this);
    updateMenu->addAction(checkForUpdateAction);
    updateMenu->addSeparator();
    checkForUpdatesAtStartupAction = new QAction("启动时检查更新", this);
    checkTheBetaUpdateAction = new QAction("检查测试版更新", this);
    updateMenu->addAction(checkForUpdatesAtStartupAction);
    updateMenu->addAction(checkTheBetaUpdateAction);
    helpMenu->addAction(showLogAction);
    helpMenu->addAction(detailedLogAction);
    helpMenu->addMenu(updateMenu);
    aboutAction = new QAction("关于", this);
    helpMenu->addAction(aboutAction);
    menu->addMenu(helpMenu);


    exitAction = new QAction("退出", this);
    menu->addAction(exitAction);

    setContextMenu(menu);


    for (int i = 0; i < maxLenth; ++i) {
        inBytes.append(0);
        outBytes.append(0);
    }
    auto timer = new QTimer();
    connect(timer,&QTimer::timeout,[=](){
        int type = 0;
        if(pacModeAction->isChecked()){
            type = type | Util::Type ::Pac;
        } else{
            type = type | Util::Type ::Global;
        }
        if(inByte>0){
            type=type | Util::Type ::In;
        }
        inBytes.append(inByte);
        inByte=0;
        if(inBytes.size()>maxLenth){
            inBytes.pop_front();
        }

        if(outByte>0){
            type=type|Util::Type ::Out;
        }
        outBytes.append(outByte);
        outByte=0;
       if(outBytes.size()>maxLenth){
           outBytes.pop_front();
       }
        setIcon(QPixmap::fromImage(Util::proxyIconImage(type)));
        // 如果显示流量监控窗口 触发重绘
    });
    timer->start(300);
    startSystemAgentAction->setChecked(false);
    systemAgentModeMenu->setEnabled(false);


    detailedLogAction->setCheckable(true);
    detailedLogAction->setChecked(true);
    controller = new Controller(true);
    QObject::connect(controller, &QSS::Controller::debug, [=](QString log) {
        qDebug() << "[QSS::Controller::debug]" << log;
    });
    QObject::connect(controller, &QSS::Controller::info, [=](QString log) {
        qDebug() << "[QSS::Controller::info]" << log;
    });
    connect(controller, &QSS::Controller::runningStateChanged, [=](bool flag) {
        qDebug() << "QSS::Controller::runningStateChanged" << flag;
    });
    connect(controller, &QSS::Controller::newBytesReceived, [=](const qint64 bytes) {
//        qDebug() << "QSS::Controller::newBytesReceived" << bytes;
        inByte+=bytes;
    });
    connect(controller, &QSS::Controller::newBytesSent, [=](const qint64 bytes) {
//        qDebug() << "QSS::Controller::newBytesSent" << bytes;
        outByte+=bytes;
    });
//    editServerDialog=new EditServerDialog(profiles);
    initConfig();

/*

        bool checked = startSystemAgentAction->isChecked();
        if (!checked) {
            qDebug() << "取消系统代理";
            systemAgentModeMenu->setEnabled(false);
            setProxyMethod("none");
            controller->stop();
            setIcon(QPixmap::fromImage(Util::noProxyIconImage()));

        } else {
            qDebug() << "启动系统代理";
            systemAgentModeMenu->setEnabled(true);
            if (pacModeAction->isChecked()) {
                setAutoProxy();
                setIcon(QPixmap::fromImage(Util::proxyIconImage(Util::Type::Pac)));
            } else if (globelModeAction->isChecked()) {
                setManualProxy();
                setIcon(QPixmap::fromImage(Util::proxyIconImage(Util::Type::Global)));
            } else {
                pacModeAction->trigger();
            }

            for (auto &it:serverGroup->actions()) {
                ServerAction *action = dynamic_cast<ServerAction *>(it);
                controller->setup(action->profile);
                controller->start();
            }
        }
*/

    connect(startSystemAgentAction, &QAction::triggered, proxyService, &ProxyService::setProxyEnabled);
    connect(systemAgentModeActionGroup, &QActionGroup::triggered, [this](QAction *action) {
        auto proxyMethod = action == pacModeAction ? ProxyService::Auto : ProxyService::Manual;
        proxyService->setProxyMethod(proxyMethod);
    });
    connect(serverGroup, &QActionGroup::triggered, this, &SystemTrayIcon::onServerActionTriggered);
    connect(editServerAction, &QAction::triggered, serverSerivce, &ServerSerivce::editServers);
    connect(pacGroup, &QActionGroup::triggered, [=](QAction *action) {
        pacService->setUseLocalPac(action == useLocalPacAction);
    });
    connect(editLocalPacFileAction, &QAction::triggered, pacService, &PacService::editLocalPacFile);
    connect(updateLocalPacFromGFWListAction, &QAction::triggered, updateService,
            &UpdateService::updateLocalPacFromGFWList);
    connect(editUserRulesForGFWListAction, &QAction::triggered, pacService, &PacService::editUserRuleForGFWList);
    connect(copyLocalPacUrlAction, &QAction::triggered, pacService, &PacService::copyLocalPacURL);
    connect(editOnlinePacUrlAction, &QAction::triggered, pacService, &PacService::editOnlinePacUrl);
    connect(shareServerConfigurationAction, &QAction::triggered, serverSerivce, &ServerSerivce::shareServerConfig);
    connect(scanThe2DCodeOnTheScreenAction, &QAction::triggered, serverSerivce, &ServerSerivce::scanQRCodeFromScreen);
    connect(importTheURLFromTheClipboardAction, &QAction::triggered, serverSerivce,
            &ServerSerivce::importURLfromClipboard);
    bootAction->setCheckable(true);
    bootAction->setChecked(bootService->isAutoBoot());
    connect(bootAction, &QAction::triggered, bootService, &BootService::setAutoBoot);
    connect(positiveAgentAction, &QAction::triggered, proxyService, &ProxyService::editForwardProxy);
    connect(editShortcutsAction, &QAction::triggered, hotkeyService, &HotkeyService::editHotkey);
    connect(showLogAction, &QAction::triggered, logService, &LogService::showLog);
    connect(checkForUpdateAction,&QAction::triggered,&updateChecker,&UpdateChecker::checkUpdate);
    checkForUpdatesAtStartupAction->setCheckable(true);
    checkTheBetaUpdateAction->setCheckable(true);
    checkForUpdatesAtStartupAction->setChecked(guiConfig.autoCheckUpdate);
    checkTheBetaUpdateAction->setChecked(guiConfig.checkPreRelease);
    connect(checkForUpdatesAtStartupAction, &QAction::triggered, updateService,
            &UpdateService::setCheckForUpdatesAtStartup);
    connect(checkTheBetaUpdateAction, &QAction::triggered, updateService, &UpdateService::setCheckPrereleaseVersion);
    connect(aboutAction, &QAction::triggered, aboutService, &AboutService::showAbout);
    connect(exitAction, &QAction::triggered, [=]() {
        proxyService->setProxyEnabled(false);
        qDebug() << "退出并取消代理";
        qApp->exit();
    });


    updateServerMenu();
    if (!configs.isEmpty()) {
        startSystemAgentAction->trigger();
        pacModeAction->trigger();
    }
    if(guiConfig.autoCheckUpdate){
        checkForUpdateAction->triggered();
    }
}

void SystemTrayIcon::updateServerMenu() {
#ifdef QT_DEBUG
    qDebug() << "刷新服务器列表";
#endif
    serverMenu->clear();
    serverMenu->addAction(loadBalancingAction);
    serverMenu->addAction(highAvailabilityAction);
    serverMenu->addAction(accordingToStatisticsAction);
    serverMenu->addSeparator();
    if (!configs.isEmpty()) {
/*        delete serverGroup;
        QAction *t = nullptr;
        serverGroup = new QActionGroup(this);
        connect(serverGroup, &QActionGroup::triggered, this, &SystemTrayIcon::onServerActionTriggered);
        for (int i = 0; i < configs.size(); ++i) {
            auto it = configs[i];
#ifdef QT_DEBUG
            qDebug() << it.remarks;
#endif
            ServerAction *action = new ServerAction(it.remarks, this);
            action->profile = it.profile;
            action->setCheckable(true);
            serverGroup->addAction(action);
            serverMenu->addAction(action);
            if (i == 0) {
                t = action;
            }
#ifdef QT_DEBUG
            output(action->profile);
#endif
        }
        serverMenu->addSeparator();
        if (t != nullptr) {
            t->trigger();
        }*/
    } else {
        startSystemAgentAction->setEnabled(false);
    }
    serverMenu->addAction(editServerAction);
    serverMenu->addAction(statisticsConfigurationAction);
    serverMenu->addSeparator();
    serverMenu->addAction(shareServerConfigurationAction);
    serverMenu->addAction(scanThe2DCodeOnTheScreenAction);
    serverMenu->addAction(importTheURLFromTheClipboardAction);

}

void SystemTrayIcon::initConfig() {
    configs = ConfigUtil::readConfig();
    downloadPac();
}

void SystemTrayIcon::onServerActionTriggered(QAction *action) {
//    ServerAction *serverAction = dynamic_cast<ServerAction *>(action);
//    controller->setup(serverAction->profile);
//    localAddress = serverAction->profile.local_address;
//    localPort = QString::number(serverAction->profile.local_port);
//    if (startSystemAgentAction->isChecked()) {
//        controller->stop();
//        controller->setup(serverAction->profile);
//        controller->start();
//    }
}

void SystemTrayIcon::downloadPac() {
    pacConfig.onlineUrl = "https://raw.githubusercontent.com/PikachuHy/ss/master/autoproxy.pac";
    QFile *pacFile;//文件指针
    QNetworkReply *pacReply;
    QNetworkAccessManager *pacManager;
    //下载文件之前先在本地创建一个文件
    QDir file;//文件夹
    QString fileStr = QObject::tr("%1/.ss/").arg(QDir::homePath());
    QString fileName = fileStr + "/autoproxy.pac";
    //判断文件夹是否存在 不存在创建
    if (!file.exists(fileStr)) {
        file.mkpath(fileStr);
    }
    pacFile = new QFile(fileName);
    //判断文件是否可写入 不可写删除 指针赋值0
    if (!pacFile->open(QIODevice::WriteOnly)) {
        delete pacFile;
        pacFile = nullptr;
        return;
    }
    //开始请求 下载文件
    QUrl serviceUrl = QUrl("https://raw.githubusercontent.com/PikachuHy/ss/master/autoproxy.pac");
    pacManager = new QNetworkAccessManager();
//get方式请求 如需加密用post
    pacReply = pacManager->get(QNetworkRequest(serviceUrl));
    QObject::connect(pacReply, &QNetworkReply::readyRead, [=]() {
        if (pacFile != nullptr) {
            pacFile->write(pacReply->readAll());
        }

    });//数据写入
    QObject::connect(pacReply, &QNetworkReply::finished, [=]() {
        //刷新文件
        pacFile->flush();
        pacFile->close();
        pacFile->deleteLater();
        pacReply->deleteLater();
        pacManager->deleteLater();
        pacConfig.localFilePath = fileName;
        pacConfig.is_local = true;
        if (!configs.isEmpty()) {
            useLocalPacAction->trigger();
        }
    });//请求完成
}
