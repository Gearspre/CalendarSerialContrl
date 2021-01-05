#ifndef SERIAL_H
#define SERIAL_H
#define DEBUG 1
#include <QSerialPort>
#include <QObject>
#include <QSerialPortInfo>
#include <QDebug>

class Serial :public QObject
{
    Q_OBJECT
public:
    Serial();
    void Serial_Init();
    int AutoChoseSerial();
private:
    QSerialPort *sport;
    QString portName;
private slots:
    void Echo();
};

#endif // SERIAL_H
