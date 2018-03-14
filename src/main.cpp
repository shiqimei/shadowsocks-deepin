#include "stdafx.h"
#include "utils.h"
#include "MainWindow.h"
#include "ProxyView.h"
#include "GuiConfig.h"
#include "ConfigItem.h"
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
        app.setApplicationVersion("2.0.0");

        app.setProductIcon(QIcon(Utils::getIconQrcPath("ssw128.svg")));
        app.setProductName(QApplication::tr("Shadowsocks Client"));
        app.setApplicationDescription(descriptionText);
        app.setApplicationAcknowledgementPage(acknowledgementLink);

        app.setWindowIcon(QIcon(Utils::getIconQrcPath("ssw128.png")));
        app.setQuitOnLastWindowClosed(false);
        DLogManager::registerConsoleAppender();
        DLogManager::registerFileAppender();
        MainWindow window;
        qDebug()<<GuiConfig::instance()->getConfigs().size();

        QList<bool> toggleHideFlags;
        toggleHideFlags<<true<<true<<true<<true<<true<<true<<true<<true;
        ProxyView view(toggleHideFlags);
        QList<DSimpleListItem *> items;
        GuiConfig::instance()->readFromDisk();
        auto configs = GuiConfig::instance()->getConfigs();
        for (int i = 0; i < configs.size(); i++) {
            auto it = configs.at(i).toObject();
            auto item = new ConfigItem(it);
    //        auto item = new ProcessItem(it,i);
            items << static_cast<DSimpleListItem *>(item);
        }
        // note: this function will delete items in view before  to avoid *MEMORY LEAK*
        view.refreshItems(items);
//        window.setCentralWidget(&view);
        view.show();

        // QObject::connect(&app, &DApplication::newInstanceStarted, &window, &MainWindow::activateWindow);

//        Dtk::Widget::moveToCenter(&window);
//        window.show();
//        window.adjustStatusBarWidth();
        return app.exec();
    }
    qDebug() << "app has started";
    return 0;
}
