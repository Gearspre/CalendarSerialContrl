#include "ui.h"
#include "serial.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Serial calSerail;
    calSerail.AutoChoseSerial();
    calSerail.SerialShow();

    return a.exec();
}
