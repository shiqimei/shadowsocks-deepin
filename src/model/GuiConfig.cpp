//
// Created by pikachu on 17-8-19.
//

#include "GuiConfig.h"

QSS::Profile GuiConfig::getCurrentProfile() {
    if (index == -1) {
        //TODO 策略选择
    }
    return configs[index].profile;
}
