//
// Created by pikachu on 17-8-19.
//

#ifndef SHADOWSOCKS_CLIENT_CONFIG_H
#define SHADOWSOCKS_CLIENT_CONFIG_H

#include "common/common.h"
#include "JsonObjectSerializable.h"
/**
 * 2017/11/26
 * 由于QtShadowsocks改为大量使用std
 * 这个需要用Qt包装一下
 */
class Config : public JsonObjectSerializable {
public:
    Config(){

    }
    Config(const Config& config):profile(config.profile){

    }
    Config(Config&& config):profile(std::move(config.profile)){

    }

    virtual ~Config() {

    }

    Profile profile;
    QString getServer(){
        return QString::fromStdString(profile.serverAddress());
    }
    uint16_t getServerPort(){
        return profile.serverPort();
    }
    QString getPassword(){
        return QString::fromStdString(profile.password());
    }
    QString getMethod(){
        return QString::fromStdString(profile.method());
    }
    uint16_t getLocalPort(){
        return profile.localPort();
    }
    QString getRemarks(){
        const QString &remark = QString::fromStdString(profile.name());
        return remark.isEmpty() ? getServer() :remark;
    }
    int getTimeout(){
        return profile.timeout();
    }
    QString getLocalAddress(){
        return QString::fromStdString(profile.localAddress());
    }
    QString getSsUri() {
        // ss://method:password@hostname:port
        QString plaintext = QString("%1:%2@%3:%4")
                .arg(getMethod()).arg(getPassword())
                .arg(getServer()).arg(getLocalPort());
        QString ciphertext = QString("ss://%1#%2").arg(QString(plaintext.toLocal8Bit().toBase64())).arg(getRemarks());
        return ciphertext;
    }

    QJsonObject toJsonObject() override {
        QJsonObject jsonObject;
        jsonObject.insert("server", getServer());
        jsonObject.insert("server_port", getServerPort());
        jsonObject.insert("password", getPassword());
        jsonObject.insert("method", getMethod());
        jsonObject.insert("timeout", getTimeout());
        jsonObject.insert("remarks", getRemarks());
        return jsonObject;
    }

    void fromJsonObject(QJsonObject jsonObject) override {
        profile.setServerAddress(jsonObject.value("server").toString("").toStdString());
        profile.setServerPort(jsonObject.value("server_port").toInt(0));
        profile.setPassword(jsonObject.value("password").toString("").toStdString());
        profile.setMethod(jsonObject.value("method").toString("").toStdString());
        profile.setTimeout(jsonObject.value("timeout").toInt(0));
        profile.setName(jsonObject.value("remarks").toString("").toStdString());
        /*
        profile.server = jsonObject.value("server").toString("");
        profile.server_port = static_cast<quint16>(jsonObject.value("server_port").toInt(0));
        profile.password = jsonObject.value("password").toString("");
        profile.method = jsonObject.value("method").toString("");
        profile.timeout = jsonObject.value("timeout").toInt(0);
//        qDebug() << profile.server << jsonObject.value("server").toString("");
        remarks = jsonObject.value("remarks").toString("");
        */
    }
};


#endif //SHADOWSOCKS_CLIENT_CONFIG_H
