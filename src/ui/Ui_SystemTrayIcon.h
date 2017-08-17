//
// Created by pikachu on 17-8-15.
//

#ifndef SHADOWSOCKS_CLIENT_UI_SYSTEMTRAYICON_H
#define SHADOWSOCKS_CLIENT_UI_SYSTEMTRAYICON_H

#include <SystemTrayIcon.h>
#include "common/common.h"
#include "common/dtk.h"
#include "common/QCore.h"
#include "common/QGui.h"
#include "common/QWidgets.h"
#include "common/QNetwork.h"
QT_BEGIN_NAMESPACE
class Ui_SystemTrayIcon {
public:
    QMenu* menu;
    void setupUi(SystemTrayIcon* systemTrayIcon){
        if(systemTrayIcon->objectName().isEmpty()){
            systemTrayIcon->setObjectName("systemTrayIcon");
        }
        menu = new QMenu(QObject::tr("menu"));
        NEW_ACTION(startSystemAgentAction,"Enalble System Proxy",menu)
    }
};
namespace Ui{
    class SystemTrayIcon:public Ui_SystemTrayIcon{};
}
QT_END_NAMESPACE
#endif //SHADOWSOCKS_CLIENT_UI_SYSTEMTRAYICON_H
