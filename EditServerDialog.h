#ifndef EDITSERVERDIALOG_H
#define EDITSERVERDIALOG_H

#include <QDialog>
#include <QListWidget>
#include <profile.h>

using QSS::Profile;
namespace Ui {
class EditServerDialog;
}
class ServerItem:public QListWidgetItem{
public:
    ServerItem(const Profile &profile, QString remarks=QString("new server"), QListWidget *view= nullptr, int type=Type);

public:
    Profile profile;
};

class EditServerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditServerDialog(bool isNew= false, QWidget *parent= nullptr);
    ~EditServerDialog();

private slots:
    void on_addPushButton_clicked();
    void onListWidgetChange();
    void on_removePushButton_clicked();

    void on_copyPushButton_clicked();

    void on_upPushButton_clicked();

    void on_downPushButton_clicked();

private:
    Ui::EditServerDialog *ui;
    /**
     * 从配置文件读取数据，并展示在界面上
     */
    void initConfig();
    /**
     * 本地端口号，所有服务器共用一个端口号
     */
    int localPort;
    QList<ServerItem*> serverItemList;
    void updateListWidget();
    void setFormEnabled(bool flag);
};

#endif // EDITSERVERDIALOG_H
