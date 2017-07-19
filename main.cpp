#include <iostream>
#include <QtCore/QFile>
#include <QtCore/QJsonDocument>
#include <QtCore/QJsonObject>
#include <QtCore/QCoreApplication>
#include <common.h>
#include "controller.h"
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
    QCoreApplication a(argc, argv);
    Dtk::Util::DLogManager::registerConsoleAppender();
    bool success = readConfig("/etc/ss/ss.json");
    if (!success) {
        qDebug() << "讀取文件失敗";
        exit(0);
    } else {
        qDebug() << "讀取文件成功";
    }
    auto controller = new QSS::Controller(true, false, nullptr);
    QObject::connect(controller, &QSS::Controller::debug, &a, [](QString log) {
        qDebug() << "[QSS::Controller::debug]" << log;
    });
    QObject::connect(controller, &QSS::Controller::info, &a, [](QString log) {
        qDebug() << "[QSS::Controller::info]" << log;
    });
    controller->setup(profile);
    success = controller->start();
    if (!success) {
        qDebug() << "啓動失敗";
        exit(0);
    } else {
        qDebug() << "啓動成功";
    }

    return a.exec();
}
