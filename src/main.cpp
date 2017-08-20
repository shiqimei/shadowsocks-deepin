#include <util/Util.h>
#include "SystemTrayIcon.h"
#include "MainWindow.h"

int main(int argc, char *argv[]) {

    DApplication::loadDXcbPlugin();
    DApplication app(argc, argv);
    if(app.setSingleInstance("shadowsocks-client")){
        qRegisterMetaTypeStreamOperators<SQProfile>("SQProfile");
        app.setOrganizationName("pikachu");
        app.setApplicationName("shadowsocks-client");
        app.setApplicationVersion("0.4.0");

        app.setProductIcon(QPixmap::fromImage(QImage(":/icons/Resources/shadowsocks-client.png")));
        app.setProductName("Shadowsocks Client");
        app.setApplicationDescription("If you want to keep a secret, you must also hide it from yourself.");
        app.setApplicationAcknowledgementPage("https://github.com/PikachuHy/shadowsocks-client");

        app.setTheme("light");
//        QApplication::setWindowIcon(QIcon(":/icons/shadowsocks.ico"));
        app.setQuitOnLastWindowClosed(false);
        Dtk::Util::DLogManager::registerConsoleAppender();
        Dtk::Util::DLogManager::registerFileAppender();

//        SystemTrayIcon systemTrayIcon(&app);
//        systemTrayIcon.show();
        MainWindow mainWindow;

//        mainWindow.show();
        return QApplication::exec();

    }
    return 0;
}
