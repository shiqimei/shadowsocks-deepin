//
// Created by pikachu on 17-12-31.
//

#include "ConfigDAO.h"

ProxyConfig *ConfigDAO::find(QString id) {
    QSqlQuery sqlQuery;
    QString sql = "select * from ss where id = :id";
    sqlQuery.prepare(sql);
    sqlQuery.bindValue(":id",id);
    ProxyConfig* config = new ProxyConfig();
    while (sqlQuery.next()){
        config->setProperty("1",sqlQuery.value(0).toString());
    }
    return config;
}

QList<ProxyConfig *> ConfigDAO::findAll() {
    QList<ProxyConfig*> list;
    QSqlQuery sqlQuery;
    sqlQuery.exec("select * from ss");
    while (sqlQuery.next()){
        ProxyConfig* config = new ProxyConfig();
        for(auto&it:config->dynamicPropertyNames()){
            config->setProperty(it,sqlQuery.value(QString(it)));
        }
        list.append(config);
    }
    return list;
}

void ConfigDAO::remove(QString id) {
    QSqlQuery sqlQuery;
    sqlQuery.prepare("delete from ss where id = :id");
    sqlQuery.bindValue(":id",id);
    sqlQuery.exec();
}

void ConfigDAO::insert(ProxyConfig* config) {

}
