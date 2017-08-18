//
// Created by pikachu on 17-8-18.
//

#ifndef SHADOWSOCKS_CLIENT_BOOTSERVICEIMPL_WITH_DDE_API_H
#define SHADOWSOCKS_CLIENT_BOOTSERVICEIMPL_WITH_DDE_API_H

#include <service/BootService.h>
#include <dbusinterface/DBusStartManager.h>
#include "common/QCore.h"
#include "common/QGui.h"
#include "common/QWidgets.h"
#include "common/dtk.h"

using StartManagerInter = com::deepin::StartManager;

class BootServiceImpl_with_dde_api : public BootService {
public:
    bool isAutoBoot() override;

    void setAutoBoot(bool b) override;

private:
    StartManagerInter startManagerInter;
};


#endif //SHADOWSOCKS_CLIENT_BOOTSERVICEIMPL_WITH_DDE_API_H
