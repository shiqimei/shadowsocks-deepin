//
// Created by pikachu on 17-8-18.
//

#ifndef SHADOWSOCKS_CLIENT_HOTKEYSERVICEIMPL_OLD_IMPL_H
#define SHADOWSOCKS_CLIENT_HOTKEYSERVICEIMPL_OLD_IMPL_H

#include <service/HotkeyService.h>

class HotkeyServiceImpl_old_impl : public HotkeyService {
    Q_OBJECT
public:
    explicit HotkeyServiceImpl_old_impl(QObject *parent);

    void editHotkey() override;
};


#endif //SHADOWSOCKS_CLIENT_HOTKEYSERVICEIMPL_OLD_IMPL_H
