#include "serial.h"


Serial::Serial()
{
    sport=new QSerialPort(this);
    serialUI=new ui();
    SerialInit();
}

void Serial::SerialInit()
{
    sport->setParity(QSerialPort::NoParity);
    sport->setDataBits(QSerialPort::Data8);
    sport->setStopBits(QSerialPort::OneStop);
    sport->setBaudRate(QSerialPort::Baud115200);
    sport->setFlowControl(QSerialPort::NoFlowControl);
    connect(serialUI->getBtn2(),&QPushButton::clicked,this,&Serial::SyncEvent);
}

void Serial::SerialShow()
{
    serialUI->show();
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

    connect(sport,SIGNAL(readyRead()),this,SLOT(receiveInfo()));
    return 1;
}

void Serial::SyncEvent()
{
#ifdef DEBUG
    char SendHead=0xA0;
    //sport->write(&SendHead);
    Serial::sendInfo(&SendHead,1);
#endif

}

//接收单片机的数据
void Serial::receiveInfo()
{
    QByteArray info = sport->readAll();
    QByteArray hexData = info.toHex();
#ifdef DEBUG
    qDebug()<<hexData;
#endif

}
//向单片机发送数据

void Serial::convertStringToHex(const QString &str, QByteArray &byteData)
{
    int hexdata,lowhexdata;
    int hexdatalen = 0;
    int len = str.length();
    byteData.resize(len/2);
    char lstr,hstr;
    for(int i=0; i<len; )
    {
        //char lstr,
        hstr=str[i].toLatin1();
        if(hstr == ' ')
        {
            i++;
            continue;
        }
        i++;
        if(i >= len)
            break;
        lstr = str[i].toLatin1();
        hexdata = convertCharToHex(hstr);
        lowhexdata = convertCharToHex(lstr);
        if((hexdata == 16) || (lowhexdata == 16))
            break;
        else
            hexdata = hexdata*16+lowhexdata;
        i++;
        byteData[hexdatalen] = (char)hexdata;
        hexdatalen++;
    }
    byteData.resize(hexdatalen);
}

char Serial::convertCharToHex(char ch)
{
    /*
        0x30等于十进制的48，48也是0的ASCII值，，
        1-9的ASCII值是49-57，，所以某一个值－0x30，，
        就是将字符0-9转换为0-9

    */
    if((ch >= '0') && (ch <= '9'))
        return ch-0x30;
    else if((ch >= 'A') && (ch <= 'F'))
        return ch-'A'+10;
    else if((ch >= 'a') && (ch <= 'f'))
        return ch-'a'+10;
    else return (-1);
}


//向单片机发送数据
void Serial::sendInfo(char* info,int len)
{

    for(int i=0; i<len; ++i)
    {
        printf("0x%x\n", info[i]);
    }
    sport->write(info,len);
}

void Serial::sendInfo(const QString &info)
{

    QByteArray sendBuf;
    qDebug()<<"Write to serial: "<<info;
    convertStringToHex(info, sendBuf); //把QString 转换 为 hex

    sport->write(sendBuf);

}
