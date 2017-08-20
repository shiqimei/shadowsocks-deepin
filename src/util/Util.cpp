//
// Created by pikachu on 17-8-5.
//

#include <QtGui/QPainter>
#include <QtCore/QMap>
#include <QtCore/QFile>
#include "Util.h"

GuiConfig Util::guiConfig = GuiConfigDao::instance()->get();
QString Util::ONLINE_PAC_URL = QString("https://raw.githubusercontent.com/PikachuHy/ss/master/autoproxy.pac");
QString Util::LOCAL_PAC_URL = QString("file://%1/.ss/autoproxy.pac").arg(QDir::homePath());
ConnectionTableModel *Util::model = nullptr;
ConfigHelper *Util::configHelper = nullptr;

QImage *Util::mix(QStringList list) {
    if(list.isEmpty()){
        return new QImage();
    }
    QImage *image = new QImage(list[0]);
//    image=image.scaled(24,24,Qt::KeepAspectRatio);
    QPainter painter(image);
//    painter.setCompositionMode(QPainter::CompositionMode_Source);
//    painter.fillRect(image.rect(),Qt::transparent);
    for (int i = 1; i < list.size(); ++i) {
        auto t=QImage(list[i]);
//        t=t.scaled(24,24,Qt::KeepAspectRatio);
        painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
        painter.drawImage(0,0,t);
    }
    painter.end();
    return image;
}
QImage Util::gray(QImage image) {
    QImage grayImage(image.width(),image.height(),QImage::Format_ARGB32);
    for (int i = 0; i < image.width(); ++i) {
        for (int j = 0; j < image.height(); ++j) {
            QRgb  pixel = image.pixel(i,j);
            int grayValue = qGray(pixel);
            QRgb grayPixel = qRgba(grayValue,grayValue,grayValue,grayValue);
            grayImage.setPixel(i,j,grayPixel);
        }
    }
    return grayImage;
}

QImage *Util::noProxyIconImage() {
    static QImage* image = nullptr;
    if(image!= nullptr){
        return image;
    } else{
        image = new QImage();
        *image = gray(QImage(":/icons/Resources/ssProxy24"));
        return image;
    }
}

QImage *const Util::proxyIconImage(int type) {
    static QMap<int, QImage *> map;
    if(map.contains(type)){
        qDebug() << "has " << type;
        return map.value(type);
    }
    QStringList list;
    if (type & Util::Type::None) {
        auto image = noProxyIconImage();
        map.insert(type, image);
        qDebug() << "noproxy";
        return image;
    }
    if(type & Util::Type::Global){
        list<<":/icons/Resources/ssProxy24";
    } else{
        list<<":/icons/Resources/ss24.png";
    }
    if(Util::Type::In & type){
        list<<":/icons/Resources/ssIn24.png";
    }
    if(Util::Type::Out & type){
        list<<":/icons/Resources/ssOut24.png";
    }
    auto image = mix(list);
    map.insert(type,image);
    return image;
}

QIcon Util::getIcon(int type) {
//    qDebug() << "get icon" << type;
    return QIcon(QString(":/icons/Resources/%1.png").arg(type));
}


QByteArray Util::readAllFile(QString filename) {
    QFile file(filename);
    if(!file.exists()){
        qDebug()<<"文件不存在";
        exit(0);
    }
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text)){
        qDebug()<<"打开文件失败";
        exit(0);
    }
//    qDebug()<<"打开文件成功";
    return file.readAll();
}

int Util::compareVersion(QString l, QString r) {
    auto ls = l.split(".");
    auto rs = r.split(".");
    for (int i = 0; i < qMax(ls.length(), rs.length()); ++i) {
        int lp = (i<ls.length())?ls[i].toInt():0;
        int rp = (i<ls.length())?rs[i].toInt():0;
        if(lp!=rp){
            return lp-rp;
        }
    }
    return 0;
}

QString Util::getFullpath(QString filename) {
    return QString("%1/.ss/%2").arg(QDir::homePath()).arg(filename);
}

QString Util::getQrcPath(QString imageName) {
    return QString(":/icons/Resources/%1").arg(imageName);
}

qreal Util::easeInOut(qreal x) {
    return (1 - qCos(M_PI * x)) / 2;
}

qreal Util::easeInQuad(qreal x) {
    return qPow(x, 2);
}

qreal Util::easeOutQuad(qreal x) {
    return -1 * qPow(x - 1, 2) + 1;
}

qreal Util::easeInQuint(qreal x) {
    return qPow(x, 5);
}

qreal Util::easeOutQuint(qreal x) {
    return qPow(x - 1, 5) + 1;
}

void Util::setFontSize(QPainter &painter, int textSize) {
    QFont font = painter.font();
    font.setPointSize(textSize);
    painter.setFont(font);

}


QString Util::formatBandwidth(double v) {
    static const char *orders[] = {"KB/s", "MB/s", "GB/s", "TB/s"};

    return formatUnitSize(v, orders, sizeof(orders) / sizeof(orders[0]));
}

QString Util::formatByteCount(double v) {
    static const char *orders[] = {"B", "KB", "MB", "GB", "TB"};

    return formatUnitSize(v, orders, sizeof(orders) / sizeof(orders[0]));
}

QString Util::formatUnitSize(double v, const char **orders, int nb_orders) {
    int order = 0;
    while (v >= 1024 && order + 1 < nb_orders) {
        order++;
        v = v / 1024;
    }
    char buffer1[30];
    snprintf(buffer1, sizeof(buffer1), "%.1lf %s", v, orders[order]);

    return QString(buffer1);
}

QString Util::formatMillisecond(int millisecond) {
    if (millisecond / 1000 < 3600) {
        // At least need return 1 seconds.
        return QDateTime::fromTime_t(std::max(1, millisecond / 1000)).toUTC().toString("mm:ss");
    } else {
        return QDateTime::fromTime_t(millisecond / 1000).toUTC().toString("hh:mm:ss");
    }
}

void Util::readConfig(QString string, QObject *parent) {
    configHelper = new ConfigHelper(string, parent);
    model = new ConnectionTableModel(parent);
    configHelper->read(model);
}

void Util::saveConfig() {
    GuiConfigDao::instance()->save(guiConfig);
    configHelper->save(*model);
}

void Util::showNotification(const QString &msg) {
    //Using DBus to send message.
    QDBusMessage method = QDBusMessage::createMethodCall("org.freedesktop.Notifications",
                                                         "/org/freedesktop/Notifications",
                                                         "org.freedesktop.Notifications", "Notify");
    QVariantList args;
    args << QCoreApplication::applicationName() << quint32(0) << "shadowsocks-qt5" << "Shadowsocks-Qt5" << msg
         << QStringList() << QVariantMap() << qint32(-1);
    method.setArguments(args);
    QDBusConnection::sessionBus().asyncCall(method);
}

Connection *Util::getCurrentConnection() {
    int index = guiConfig.index;
    return model->getItem(index)->getConnection();
}

bool Util::hasPacFile() {
    QFile file(Util::LOCAL_PAC_URL.right(Util::LOCAL_PAC_URL.length() - 7));
    return file.exists();
}
