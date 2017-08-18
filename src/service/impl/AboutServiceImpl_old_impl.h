//
// Created by pikachu on 17-8-18.
//

#ifndef SHADOWSOCKS_CLIENT_ABOUTSERVICEIMPL_OLD_IMPL_H
#define SHADOWSOCKS_CLIENT_ABOUTSERVICEIMPL_OLD_IMPL_H

#include "service/AboutService.h"

class AboutServiceImpl_old_impl : public AboutService {
public:
    explicit AboutServiceImpl_old_impl(QObject *parent);

    void showAbout() override;
};


#endif //SHADOWSOCKS_CLIENT_ABOUTSERVICEIMPL_OLD_IMPL_H
