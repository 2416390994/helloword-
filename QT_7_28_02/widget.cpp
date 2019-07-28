#include "widget.h"
#include "ui_widget.h"
#include<QTimerEvent>
#include<QTimer>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //启动定时器
    id1 = startTimer(1000);//每一千毫秒调用一下timerEnvent事件
    id2 = startTimer(2000);


    //定时器第二种方法
    QTimer * timer1 = new QTimer(this);
    timer1->start(5);//5毫秒发送一个信号
    connect(timer1,&QTimer::timeout,[=](){
        static int num = 0;
        ui->label_4->setText(QString::number(num++));

    });
    //通过按钮控制开始和暂停
    connect(ui->pushButton,&QPushButton::clicked,[=](){

        timer1->stop();
    });
    connect(ui->pushButton_2,&QPushButton::clicked,[=](){

        timer1->start();
    });

}

Widget::~Widget()
{
    delete ui;
}
//实现定时器
void Widget::timerEvent(QTimerEvent *e)
{
    if(e->timerId() == id1)
    {
        static int num = 0 ;
        ui->label_2->setText(QString::number(num++));
    }else
    {
        static int num2 = 0;
        ui->label_3->setText(QString::number(num2++));
    }
}
