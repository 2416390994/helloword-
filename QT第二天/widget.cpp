#include "widget.h"
//需求，创建两个类，Teacher类 Student类
//下课后老师发送一个信号饿了，由学生响应信号，处理信号的槽函数 请客吃饭
#include<QPushButton>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{

    zt = new Teacher(this);
    st = new Student(this);
    //连接老师和学生
    //connect(zt,&Teacher::hungry,st,&Student::treat);  //连接的是无参函数
    //调用下课函数，因为老师不能一直处于饥饿状态必须是下课之后老师才会发送饥饿的信号，在classover有发送信号的关键字
    //void (Teacher::*ww)(QString) = &Teacher::hungry;   //首先定义两个函数指针来指向有参的函数，因为connect连接到的时候要发生重载 但是无法指定参数，所以我们在外面就先确定好函数地址
    //void (Student::*ss)(QString) = &Student::treat;
    //connect(zt,ww,st,ss);
    //classover();

    //不能一运行就下课，设置一个按钮，按下按钮才下课
   QPushButton * btn = new QPushButton("下课",this);
   this->resize(600,400);
   //btn->resize(100,100);
   btn->move(500,0);
   //void (Teacher::*ww)(void) = &Teacher::hungry;
   //void (Student::*ss)(void) = &Student::treat;
   //connect(btn,&QPushButton::clicked,zt,ww);     //信号连接信号，按钮连接老师的饥饿信号，
   //connect(zt,ww,st,ss);//饥饿信号触发之后然后学生的槽函数就会给予响应
   //disconnect(zt,ww,st,ss);    //断开连接，断开信号和槽
   void(Widget::*clas)(void) = &Widget::classover;
   void (Student::*sse)(QString) = &Student::treat;
   void (Teacher::*wwe)(QString) = &Teacher::hungry;
   connect(btn,&QPushButton::clicked,this,clas);
   connect(btn,&QPushButton::clicked,this,&Widget::close);
   connect(zt,wwe,st,sse);
}
void Widget::classover()
{
    //触发老师饿了的信号
    //老师饿了的信号属于自定义的信号，出发自定义信号的关键字emit
    //emit zt->hungry();//激发函数,//进行有参的时候就不能调用无参的函数了
    emit zt->hungry("豆角茄子");  //但是为啥传参是在这个时候

}
Widget::~Widget()
{

}
