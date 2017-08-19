//
// Created by pikachu on 17-8-18.
//

#ifndef SHADOWSOCKS_CLIENT_PACSERVICE_H
#define SHADOWSOCKS_CLIENT_PACSERVICE_H

#include "common/common.h"
/**
 * 处理与pac相关的事情
 */
class PacService : public QObject {
Q_OBJECT
public:
    PacService(QObject *parent) : QObject(parent) {}

    /**
     * 是否使用本地pac文件
     * @param isLocal
     */
    virtual void setUseLocalPac(bool isLocal)= 0;

    virtual bool isUseLocalPac()= 0;

    virtual bool isUseOnlinePac()= 0;
    /**
     * 编辑本地pac文件
     */
    virtual void editLocalPacFile()= 0;

    /**
     * 编辑用户规则
     */
    virtual void editUserRuleForGFWList()= 0;

    /**
     * 保护本地pac文件
     * @param b
     */
    virtual void setSecureLocalPac(bool b)= 0;

    virtual bool isSecureLocalPac()= 0;
    /**
     * 复制本地pac文件地址
     * @return
     */
    virtual void copyLocalPacURL()= 0;

    /**
     * 编辑在线pac文件地址
     */
    virtual void editOnlinePacUrl()= 0;
};
#endif //SHADOWSOCKS_CLIENT_PACSERVICE_H
