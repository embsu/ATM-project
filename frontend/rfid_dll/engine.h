
#ifndef ENGINE_H
#define ENGINE_H

#include <QDebug>
#include <QObject>
#include <QtSerialPort/QSerialPort>


class engine : public QObject
{
    Q_OBJECT

public:
    engine();


signals:
    void sendCardNumber(QString cardNumber);
    void requestCardNumberFromReader();
private slots:
    void readyToRead();
public slots:
    void openSerialPort();
private:
    QSerialPort port;
    void sendNumberToRFIDDLL(QString cardNumber);
};

#endif // ENGINE_H
