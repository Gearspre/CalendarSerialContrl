#ifndef SERIAL_H
#define SERIAL_H
#define DEBUG 1
#include <QSerialPort>
#include <QObject>
#include <QSerialPortInfo>
#include <QDebug>
#include <QElapsedTimer>
#include <QString>
#include "ui.h"


#define HEAD 0XA0
#define TAIL 0XA1

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
    int AutoChoseSerial();
private:
    QSerialPort *sport;
    QString portName;
    ui* serialUI;
private slots:
    void SyncEvent();
    void receiveInfo();
};

#endif // SERIAL_H
