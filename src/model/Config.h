//
// Created by pikachu on 17-8-19.
//

#ifndef SHADOWSOCKS_CLIENT_CONFIG_H
#define SHADOWSOCKS_CLIENT_CONFIG_H

#include "common/common.h"
#include "JsonObjectSerializable.h"

class Config : public JsonObjectSerializable {
    QString remarks;
public:
    Profile profile;

    QString getSsUri() {
        // ss://method:password@hostname:port
        QString plaintext = QString("%1:%2@%3:%4")
                .arg(profile.method).arg(profile.password)
                .arg(profile.server).arg(profile.server_port);
        QString ciphertext = QString("ss://%1#%2").arg(QString(plaintext.toLocal8Bit().toBase64())).arg(remarks);
        return ciphertext;
    }

    QJsonObject toJsonObject() override {
        QJsonObject jsonObject;
        jsonObject.insert("server", profile.server);
        jsonObject.insert("server_port", profile.server_port);
        jsonObject.insert("password", profile.password);
        jsonObject.insert("method", profile.method);
        jsonObject.insert("timeout", profile.timeout);
        jsonObject.insert("remarks", remarks);
        return jsonObject;
    }

    void fromJsonObject(QJsonObject jsonObject) override {
        profile.server = jsonObject.value("server").toString("");
        profile.server_port = static_cast<quint16>(jsonObject.value("server_port").toInt(0));
        profile.password = jsonObject.value("password").toString("");
        profile.method = jsonObject.value("method").toString("");
        profile.timeout = jsonObject.value("timeout").toInt(0);
//        qDebug() << profile.server << jsonObject.value("server").toString("");
        remarks = jsonObject.value("remarks").toString("");
    }

    const QString &getRemarks() const {
        return remarks.isEmpty() ? profile.server : remarks;
    }

    void setRemarks(const QString &remarks) {
        Config::remarks = remarks;
    }
};


#endif //SHADOWSOCKS_CLIENT_CONFIG_H
