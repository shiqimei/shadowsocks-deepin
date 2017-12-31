//
// Created by pikachu on 17-12-31.
//

#include "DBHelper.h"

DBHelper::DBHelper() {
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName(QString("%1/.ss/ss.db").arg(QDir::homePath()));
    qDebug()<<database.databaseName();
    if(!database.open()){
        qCritical()<<"database open fail";
    } else{
        qDebug()<<"database opened";
        QSqlQuery sqlQuery;
        QString createTableSQL = "CREATE TABLE if not exists ss"
                "("
                "  id          TEXT"
                "    PRIMARY KEY,"
                "  server      TEXT,"
                "  server_port TEXT,"
                "  password    TEXT,"
                "  method      TEXT,"
                "  remarks     TEXT,"
                "  timeout     TEXT,"
                "  status      TEXT,"
                "  latency     TEXT,"
                "  local_port  INT,"
                "  term_usage  INT,"
                "  total_usage INT,"
                "  last_used   TEXT"
                ");";
        sqlQuery.prepare(createTableSQL);
        if(!sqlQuery.exec()){
            qCritical()<<"create table ss failed";
            qCritical()<<sqlQuery.lastError();
        } else{
            qDebug()<<"table created ";
        }
    }
}

DBHelper::~DBHelper() {
    database.close();
    qDebug()<<"database closed";
}
