#ifndef SHAREDIALOG_H
#define SHAREDIALOG_H

#include <QDialog>

namespace Ui {
class ShareDialog;
}

class ShareDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ShareDialog(QWidget *parent = 0);
    ~ShareDialog();

private slots:
    void on_listWidget_currentRowChanged(int currentRow);

private:
    Ui::ShareDialog *ui;
};

#endif // SHAREDIALOG_H
