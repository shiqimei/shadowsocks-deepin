/********************************************************************************
** Form generated from reading UI file 'ProxyDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROXYDIALOG_H
#define UI_PROXYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProxyDialog
{
public:
    QDialogButtonBox *buttonBox;
    QCheckBox *checkBox;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label;
    QComboBox *comboBoxProxyType;
    QLabel *label_3;
    QLineEdit *lineEditTimeout;
    QLabel *label_2;
    QLineEdit *lineEditProxyAddr;
    QLabel *label_4;
    QLineEdit *lineEditProxyPort;

    void setupUi(QDialog *ProxyDialog)
    {
        if (ProxyDialog->objectName().isEmpty())
            ProxyDialog->setObjectName(QStringLiteral("ProxyDialog"));
        ProxyDialog->resize(440, 220);
        buttonBox = new QDialogButtonBox(ProxyDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(240, 170, 181, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        checkBox = new QCheckBox(ProxyDialog);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(30, 20, 84, 23));
        widget = new QWidget(ProxyDialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(30, 70, 392, 68));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        comboBoxProxyType = new QComboBox(widget);
        comboBoxProxyType->setObjectName(QStringLiteral("comboBoxProxyType"));

        gridLayout->addWidget(comboBoxProxyType, 0, 1, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 0, 2, 1, 1);

        lineEditTimeout = new QLineEdit(widget);
        lineEditTimeout->setObjectName(QStringLiteral("lineEditTimeout"));

        gridLayout->addWidget(lineEditTimeout, 0, 3, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineEditProxyAddr = new QLineEdit(widget);
        lineEditProxyAddr->setObjectName(QStringLiteral("lineEditProxyAddr"));

        gridLayout->addWidget(lineEditProxyAddr, 1, 1, 1, 1);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 1, 2, 1, 1);

        lineEditProxyPort = new QLineEdit(widget);
        lineEditProxyPort->setObjectName(QStringLiteral("lineEditProxyPort"));

        gridLayout->addWidget(lineEditProxyPort, 1, 3, 1, 1);


        retranslateUi(ProxyDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ProxyDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ProxyDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ProxyDialog);
    } // setupUi

    void retranslateUi(QDialog *ProxyDialog)
    {
        ProxyDialog->setWindowTitle(QApplication::translate("ProxyDialog", "Dialog", 0));
        checkBox->setText(QApplication::translate("ProxyDialog", "Use Proxy", 0));
        label->setText(QApplication::translate("ProxyDialog", "Proxy Type", 0));
        comboBoxProxyType->clear();
        comboBoxProxyType->insertItems(0, QStringList()
         << QApplication::translate("ProxyDialog", "HTTP", 0)
         << QApplication::translate("ProxyDialog", "SOCKS5", 0)
        );
        label_3->setText(QApplication::translate("ProxyDialog", "Timeout(Sec)", 0));
        label_2->setText(QApplication::translate("ProxyDialog", "Proxy Addr", 0));
        label_4->setText(QApplication::translate("ProxyDialog", "Proxy Port", 0));
    } // retranslateUi

};

namespace Ui {
    class ProxyDialog: public Ui_ProxyDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROXYDIALOG_H
