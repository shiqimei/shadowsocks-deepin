//
// Created by pikachu on 17-8-22.
//

#ifndef SHADOWSOCKS_CLIENT_HIGHAVAILABILITYSTRATEGY_H
#define SHADOWSOCKS_CLIENT_HIGHAVAILABILITYSTRATEGY_H


#include <service/Strategy.h>

class HighAvailabilityStrategy: public Strategy  {
Q_OBJECT
public:
    explicit HighAvailabilityStrategy(QObject* parent = nullptr);

    void reloadServers() override;

    int getAServer(StrategyCallerType type=StrategyCallerType::TCP) override;
};


#endif //SHADOWSOCKS_CLIENT_HIGHAVAILABILITYSTRATEGY_H
