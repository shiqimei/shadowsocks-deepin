//
// Created by pikachu on 17-12-30.
//

#ifndef SHADOWSOCKS_CLIENT_SYSTEMPROXYMODEMANAGER_H
#define SHADOWSOCKS_CLIENT_SYSTEMPROXYMODEMANAGER_H

#include "stdafx.h"

class SystemProxyModeManager : public QObject {
Q_OBJECT
public:
    SystemProxyModeManager(QObject *parent) : QObject(parent) {}

    virtual void switchToNone()= 0;

    virtual void switchToAuto(QString pacURI)= 0;

    virtual void switchToManual(QString localAddress, int port)= 0;
};

#endif //SHADOWSOCKS_CLIENT_SYSTEMPROXYMODEMANAGER_H
