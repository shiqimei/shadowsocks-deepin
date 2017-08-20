//
// Created by pikachu on 17-8-19.
//

#ifndef SHADOWSOCKS_CLIENT_PROCESSVIEW_H
#define SHADOWSOCKS_CLIENT_PROCESSVIEW_H

#include "common/common.h"
#include "ListView.h"

class ConnectionView : public ListView {
Q_OBJECT

public:
    explicit ConnectionView(QList<bool> columnHideFlags);

public slots:

    void changeTheme(QString theme);

    void initTheme();
};


#endif //SHADOWSOCKS_CLIENT_PROCESSVIEW_H
