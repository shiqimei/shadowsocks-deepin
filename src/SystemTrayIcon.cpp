//
// Created by pikachu on 17-7-20.
//

#include <util/Util.h>
#include "SystemTrayIcon.h"

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

    menu = new QMenu("menu");
    startSystemAgentAction = new QAction("启动系统代理", this);
    startSystemAgentAction->setCheckable(true);
    menu->addAction(startSystemAgentAction);
    systemAgentModeMenu = new QMenu("系统代理模式", menu);
    auto *systemAgentModeActionGroup = new QActionGroup(this);
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
    auto *pacGroup = new QActionGroup(this);
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
    bootAction->setCheckable(true);
    menu->addAction(bootAction);

    allowConnectionsFromTheLANAction = new QAction("允许来自局域网的连接", this);
    menu->addAction(allowConnectionsFromTheLANAction);

    menu->addSeparator();

    editShortcutsAction = new QAction("编辑快捷键...", this);
    menu->addAction(editShortcutsAction);

    helpMenu = new QMenu("帮助", menu);
    showLogAction = new QAction("显示日志", this);
    detailedLogAction = new QAction("详细记录日志", this);
    detailedLogAction->setCheckable(true);
    updateMenu = new QMenu("更新", helpMenu);
    checkForUpdateAction = new QAction("检查更新", this);
    updateMenu->addAction(checkForUpdateAction);
    updateMenu->addSeparator();
    checkForUpdatesAtStartupAction = new QAction("启动时检查更新", this);
    checkTheBetaUpdateAction = new QAction("检查测试版更新", this);
    checkForUpdatesAtStartupAction->setCheckable(true);
    checkTheBetaUpdateAction->setCheckable(true);
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

    connect(startSystemAgentAction, &QAction::triggered, proxyService, &ProxyService::setProxyEnabled);
    connect(systemAgentModeActionGroup, &QActionGroup::triggered, [this](QAction *action) {
        auto proxyMethod = action == pacModeAction ? ProxyService::Auto : ProxyService::Manual;
        proxyService->setProxyMethod(proxyMethod);
    });
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
    connect(bootAction, &QAction::triggered, bootService, &BootService::setAutoBoot);
    connect(positiveAgentAction, &QAction::triggered, proxyService, &ProxyService::editForwardProxy);
    connect(editShortcutsAction, &QAction::triggered, hotkeyService, &HotkeyService::editHotkey);
    connect(showLogAction, &QAction::triggered, logService, &LogService::showLog);
    connect(checkForUpdateAction, &QAction::triggered, updateService, &UpdateService::checkUpdate);
    connect(checkForUpdatesAtStartupAction, &QAction::triggered, updateService,
            &UpdateService::setCheckForUpdatesAtStartup);
    connect(checkTheBetaUpdateAction, &QAction::triggered, updateService, &UpdateService::setCheckPrereleaseVersion);
    connect(aboutAction, &QAction::triggered, aboutService, &AboutService::showAbout);
    connect(exitAction, &QAction::triggered, [=]() {
        proxyService->setProxyEnabled(false);
        qDebug() << "退出并取消代理";
        qApp->exit();
    });

    connect(proxyService, &ProxyService::requestReloadMenu, this, &SystemTrayIcon::reloadMenu);
    connect(proxyService, &ProxyService::newController, logService, &LogService::newController);
    connect(logService, &LogService::requestUpdateIcon, this, &SystemTrayIcon::setIcon);
    reloadMenu();
}

void SystemTrayIcon::reloadMenu() {
    startSystemAgentAction->setChecked(proxyService->isProxyEnaled());
    systemAgentModeMenu->setEnabled(proxyService->isProxyEnaled());
    pacModeAction->setChecked(proxyService->isPacMode());
    globelModeAction->setChecked(proxyService->isGlobelMode());
    useLocalPacAction->setChecked(pacService->isUseLocalPac());
    useOnlinePacAction->setChecked(pacService->isUseOnlinePac());
    protectLocalPacAction->setChecked(pacService->isSecureLocalPac());
    bootAction->setChecked(bootService->isAutoBoot());
    allowConnectionsFromTheLANAction->setChecked(proxyService->isAllowClientsFromLAN());
    detailedLogAction->setChecked(logService->isVerboseLogging());
    checkForUpdatesAtStartupAction->setChecked(updateService->isCheckForUpdatesAtStartup());
    checkTheBetaUpdateAction->setChecked(updateService->isCheckPrereleaseVersion());

    serverMenu->clear();
    serverMenu->addAction(loadBalancingAction);
    serverMenu->addAction(highAvailabilityAction);
    serverMenu->addAction(accordingToStatisticsAction);
    serverMenu->addSeparator();
    if (!Util::guiConfig.configs.isEmpty()) {
        auto actionGroup = new QActionGroup(this);
        for (int i = 0; i < Util::guiConfig.configs.size(); ++i) {
            auto action = new QAction(Util::guiConfig.configs[i].getRemarks(), this);
            action->setData(i);
            actionGroup->addAction(action);
            serverMenu->addAction(action);
//            qDebug()<<i<<(Util::guiConfig.configs.value(i).getRemarks());
        }
        connect(actionGroup, &QActionGroup::triggered, [=](QAction *action) {
            int index = action->data().toInt();
            Util::guiConfig.index = index;
            proxyService->setProxyEnabled(true);
        });
        serverMenu->addSeparator();
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
