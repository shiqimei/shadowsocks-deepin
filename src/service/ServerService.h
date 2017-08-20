//
// Created by pikachu on 17-8-18.
//

#ifndef SHADOWSOCKS_CLIENT_SERVERSERVICE_H
#define SHADOWSOCKS_CLIENT_SERVERSERVICE_H

#include "common/common.h"
/**
 * 处理与服务器配置相关的事情
 */
class ServerSerivce : public QObject {
Q_OBJECT
public:
    explicit ServerSerivce(QObject *parent) : QObject(parent) {}

    /**
     * 配置服务器
     */
    virtual void editServers()= 0;

    /**
     * 数据统计配置
     */
    virtual void statiscsConfig()= 0;

    /**
     * 分享服务器配置
     */
    virtual void shareServerConfig()= 0;

    /**
     * 扫描屏幕上的二维码
     * @return 二维码的字符串
     */
    virtual QString scanQRCodeFromScreen()= 0;

    /**
     * 复制剪切版上的URL地址
     * @return
     */
    virtual QString importURLfromClipboard()= 0;

signals:

    void requestReloadMenu();
};
#endif //SHADOWSOCKS_CLIENT_SERVERSERVICE_H
