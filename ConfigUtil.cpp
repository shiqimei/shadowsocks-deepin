//
// Created by pikachu on 17-7-22.
//

#include <QtCore/QIODevice>
#include <QtCore/QFileInfo>
#include <QtCore/QDir>
#include <QtCore/QJsonObject>
#include <QtCore/QJsonArray>
#include "ConfigUtil.h"
#include <QDebug>
void ConfigUtil::printProfile(Profile &profile) {
    qDebug()<<"profile";
    qDebug()<<"server"<<profile.server<<profile.server_port<<profile.password;
    qDebug()<<"local "<<profile.local_address<<profile.local_port;
    qDebug()<<"method"<<profile.method;
    qDebug()<<"timeout"<<profile.timeout;

}

QList<Config> ConfigUtil::readConfig() {
    QFile configFile(QObject::tr("%1/.ss/gui-config.json").arg(QDir::homePath()));
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
    if(localPort==0){
        localPort=1080;
    }
    QList<Config> list;
    for (auto o:configs) {
        auto confObj = o.toObject();
#ifdef QT_DEBUG
        qDebug()<<confObj;
#endif

        Profile profile;
//        profile.local_address = confObj["local_address"].toString();
//        if (profile.local_address.isSimpleText()){
//            profile.local_address="127.0.0.1";
//        }
        profile.local_address="127.0.0.1";
        profile.local_port = localPort;
        profile.method = confObj["method"].toString();
        profile.password = confObj["password"].toString();
        profile.server = confObj["server"].toString();
        profile.server_port = confObj["server_port"].toInt();
        profile.timeout = confObj["timeout"].toInt();
        if(profile.timeout<300){
            profile.timeout=300;
        }
        profile.http_proxy = confObj["http_proxy"].toBool();
        profile.auth = confObj["auth"].toBool();
        QString remarks=confObj["remarks"].toString();
#ifdef QT_DEBUG
        qDebug()<<"remarks"<<remarks;
        qDebug()<<"server port"<<confObj["server_port"].toInt();
//        ui->listWidget->addItem(new ServerItem(profile, remarks, nullptr, 0));
#endif
        Config config;
        config.profile=profile;
        config.remarks=remarks;
        list.append(config);
    }
    return list;
}

void ConfigUtil::saveConfig(QList<Config> configList) {
    QJsonDocument jsonDocument;
    QJsonObject jsonObject;
    QJsonArray jsonArray;
    int localPort=0;
    for(auto&it:configList){
        QJsonObject config;
        Profile& profile=it.profile;
        localPort=profile.local_port;
        config.insert("local_address",profile.local_address);
        config.insert("local_port",profile.local_port);
        config.insert("method",profile.method);
        config.insert("password",profile.password);
        config.insert("server",profile.server);
        config.insert("server_port",profile.server_port);
        config.insert("timeout",profile.timeout);
        config.insert("remarks",it.remarks);
        jsonArray.append(config);
    }
    jsonObject.insert("configs",jsonArray);
    if (localPort==0){
        localPort=1080;
    }
    jsonObject.insert("local_port",localPort);
    jsonDocument.setObject(jsonObject);
    QFile configFile(QObject::tr("%1/.ss/gui-config.json").arg(QDir::homePath()));
    if (!configFile.exists()) {
        qDebug() << "配置文件不存在,写入新的配置文件";
        QDir dir;
        dir.mkpath(QFileInfo(configFile).absolutePath());
    }
    configFile.open(QIODevice::WriteOnly | QIODevice::Text);
    configFile.write(jsonDocument.toJson());
    configFile.close();
}
