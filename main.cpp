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
#if 1

    QFile pacFile("/etc/ss/autoproxy.pac");
    if(!pacFile.exists()){
        qDebug()<<"file /etc/ss/autoproxy.pac"<<"不存在";
        qDebug()<<"可以前往"<<"https://raw.githubusercontent.com/PikachuHy/ss/master/autoproxy.pac"<<"下载";
        qDebug()<<"然后放在/ect/ss目录下";
        qDebug()<<"注意：这不是最新的，仅仅作为测试使用";
        exit(0);
    }
#endif
    return a.exec();
}
