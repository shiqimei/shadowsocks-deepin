#ifndef QRCODECAPTURER_H
#define QRCODECAPTURER_H

#include <QMainWindow>

class QRCodeCapturer : public QMainWindow
{
    Q_OBJECT

public:
    explicit QRCodeCapturer(QWidget *parent = 0);
    ~QRCodeCapturer();

    static QString scanEntireScreen();

signals:
    void qrCodeFound(const QString &result);
    void closed();

protected slots:
    void moveEvent(QMoveEvent *e);
    void resizeEvent(QResizeEvent *e);
    void closeEvent(QCloseEvent *e);

private:
    void decodeCurrentRegion();
};

#endif // QRCODECAPTURER_H
