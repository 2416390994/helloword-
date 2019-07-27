#include "widget.h"
#include "ui_widget.h"
#include<QDebug>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //点击设置到一半的位置
    connect(ui->set,&QPushButton::clicked,[=](){

        ui->widget->setValue(50);
    });
    //点击获取当前位置
    connect(ui->get,&QPushButton::clicked,[=](){

        int val = ui->widget->getValue();
        qDebug()<<val;
    });

}

Widget::~Widget()
{
    delete ui;
}
