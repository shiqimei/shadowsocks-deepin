//
// Created by pikachu on 17-8-19.
//

#ifndef SHADOWSOCKS_CLIENT_PROXY_H
#define SHADOWSOCKS_CLIENT_PROXY_H


#include "JsonObjectSerializable.h"

class Proxy : public JsonObjectSerializable {
public:
    /**
     * 是否使用正向代理
     */
    bool useProxy;
    /**
     * 代理类型
     * SOCK5
     * HTTP
     */
    int proxyType;
    /**
     * 代理地址
     */
    QString proxyServer;
    /**
     * 代理端口
     */
    int proxyPort;
    /**
     * 超时(秒)
     */
    int proxyTimeout;

    QJsonObject toJsonObject() override {
        QJsonObject jsonObject;
        jsonObject.insert("useProxy", useProxy);
        jsonObject.insert("proxyType", proxyPort);
        jsonObject.insert("proxyServer", proxyPort);
        jsonObject.insert("proxyTimeout", proxyTimeout);
        return jsonObject;
    }

    void fromJsonObject(QJsonObject jsonObject) override {
        useProxy = jsonObject.value("useProxy").toBool();
        proxyPort = jsonObject.value("proxyPort").toInt();
        proxyServer = jsonObject.value("proxyServer").toString();
        proxyTimeout = jsonObject.value("proxyTimeout").toInt();
    }
};


#endif //SHADOWSOCKS_CLIENT_PROXY_H
