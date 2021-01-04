#ifndef SERIAL_H
#define SERIAL_H
#include <QSerialPort>
#include <QObject>
#include <QSerialPortInfo>
#include <QDebug>

class Serial
{
public:
    Serial();
    void Serial_Init();
    void getSerialPortName();
private:
    QSerialPort sport;
    QStringList serialPortName;
};

#endif // SERIAL_H
