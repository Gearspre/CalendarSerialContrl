#include "serial.h"

Serial::Serial()
{
    sport=new QSerialPort(this);
    Serial_Init();
}

void Serial::Serial_Init()
{
    sport->setParity(QSerialPort::NoParity);
    sport->setDataBits(QSerialPort::Data8);
    sport->setStopBits(QSerialPort::OneStop);
    sport->setBaudRate(QSerialPort::Baud115200);
    sport->setFlowControl(QSerialPort::NoFlowControl);
}

int Serial::AutoChoseSerial()
{
    if(sport->isOpen())
    {
        sport->clear();
        sport->close();
    }

    foreach(const QSerialPortInfo &info,QSerialPortInfo::availablePorts())
    {
        if((info.description().indexOf("CH340") != -1))//Chose last CH340
        {
#ifdef DEBUG
        qDebug()<<info.description();
        qDebug()<<info.portName();
#endif
            portName=info.portName();
            sport->setPortName(portName);
            sport->setPort(info);
        }
    }

    if(!sport->open(QIODevice::ReadWrite))
    {
#ifdef DEBUG
        qDebug()<<portName<<":Open failed!";
        return -1;
#endif
    }

    connect(sport,SIGNAL(readyRead()),this,SLOT(Echo()));
    return 1;
}

void Serial::Echo()
{
    QByteArray info =sport->readAll();
    //qDebug()<<"aaa";
    qDebug()<<info;
}


