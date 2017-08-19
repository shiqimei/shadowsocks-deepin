//
// Created by pikachu on 17-7-22.
//

#ifndef SS_CONFIGUTIL_H
#define SS_CONFIGUTIL_H

#include <profile.h>
#include <QtCore/QJsonDocument>
#include <QtCore/QList>
#include <QDir>
#include "model/Config.h"
using QSS::Profile;
class PacConfig{
public:
    bool is_local ;
    QString localFilePath;
    QString onlineUrl;

    QString getProxy(){
        if (is_local){
            return QObject::tr("file://%1").arg(localFilePath);
        } else{
            return onlineUrl;
        }
    }
};


class ConfigUtil {
public:
    static QList<Config> readConfig();
    static void printProfile(Profile&profile);
    static void saveConfig(QList<Config> configList);
};


#endif //SS_CONFIGUTIL_H
