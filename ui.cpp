#include "ui.h"

ui::ui()
{
    ui_Init();
    resize(300,400);
}

void ui::ui_Init()
{
    combox = new QComboBox();
    combox->addItem("Apple");
    combox->addItem("Pear");

    btn1 = new QPushButton();
    //btn1->setMinimumSize(100,50);
    btn1->setText("Open");

    btn2 = new QPushButton();
    //btn2->setMinimumSize(100,50);
    btn2->setText("Sync");

    vlayout = new QVBoxLayout();
    vlayout->addStretch();
    //vlayout->setSpacing(3);
    vlayout->addWidget(btn1);
    vlayout->addWidget(btn2);
    vlayout->addWidget(combox);

    setLayout(vlayout);
    //setMinimumSize(300,400);
}
