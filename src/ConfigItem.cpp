#include "ConfigItem.h"
#include "GuiConfig.h"
#include "utils.h"

DWIDGET_USE_NAMESPACE

using namespace Utils;

ConfigItem::ConfigItem(QJsonObject o) {

    initTheme();

    connect(DThemeManager::instance(), &DThemeManager::themeChanged, this, &ConfigItem::changeTheme);

    config = o;
    iconSize = 24;

    padding = 14;
    textPadding = 5;
    config = o;
    texts << getName() << getServer() << getStatus() << getLatency() << getLocalPort() << getTermUsage()
          << getTotalUsage() << getResetDate() << getLastUsed();
//    qDebug()<<texts;
}

bool ConfigItem::sameAs(DSimpleListItem *item) {
    auto id = getId();
    auto other_id = (static_cast<ConfigItem *>(item))->getId();
//    qDebug()<<"compare id"<<id<<other_id;
    return id == other_id;
}

void ConfigItem::drawBackground(QRect rect, QPainter *painter, int index, bool isSelect, bool) {
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

void ConfigItem::drawCell(bool isSelect, QRect rect, QPainter *painter, QString text) {
    if (isSelect) {
        painter->setOpacity(1);
    } else {
        painter->setOpacity(textRightOpacity);
    }

    setFontSize(*painter, 9);
    painter->drawText(QRect(rect.x(), rect.y(), rect.width() - textPadding, rect.height()),
                      Qt::AlignRight | Qt::AlignVCenter, text);
}

void ConfigItem::drawForeground(QRect rect, QPainter *painter, int column, int, bool isSelect, bool) {
    // Init opacity and font size.
    painter->setOpacity(1);

    // Set font color with selected status.
    if (isSelect) {
        painter->setPen(QPen(QColor("#ffffff")));
    } else {
        painter->setPen(QPen(QColor(textColor)));
    }
    // Draw name
    if (column == 0) {
        setFontSize(*painter, 10);
        QString name = getName();
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

    }
        // Draw server
    else if (column < texts.size()) {
        QString text = texts.at(column);
//        qDebug()<<text<<column<<texts.size()<<isSelect<<rect<<painter;
        drawCell(isSelect, rect, painter, text);

    } else {
        qCritical() << "index out of range";
    }

}

bool ConfigItem::search(const DSimpleListItem *item, QString searchContent) {
    const auto *t = static_cast<const ConfigItem *>(item);
    QString content = searchContent.toLower();

    return t->getName().toLower().contains(content) || t->getServer().toLower().contains(content);
}

bool ConfigItem::sortByName(const DSimpleListItem *item1, const DSimpleListItem *item2, bool descendingSort) {
    // Init.
    QString name1 = (static_cast<const ConfigItem *>(item1))->getName();
    QString name2 = (static_cast<const ConfigItem *>(item2))->getName();
    bool sortOrder;

    // Sort item with cpu if name is same.
    if (name1 == name2) {
        sortOrder = sortByServer(item1, item2, descendingSort);
    }
        // Otherwise sort by name.
    else {
        QCollator qco(QLocale::system());
        int result = qco.compare(name1, name2);

        sortOrder = result < 0;
    }

    return descendingSort ? sortOrder : !sortOrder;
}

bool ConfigItem::sortByServer(const DSimpleListItem *item1, const DSimpleListItem *item2, bool descendingSort) {
    QString server1 = (static_cast<const ConfigItem *>(item1))->getServer();
    QString server2 = (static_cast<const ConfigItem *>(item2))->getServer();
    bool sortOrder;
    if (server1 == server2) {
        sortOrder = sortByTotalUsager(item1, item2, descendingSort);
    } else {
        QCollator qco(QLocale::system());
        int result = qco.compare(server1, server2);

        sortOrder = result < 0;
    }
    return descendingSort ? sortOrder : !sortOrder;
}

bool ConfigItem::sortByTotalUsager(const DSimpleListItem *item1, const DSimpleListItem *item2, bool descendingSort) {
    int n1 = (static_cast<const ConfigItem *>(item1))->getTotalUsage().toInt();
    int n2 = (static_cast<const ConfigItem *>(item2))->getTotalUsage().toInt();
    bool sortOrder;
    sortOrder = n1 < n2;
    return descendingSort ? sortOrder : !sortOrder;
}

QString ConfigItem::getId() {
    auto ret = config.isEmpty();
    if(ret){
        config = GuiConfig::instance()->createConfig();
    }
    auto sid = config.value("id").toString();
    ret = config.value("id").toString().isNull();
    if(ret){
        GuiConfig::instance()->calId(config);
    }
    return config.value("id").toString();
}

QString ConfigItem::getName() const {
    return config.value("remarks").toString();
}

QString ConfigItem::getServer() const {
    return config.value("server").toString();
}

QString ConfigItem::getStatus() {
    if (GuiConfig::instance()->get("enabled").toBool()) {
        auto id = config.value("id").toString();
        if (id == GuiConfig::instance()->getCurrentId()) {
            return tr("connected");
        }
    }
    return tr("unconnect");
}

QString ConfigItem::getLatency() {
    return tr("unsupport");
}

QString ConfigItem::getLocalPort() {
    return QString::number(config.value("local_port").toInt());
}

QString ConfigItem::getTermUsage() {
    return Utils::formatByteCount(config.value("term_usage").toInt());
}

QString ConfigItem::getTotalUsage() const {
    return Utils::formatByteCount(config.value("total_usage").toInt());
}

QString ConfigItem::getResetDate() {
    return config.value("reset_date").toString();
}

QString ConfigItem::getLastUsed() {
    return config.value("last_used").toString();
}

void ConfigItem::changeTheme(QString) {
    initTheme();
}

void ConfigItem::initTheme() {
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
