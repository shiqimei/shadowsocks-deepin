//
// Created by pikachu on 17-8-15.
//

#ifndef SHADOWSOCKS_CLIENT_PROXYSERVICE_H
#define SHADOWSOCKS_CLIENT_PROXYSERVICE_H
/**
 * 负责系统代理方法之间的切换
 */
class ProxyService{
public:
    /**
     * 代理方法
     * 无
     * 手动
     * 自动
     */
    enum ProxyMethod{
        None,
        Manual,
        Auto
    };

    /**
     * 设置代理方法
     * @param proxyMethod
     */
    virtual void setProxyMethod(ProxyMethod proxyMethod)= 0;

    /**
     * 是否启动代理
     * @param enabled
     */
    virtual void setProxyEnabled(bool enabled)= 0;

    /**
     * 编辑正向代理配置
     */
    virtual void editForwardProxy()= 0;

    /**
     * 是否允许来自局域网的连接
     * @param b
     */
    virtual void setAllowClientsFromLAN(bool b)= 0;
};


#endif //SHADOWSOCKS_CLIENT_PROXYSERVICE_H
