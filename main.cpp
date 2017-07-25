#include <iostream>
#include <QtCore/QFile>
#include <QtCore/QJsonDocument>
#include <QtCore/QJsonObject>
#include <QtCore/QCoreApplication>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>
#include <common.h>
#include "controller.h"
#include "SystemTrayIcon.h"
#include <DApplication>
#include <dlabel.h>
#include <DPlatformWindowHandle>
#include <DLog>
#include <dutility.h>
#include <QScreen>
#include <QDesktopServices>
#include <QDesktopWidget>
#include "UriHelper.h"
using QSS::Controller;
using QSS::Profile;
DWIDGET_USE_NAMESPACE

int main(int argc, char *argv[]) {

    DApplication::loadDXcbPlugin();
    DApplication a(argc, argv);
    a.setOrganizationName("pikachu");
    a.setApplicationName("deepin-ss");
    a.setApplicationVersion("0.0.1");
    qApp->setQuitOnLastWindowClosed(false);
    a.setTheme("light");
    a.setWindowIcon(QIcon(":/icons/shadowsocks.ico"));
    Dtk::Util::DLogManager::registerConsoleAppender();
    SystemTrayIcon systemTrayIcon(&a);
    systemTrayIcon.show();


    return a.exec();
}
