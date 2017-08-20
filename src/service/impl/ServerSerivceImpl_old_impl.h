//
// Created by pikachu on 17-8-18.
//

#ifndef SHADOWSOCKS_CLIENT_SERVERSERIVCEIMPL_OLD_IMPL_H
#define SHADOWSOCKS_CLIENT_SERVERSERIVCEIMPL_OLD_IMPL_H

#include "service/ServerService.h"
#include "common/QCore.h"

class ServerSerivceImpl_old_impl : public ServerSerivce {

public:
    explicit ServerSerivceImpl_old_impl(QObject *parent);

    void editServers() override;

    void statiscsConfig() override;

    void shareServerConfig() override;

    QString scanQRCodeFromScreen() override;

    QString importURLfromClipboard() override;

private:
    void newCon(const QString &uri);
};


#endif //SHADOWSOCKS_CLIENT_SERVERSERIVCEIMPL_OLD_IMPL_H
