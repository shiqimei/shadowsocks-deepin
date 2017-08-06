//
// Created by pikachu on 17-8-6.
//

#ifndef SHADOWSOCKS_CLIENT_MODELS_H
#define SHADOWSOCKS_CLIENT_MODELS_H

#include <QtCore/QString>
#include <QtCore/QObject>
#include <profile.h>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include "Util.h"

class JsonObjectSerializable{
public:
    virtual QJsonObject toJsonObject() = 0;
    virtual void fromJsonObject(QJsonObject jsonObject)=0;
};
using QSS::Profile;
class Config:public JsonObjectSerializable{
public:
    Profile profile;
    QString remarks;
    QString getSsUri(){
        // ss://method:password@hostname:port
        QString plaintext=QObject::tr("%1:%2@%3:%4")
                .arg(profile.method).arg(profile.password)
                .arg(profile.server).arg(profile.server_port);
        QString ciphertext=QObject::tr("ss://%1#%2").arg(QString(plaintext.toLocal8Bit().toBase64())).arg(remarks);
        return ciphertext;
    }

    QJsonObject toJsonObject() override {
        QJsonObject jsonObject;
        jsonObject.insert("server",profile.server);
        jsonObject.insert("server_port",profile.server_port);
        jsonObject.insert("password",profile.password);
        jsonObject.insert("method",profile.method);
        jsonObject.insert("timeout",profile.timeout);
        jsonObject.insert("remarks",remarks);
        return jsonObject;
    }
    void fromJsonObject(QJsonObject jsonObject) override {
        profile.server = jsonObject.value("server").toString("");
        profile.server_port= static_cast<quint16>(jsonObject.value("server_port").toInt(0));
        profile.password=jsonObject.value("password").toString("");
        profile.method=jsonObject.value("method").toString("");
        profile.timeout=jsonObject.value("timeout").toInt(0);
        remarks=jsonObject.value("remarks").toString("");
    }
};
class Proxy:public JsonObjectSerializable{
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
        jsonObject.insert("useProxy",useProxy);
        jsonObject.insert("proxyType",proxyPort);
        jsonObject.insert("proxyServer",proxyPort);
        jsonObject.insert("proxyTimeout",proxyTimeout);
        return jsonObject;
    }

    void fromJsonObject(QJsonObject jsonObject) override {
        useProxy=jsonObject.value("useProxy").toBool();
        proxyPort=jsonObject.value("proxyPort").toInt();
        proxyServer=jsonObject.value("proxyServer").toString();
        proxyTimeout=jsonObject.value("proxyTimeout").toInt();
    }
};
class LogViewer:public JsonObjectSerializable{
public:
    QJsonObject toJsonObject() override {
        QJsonObject jsonObject;
        jsonObject.insert("topMost",topMost);
        jsonObject.insert("wrapText",wrapText);
        jsonObject.insert("toolbarShown",toolbarShown);
        jsonObject.insert("Font",font);
        jsonObject.insert("TextColor",textColor);
        jsonObject.insert("BackgroundColor",backgroundColor);
        return jsonObject;
    }

    void fromJsonObject(QJsonObject jsonObject) override {
        topMost=jsonObject.value("topMost").toBool();
        wrapText=jsonObject.value("wrapText").toBool();
        toolbarShown=jsonObject.value("toolbarShown").toBool();
        font=jsonObject.value("Font").toString();
        textColor=jsonObject.value("TextColor").toString();
        backgroundColor=jsonObject.value("BackgroundColor").toString();
    }

    bool topMost;
    bool wrapText;
    bool toolbarShown;
    /**
     * json为Font
     */
    QString font;
    /**
     * json为BackgroundColor
     */
    QString backgroundColor;
    /**
     * json为TextColor
     */
    QString textColor;
};
/**
 * json 首字母全是大写
 */
class Hotkey:public JsonObjectSerializable{
public:
    QJsonObject toJsonObject() override {
        QJsonObject jsonObject;
        jsonObject.insert("SwitchSystemProxy",switchSystemProxy);
        jsonObject.insert("SwitchSystemProxyMode",switchSystemProxyMode);
        jsonObject.insert("SwitchAllowLan",switchAllowLan);
        jsonObject.insert("ShowLogs",showLogs);
        jsonObject.insert("ServerMoveUp",serverMoveUp);
        jsonObject.insert("ServerMoveDown",serverMoveDown);
        return jsonObject;
    }

    void fromJsonObject(QJsonObject jsonObject) override {
        switchSystemProxy     = jsonObject.value("SwitchSystemProxy").toString();
        switchSystemProxyMode = jsonObject.value("SwitchSystemProxyMode").toString();
        switchAllowLan        = jsonObject.value("SwitchAllowLan").toString();
        showLogs              = jsonObject.value("ShowLogs").toString();
        serverMoveUp          = jsonObject.value("ServerMoveUp").toString();
        serverMoveDown        = jsonObject.value("ServerMoveDown").toString();
    }

    QString switchSystemProxy;
    QString switchSystemProxyMode;
    QString switchAllowLan;
    QString showLogs;
    QString serverMoveUp;
    QString serverMoveDown;
};
class GuiConfig : public JsonObjectSerializable{
public:
    QJsonObject toJsonObject() override {
        QJsonObject jsonObject;
        {
            QJsonArray jsonArray;
            for(auto&it:configs){
//                qDebug()<<it.toJsonObject();
                jsonArray.append(it.toJsonObject());

            }
            jsonObject.insert("configs",jsonArray);
        }
        jsonObject.insert("strategy",strategy);
        jsonObject.insert("index",index);
        jsonObject.insert("global",global);
        jsonObject.insert("enabled",enabled);
        jsonObject.insert("enabled",enabled);
        jsonObject.insert("shareOverLan",shareOverLan);
        jsonObject.insert("localPort",localPort);
        jsonObject.insert("pacUrl",pacUrl);
        jsonObject.insert("useOnlinePac",useOnlinePac);
        jsonObject.insert("secureLocalPac",secureLocalPac);
        jsonObject.insert("availabilityStatistics",availabilityStatistics);
        jsonObject.insert("autoCheckUpdate",autoCheckUpdate);
        jsonObject.insert("checkPreRelease",checkPreRelease);
        jsonObject.insert("isVerboseLogging",isVerboseLogging);
        jsonObject.insert("proxy",proxy.toJsonObject());
        jsonObject.insert("logViewer",logViewer.toJsonObject());
        jsonObject.insert("hotkey",hotkey.toJsonObject());
        return jsonObject;
    }

    void fromJsonObject(QJsonObject jsonObject) override {
        {
            QJsonArray jsonArray = jsonObject.value("configs").toArray();
            for(auto it:jsonArray){
                Config config;
                config.fromJsonObject(it.toObject());
                configs.append(config);
            }
        }

        strategy                =jsonObject.value("strategy").toString();
        index                   =jsonObject.value("index").toInt();
        global                  =jsonObject.value("global").toBool();
        enabled                 =jsonObject.value("enabled").toBool();
        shareOverLan            =jsonObject.value("shareOverLan").toBool();
        localPort               =jsonObject.value("localPort").toInt();
        pacUrl                  =jsonObject.value("pacUrl").toString();
        useOnlinePac            =jsonObject.value("useOnlinePac").toBool();
        secureLocalPac          =jsonObject.value("secureLocalPac").toBool();
        availabilityStatistics  =jsonObject.value("availabilityStatistics").toBool();
        autoCheckUpdate         =jsonObject.value("autoCheckUpdate").toBool();
        checkPreRelease         =jsonObject.value("checkPreRelease").toBool();
        isVerboseLogging        =jsonObject.value("isVerboseLogging").toBool();

        proxy.fromJsonObject(jsonObject.value("proxy").toObject());
        logViewer.fromJsonObject(jsonObject.value("logViewer").toObject());
        hotkey.fromJsonObject(jsonObject.value("hotkey").toObject());
    }

    /**
     * ss账号
     */
    QList<Config> configs;
    /**
     * 服务器策略
     * 负载均衡
     * 高可用
     * 根据统计
     */
    QString strategy;
    /**
     * 当前使用的是哪个账号，如果使用其他的策略，赋值-1
     */
    int index;
    /**
     * 是否是全集模式
     */
    bool global;
    /**
     * 是否开启代理
     */
    bool enabled;
    /**
     * 是否允许来自局域网的连接
     */
    bool shareOverLan;
    /**
     * 本地端口
     */
    int localPort;
    /**
     * 在线pac url地址
     */
    QString pacUrl;
    /**
     * 是否使用在线pac
     */
    bool useOnlinePac;
    /**
     * 是否保护本地PAC
     */
    bool secureLocalPac;

    bool availabilityStatistics;
    /**
     * 是否自动检查更新
     */
    bool autoCheckUpdate;
    /**
     * 是否检查测试版更新
     */
    bool checkPreRelease;
    /**
     * 是否详细记录日志
     */
    bool isVerboseLogging;
    /**
     * 正向代理配置
     */
    Proxy proxy;
    /**
     * 显示日志配置
     */
    LogViewer logViewer;
    /**
     * 热键配置
     */
    Hotkey hotkey;
};


#endif //SHADOWSOCKS_CLIENT_MODELS_H
