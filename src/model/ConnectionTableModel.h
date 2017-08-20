//
// Created by pikachu on 17-8-19.
//

#ifndef SHADOWSOCKS_CLIENT_CONNECTIONTABLEMODEL_H
#define SHADOWSOCKS_CLIENT_CONNECTIONTABLEMODEL_H

#include "common/common.h"
#include "ConnectionItem.h"

class ConnectionTableModel : public QAbstractTableModel {
Q_OBJECT

public:
    explicit ConnectionTableModel(QObject *parent = nullptr);

    ~ConnectionTableModel();

    ConnectionItem *getItem(const int &row) const;

    const QList<ConnectionItem *> &getItems() const;

    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) Q_DECL_OVERRIDE;

    bool move(int row, int target, const QModelIndex &parent = QModelIndex());

    bool appendConnection(Connection *con, const QModelIndex &parent = QModelIndex());

    void disconnectConnectionsAt(const QString &addr, quint16 port);

    bool setData(const QModelIndex &index, const QVariant &value, int role) override;

public slots:

    void testAllLatency();

signals:

    void message(const QString &);

    void rowStatusChanged(int row, bool running);

private:
    QList<ConnectionItem *> items;


private slots:

    void onConnectionStateChanged(bool running);

    void onConnectionLatencyChanged();
};


#endif //SHADOWSOCKS_CLIENT_CONNECTIONTABLEMODEL_H
