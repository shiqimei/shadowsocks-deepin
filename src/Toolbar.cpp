#include "stdafx.h"
#include "Toolbar.h"
#include "utils.h"

using namespace Utils;

Toolbar::Toolbar(QWidget *parent) : QWidget(parent) {
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

Toolbar::~Toolbar() {
}

bool Toolbar::eventFilter(QObject *obj, QEvent *event) {
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

void Toolbar::handleSearch() {
    if (searchEdit->text() == searchTextCache) {
        search(searchTextCache);
    }
}

void Toolbar::handleSearchTextChanged() {
    searchTextCache = searchEdit->text();

    if (searchTimer->isActive()) {
        searchTimer->stop();
    }
    searchTimer->start(300);
}

void Toolbar::focusInput() {
    if (searchEdit->text() != "") {
        searchEdit->getLineEdit()->setFocus();
    } else {
        searchEdit->setFocus();
    }
}
