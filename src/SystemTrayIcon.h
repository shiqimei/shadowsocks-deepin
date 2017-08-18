//
// Created by pikachu on 17-7-20.
//

#ifndef SS_SYSTEMTRAYICON_H
#define SS_SYSTEMTRAYICON_H

#include <util/ConfigUtil.h>
#include "service/impl/ServiceImpl.h"
#include "dao/GuiConfigDao.h"
class SystemTrayIcon: public QSystemTrayIcon {
    Q_OBJECT
public:
    explicit SystemTrayIcon(QObject *parent);

    Controller* controller;
    QMenu* menu;
    QActionGroup* serverGroup;
    /**
     * 启动系统代理
     */
    QAction* startSystemAgentAction;
    /**
     * 系统代理模式
     */
    QMenu* systemAgentModeMenu;
    /**
     * PAC模式
     */
    QAction* pacModeAction;
    /**
     * 全局模式
     */
    QAction* globelModeAction;
    /**
     * 服务器
     */
    QMenu* serverMenu;
    /**
     * 负载均衡
     */
    QAction* loadBalancingAction;
    /**
     * 高可用
     */
    QAction* highAvailabilityAction;
    /**
     * 根据统计
     */
    QAction* accordingToStatisticsAction;
    /**
     * 编辑服务器
     */
    QAction* editServerAction;
    /**
     * 统计配置
     */
    QAction* statisticsConfigurationAction;
    /**
     * 分享服务器配置
     */
    QAction* shareServerConfigurationAction;
    /**
     * 扫描屏幕上的二维码
     */
    QAction* scanThe2DCodeOnTheScreenAction;
    /**
     * 从剪贴板导入URL
     */
    QAction* importTheURLFromTheClipboardAction;
    /**
     * PAC
     */
    QMenu* pacMenu;
    /**
     * 使用本地PAC
     */
    QAction* useLocalPacAction;
    /**
     * 使用在线PAC
     */
    QAction* useOnlinePacAction;
    /**
     * 编辑本地PAC文件
     */
    QAction* editLocalPacFileAction;
    /**
     * 从GFWList更新本地PAC
     */
    QAction* updateLocalPacFromGFWListAction;
    /**
     * 编辑GFWList的用户规则
     */
    QAction* editUserRulesForGFWListAction;
    /**
     * 保护本地PAC
     */
    QAction* protectLocalPacAction;
    /**
     * 复制本地PAC网址
     */
    QAction* copyLocalPacUrlAction;
    /**
     * 编辑在线PAC网址
     */
    QAction* editOnlinePacUrlAction;
    /**
     * 正向代理
     */
    QAction* positiveAgentAction;
    /**
     * 开机启动
     */
    QAction* bootAction;
    /**
     * 允许来自局域网的连接
     */
    QAction* allowConnectionsFromTheLANAction;
    /**
     * 编辑快捷键
     */
    QAction* editShortcutsAction;
    /**
     * 帮助
     */
    QMenu* helpMenu;
    /**
     * 显示日志
     */
    QAction* showLogAction;
    /**
     * 详细记录日志
     */
    QAction* detailedLogAction;
    /**
     * 更新
     */
    QMenu* updateMenu;
    /**
     * 检查更新
     */
    QAction* checkForUpdateAction;
    /**
     * 启动时检查更新
     */
    QAction* checkForUpdatesAtStartupAction;
    /**
     * 检查测试版更新
     */
    QAction* checkTheBetaUpdateAction;
    /**
     * 关于
     */
    QAction* aboutAction;
    /**
     * 退出
     */
    QAction* exitAction;
    QVector<int > inBytes;
    QList<int > outBytes;
    int inByte = 0;
    int outByte = 0;
    int maxLenth = 12;
private:
    PacConfig pacConfig;
    QList<Config> configs;
    GuiConfig guiConfig;
    UpdateChecker updateChecker;
    GuiConfigDao *guiConfigDao;
    ProxyService *proxyService;
    ServerSerivce *serverSerivce;
    PacService *pacService;
    BootService *bootService;
    UpdateService *updateService;
    HotkeyService *hotkeyService;
    LogService *logService;
    AboutService *aboutService;

    void initConfig();

    void downloadPac();

private slots:

    void updateServerMenu();

    void onServerActionTriggered(QAction *action);
};


#endif //SS_SYSTEMTRAYICON_H
