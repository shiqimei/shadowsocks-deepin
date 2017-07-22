//
// Created by pikachu on 17-7-22.
//

#ifndef SS_CONFIGUTIL_H
#define SS_CONFIGUTIL_H

#include <profile.h>
#include <QtCore/QJsonDocument>
#include <QtCore/QList>

using QSS::Profile;
class Config{
public:
    Profile profile;
    QString remarks;
};
class ConfigUtil {
public:
    static QList<Config> readConfig();
    static void printProfile(Profile&profile);
    static void saveConfig(QList<Config> configList);
};


#endif //SS_CONFIGUTIL_H
