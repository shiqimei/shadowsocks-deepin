//
// Created by pikachu on 17-12-31.
//

#ifndef SHADOWSOCKS_CLIENT_DBHELPER_H
#define SHADOWSOCKS_CLIENT_DBHELPER_H

#include <DSingleton>
#include "stdafx.h"
using Dtk::Core::DSingleton;
class DBHelper: public QObject, public DSingleton<DBHelper> {
Q_OBJECT
public:
    DBHelper();
    ~DBHelper();
private:
    QSqlDatabase database;
};


#endif //SHADOWSOCKS_CLIENT_DBHELPER_H
