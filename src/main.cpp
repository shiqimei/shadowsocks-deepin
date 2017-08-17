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
#include <QClipboard>
#include <dbusinterface/DBusStartManager.h>
#include "UriHelper.h"
#include "Util.h"
#include "daos.h"
#include "UpdateChecker.h"

using QSS::Controller;
using QSS::Profile;
DWIDGET_USE_NAMESPACE

int main(int argc, char *argv[]) {

    DApplication::loadDXcbPlugin();
    DApplication app(argc, argv);
    if(app.setSingleInstance("shadowsocks-client")){
        app.setOrganizationName("pikachu");
        app.setApplicationName("shadowsocks-client");
        app.setApplicationVersion("0.4.0");

        app.setProductIcon(QPixmap::fromImage(QImage(":/icons/Resources/shadowsocks-client.png")));
        app.setProductName("Shadowsocks Client");
        app.setApplicationDescription("If you want to keep a secret, you must also hide it from yourself.");
        app.setApplicationAcknowledgementPage("https://github.com/PikachuHy/shadowsocks-client");

        app.setTheme("light");
        QApplication::setWindowIcon(QIcon(":/icons/shadowsocks.ico"));
        app.setQuitOnLastWindowClosed(false);
        Dtk::Util::DLogManager::registerConsoleAppender();
        Dtk::Util::DLogManager::registerFileAppender();
        SystemTrayIcon systemTrayIcon(&app);
        systemTrayIcon.show();
        return QApplication::exec();

    }
    return 0;
}
