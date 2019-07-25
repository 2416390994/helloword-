#ifndef TEACHER_H
#define TEACHER_H

#include <QObject>

class Teacher : public QObject
{
    Q_OBJECT
public:
    explicit Teacher(QObject *parent = 0);

signals:
    //自定义的信号需要写到singnals下面
    //返回值类型必须是void
    //信号只需要声明不需要实现
    //信号可以有参数，可以发送重载
    void hungry();
    void hungry(QString foodname);  //有参

public slots:
};

#endif // TEACHER_H
