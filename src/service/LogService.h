//
// Created by pikachu on 17-8-18.
//

#ifndef SHADOWSOCKS_CLIENT_LOGSERVICE_H
#define SHADOWSOCKS_CLIENT_LOGSERVICE_H
/**
 * 负责处理日志方面的事情
 */
class LogService{
public:
    /**
     * 显示日志
     */
    virtual void showLog()= 0;

    /**
     * 是否记录详细的日志
     * @param b
     */
    virtual void setVerboseLogging(bool b)= 0;
};
#endif //SHADOWSOCKS_CLIENT_LOGSERVICE_H
