#include <util/Util.h>
#include "MainWindow.h"

int main(int argc, char *argv[]) {
    DApplication::loadDXcbPlugin();
    DApplication app(argc, argv);
    if (app.setSingleInstance(Util::APPLICATION_NAME)) {
        qRegisterMetaTypeStreamOperators<SQProfile>("SQProfile");
        app.setOrganizationName(Util::ORGANIZATION_NAME);
        app.setApplicationName(Util::APPLICATION_NAME);
        app.setApplicationVersion(Util::VERSION);

        app.setProductIcon(QPixmap::fromImage(QImage(":/icons/Resources/shadowsocks-client.png")));
        app.setProductName("Shadowsocks Client");
        app.setApplicationDescription("If you want to keep a secret, you must also hide it from yourself.");
        app.setApplicationAcknowledgementPage("https://github.com/PikachuHy/shadowsocks-client");

        app.setTheme("light");
        app.loadTranslator();
        app.setQuitOnLastWindowClosed(false);
        Dtk::Util::DLogManager::registerConsoleAppender();
        Dtk::Util::DLogManager::registerFileAppender();

        MainWindow mainWindow;
        mainWindow.show();
        return QApplication::exec();
    }
    return 0;
}
