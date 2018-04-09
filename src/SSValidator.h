/**
 * Copyright (C) 2017 ~ 2018 PikachuHy
 *
 * Author:     PikachuHy <pikachuhy@163.com>
 * Maintainer: PikachuHy <pikachuhy@163.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

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
