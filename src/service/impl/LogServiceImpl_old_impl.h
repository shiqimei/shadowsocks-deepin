//
// Created by pikachu on 17-8-18.
//

#ifndef SHADOWSOCKS_CLIENT_LOGSERVICEIMPL_OLD_IMPL_H
#define SHADOWSOCKS_CLIENT_LOGSERVICEIMPL_OLD_IMPL_H

#include <service/LogService.h>
#include "common/QCore.h"
#include "common/QGui.h"
#include "common/QWidgets.h"
#include "common/dtk.h"

#include <widget/ShowLogWidget.h>

class LogServiceImpl_old_impl : public LogService, public QObject {
Q_OBJECT
public:

    void showLog() override;

    void setVerboseLogging(bool b) override;

private:
    ShowLogWidget showLogWidget;
};


#endif //SHADOWSOCKS_CLIENT_LOGSERVICEIMPL_OLD_IMPL_H
