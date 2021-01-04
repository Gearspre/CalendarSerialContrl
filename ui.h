#ifndef UI_H
#define UI_H

#include <QObject>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QComboBox>
class ui : public QWidget
{
    Q_OBJECT
public:
    ui();
    void ui_Init();
private:
    QVBoxLayout* vlayout;
    QPushButton* btn1;
    QPushButton* btn2;
    QComboBox* combox;
};

#endif // UI_H
