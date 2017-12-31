//
// Created by pikachu on 17-8-19.
//

#ifndef SHADOWSOCKS_CLIENT_GUICONFIG_H
#define SHADOWSOCKS_CLIENT_GUICONFIG_H

#include "common/common.h"
#include "JsonObjectSerializable.h"
#include "Config.h"
#include "Hotkey.h"
#include "LogViewer.h"
#include <QJsonObject>
#include <QJsonArray>
class GuiConfig : public JsonObjectSerializable {
public:
    virtual ~GuiConfig();

    QJsonObject toJsonObject() override {
        QJsonObject jsonObject;
        {
            QJsonArray jsonArray;
            for (auto &it:configs) {
//                qDebug()<<it.toJsonObject();
                jsonArray.append(it->toJsonObject());

            }
            jsonObject.insert("configs", jsonArray);
        }
        jsonObject.insert("strategy", strategy);
        jsonObject.insert("index", index);
        jsonObject.insert("global", global);
        jsonObject.insert("enabled", enabled);
        jsonObject.insert("enabled", enabled);
        jsonObject.insert("shareOverLan", shareOverLan);
        jsonObject.insert("localPort", localPort);
        jsonObject.insert("pacUrl", pacUrl);
        jsonObject.insert("useOnlinePac", useOnlinePac);
        jsonObject.insert("secureLocalPac", secureLocalPac);
        jsonObject.insert("availabilityStatistics", availabilityStatistics);
        jsonObject.insert("autoCheckUpdate", autoCheckUpdate);
        jsonObject.insert("checkPreRelease", checkPreRelease);
        jsonObject.insert("isVerboseLogging", isVerboseLogging);
        jsonObject.insert("logViewer", logViewer.toJsonObject());
        jsonObject.insert("hotkey", hotkey.toJsonObject());
        return jsonObject;
    }

    void fromJsonObject(QJsonObject jsonObject) override {
        {
            QJsonArray jsonArray = jsonObject.value("configs").toArray();
            clean();
            for (auto it:jsonArray) {
                // 老是出问题我用指针算了
                Config* config = new Config();
                config->fromJsonObject(it.toObject());
                configs.append(config);
            }
        }

        strategy = jsonObject.value("strategy").toString();
        index = jsonObject.value("index").toInt();
        global = jsonObject.value("global").toBool(true);
        enabled = jsonObject.value("enabled").toBool();
        shareOverLan = jsonObject.value("shareOverLan").toBool();
        localPort = jsonObject.value("localPort").toInt();
        pacUrl = jsonObject.value("pacUrl").toString();
        useOnlinePac = jsonObject.value("useOnlinePac").toBool();
        secureLocalPac = jsonObject.value("secureLocalPac").toBool();
        availabilityStatistics = jsonObject.value("availabilityStatistics").toBool();
        autoCheckUpdate = jsonObject.value("autoCheckUpdate").toBool();
        checkPreRelease = jsonObject.value("checkPreRelease").toBool();
        isVerboseLogging = jsonObject.value("isVerboseLogging").toBool();

        logViewer.fromJsonObject(jsonObject.value("logViewer").toObject());
        hotkey.fromJsonObject(jsonObject.value("hotkey").toObject());
    }

    /**
     * ss账号
     */
    QList<Config*> configs;
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
     * 显示日志配置
     */
    LogViewer logViewer;
    /**
     * 热键配置
     */
    Hotkey hotkey;

    Profile getCurrentProfile();

private:
    void clean(){
        while (!configs.isEmpty()){
            auto config = configs.first();
            configs.removeOne(config);
            delete config;
        }
    }
};


#endif //SHADOWSOCKS_CLIENT_GUICONFIG_H
