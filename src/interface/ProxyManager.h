//
// Created by pikachu on 17-12-30.
//

#ifndef SHADOWSOCKS_CLIENT_PROXYMANAGER_H
#define SHADOWSOCKS_CLIENT_PROXYMANAGER_H

#include "stdafx.h"
#include "ProxyConfig.h"
#include "Proxy.h"
class ProxyManager:public QObject{
Q_OBJECT
public:
    ProxyManager(QObject* parent):QObject(parent){}
    virtual Proxy * startProxy(ProxyConfig *config)= 0;

    virtual void stopProxy()= 0;
};
#endif //SHADOWSOCKS_CLIENT_PROXYMANAGER_H
