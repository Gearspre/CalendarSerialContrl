#ifndef SERIAL_H
#define SERIAL_H

#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include <QString>
#include <QTime>
#include <QDateTime>
#include <QTimer>
#include <QEventLoop>
#include "ui.h"

#define DEBUG
#define HEAD 0XA0
#define TAIL 0XA1
#define ATIME 0XB0
#define DELAY_TIME 50


class Serial :public QObject
{
    Q_OBJECT
public:
    Serial();
    void SerialInit();
    void SerialShow();
    void convertStringToHex(const QString &str, QByteArray &byteData);
    char convertCharToHex(char ch);
    void sendInfo(char* info,int len);
    void sendInfo(const QString &info);
    void Delay_MSec(unsigned int msec);
    int AutoChoseSerial();
private:
    QSerialPort *sport;
    QString portName;
    ui* serialUI;
private slots:
    void SyncEvent();
    void SendEvent();
    void receiveInfo();
};

#endif // SERIAL_H
