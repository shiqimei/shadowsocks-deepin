//
// Created by pikachu on 18-4-10.
//

#ifndef DSIMPLELISTDEMO_SINGLELISTVIEW_H
#define DSIMPLELISTDEMO_SINGLELISTVIEW_H

#include <DSimpleListView>

DWIDGET_USE_NAMESPACE  // 这句话主要强调使用 dtkwidget 的命名空间，以使用其控件
class SingleListView : public DSimpleListView
{
    Q_OBJECT

public:
    SingleListView(QWidget *parent=0);
    virtual ~SingleListView();
public slots:

    void changeTheme(QString theme);

    void initTheme();
signals:
    void currentRowChanged(int currentRow);
private:
    int currentRow = -1;
};

#endif //DSIMPLELISTDEMO_SINGLELISTVIEW_H
