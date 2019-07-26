#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setFixedSize(400,300);
    setWindowTitle("用户登陆");
}

Widget::~Widget()
{
    delete ui;
}
