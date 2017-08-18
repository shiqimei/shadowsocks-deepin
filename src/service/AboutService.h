//
// Created by pikachu on 17-8-18.
//

#ifndef SHADOWSOCKS_CLIENT_ABOUTSERVICE_H
#define SHADOWSOCKS_CLIENT_ABOUTSERVICE_H

#include "common/common.h"
/**
 * 处理关于
 */
class AboutService : public QObject {
Q_OBJECT
public:
    AboutService(QObject *parent) : QObject(parent) {}

    /**
     * 显示关于信息
     */
    virtual void showAbout()= 0;
};
#endif //SHADOWSOCKS_CLIENT_ABOUTSERVICE_H
