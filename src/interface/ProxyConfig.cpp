//
// Created by pikachu on 17-12-30.
//

#include "ProxyConfig.h"
ProxyConfig::ProxyConfig(QObject *parent):QObject(parent){
    setProperty("id","");
    setProperty("server","");
    setProperty("server_port","");
    setProperty("password","");
    setProperty("method","");
    setProperty("remarks","");
    setProperty("timeout","");
}