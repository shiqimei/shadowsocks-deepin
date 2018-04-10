#ifndef SHAREDIALOG_H
#define SHAREDIALOG_H
#include "stdafx.h"
#include "widget/QRWidget.h"
#include "widget/SingleListView.h"

class ShareDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ShareDialog(QWidget *parent = 0);
    virtual ~ShareDialog();
    void closeEvent(QCloseEvent *);
private slots:
    void onItemSelected();
    void onSaveQRCodeImage();
private:
    SingleListView* listView;
    QRWidget* qrWidget;
    QLabel* uriLabel;
    QPlainTextEdit* uriText;
    QPushButton* saveButton;

    QString currentURI;

    void setCurrentURI(QString uri);
};

#endif // SHAREDIALOG_H
