#include "LogMainWindow.h"
#include "ui_LogMainWindow.h"

LogMainWindow::LogMainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::LogMainWindow) {
    ui->setupUi(this);
}

LogMainWindow::~LogMainWindow() {
    delete ui;
}
