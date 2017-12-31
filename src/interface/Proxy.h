//
// Created by pikachu on 17-12-30.
//

#ifndef SHADOWSOCKS_CLIENT_PROXY_H
#define SHADOWSOCKS_CLIENT_PROXY_H
#include "stdafx.h"
class Proxy : public QObject{
Q_OBJECT
public:
    explicit Proxy(QObject* parent= nullptr):QObject(parent){}
};
#endif //SHADOWSOCKS_CLIENT_PROXY_H
