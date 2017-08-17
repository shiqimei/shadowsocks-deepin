//
// Created by pikachu on 17-8-15.
//

#ifndef SHADOWSOCKS_CLIENT_PROXYSERVICE_H
#define SHADOWSOCKS_CLIENT_PROXYSERVICE_H

/**
 * 负责系统代理方法之间的切换
 */
class ProxyService {
    enum ProxyMethod{
        None,
        Manual,
        Auto
    };
    void setProxyMethod(ProxyMethod proxyMethod);
};


#endif //SHADOWSOCKS_CLIENT_PROXYSERVICE_H
