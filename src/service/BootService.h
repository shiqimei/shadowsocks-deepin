//
// Created by pikachu on 17-8-18.
//

#ifndef SHADOWSOCKS_CLIENT_BOOTSERVICE_H
#define SHADOWSOCKS_CLIENT_BOOTSERVICE_H
/**
 * 处理开机自启动相关的事情
 */
class BootService{
public:
    /**
     * 是否开机自启动
     * @return
     */
    virtual bool isAutoBoot()= 0;

    /**
     * 设置开机是否自启动
     * @param b
     */
    virtual void setAutoBoot(bool b)= 0;
};
#endif //SHADOWSOCKS_CLIENT_BOOTSERVICE_H
