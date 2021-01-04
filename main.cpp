#include "ui.h"
#include <QApplication>
#include "serial.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Serial calSerail;
    calSerail.getSerialPortName();
    ui MainUI;
    MainUI.show();
    return a.exec();
}
