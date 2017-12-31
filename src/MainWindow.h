//
// Created by pikachu on 17-8-19.
//

#ifndef SHADOWSOCKS_CLIENT_MAINWINDOW_H
#define SHADOWSOCKS_CLIENT_MAINWINDOW_H

#include <model/ConnectionTableModel.h>
#include "common/common.h"
#include "widget/Toolbar.h"
#include "widget/ListItem.h"
#include <util/ConfigUtil.h>
#include "service/impl/ServiceImpl.h"
#include "dao/GuiConfigDao.h"
#include <DMainWindow>
#include <DApplication>
#include <DLog>
#include <interface/ProxyManager.h>
#include "interface/SystemProxyModeManager.h"
namespace Ui {
    class MainWindow;
}
DWIDGET_USE_NAMESPACE
//#ifdef DUTIL_USE_NAMESPACE
//DUTIL_USE_NAMESPACE
//#else
//DCORE_USE_NAMESPACE
//#endif
class MainWindow : public Dtk::Widget::DMainWindow {
Q_OBJECT
protected:
    void paintEvent(QPaintEvent *event) override;

private:

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow() override;

    bool eventFilter(QObject *watched, QEvent *event) override;


private:
    Ui::MainWindow *ui;
    Toolbar *toolbar;

    QHBoxLayout *layout;
    QWidget *layoutWidget;

    QList<bool> getColumnHideFlags();

    QString backgroundColor;
    QMenu *rightMenu;
    ConnectionTableModel *model;
    QSystemTrayIcon systemTrayIcon;
    ProxyService *proxyService;
    ServerSerivce *serverSerivce;
    PacService *pacService;
    BootService *bootService;
    UpdateService *updateService;
    HotkeyService *hotkeyService;
    LogService *logService;
    AboutService *aboutService;

    void reloadMenu();

    void changeTheme(QString theme);

    void initTheme();

    void initMenu();

    void popupMenu(QPoint pos, QList<ListItem *> items);

    void initService();

    void initCentralWidget();

    QMenu *modeMenu;
    QMenu *serversMenu;
    QMenu *menu;
    ProxyManager* proxyManager;
    SystemProxyModeManager* systemProxyModeManager;
private slots:
    void on_actionEnable_System_Proxy_triggered(bool checked);
    void on_actionEdit_Servers_triggered(bool checked);
    void on_actionEdit_Local_PAC_File_triggered(bool checked);
    void on_actionEdit_User_Rule_for_GFWList_triggered(bool checked);
    void on_actionCopy_Local_PAC_URL_triggered(bool checked);
    void on_actionEdit_Online_PAC_URL_triggered(bool checked);
    void on_actionShare_Server_Config_triggered(bool checked);
    void on_actionScan_QRCode_from_Screen_triggered(bool checked);
    void on_actionImport_URL_from_Clipboard_triggered(bool checked);
    void on_actionStart_on_Boot_triggered(bool checked);
    void on_actionForward_Proxy_triggered(bool checked);
    void on_actionEdit_Hotkeys_triggered(bool checked);
    void on_actionShow_Logs_triggered(bool checked);
    void on_actionCheck_for_Updates_triggered(bool checked);
    void on_actionCheck_for_Update_at_Startup_triggered(bool checked);
    void on_actionCheck_Pre_release_Version_triggered(bool checked);
    void on_actionAbout_triggered(bool checked);
    void on_actionQuit_triggered(bool checked);
    void on_actionPAC_triggered(bool checked);
    void on_actionGlobal_triggered(bool checked);
    void on_actionLocal_PAC_triggered(bool checked);
    void on_actionOnline_PAC_triggered(bool checked);
    void on_actionUpdate_Local_PAC_from_GFWList_triggered(bool checked);
    void on_actionSwitch_system_proxy_mode_triggered(bool checked);
    void on_actionSwitch_to_next_server_triggered(bool checked);
    void on_actionSwitch_to_prev_server_triggered(bool checked);


    void switchToManual() const;

    void swtichToAuto() const;
};


#endif //SHADOWSOCKS_CLIENT_MAINWINDOW_H
