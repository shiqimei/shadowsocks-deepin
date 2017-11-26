//
// Created by pikachu on 17-7-22.
//

#include <QtCore/QIODevice>
#include <QtCore/QFileInfo>
#include <QtCore/QDir>
#include <QtCore/QJsonObject>
#include <QtCore/QJsonArray>
#include "ConfigUtil.h"

void ConfigUtil::printProfile(Profile &profile) {
/*
    qDebug() << "profile";
    qDebug() << "server" << profile.server << profile.server_port << profile.password;
    qDebug() << "local " << profile.local_address << profile.local_port;
    qDebug() << "method" << profile.method;
    qDebug() << "timeout" << profile.timeout;
    */

}

QList<Config*> ConfigUtil::readConfig() {
    QFile configFile(QString("%1/.ss/gui-config.json").arg(QDir::homePath()));
    if (!configFile.exists()) {
        qDebug() << "配置文件不存在,写入新的配置文件";
        QDir dir;
        dir.mkpath(QFileInfo(configFile).absolutePath());

        configFile.open(QIODevice::WriteOnly | QIODevice::Text);
        configFile.close();
    }
    if (!configFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "can't open config file " << configFile.fileName();
        exit(0);
    }
    if (!configFile.isReadable()) {
        qDebug() << "config file " << configFile.fileName()
                 << " is not readable!";
        exit(0);
    }
    QByteArray configArray = configFile.readAll();
    configFile.close();

    QJsonDocument configJson = QJsonDocument::fromJson(configArray);
    QJsonObject configObject = configJson.object();
    QJsonArray configs = configObject["configs"].toArray();
    int localPort = configObject["localPort"].toInt();
    if (localPort == 0) {
        localPort = 1080;
    }
    QList<Config*> list;
    for (auto o:configs) {
        auto confObj = o.toObject();
#ifdef QT_DEBUG
        qDebug() << confObj;
#endif

        Profile profile;
//        profile.local_address = confObj["local_address"].toString();
//        if (profile.local_address.isSimpleText()){
//            profile.local_address="127.0.0.1";
//        }
        profile.setLocalAddress("127.0.0.1");
        profile.setLocalPort(localPort);
        profile.setMethod(confObj["method"].toString().toStdString());
        profile.setPassword(confObj["password"].toString().toStdString());
        profile.setServerAddress(confObj["server"].toString().toStdString());
        profile.setServerPort(confObj["server_port"].toInt());
        int timeout = confObj["timeout"].toInt();
        profile.setTimeout(timeout>300?timeout:300);
/*        profile.local_address = "127.0.0.1";
        profile.local_port = localPort;
        profile.method = confObj["method"].toString();
        profile.password = confObj["password"].toString();
        profile.server = confObj["server"].toString();
        profile.server_port = confObj["server_port"].toInt();
        profile.timeout = confObj["timeout"].toInt();
        if (profile.timeout < 300) {
            profile.timeout = 300;
        }
        profile.http_proxy = confObj["http_proxy"].toBool();
        profile.auth = confObj["auth"].toBool();
        */
        QString remarks = confObj["remarks"].toString();
        profile.setName(remarks.toStdString());
#ifdef QT_DEBUG
        qDebug() << "remarks" << remarks;
        qDebug() << "server port" << confObj["server_port"].toInt();
//        ui->listWidget->addItem(new ServerItem(profile, remarks, nullptr, 0));
#endif
        Config* config = new Config();
//        config->profile=profile;
//        config.setRemarks(remarks);
        config->fromJsonObject(confObj);
        list.append(config);
    }
    return list;
}

void ConfigUtil::saveConfig(QList<Config> configList) {
    QJsonDocument jsonDocument;
    QJsonObject jsonObject;
    QJsonArray jsonArray;
    int localPort = 0;
    for (auto &it:configList) {
        QJsonObject config;
        Profile &profile = it.profile;
        config.insert("local_address", it.getLocalAddress());
        config.insert("local_port", it.getLocalPort());
        config.insert("method", it.getMethod());
        config.insert("password", it.getPassword());
        config.insert("server", it.getServer());
        config.insert("server_port", it.getServerPort());
        config.insert("timeout", it.getTimeout());
        config.insert("remarks", it.getRemarks());
        jsonArray.append(config);
    }
    jsonObject.insert("configs", jsonArray);
    if (localPort == 0) {
        localPort = 1080;
    }
    jsonObject.insert("local_port", localPort);
    jsonDocument.setObject(jsonObject);
    QFile configFile(QString("%1/.ss/gui-config.json").arg(QDir::homePath()));
    if (!configFile.exists()) {
        qDebug() << "配置文件不存在,写入新的配置文件";
        QDir dir;
        dir.mkpath(QFileInfo(configFile).absolutePath());
    }
    configFile.open(QIODevice::WriteOnly | QIODevice::Text);
    configFile.write(jsonDocument.toJson());
    configFile.close();
}

