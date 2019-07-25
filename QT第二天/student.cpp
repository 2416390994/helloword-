#include "student.h"
#include<QDebug>
Student::Student(QObject *parent) : QObject(parent)
{

}
void Student::treat()
{
    qDebug()<<"请老师吃饭";

}

void Student::treat(QString foodname)
{
    //请老师吃饭 老师要吃 "豆角茄子"
    //qDebug()<<"请老师吃饭"<<"老师要吃"<<foodname;   //foodname是QString类型，而<"请老师吃饭"<<"老师要吃"是char*类型，下面来一个类型转换
    qDebug()<<"请老师吃饭"<<"老师要吃"<<foodname.toUtf8().data();//结果：请老师吃饭 老师要吃 豆角茄子

}
