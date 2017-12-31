//
// Created by pikachu on 17-8-15.
//

#ifndef SHADOWSOCKS_CLIENT_PROXYSERVICE_H
#define SHADOWSOCKS_CLIENT_PROXYSERVICE_H

#include "common/common.h"

/**
 * 负责系统代理方法之间的切换
 */
class ProxyService : public QObject {
Q_OBJECT
public:
    explicit ProxyService(QObject *parent) : QObject(parent) {}

    /**
     * 代理方法
     * 无
     * 手动
     * 自动
     */
    enum ProxyMethod {
        None,
        Manual,
        Auto
    };

    /**
     * 设置代理方法
     * @param proxyMethod
     */
    virtual void setProxyMethod(ProxyMethod proxyMethod)= 0;

    virtual bool isPacMode()= 0;

    virtual bool isGlobelMode()=0;
    /**
     * 是否启动代理
     * @param enabled
     */
    virtual void setProxyEnabled(bool enabled)= 0;

    virtual bool isProxyEnaled()=0;

    /**
     * 编辑正向代理配置
     */
    virtual void editForwardProxy()= 0;

    /**
     * 是否允许来自局域网的连接
     * @param b
     */
    virtual void setAllowClientsFromLAN(bool b)= 0;

    virtual bool isAllowClientsFromLAN()= 0;

signals:

    void requestReloadMenu();

    void newController(Controller *controller);
};


#endif //SHADOWSOCKS_CLIENT_PROXYSERVICE_H
