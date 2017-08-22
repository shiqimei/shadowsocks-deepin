//
// Created by pikachu on 17-8-22.
//

#ifndef SHADOWSOCKS_CLIENT_STRATEGY_H
#define SHADOWSOCKS_CLIENT_STRATEGY_H

#include "common/common.h"
class Strategy:public QObject{
    Q_OBJECT
public:
    Strategy(QObject *parent= nullptr) : QObject(parent) {}

    enum StrategyCallerType{
        TCP,
        UDP
    };

    const QString &getName() const {
        return name;
    }

    const QString &getId() const {
        return id;
    }

    virtual void reloadServers()= 0;

    virtual int getAServer(StrategyCallerType type=StrategyCallerType::TCP)= 0;
protected:
    QString name;
    QString id;
};
#endif //SHADOWSOCKS_CLIENT_STRATEGY_H
