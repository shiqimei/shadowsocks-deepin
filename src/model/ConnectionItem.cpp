//
// Created by pikachu on 17-8-19.
//

#include <util/Util.h>

ConnectionItem::ConnectionItem(Connection *_con, QObject *parent) :
        con(_con) {
    initTheme();

    connect(DThemeManager::instance(), &DThemeManager::themeChanged, this, &ConnectionItem::changeTheme);
    if (con) {
        con->setParent(this);
        connect(con, &Connection::stateChanged, this, &ConnectionItem::onConnectionStateChanged);
        connect(con, &Connection::stateChanged, this, &ConnectionItem::stateChanged);
        connect(con, &Connection::latencyAvailable, this, &ConnectionItem::onConnectionPingFinished);
        connect(con, &Connection::latencyAvailable, this, &ConnectionItem::latencyChanged);
        connect(con, &Connection::startFailed, this, &ConnectionItem::onStartFailed);
    }
}

const QStringList ConnectionItem::bytesUnits = QStringList()
        << " B" << " KiB" << " MiB" << " GiB" << " TiB"
        << " PiB" << " EiB" << " ZiB" << " YiB";

int ConnectionItem::columnCount() {
    return 9;
}

QVariant ConnectionItem::data(int column, int role) const {
    if (!con) {
        return QVariant();
    }

    if (role == Qt::DisplayRole || role == Qt::EditRole) {
        switch (column) {
            case 0://name
                return QVariant(con->profile.name);
            case 1://server
//                qDebug() << "server" << QVariant(con->profile.serverAddress);
                return QVariant(con->profile.serverAddress);
            case 2://status
                return con->isRunning() ? QVariant(QObject::tr("Connected"))
                                        : QVariant(tr("Disconnected"));
            case 3://latency
                if (role == Qt::DisplayRole) {
                    return QVariant(convertLatencyToString(con->profile.latency));
                } else {
                    return QVariant(QString::number(con->profile.latency));
                }
            case 4://local port
//                qDebug() << "local port " << QVariant(con->profile.localPort);
                return QVariant(QString::number(con->profile.localPort));
            case 5://data usage (term)
                if (role == Qt::DisplayRole) {
                    return QVariant(convertBytesToHumanReadable(con->profile.currentUsage));
                } else {
                    return QVariant(con->profile.currentUsage);
                }
            case 6://data usage (total)
                if (role == Qt::DisplayRole) {
                    return QVariant(convertBytesToHumanReadable(con->profile.totalUsage));
                } else {
                    return QVariant(con->profile.totalUsage);
                }
            case 7://reset date
                if (role == Qt::DisplayRole) {
                    return QVariant(con->profile.nextResetDate.toString(Qt::SystemLocaleShortDate));
                } else {
                    return QVariant(con->profile.nextResetDate);
                }
            case 8://last used
                if (role == Qt::DisplayRole) {
                    return QVariant(con->profile.lastTime.toString(Qt::SystemLocaleShortDate));
                } else {
                    return QVariant(con->profile.lastTime);
                }
            case 9:// server port
//                qDebug() << "server port" << QVariant(con->profile.serverPort);
                return QVariant(con->profile.serverPort);

            case 10:
//                qDebug() << "method" << QVariant(con->profile.method);
                return QVariant(con->profile.method.toLower());

            case 11:
//                qDebug() << "password" << QVariant(con->profile.password);
                return QVariant(con->profile.password);

            case 12:
//                qDebug() << "timeout" << QVariant(con->profile.timeout);
                return QVariant(con->profile.timeout);

            default:
                return QVariant();
        }
    } else if (role == Qt::FontRole) {
        QFont font;
        font.setBold(con->isRunning());
        return QVariant(font);
    }

    return QVariant();
}

QString ConnectionItem::convertLatencyToString(const int latency) {
    QString latencyStr;
    switch (latency) {
        case SQProfile::LATENCY_TIMEOUT:
            latencyStr = tr("Timeout");
            break;
        case SQProfile::LATENCY_ERROR:
            latencyStr = tr("Error");
            break;
        case SQProfile::LATENCY_UNKNOWN:
            latencyStr = tr("Unknown");
            break;
        default:
            if (latency >= 1000) {
                latencyStr = QString::number(static_cast<double>(latency) / 1000.0)
                             + QStringLiteral(" ") + tr("s");
            } else {
                latencyStr = QString::number(latency) + QStringLiteral(" ") + tr("ms");
            }
    }
    return latencyStr;
}

QString ConnectionItem::convertBytesToHumanReadable(quint64 quot) {
    int unitId = 0;
    quint64 rem = 0;
    for (; quot > 1024; ++unitId) {
        rem = quot % 1024;//the previous rem would be negligible
        quot /= 1024;
    }
    double output = static_cast<double>(quot)
                    + static_cast<double>(rem) / 1024.0;
    return QString("%1 %2").arg(output, 0, 'f', 2).arg(bytesUnits.at(unitId));
}

void ConnectionItem::testLatency() {
    con->latencyTest();
}

Connection *ConnectionItem::getConnection() {
    return con;
}

void ConnectionItem::onConnectionStateChanged(bool running) {
    if (running) {
        emit message(con->getName() + " " + tr("connected"));
    } else {
        emit message(con->getName() + " " + tr("disconnected"));
    }
}

void ConnectionItem::onConnectionPingFinished(const int latency) {
    if (latency == SQProfile::LATENCY_TIMEOUT) {
        emit message(con->getName() + " " + tr("timed out"));
    } else if (latency == SQProfile::LATENCY_ERROR) {
        emit message(con->getName() + " " + tr("latency test failed"));
    }
}

void ConnectionItem::onStartFailed() {
    emit message(tr("Failed to start") + " " + con->getName());
}

bool ConnectionItem::sameAs(ListItem *item) {
    return false;
}

void ConnectionItem::drawBackground(QRect rect, QPainter *painter, int index, bool isSelect) {
    // Init draw path.
    QPainterPath path;
    path.addRect(QRectF(rect));

    // Draw selected effect.
    if (isSelect) {
        painter->setOpacity(selectOpacity);
        painter->fillPath(path, QColor(selectLineColor));
    }
        // Draw background effect.
    else {
        // Use different opacity with item index.
        if (index % 2 == 0) {
            painter->setOpacity(evenLineOpacity);
            painter->fillPath(path, QColor(evenLineColor));
        } else {
            painter->setOpacity(oddLineOpacity);
            painter->fillPath(path, QColor(oddLineColor));
        }
    }

}

void ConnectionItem::drawForeground(QRect rect, QPainter *painter, int column, int index, bool isSelect) {

//    qDebug()<<column<<rect;
    // Init opacity and font size.
    painter->setOpacity(1);

    // Set font color with selected status.
    if (isSelect) {
        painter->setPen(QPen(QColor("#ffffff")));
    } else {
        painter->setPen(QPen(QColor(textColor)));
    }

    // Draw name.
    if (column == 0) {
        Util::setFontSize(*painter, 10);
        painter->drawPixmap(QRect(rect.x() + padding, rect.y() + (rect.height() - iconSize) / 2, iconSize, iconSize),
                            iconPixmap);

        displayName = con->getName();
        QString name = displayName;

        if (isSelect) {
            painter->setOpacity(1);
        } else {
            painter->setOpacity(textLeftOpacity);
        }

        int renderWidth = rect.width() - iconSize - padding * 3;
        QFont font = painter->font();
        QFontMetrics fm(font);
        QString renderName = fm.elidedText(name, Qt::ElideRight, renderWidth);
        painter->drawText(QRect(rect.x() + iconSize + padding * 2, rect.y(), renderWidth, rect.height()),
                          Qt::AlignLeft | Qt::AlignVCenter, renderName);
//        qDebug()<<renderName<<name;
        displayNameComplete = fm.width(name) <= renderWidth;
    }
        // Draw Server.
    else if (column == 1) {
        drawCell(rect, painter, isSelect, con->getProfile().serverAddress);

    }
        // Draw Status.
    else if (column == 2) {
        drawCell(rect, painter, isSelect, tr("unknown"));
    }
        // Draw Latency.
    else if (column == 3) {
        drawCell(rect, painter, isSelect, QString("%1").arg(con->getProfile().latency));
    } else if (column == 4) {
        drawCell(rect, painter, isSelect, QString::number(con->getProfile().localPort));
    } else if (column == 5) {
        drawCell(rect, painter, isSelect, QString::number(con->getProfile().currentUsage));
    } else if (column == 6) {
        drawCell(rect, painter, isSelect, QString::number(con->getProfile().totalUsage));
    } else if (column == 7) {
        drawCell(rect, painter, isSelect, con->getProfile().nextResetDate.toString());
    } else if (column == 8) {
        drawCell(rect, painter, isSelect, con->getProfile().lastTime.toString());
    }
}

void ConnectionItem::drawCell(const QRect &rect, QPainter *painter, bool isSelect, QString text) const {
    if (isSelect) {
        painter->setOpacity(1);
    } else {
        painter->setOpacity(textRightOpacity);
    }

    Util::setFontSize(*painter, 9);
    painter->drawText(QRect(rect.x(), rect.y(), rect.width() - textPadding, rect.height()),
                      Qt::AlignRight | Qt::AlignVCenter, text);
}

void ConnectionItem::changeTheme(QString theme) {
    initTheme();
}

void ConnectionItem::initTheme() {
    if (DThemeManager::instance()->theme() == "light") {
        evenLineColor = "#000000";
        evenLineOpacity = 0.02;

        oddLineColor = "#D8D8D8";
        oddLineOpacity = 0.02;

        selectLineColor = "#2CA7F8";
        selectOpacity = 1.0;

        textColor = "#303030";
        textLeftOpacity = 1.0;
        textRightOpacity = 0.8;
    } else {
        evenLineColor = "#D8D8D8";
        evenLineOpacity = 0.02;

        oddLineColor = "#000000";
        oddLineOpacity = 0.1;

        selectLineColor = "#006BBA";
        selectOpacity = 0.8;

        textColor = "#ffffff";
        textLeftOpacity = 0.6;
        textRightOpacity = 0.5;
    }
}

bool ConnectionItem::setData(const QModelIndex &index, const QVariant &value, int role) {
    if (role == Qt::DisplayRole || role == Qt::EditRole) {
//        qDebug()<<index;
        switch (index.column()) {
            case 0:
                con->profile.name = value.toString();
                break;
            case 1:
                con->profile.serverAddress = value.toString();
                break;
            case 4:
                con->profile.localPort = value.toInt();
                break;
            case 9:
                con->profile.serverPort = value.toInt();
                break;
            case 10:
                qDebug() << value;
                con->profile.method = value.toString();
                break;
            case 11:
                con->profile.password = value.toString();
                break;
            case 12:
                con->profile.timeout = value.toInt();
                break;
            default:
                break;
        }
    }
    return false;
}
