//
// Created by pikachu on 17-8-22.
//

#include <util/Util.h>
#include "HighAvailabilityStrategy.h"

HighAvailabilityStrategy::HighAvailabilityStrategy(QObject *parent) : Strategy(parent) {
    name = QString("High Availability");
    id=QString("com.shadowsocks.strategy.ha");
}

void HighAvailabilityStrategy::reloadServers() {

}

int HighAvailabilityStrategy::getAServer(Strategy::StrategyCallerType type) {
    //选择延迟最小的
    for (auto &it : Util::model->getItems()) {
        it->testLatency();
    }

    QTimer::singleShot(1000,this,[=](){
        ConnectionItem* item = nullptr;
        for(auto it:Util::model->getItems()){
            if(item== nullptr){
                item = it;
            }
            if(item->getConnection()->getProfile().latency>it->getConnection()->getProfile().latency){
                item=it;
            }
        }
        return Util::model->getItems().indexOf(item);
    });
}
