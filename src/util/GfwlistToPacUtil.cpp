//
// Created by pikachu on 17-7-27.
//

#include <QtCore/QString>
#include "GfwlistToPacUtil.h"
#include <QFile>
#include <QDebug>
#include <QtCore/QDir>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtWidgets/QApplication>
#include <QtCore/QJsonObject>
#include <QtCore/QJsonDocument>
#include "DownloadUtil.h"
#include "Util.h"

void GfwlistToPacUtil::gfwlist2pac() {
    DownloadUtil* downloadUtil =new DownloadUtil();
    downloadUtil->download(Util::ONLINE_GFWLIST_URL, Util::LOCAL_GFWLIST_PATH);
    QObject::connect(downloadUtil,&DownloadUtil::finished,[=](){
        QFile gfwlistFile(Util::LOCAL_GFWLIST_PATH);
        if(!gfwlistFile.open(QIODevice::ReadOnly)){
            qDebug()<<"打开失败";
            Util::showNotification(tr("open local gfwlist fail"));
            exit(0);
        }
        auto content = QByteArray::fromBase64(gfwlistFile.readAll());
        auto domains=parseGfwlist(content);
        QFile userRulesFile(Util::USER_RULE_PATH);
        if(userRulesFile.exists()){
            if(!userRulesFile.open(QIODevice::ReadOnly|QIODevice::Text)){
                qDebug()<<"文件打开失败";
                Util::showNotification(tr("open local user-rule file fail"));
                exit(0);
            }
            domains=parseGfwlist(userRulesFile.readAll());
        }
        QJsonObject jsonObject;
        for(auto&it:domains){
            jsonObject.insert(it,1);
        }
//        qDebug()<<jsonObject;
        QJsonDocument jsonDocument;
        jsonDocument.setObject(jsonObject);
//        qDebug()<<jsonDocument.toJson();

        /**
         * 2017年09月13日
         * 没有考虑到用户会更换本地端口,默认是1080，
         * https://github.com/PikachuHy/shadowsocks-client/issues/19
         */
//        QString pacContent=generatePac(jsonDocument.toJson(),"SOCKS5 127.0.0.1:1080");
        // 获取用户设置的端口号
        auto items = Util::model->getItems();
        int port = 1080;
        if(!items.isEmpty()){
            port=items.first()->getConnection()->getProfile().localPort;
        }
        qDebug()<<"port"<<port;
        QString pacContent=generatePac(jsonDocument.toJson(),QString("SOCKS5 127.0.0.1:%1").arg(port));
        QFile file(Util::LOCAL_PAC_PATH);
        file.open(QIODevice::WriteOnly|QIODevice::Text);
        file.write(pacContent.toLocal8Bit());
        file.close();
        downloadUtil->deleteLater();
        emit finished();
    });
}

QSet<QString> GfwlistToPacUtil::parseGfwlist(QByteArray byteArray) {
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

    QFile file(":/Resources/proxy.pac");
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
//    proxy_content=proxy_content.replace("__RULES__",domains);
    return proxy_content;
}
