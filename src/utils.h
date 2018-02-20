#ifndef UTILS_H
#define UTILS_H
//#include "stdafx.h"
#include <QString>
#include <QDateTime>
#include <QFileInfoList>
#include <QLayout>
#include <QObject>
#include <QPainter>
#include <QString>
#include <unordered_set>

namespace Utils {
    QString getIconQrcPath(QString imageName);

    qint64 getTimestamp();

    QString configPath();

    void critical(QString msg);

    void warning(QString msg);

    void info(QString msg);
// copy from deepin-system-monitor

    QSize getRenderSize(int fontSize, QString string);

    QString formatBandwidth(double v);

    QString formatByteCount(double v);

    QString formatMillisecond(int millisecond);

    QString formatUnitSize(double v, const char **orders, int nb_orders);

    QString getQrcPath(QString imageName);

    QString getQssPath(QString qssName);

    qreal easeInOut(qreal x);

    qreal easeInQuad(qreal x);

    qreal easeInQuint(qreal x);

    qreal easeOutQuad(qreal x);

    qreal easeOutQuint(qreal x);

    void setFontSize(QPainter &painter, int textSize);
}
#endif // UTILS_H
