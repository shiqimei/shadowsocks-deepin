//
// Created by pikachu on 17-8-6.
//

#ifndef SHADOWSOCKS_CLIENT_DAOS_H
#define SHADOWSOCKS_CLIENT_DAOS_H

#include <QObject>
#include <QFile>
#include <QJsonDocument>
#include "models.h"
class GuiConfigDao{
public:
    GuiConfigDao();

    void save(GuiConfig guiConfig);
    GuiConfig get();

private:
    void openFile();
    QFile configFile;
};

#endif //SHADOWSOCKS_CLIENT_DAOS_H
