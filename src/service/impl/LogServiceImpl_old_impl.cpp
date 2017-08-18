//
// Created by pikachu on 17-8-18.
//

#include "LogServiceImpl_old_impl.h"

void LogServiceImpl_old_impl::showLog() {
    showLogWidget.show();
}

void LogServiceImpl_old_impl::setVerboseLogging(bool b) {

}

LogServiceImpl_old_impl::LogServiceImpl_old_impl(QObject *parent) : LogService(parent) {}
