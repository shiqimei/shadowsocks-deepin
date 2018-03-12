#ifndef SSVALIDATOR_H
#define SSVALIDATOR_H
#include <QString>
#include <QStringList>

class SSValidator
{
public:
    static bool validate(QString input);
    static bool validatePort(const QString &port);
    static bool validateMethod(const QString &method);

    /*
     * Return supported encryption method list at run-time
     * To avoid repetitive query, please store return result as static.
     */
    static QStringList supportedMethodList();
};

#endif // SSVALIDATOR_H
