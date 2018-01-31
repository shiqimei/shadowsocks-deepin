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
QString getIconQrcPath(QString imageName){
    return QString(":/icon/Resources/%1").arg(imageName);
}

qint64 getTimestamp()
{
    return QDateTime::currentDateTime().toMSecsSinceEpoch(); //毫秒级
}

QString configPath()
{

    return QDir(QDir(QStandardPaths::standardLocations(QStandardPaths::ConfigLocation).first()).filePath(qApp->organizationName())).filePath(qApp->applicationName());
}

void critical(QString msg)
{
    QMessageBox::critical(nullptr,"critical",msg);
}

void warning(QString msg)
{
    QMessageBox::warning(nullptr,"warning",msg);
}

void info(QString msg)
{
    QMessageBox::information(nullptr,"info",msg);
}

// copy from deepin-system-monitor

QMap<QString, QString> desktopfileMaps = getDesktopfileMap();

QMap<QString, QString> getDesktopfileMap() {
    QMap<QString, QString> map;

    map["/opt/kingsoft/wps-office/office6/wps"] = "/usr/share/applications/wps-office-wps.desktop";
    map["/opt/kingsoft/wps-office/office6/wpp"] = "/usr/share/applications/wps-office-wpp.desktop";
    map["/opt/kingsoft/wps-office/office6/et"] = "/usr/share/applications/wps-office-et.desktop";

    return map;
}

QMap<QString, QString> processDescriptions = getProcessDescriptions();

QMap<QString, QString> getProcessDescriptions() {
    QMap<QString, QString> map;

    map["startdde"] =  QObject::tr("Deepin Desktop Environment - Process initiation service");
    map["dde-desktop"] =  QObject::tr("Deepin Desktop Environment - Desktop");
    map["dde-polkit-agent"] =  QObject::tr("Deepin Desktop Environment - Polkit proxy");
    map["dde-launcher"] =  QObject::tr("Deepin Desktop Environment - Launcher");
    map["dde-dock"] =  QObject::tr("Deepin Desktop Environment - Dock");
    map["dde-osd"] =  QObject::tr("Deepin Desktop Environment - Screen display");
    map["dde-system-daemon"] =  QObject::tr("Deepin Desktop Environment - Daemon");
    map["dde-session-daemon"] =  QObject::tr("Deepin Desktop Environment - Session daemon");
    map["dde-session-initializer"] =  QObject::tr("Deepin Desktop Environment - Session initialization process");
    map["dde-file-manager-daemon"] =  QObject::tr("Deepin File Manager daemon");
    map["dde-lockservice"] =  QObject::tr("Deepin Desktop Environment - Lock screen service");
    map["deepin-wm"] =  QObject::tr("Deepin Window Manager ");
    map["deepin-wm-switcher"] =  QObject::tr("Deepin Window Manager switcher");
    map["deepin-notifications"] =  QObject::tr("Deepin notification");
    map["deepin-cloud-print-agent"] =  QObject::tr("Deepin Cloud Print agent");
    map["deepin-menu"] =  QObject::tr("Deepin menu service");
    map["lastore-daemon"] =  QObject::tr("Deepin Store daemon");
    map["bamfdaemon"] =  QObject::tr("Window match daemon");
    map["bamfdaemon-dbus-runner"] =  QObject::tr("Window match daemon DBus service");
    map["ssh-agent"] =  QObject::tr("SSH agent");
    map["gvfsd"] =  QObject::tr("User mode virtual file system daemon");
    map["gvfsd-fuse"] =  QObject::tr("Fuse server of user mode virtual file system daemon");
    map["lastore-session-helper"] =  QObject::tr("Helper process of Deepin Store client");
    map["networkmanager"] =  QObject::tr("Network manager");
    map["polkitd"] =  QObject::tr("PolicyKit DBus service");
    map["smbd"] =  QObject::tr("File sharing service daemon");
    map["xorg"] = QObject::tr("X service");
    map["fcitx"] = QObject::tr("Fcitx input method");
    map["fcitx-dbus-watcher"] = QObject::tr("Fcitx input method DBus daemon");
    map["sogou-qimpanel-watchdog"] = QObject::tr("Sogou input method daemon");
    map["sslocal"] = QObject::tr("ShadowSocks local client");
    map["pulseaudio"] = QObject::tr("Sound service");
    map["cupsd"] = QObject::tr("Print daemon");
    map["lightdm"] = QObject::tr("Light display manager");
    map["systemd"] = QObject::tr("System service manager");
    map["systemd-udevd"] = QObject::tr("System service manager - Device management daemon");
    map["udisksd"] = QObject::tr("Disk daemon");
    map["accounts-daemon"] = QObject::tr("Account daemon");
    map["dbus-daemon"] = QObject::tr("DBus daemon");
    map["mousearea"] = QObject::tr("Mouse event daemon");
    map["dconf-service"] = QObject::tr("DConf service");
    map["gnome-keyring-daemon"] = QObject::tr("Gnome keyring daemon");
    map["bluetoothd"] = QObject::tr("Bluetooth daemon");
    map["upowerd"] = QObject::tr("Power daemon");
    map["modemmanager"] = QObject::tr("Modem device manager");
    map["applet.py"] = QObject::tr("System print tray service");
    map["chrome-sandbox"] = QObject::tr("Chrome browser sandbox");
    map["syndaemon"] = QObject::tr("Synaptics touchpad device daemon");
    map["sogou-qimpanel"] = QObject::tr("Sogou input method");

    return map;
}


    QSize getRenderSize(int fontSize, QString string)
{
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

QString formatBandwidth(double v)
{
    static const char* orders[] = { "KB/s", "MB/s", "GB/s", "TB/s" };

    return formatUnitSize(v, orders, sizeof(orders)/sizeof(orders[0]));
}

QString formatByteCount(double v)
{
    static const char* orders[] = { "B", "KB", "MB", "GB", "TB" };

    return formatUnitSize(v, orders, sizeof(orders)/sizeof(orders[0]));
}

QString formatUnitSize(double v, const char** orders, int nb_orders)
{
    int order = 0;
    while (v >= 1024 && order + 1 < nb_orders) {
        order++;
        v  = v/1024;
    }
    char buffer1[30];
    snprintf(buffer1, sizeof(buffer1), "%.1lf %s", v, orders[order]);

    return QString(buffer1);
}

QString formatMillisecond(int millisecond)
{
    if (millisecond / 1000 < 3600) {
        // At least need return 1 seconds.
        return QDateTime::fromTime_t(std::max(1, millisecond / 1000)).toUTC().toString("mm:ss");
    } else {
        return QDateTime::fromTime_t(millisecond / 1000).toUTC().toString("hh:mm:ss");
    }
}

    QString getQrcPath(QString imageName)
{
    return QString(":/image/%1").arg(imageName);
}

QString getQssPath(QString qssName)
{
    return QString(":/qss/%1").arg(qssName);
}

    qreal easeInOut(qreal x)
{
    return (1 - qCos(M_PI * x)) / 2;
}

qreal easeInQuad(qreal x)
{
    return qPow(x, 2);
}

qreal easeOutQuad(qreal x)
{
    return -1 * qPow(x - 1, 2) + 1;
}

qreal easeInQuint(qreal x)
{
    return qPow(x, 5);
}

qreal easeOutQuint(qreal x)
{
    return qPow(x - 1, 5) + 1;
}

    void setFontSize(QPainter &painter, int textSize)
{
    QFont font = painter.font() ;
    font.setPointSize(textSize);
    painter.setFont(font);
}

}
