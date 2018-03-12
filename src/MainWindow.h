#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "stdafx.h"
#include "ProxyManager.h"
#include "interface/SystemProxyModeManager.h"
#include "dbusinterface/DBusStartManager.h"
#include "Settings.h"
#include "Toolbar.h"
#include "ProxyView.h"

DWIDGET_USE_NAMESPACE
using StartManagerInter = com::deepin::StartManager;
namespace Ui {
    class MainWindow;
}

class MainWindow : public DMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

    QList<bool> getColumnHideFlags();

    bool eventFilter(QObject *, QEvent *) override ;

    bool getSortingOrder();

    int getSortingIndex();


private slots:

    void on_actionEdit_Servers_triggered();

    void on_actionEdit_Online_PAC_URL_triggered();

    void on_actionForward_Proxy_triggered();

    void on_actionShow_Logs_triggered();

    void on_actionImport_from_gui_config_json_triggered();

    void on_actionEnable_System_Proxy_triggered(bool flag);

    void on_actionPAC_triggered(bool checked);

    void on_actionGlobal_triggered(bool checked);

    void updateTrayIcon();

    void on_actionStart_on_Boot_triggered(bool checked);

    void on_actionQuit_triggered();

    void updateList();

    void popupMenu(QPoint pos, QList<DSimpleListItem *> items);
    void popupMenuBlank();

    void on_actionDisconnect_triggered();

    void on_actionScan_QRCode_from_Screen_triggered();

private:
    Ui::MainWindow *ui;
    QSystemTrayIcon *systemTrayIcon;
    Toolbar *toolbar;
    // I can't use both DSimpleView and QSystemTrayIcon.
    // So I create a container
    DMainWindow *w;
    ProxyView *config_view;
    QMenu *rightMenu;
    QMenu *rightMenuBlank;
    QMenu *menuAdd;
    ProxyManager *proxyManager;
    SystemProxyModeManager *systemProxyModeManager;
    StartManagerInter startManagerInter;
    Settings *settings;
    QList<quint64> ins;
    QList<quint64> outs;
    quint64 in;
    quint64 out;
    quint64 term_usage_in;
    quint64 term_usage_out;

    void updateMenu();

    void switchToPacMode();

    void switchToGlobal();

    // QWidget interface
protected:
    void contextMenuEvent(QContextMenuEvent *event) override;
};

#endif // MAINWINDOW_H
