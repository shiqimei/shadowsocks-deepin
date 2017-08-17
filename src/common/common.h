//
// Created by pikachu on 17-8-9.
//

#ifndef SS_CLIENT_COMMON_H
#define SS_CLIENT_COMMON_H
#define NEW_ACTION(actionName,actionText,menu) \
QAction* actionName = new QAction(QStringLiteral(actionText),menu); \
actionName->setObjectName(#actionName); \
menu->addAction(actionName);
#include <QDebug>
#endif //SS_CLIENT_COMMON_H
