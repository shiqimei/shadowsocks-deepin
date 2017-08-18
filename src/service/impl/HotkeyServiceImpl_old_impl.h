//
// Created by pikachu on 17-8-18.
//

#ifndef SHADOWSOCKS_CLIENT_HOTKEYSERVICEIMPL_OLD_IMPL_H
#define SHADOWSOCKS_CLIENT_HOTKEYSERVICEIMPL_OLD_IMPL_H

#include <service/HotkeyService.h>
#include "common/QCore.h"
#include "common/QGui.h"
#include "common/QWidgets.h"
#include "common/dtk.h"


class HotkeyServiceImpl_old_impl : public HotkeyService {
public:
    void editHotkey() override;
};


#endif //SHADOWSOCKS_CLIENT_HOTKEYSERVICEIMPL_OLD_IMPL_H
