//#include "stdafx.h"
#include "utils.h"
#include <QApplication>
#include <QDir>
#include <QStandardPaths>
#include <QMessageBox>

#include <QApplication>
#include <QDateTime>
#include <QDebug>
#include <QDir>
#include <QFontMetrics>
#include <QIcon>
#include <QImageReader>
#include <QLayout>
#include <QPainter>
#include <QPixmap>
#include <QStandardPaths>
#include <QString>
#include <QWidget>
#include <QtDBus>
#include <QtMath>
#include <QtX11Extras/QX11Info>
#include <X11/extensions/shape.h>
#include <fstream>
#include <qdiriterator.h>
#include <sstream>
#include <stdio.h>
#include <string>
#include <time.h>
#include <unordered_set>

class DApplication;
namespace Utils {
    QString getIconQrcPath(QString imageName) {
        return QString(":/icon/Resources/%1").arg(imageName);
    }

    qint64 getTimestamp() {
        return QDateTime::currentDateTime().toMSecsSinceEpoch(); //毫秒级
    }

    QString configPath() {

        return QDir(QDir(QStandardPaths::standardLocations(QStandardPaths::ConfigLocation).first()).filePath(
                qApp->organizationName())).filePath(qApp->applicationName());
    }

    void critical(QString msg) {
        QMessageBox::critical(nullptr, "critical", msg);
    }

    void warning(QString msg) {
        QMessageBox::warning(nullptr, "warning", msg);
    }

    void info(QString msg) {
        QMessageBox::information(nullptr, "info", msg);
    }

// copy from deepin-system-monitor

    QSize getRenderSize(int fontSize, QString string) {
        QFont font;
        font.setPointSize(fontSize);
        QFontMetrics fm(font);

        int width = 0;
        int height = 0;
                foreach (auto line, string.split("\n")) {
                int lineWidth = fm.width(line);
                int lineHeight = fm.height();

                if (lineWidth > width) {
                    width = lineWidth;
                }
                height += lineHeight;
            }

        return QSize(width, height);
    }

    QString formatBandwidth(double v) {
        static const char *orders[] = {"KB/s", "MB/s", "GB/s", "TB/s"};

        return formatUnitSize(v, orders, sizeof(orders) / sizeof(orders[0]));
    }

    QString formatByteCount(double v) {
        static const char *orders[] = {"B", "KB", "MB", "GB", "TB"};

        return formatUnitSize(v, orders, sizeof(orders) / sizeof(orders[0]));
    }

    QString formatUnitSize(double v, const char **orders, int nb_orders) {
        int order = 0;
        while (v >= 1024 && order + 1 < nb_orders) {
            order++;
            v = v / 1024;
        }
        char buffer1[30];
        snprintf(buffer1, sizeof(buffer1), "%.1lf %s", v, orders[order]);

        return QString(buffer1);
    }

    QString formatMillisecond(int millisecond) {
        if (millisecond / 1000 < 3600) {
            // At least need return 1 seconds.
            return QDateTime::fromTime_t(std::max(1, millisecond / 1000)).toUTC().toString("mm:ss");
        } else {
            return QDateTime::fromTime_t(millisecond / 1000).toUTC().toString("hh:mm:ss");
        }
    }

    QString getQrcPath(QString imageName) {
        return QString(":/image/%1").arg(imageName);
    }

    QString getQssPath(QString qssName) {
        return QString(":/qss/%1").arg(qssName);
    }

    qreal easeInOut(qreal x) {
        return (1 - qCos(M_PI * x)) / 2;
    }

    qreal easeInQuad(qreal x) {
        return qPow(x, 2);
    }

    qreal easeOutQuad(qreal x) {
        return -1 * qPow(x - 1, 2) + 1;
    }

    qreal easeInQuint(qreal x) {
        return qPow(x, 5);
    }

    qreal easeOutQuint(qreal x) {
        return qPow(x - 1, 5) + 1;
    }

    void setFontSize(QPainter &painter, int textSize) {
        QFont font = painter.font();
        font.setPointSize(textSize);
        painter.setFont(font);
    }

}
