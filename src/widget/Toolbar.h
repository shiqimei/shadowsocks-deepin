//
// Created by pikachu on 17-8-19.
//

#ifndef SHADOWSOCKS_CLIENT_TOOLBAR_H
#define SHADOWSOCKS_CLIENT_TOOLBAR_H


#include <common/common.h>
#include <dsearchedit.h>
DWIDGET_USE_NAMESPACE
class Toolbar : public QWidget {
Q_OBJECT

public:
    explicit Toolbar(QWidget *parent = 0);

    ~Toolbar() override;

    bool eventFilter(QObject *, QEvent *event) override;

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


#endif //SHADOWSOCKS_CLIENT_TOOLBAR_H
