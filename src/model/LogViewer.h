//
// Created by pikachu on 17-8-19.
//

#ifndef SHADOWSOCKS_CLIENT_LOGVIEWER_H
#define SHADOWSOCKS_CLIENT_LOGVIEWER_H


#include "JsonObjectSerializable.h"

class LogViewer : public JsonObjectSerializable {
public:
    QJsonObject toJsonObject() override {
        QJsonObject jsonObject;
        jsonObject.insert("topMost", topMost);
        jsonObject.insert("wrapText", wrapText);
        jsonObject.insert("toolbarShown", toolbarShown);
        jsonObject.insert("Font", font);
        jsonObject.insert("TextColor", textColor);
        jsonObject.insert("BackgroundColor", backgroundColor);
        return jsonObject;
    }

    void fromJsonObject(QJsonObject jsonObject) override {
        topMost = jsonObject.value("topMost").toBool();
        wrapText = jsonObject.value("wrapText").toBool();
        toolbarShown = jsonObject.value("toolbarShown").toBool();
        font = jsonObject.value("Font").toString();
        textColor = jsonObject.value("TextColor").toString();
        backgroundColor = jsonObject.value("BackgroundColor").toString();
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


#endif //SHADOWSOCKS_CLIENT_LOGVIEWER_H
