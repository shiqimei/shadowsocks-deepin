//
// Created by pikachu on 17-8-22.
//

#include <util/Util.h>
#include "BalancingStrategy.h"

void BalancingStrategy::reloadServers() {

}

int BalancingStrategy::getAServer(Strategy::StrategyCallerType type) {
    auto max = Util::model->rowCount();
    qsrand(time(NULL));
    auto n = qrand();
    return n%max;
}

BalancingStrategy::BalancingStrategy() {
    name=QString("Load Balance");
    id=QString("com.shadowsocks.strategy.balancing");
}
