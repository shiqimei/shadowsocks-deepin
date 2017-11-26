//
// Created by pikachu on 17-8-18.
//

#include "GuiConfigDao.h"

GuiConfigDao::GuiConfigDao() {
    configFile.setFileName(QObject::tr("%1/.ss/gui-config.json").arg(QDir::homePath()));
    if (!configFile.exists()) {
        qDebug() << "配置文件不存在,写入新的配置文件";
        QDir dir;
        dir.mkpath(QFileInfo(configFile).absolutePath());

        configFile.open(QIODevice::WriteOnly | QIODevice::Text);
        configFile.close();
    }
}

void GuiConfigDao::save(GuiConfig guiConfig) {
    if (!configFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "can't open config file " << configFile.fileName();
        exit(0);
    }
    QJsonDocument jsonDocument(guiConfig.toJsonObject());
    configFile.write(jsonDocument.toJson());
    configFile.close();
}
// 实际上这里是读不出什么东西的
GuiConfig GuiConfigDao::get() {
    GuiConfig guiConfig;
    if (!configFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "can't open config file " << configFile.fileName();
//        exit(0);
        return guiConfig;
    }
    if (!configFile.isReadable()) {
        qDebug() << "config file " << configFile.fileName()
                 << " is not readable!";
//        exit(0);
        return guiConfig;
    }
    QJsonDocument jsonDocument;
    auto json = configFile.readAll();
    qDebug().noquote() << "json" << json;
    jsonDocument = jsonDocument.fromJson(json);
//    qDebug()<<"json doc"<<jsonDocument.toJson();
    guiConfig.fromJsonObject(jsonDocument.object());
    configFile.close();
    qDebug() << "服务器";
    for (auto &it:guiConfig.configs) {
        qDebug() << it->getRemarks();
    }
    return guiConfig;
}

GuiConfigDao *GuiConfigDao::instance() {
    static GuiConfigDao guiConfigDao;
    return &guiConfigDao;
}



