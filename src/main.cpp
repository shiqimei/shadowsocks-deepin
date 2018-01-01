#include <util/Util.h>
#include "MainWindow.h"
#include <DApplication>
#include <DLog>
#include <csignal>
#include <dao/DBHelper.h>

DWIDGET_USE_NAMESPACE
#ifdef DUTIL_USE_NAMESPACE
DUTIL_USE_NAMESPACE
#else
DCORE_USE_NAMESPACE
#endif
static void onSignalRecv(int sig)
{
    if (sig == SIGINT || sig == SIGTERM) {
        qApp->quit();
    } else {
        qWarning("Unhandled signal %d", sig);
    }
}

int main(int argc, char *argv[]) {
    DApplication::loadDXcbPlugin();
    DApplication app(argc, argv);
    if (app.setSingleInstance("shadowsocks-client")) {
        signal(SIGINT, onSignalRecv);
        signal(SIGTERM, onSignalRecv);
        app.setOrganizationName("pikachu");
        app.setApplicationName("shadowsocks-client");
        app.setApplicationVersion("1.1.1");

        app.setProductIcon(QIcon(":/icons/Resources/shadowsocks-client.png"));
        app.setProductName("Shadowsocks Client");
        app.setApplicationDescription("If you want to keep a secret, you must also hide it from yourself.");
        app.setApplicationAcknowledgementPage("https://github.com/PikachuHy/shadowsocks-client");

        app.setTheme("light");
        app.loadTranslator();
        app.setQuitOnLastWindowClosed(false);
        DLogManager::registerConsoleAppender();
        DLogManager::registerFileAppender();

        MainWindow mainWindow;
        mainWindow.show();
        return QApplication::exec();
    }
    QMessageBox::critical(nullptr,QObject::tr("critical"),QObject::tr("application has started!!!"));
    return 0;
}
