//
// Created by pikachu on 17-8-18.
//

#include <widget/EditHotkeysDialog.h>
#include "HotkeyServiceImpl_old_impl.h"

void HotkeyServiceImpl_old_impl::editHotkey() {
    auto dialog = new EditHotkeysDialog();
    dialog->exec();
    dialog->deleteLater();
    emit requestReloadMenu();
}

HotkeyServiceImpl_old_impl::HotkeyServiceImpl_old_impl(QObject *parent) : HotkeyService(parent) {}
