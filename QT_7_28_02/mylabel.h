#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>

class MyLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MyLabel(QWidget *parent = 0);
//鼠标进入
void enterEvent(QEvent *);
//鼠标离开
void leaveEvent(QEvent *);
//鼠标按下
void mousePressEvent(QMouseEvent *ev);
//
void mouseReleaseEvent(QMouseEvent *ev);
//鼠标拖动
void mouseMoveEvent(QMouseEvent *ev);
};

#endif // MYLABEL_H
