//
// Created by pikachu on 17-8-6.
//

#ifndef SHADOWSOCKS_CLIENT_POSITIVEAGENTWIDGET_H
#define SHADOWSOCKS_CLIENT_POSITIVEAGENTWIDGET_H

#include <QObject>
#include <QDialog>
#include <QPushButton>
#include <QLineEdit>
#include <QSpinBox>
#include <QComboBox>
#include <QCheckBox>
class PositiveAgentWidget : public QDialog{
public:
    PositiveAgentWidget(QWidget *parent = nullptr);

private:
    QCheckBox* checkBoxUseProxy;
    QComboBox* comboBoxProxyType;
    QLineEdit* lineEditProxyServer;
    QSpinBox* spinBoxProxyPort;
    QSpinBox* spinBoxProxyTimeout;
    QPushButton* pushButtonConfirm;
    QPushButton* pushButtonCancel;
};


#endif //SHADOWSOCKS_CLIENT_POSITIVEAGENTWIDGET_H
