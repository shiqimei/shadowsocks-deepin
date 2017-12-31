//
// Created by pikachu on 17-12-30.
//

#ifndef SHADOWSOCKS_CLIENT_PROXYCONFIG_H
#define SHADOWSOCKS_CLIENT_PROXYCONFIG_H

#include "stdafx.h"
class ProxyConfig:public QObject{
Q_OBJECT
public:
    ProxyConfig(QObject *parent = nullptr);
};
#endif //SHADOWSOCKS_CLIENT_PROXYCONFIG_H
