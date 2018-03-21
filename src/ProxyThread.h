#ifndef PROXYTHREAD_H
#define PROXYTHREAD_H

#include "stdafx.h"

class ProxyThread : public QThread {
public:
    ProxyThread(QSS::Controller *controller);

    // QThread interface
protected:
    void run() override;

private:
    QSS::Controller *controller;
};

#endif // PROXYTHREAD_H
