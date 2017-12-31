//
// Created by pikachu on 17-12-31.
//

#ifndef SHADOWSOCKS_CLIENT_CONFIGDAO_H
#define SHADOWSOCKS_CLIENT_CONFIGDAO_H

#include "stdafx.h"
#include <interface/ProxyConfig.h>
#include <DSingleton>

using Dtk::Core::DSingleton;
class ConfigDAO: public QObject, public DSingleton<ConfigDAO> {
Q_OBJECT
public:
    ProxyConfig* find(QString id);
    QList<ProxyConfig*> findAll();
    void remove(QString id);
    void insert(ProxyConfig* config);
};


#endif //SHADOWSOCKS_CLIENT_CONFIGDAO_H
