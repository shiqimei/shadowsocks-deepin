//
// Created by pikachu on 17-12-30.
//

#ifndef SHADOWSOCKS_CLIENT_SSPROXY_H
#define SHADOWSOCKS_CLIENT_SSPROXY_H

#include "stdafx.h"
#include <controller.h>
#include "interface/Proxy.h"
class SSProxy: public Proxy {
//class SSProxy: public QObject {
Q_OBJECT
public:
    SSProxy(QSS::Controller* controller, QObject* parent = nullptr);

private:
    QSS::Controller* controller;
};


#endif //SHADOWSOCKS_CLIENT_SSPROXY_H
