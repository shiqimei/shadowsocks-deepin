#include "stdafx.h"
#include "utils.h"
#include "MainWindow.h"
#include "widget/ProfileView.h"
#include "GuiConfig.h"
#include "widget/ProfileItem.h"
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
    const QString socket_path(QString("shadowsocks-client_%1").arg(getuid()));
    if (app.setSingleInstance(socket_path)) {
        signal(SIGINT, onSignalRecv);
        signal(SIGTERM, onSignalRecv);
        app.setTheme("light");
        app.loadTranslator();

        const QString descriptionText = QApplication::tr(
                    "If you want to keep a secret, you must also hide it from yourself.");

        const QString acknowledgementLink = "https://github.com/PikachuHy/shadowsocks-client";

        app.setOrganizationName("pikachu");
        app.setApplicationName("shadowsocks-client");
        app.setApplicationDisplayName(QObject::tr("Shadowsocks Client"));
        app.setApplicationVersion("1.1.0");

        app.setProductIcon(QIcon(Utils::getIconQrcPath("ssw128.svg")));
        app.setProductName(QApplication::tr("Shadowsocks Client"));
        app.setApplicationDescription(descriptionText);
        app.setApplicationAcknowledgementPage(acknowledgementLink);

        app.setWindowIcon(QIcon(Utils::getIconQrcPath("ssw128.png")));
        app.setQuitOnLastWindowClosed(false);
        DLogManager::registerConsoleAppender();
        DLogManager::registerFileAppender();
        MainWindow window;

        QObject::connect(&app, &DApplication::newInstanceStarted, &window, &MainWindow::activateWindow);

        Dtk::Widget::moveToCenter(&window);
        return app.exec();
    }
    qDebug() << "app has started";
    return 0;
}
