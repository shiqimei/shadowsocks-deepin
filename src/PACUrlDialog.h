#ifndef PACURLDIALOG_H
#define PACURLDIALOG_H

#include <QDialog>

namespace Ui {
    class PACUrlDialog;
}

class PACUrlDialog : public QDialog {
Q_OBJECT

public:
    explicit PACUrlDialog(QWidget *parent = 0);

    ~PACUrlDialog();

private:
    Ui::PACUrlDialog *ui;
};

#endif // PACURLDIALOG_H
