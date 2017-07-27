//
// Created by pikachu on 17-7-27.
//

#include <QtCore/QString>
#include "GfwlistToPacUtil.h"
#include <QObject>
#include <QFile>
#include <QDebug>
#include <QtCore/QDir>
#include <QtNetwork/QNetworkAccessManager>
#include <QtCore/QIODevice>
#include <QtNetwork/QNetworkReply>
#include <QtWidgets/QApplication>
#include <QtCore/QJsonObject>
#include <QtCore/QJsonDocument>
#include "DownloadUtil.h"
void GfwlistToPacUtil::gfwlist2pac() {
    QString GFWLIST_URL = "https://raw.githubusercontent.com/gfwlist/gfwlist/master/gfwlist.txt";
    DownloadUtil* downloadUtil =new DownloadUtil();
    downloadUtil->download(GFWLIST_URL,"gfwlist.txt");
    QObject::connect(downloadUtil,&DownloadUtil::finished,[=](){

        QString gfwlistPath=QObject::tr("%1/.ss/gfwlist.txt").arg(QDir::homePath());
        QFile gfwlistFile(gfwlistPath);
        if(!gfwlistFile.open(QIODevice::ReadOnly)){
            qDebug()<<"打开失败";
            exit(0);
        }
        auto content = QByteArray::fromBase64(gfwlistFile.readAll());
        auto domains=parseGfwlist(content);
        QJsonObject jsonObject;
        for(auto&it:domains){
            jsonObject.insert(it,1);
        }
//        qDebug()<<jsonObject;
        QJsonDocument jsonDocument;
        jsonDocument.setObject(jsonObject);
//        qDebug()<<jsonDocument.toJson();
        QString pacContent=generatePac(jsonDocument.toJson(),"SOCKS5 127.0.0.1:1080");
        QFile file(QObject::tr("%1/.ss/autoproxy.pac").arg(QDir::homePath()));
        file.open(QIODevice::WriteOnly|QIODevice::Text);
        file.write(pacContent.toLocal8Bit());
        file.close();
        downloadUtil->deleteLater();
        emit finished();
    });
}

QSet<QString> GfwlistToPacUtil::parseGfwlist(QByteArray byteArray) {
    QSet<QString> set;
    QTextStream stream(byteArray);
    QJsonObject jsonObject;
    while (!stream.atEnd()){
        QString line=stream.readLine();
        if(line.startsWith("!") || line.startsWith("[") || line.isEmpty() || line.startsWith("@")){
            continue;
        }
        if(line.contains(".*")){
//            qDebug()<<line;
            continue;
        } else if (line.contains("\\*")){
//            qDebug()<<line<<line.replace("*","/")<<"line.contains(\"*\")";
            line=line.replace("*","/");
        }
        if(line.startsWith("||")){
//            qDebug()<<line<<line.right(line.size()-2)<<"line.startsWith(\"||\")";
            line=line.right(line.size()-2);
        }
        if (line.startsWith("|")){
//            qDebug()<<line<<line.right(line.size()-1)<<"line.startsWith(\"|\") || line.startsWith(\".\")";
            line=line.right(line.size()-1);
        }
        if(line.startsWith(".")){
//            qDebug()<<line;
            line=line.right(line.size()-1);
        }
        addDomainToSet(set,line);
    }
    return set;
}

QString GfwlistToPacUtil::getHostname(QString urlString) {
    if(!urlString.startsWith("http:")){
        urlString="http://"+urlString;
    }
    QUrl url;
    url.setUrl(urlString);
//    qDebug()<<"url"<<url.host();
//    qDebug()<<url.scheme()<<url.host()<<url.port()<<url.query()<<url.path();
//    return urlString.right(urlString.size()-7);
    return url.host();
}

void GfwlistToPacUtil::addDomainToSet(QSet<QString>& set, QString something) {
    QString hostname = getHostname(something);
//    QString hostname=something;
//    qDebug()<<"hostname"<<hostname<<something;
    if(!hostname.isEmpty()){
        if(hostname.startsWith(".")){
            hostname=hostname.right(hostname.size()-1);
        }
        if(hostname.endsWith("/")){
            hostname=hostname.left(hostname.size()-1);
        }
        set.insert(hostname);
//        qDebug()<<hostname;
    }
}

QString GfwlistToPacUtil::generatePac(QString domains, QString proxy) {

    QFile file(":/proxy.pac");
    if(!file.exists()){
        qDebug()<<"文件不存在"<<file.fileName();
        exit(0);
    }
    if(!file.open(QIODevice::ReadOnly)){
        qDebug()<<"文件打开失败"<<file.fileName();
        exit(0);
    }
    QString proxy_content=file.readAll();
    proxy_content=proxy_content.replace("__PROXY__",proxy);
    proxy_content=proxy_content.replace("__DOMAINS__",domains);
    return proxy_content;
}
