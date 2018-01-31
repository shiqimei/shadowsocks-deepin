/* -*- Mode: C++; indent-tabs-mode: nil; tab-width: 4 -*-
 * -*- coding: utf-8 -*-
 *
 * Copyright (C) 2011 ~ 2017 Deepin, Inc.
 *               2011 ~ 2017 Wang Yong
 *
 * Author:     Wang Yong <wangyong@deepin.com>
 * Maintainer: Wang Yong <wangyong@deepin.com>
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
#include "stdafx.h"
#include "Toolbar.h"
#include "utils.h"

using namespace Utils;

Toolbar::Toolbar(QWidget *parent) : QWidget(parent)
{
    installEventFilter(this);   // add event filter
    setMouseTracking(true);    // make MouseMove can response

    setFixedHeight(24);

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);

    QPixmap iconPixmap = DHiDPIHelper::loadNxPixmap(Utils::getIconQrcPath("ssw24.svg"));
    QLabel *iconLabel = new QLabel();
    iconLabel->setPixmap(iconPixmap);

    searchEdit = new DSearchEdit();
    searchEdit->setFixedWidth(280);
    searchEdit->setPlaceHolder(tr("Search"));
    searchEdit->getLineEdit()->installEventFilter(this);
    
    layout->addWidget(iconLabel);
    layout->addSpacing(90);
    layout->addStretch();
    layout->addWidget(searchEdit, 0, Qt::AlignHCenter);
    layout->addStretch();

    searchTimer = new QTimer(this);
    searchTimer->setSingleShot(true);
    connect(searchTimer, &QTimer::timeout, this, &Toolbar::handleSearch);

    connect(searchEdit, &DSearchEdit::textChanged, this, &Toolbar::handleSearchTextChanged, Qt::QueuedConnection);
}

Toolbar::~Toolbar()
{
}

bool Toolbar::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::KeyPress) {
        if (obj == this) {
            QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
            if (keyEvent->key() == Qt::Key_Escape) {
                searchEdit->clear();
            
                pressEsc();
            } 
        } else if (obj == searchEdit->getLineEdit()) {
            QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
            if (keyEvent->key() == Qt::Key_Tab) {
                pressTab();
            } 
        }
    }

    return QObject::eventFilter(obj, event);
}

void Toolbar::handleSearch()
{
    if (searchEdit->text() == searchTextCache) {
        search(searchTextCache);
    }
}

void Toolbar::handleSearchTextChanged()
{
    searchTextCache = searchEdit->text();

    if (searchTimer->isActive()) {
        searchTimer->stop();
    }
    searchTimer->start(300);
}

void Toolbar::focusInput()
{
    if (searchEdit->text() != "") {
        searchEdit->getLineEdit()->setFocus();
    } else {
        searchEdit->setFocus();
    }
}
