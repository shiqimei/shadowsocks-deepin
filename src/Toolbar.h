#ifndef TOOLBAR_H
#define TOOLBAR_H

#include "stdafx.h"

DWIDGET_USE_NAMESPACE

class Toolbar : public QWidget {
Q_OBJECT

public:
    Toolbar(QWidget *parent = 0);

    ~Toolbar();

    bool eventFilter(QObject *, QEvent *event);

public slots:

    void handleSearch();

    void handleSearchTextChanged();

    void focusInput();

signals:

    void search(QString searchContent);

    void pressEsc();

    void pressTab();

private:
    DSearchEdit *searchEdit;
    QString searchTextCache;
    QTimer *searchTimer;
};

#endif
