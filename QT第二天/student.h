#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>

class Student : public QObject
{
    Q_OBJECT
public:
    explicit Student(QObject *parent = 0);

signals:

public slots:
    //自定义槽函数的的地方
    //高版本可以写到public下或者全局函数
    //槽函数返回值void
    //槽函数既需要声明也需要实现
    //槽函数可以有参数也可以发生重载
    void treat();
    void treat(QString foodname);//有参

};

#endif // STUDENT_H
