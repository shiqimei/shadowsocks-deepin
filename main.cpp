#include <iostream>
#include <QtCore/QFile>
#include <QtCore/QJsonDocument>
#include <QtCore/QJsonObject>
#include <QtCore/QCoreApplication>
#include <common.h>
#include "controller.h"

using std::cout;
using QSS::Controller;
using QSS::Profile;
Profile profile;

bool readConfig(const QString &file) {
    QFile c(file);
    if (!c.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "can't open config file " << file << endl;
        return false;
    }
    if (!c.isReadable()) {
        qDebug() << "config file " << file
                 << " is not readable!" << endl;
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

bool headerTest() {
    int length;
    bool unused_auth;
    QHostAddress test_addr("1.2.3.4");
    QHostAddress test_addr_v6("2001:0db8:85a3:0000:0000:8a2e:1010:2020");
    quint16 test_port = 56;
    QSS::Address test_res, test_v6(test_addr_v6, test_port);
    QByteArray packed = QSS::Common::packAddress(test_v6);
    QSS::Common::parseHeader(packed, test_res, length, unused_auth);
    bool success = (test_v6 == test_res);
    if (!success) {
        QSS::Common::qOut << test_v6.toString() << " --> "
                          << test_res.toString() << endl;
    }
    packed = QSS::Common::packAddress(test_addr, test_port);
    QSS::Common::parseHeader(packed, test_res, length, unused_auth);
    bool success2 = ((test_res.getFirstIP() == test_addr)
                     && (test_res.getPort() == test_port));
    if (!success2) {
        QSS::Common::qOut << test_addr.toString().toLocal8Bit()
                          << ":" << test_port << " --> "
                          << test_res.toString() << endl;
    }
    return success & success2;
}

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
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
    if (!headerTest()) {
        QSS::Common::qOut << "Header test failed";
        return false;
    } else {
        qDebug() << "頭部測試成功";
    }
    success = controller->start();
    if (!success) {
        qDebug() << "啓動失敗";
        exit(0);
    } else {
        qDebug() << "啓動成功";
    }

    return a.exec();
}
