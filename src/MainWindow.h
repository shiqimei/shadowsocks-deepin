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

namespace Ui {
    class MainWindow;
}

class MainWindow : public DMainWindow {
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
};


#endif //SHADOWSOCKS_CLIENT_MAINWINDOW_H
