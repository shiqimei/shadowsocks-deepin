//
// Created by pikachu on 17-8-22.
//

#ifndef SHADOWSOCKS_CLIENT_BALANCINGSTRATEGY_H
#define SHADOWSOCKS_CLIENT_BALANCINGSTRATEGY_H

#include <service/ServerService.h>
#include <service/Strategy.h>
#include "common/common.h"
class BalancingStrategy :public Strategy{
Q_OBJECT
public:
    BalancingStrategy();

    void reloadServers() override;

    int getAServer(StrategyCallerType type=StrategyCallerType::TCP) override;
};


#endif //SHADOWSOCKS_CLIENT_BALANCINGSTRATEGY_H
