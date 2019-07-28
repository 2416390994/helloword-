#include "mylabel.h"
#include<QDebug>
#include<QMouseEvent>
MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{
    //设置鼠标的追踪
this->setMouseTracking(true);
}
void MyLabel::enterEvent(QEvent *)
{
    qDebug()<<"鼠标进入";

}

//鼠标离开
void MyLabel::leaveEvent(QEvent *)
{
    qDebug()<<"鼠标离开";

}
//鼠标按下
void MyLabel::mousePressEvent(QMouseEvent *ev)
{
    //如果鼠标按下的左键打印内容，右键不需要
    if(ev->button() == Qt::LeftButton)
    {
        //找鼠标按下的位置
        QString str = QString("鼠标按下了 x = %1 y = %2").arg(ev->x()).arg(ev->y());
        qDebug()<<str;
    }


}
//鼠标的释放
void MyLabel::mouseReleaseEvent(QMouseEvent *ev)
{
    qDebug()<<"鼠标释放";

}
//鼠标拖动
void MyLabel::mouseMoveEvent(QMouseEvent *ev)
{
    qDebug()<<"鼠标拖动 ";

}

