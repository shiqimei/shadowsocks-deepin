#ifndef PROCESSVIEW_H
#define PROCESSVIEW_H

#include <DSimpleListView>

DWIDGET_USE_NAMESPACE

class ProxyView : public DSimpleListView {
Q_OBJECT

public:
    ProxyView(QList<bool> columnHideFlags);

public slots:

    void changeTheme(QString theme);

    void initTheme();

    // QWidget interface
protected:
    void contextMenuEvent(QContextMenuEvent *event) override;
signals:
    void rightClickBlank();
};

#endif
