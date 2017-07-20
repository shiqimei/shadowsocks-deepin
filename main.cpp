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
#include <DUtil>
using QSS::Controller;
using QSS::Profile;
Profile profile;
DWIDGET_USE_NAMESPACE
bool readConfig(const QString &file) {
    QFile c(file);
    if (!c.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "can't open config file " << file;
        return false;
    }
    if (!c.isReadable()) {
        qDebug() << "config file " << file
                 << " is not readable!";
        return false;
    }
    QByteArray confArray = c.readAll();
    c.close();

    QJsonDocument confJson = QJsonDocument::fromJson(confArray);
    QJsonObject confObj = confJson.object();
    profile.local_address = confObj["local_address"].toString();
    profile.local_port = (quint16) confObj["local_port"].toInt();
    profile.method = confObj["method"].toString();
    profile.password = confObj["password"].toString();
    profile.server = confObj["server"].toString();
    profile.server_port = (quint16) confObj["server_port"].toInt();
    profile.timeout = confObj["timeout"].toInt();
    profile.http_proxy = confObj["http_proxy"].toBool();
    profile.auth = confObj["auth"].toBool();

    return true;
}
int main(int argc, char *argv[]) {

    DApplication::loadDXcbPlugin();
    DApplication a(argc, argv);
    a.setOrganizationName("pikachu");
    a.setApplicationName("deepin-ss");
    a.setApplicationVersion("0.0.1");
    a.setTheme("light");
    a.setWindowIcon(QIcon(":/icons/shadowsocks.ico"));
    Dtk::Util::DLogManager::registerConsoleAppender();
    SystemTrayIcon systemTrayIcon(&profile,&a);
    systemTrayIcon.show();
#if 1
    bool success = readConfig("/etc/ss/ss.json");
    if (!success) {
        qDebug() << "讀取文件失敗";
        exit(0);
    } else {
        qDebug() << "讀取文件成功";
    }
    QFile pacFile("/etc/ss/autoproxy.pac");
    if(!pacFile.exists()){
        qDebug()<<"file /etc/ss/autoproxy.pac"<<"不存在";
        qDebug()<<"可以前往"<<"https://raw.githubusercontent.com/PikachuHy/ss/master/autoproxy.pac"<<"下载";
        qDebug()<<"然后放在/ect/ss目录下";
        qDebug()<<"注意：这不是最新的，仅仅作为测试使用";
        exit(0);
    }
    auto controller = new QSS::Controller(true, false, nullptr);
//    QObject::connect(controller, &QSS::Controller::debug, &a, [](QString log) {
//        qDebug() << "[QSS::Controller::debug]" << log;
//    });
    QObject::connect(controller, &QSS::Controller::info, &a, [](QString log) {
        qDebug() << "[QSS::Controller::info]" << log;
    });
    controller->setup(profile);
    QObject::connect(systemTrayIcon.startSystemAgentAction,&QAction::triggered,[&controller](bool checked){
        if(checked){
            controller->start();
        } else{
            controller->stop();
        }
    });
//    success = controller->start();
//    if (!success) {
//        qDebug() << "啓動失敗";
//        exit(0);
//    } else {
//        qDebug() << "啓動成功";
//    }
#endif
    return a.exec();
}
