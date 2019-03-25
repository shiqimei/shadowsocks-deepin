#include "stdafx.h"
#include "utils.h"
#include "MainWindow.h"
#include "widgets/ProfileView.h"
#include "GuiConfig.h"
#include "widgets/ProfileItem.h"
#include "ShareDialog.h"
DWIDGET_USE_NAMESPACE
DCORE_USE_NAMESPACE

static void onSignalRecv(int sig) {
    if (sig == SIGINT || sig == SIGTERM) {
        qApp->quit();
    } else {
        qWarning("Unhandled signal %d", sig);
    }
}

int main(int argc, char *argv[]) {
    DApplication::loadDXcbPlugin();
    DApplication app(argc, argv);
    app.setAttribute(Qt::AA_UseHighDpiPixmaps);
    const QString socket_path(QString("shadowsocks-deepin_%1").arg(getuid()));

    if (app.setSingleInstance(socket_path)) {
        signal(SIGINT, onSignalRecv);
        signal(SIGTERM, onSignalRecv);
        app.setTheme("light");
        app.loadTranslator();

        app.setOrganizationName("pikachu");
        app.setApplicationName("shadowsocks-deepin");
        app.setApplicationDisplayName(QApplication::tr("Shadowsocks"));
        app.setApplicationVersion("1.3.0");

        app.setProductIcon(QIcon(Utils::getIconQrcPath("ssw128.svg")));
        app.setProductName(QApplication::tr("Shadowsocks Deepin"));
        app.setApplicationDescription("If you want to keep a secret, you must also hide it from yourself.");
        app.setApplicationAcknowledgementPage("https://github.com/lolimay/shadowsocks-deepin");

        app.setWindowIcon(QIcon(Utils::getIconQrcPath("ssw128.png")));
        app.setQuitOnLastWindowClosed(false);
        DLogManager::registerConsoleAppender();
        DLogManager::registerFileAppender();
        MainWindow window;

        QObject::connect(&app, &DApplication::newInstanceStarted, &window, &MainWindow::activateWindow);

        Dtk::Widget::moveToCenter(&window);
        return app.exec();
    }
    return 0;
}
