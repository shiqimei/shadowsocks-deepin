//
// Created by pikachu on 17-7-27.
//

#include <QtCore/QIODevice>
#include <QtCore/QFile>
#include <QtCore/QDir>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include "DownloadUtil.h"
#include <QDebug>
void DownloadUtil::download(QString url, QString filename) {
    QFile *pacFile;
    QNetworkReply *pacReply;
    QNetworkAccessManager *pacManager;
    QDir file;//文件夹
    QString fileStr = QObject::tr("%1/.ss/").arg(QDir::homePath());
    QString fileName = fileStr + "/gfwlist.txt";
    //判断文件夹是否存在 不存在创建
    if (!file.exists(fileStr)) {
        file.mkpath(fileStr);
    }
    pacFile = new QFile(fileName);
    //判断文件是否可写入 不可写删除 指针赋值0
    if (!pacFile->open(QIODevice::WriteOnly)) {
        delete pacFile;
        pacFile = 0;
        qDebug()<<"文件不可写";
        exit(0);
    }
    QUrl  serviceUrl = QUrl(url);
    pacManager = new QNetworkAccessManager();
    pacReply=pacManager->get(QNetworkRequest(serviceUrl));
#ifdef QT_DEBUG
    qDebug()<<"下载初始化完毕";
#endif
    QObject::connect(pacReply,&QNetworkReply::readyRead,[=](){
#ifdef QT_DEBUG
//        qDebug()<<"&QNetworkReply::readyRead";
#endif
        if(pacFile!= nullptr){
#ifdef QT_DEBUG
//            qDebug()<<"写入";
#endif
            pacFile->write(pacReply->readAll());
        }
    });
    QObject::connect(pacReply,&QNetworkReply::finished,[=](){
        //刷新文件
        pacFile->flush();
        pacFile->close();
        pacFile->deleteLater();
        pacReply->deleteLater();
        pacManager->deleteLater();
        emit finished();
    });
}
