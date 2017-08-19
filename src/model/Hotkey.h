//
// Created by pikachu on 17-8-19.
//

#ifndef SHADOWSOCKS_CLIENT_HOTKEY_H
#define SHADOWSOCKS_CLIENT_HOTKEY_H

#include "JsonObjectSerializable.h"

class Hotkey : public JsonObjectSerializable {
public:
    QJsonObject toJsonObject() override {
        QJsonObject jsonObject;
        jsonObject.insert("SwitchSystemProxy", switchSystemProxy);
        jsonObject.insert("SwitchSystemProxyMode", switchSystemProxyMode);
        jsonObject.insert("SwitchAllowLan", switchAllowLan);
        jsonObject.insert("ShowLogs", showLogs);
        jsonObject.insert("ServerMoveUp", serverMoveUp);
        jsonObject.insert("ServerMoveDown", serverMoveDown);
        return jsonObject;
    }

    void fromJsonObject(QJsonObject jsonObject) override {
        switchSystemProxy = jsonObject.value("SwitchSystemProxy").toString();
        switchSystemProxyMode = jsonObject.value("SwitchSystemProxyMode").toString();
        switchAllowLan = jsonObject.value("SwitchAllowLan").toString();
        showLogs = jsonObject.value("ShowLogs").toString();
        serverMoveUp = jsonObject.value("ServerMoveUp").toString();
        serverMoveDown = jsonObject.value("ServerMoveDown").toString();
    }

    QString switchSystemProxy;
    QString switchSystemProxyMode;
    QString switchAllowLan;
    QString showLogs;
    QString serverMoveUp;
    QString serverMoveDown;
};


#endif //SHADOWSOCKS_CLIENT_HOTKEY_H
