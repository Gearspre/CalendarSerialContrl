#include "serial.h"

Serial::Serial()
{

}

void Serial::Serial_Init()
{
    sport.setParity(QSerialPort::NoParity);
    sport.setDataBits(QSerialPort::Data8);
    sport.setStopBits(QSerialPort::OneStop);
}

void Serial::getSerialPortName()
{
    foreach(const QSerialPortInfo &info,QSerialPortInfo::availablePorts())
    {
        serialPortName<<info.portName();
        qDebug()<<info.description();
        qDebug()<<info.portName();
    }
}
