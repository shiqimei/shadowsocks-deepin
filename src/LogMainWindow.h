#ifndef LOGMAINWINDOW_H
#define LOGMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class LogMainWindow;
}

class LogMainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit LogMainWindow(QWidget *parent = 0);

    ~LogMainWindow();

private:
    Ui::LogMainWindow *ui;
};

#endif // LOGMAINWINDOW_H
