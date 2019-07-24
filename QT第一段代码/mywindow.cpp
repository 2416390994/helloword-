#include "mywindow.h"
#include<QPushButton>
#include"mybutton.h"
#include<QDebug>
MyWindow::MyWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //按钮
    QPushButton * btn = new QPushButton;
    //btn->show();//show用的是顶层的方法弹出，如果想在mywidget窗口中弹出，就需要依赖mywidget

    btn->setParent(this);//设置父亲
    btn->setText("德玛西亚");  //设置文字，将char*隐式类型转换成Qstring
    btn->resize(100,50);
    //创建按钮的第二种方法
    QPushButton * btn2 = new QPushButton("第二按钮",this);
    //重置窗口大小
    this->resize(600,400);
    //移动按钮
    btn2->move(500,0);
    btn2->resize(100,100);
    //重置窗口标题
    setWindowTitle("大吉大利，今晚吃鸡");
    //设置固定窗口大小，不允许缩放

    setFixedSize(600,400);
    //一定程度下QT会自动释放创建的内存
    //创建自己的按钮
    MyButton* myBtn = new MyButton;
    myBtn->setText("我的按钮");
    myBtn->move(200,200);
    myBtn->setParent(this);
    myBtn->resize(100,100);
    //点击mybtn关闭掉窗口
    //参数1信号的发送者，参数2发送的信号,参数3信号的接收者，参数四处理的槽函数
    connect(myBtn,&MyButton::clicked,this,&QWidget::close);

}

MyWindow::~MyWindow()
{
    qDebug()<<"MyWidegt析构了";
}
