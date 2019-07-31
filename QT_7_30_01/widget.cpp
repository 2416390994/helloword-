#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //点击移动按钮移动图片
    pox = 10;

    connect(ui->pushButton,&QPushButton::clicked,[=](){
        pox +=10;
        //手动调用绘图事件
        update();
    });



}

Widget::~Widget()
{
    delete ui;

}
//绘图事件
void Widget::paintEvent(QPaintEvent *)
{
    //创建画家
    QPainter painter(this);//指定当前窗口作为绘图设备
    if(pox > this->width())
    {
        pox = 10;
    }
//    //设置笔的颜色
//    QPen pen(QColor(255,0,0));
//    //设置笔的宽度
//    pen.setWidth(4);
//    //画家拿起这支笔
//    painter.setPen(pen);
//    //画刷填充颜色
//    QBrush brush(Qt::cyan);
//    //让画家使用画刷
//    painter.setBrush(brush);
//    //利用画家画画
//    painter.drawLine(QPoint(0,0),QPoint(100,100));  //画线
//    //画圆
//    painter.drawEllipse(QPoint(100,100),50,50);//指定圆心和半径
//    //画矩形
//    painter.drawRect(QRect(10,10,50,50));   //看帮助文档
//    //画字体
//    painter.drawText(QRect(10,200,100,50),"好好学习");    //看帮助文档

//    //高级设置
//    painter.drawEllipse(QPoint(100,100),50,50);
//    //设置抗锯齿，画的细，效率就低了
//    painter.setRenderHint(QPainter::Antialiasing);    //给第二个圆设置抗锯齿能力，两个圆用来比较
//    painter.drawEllipse(QPoint(200,100),50,50);
//    //画个矩形
//    painter.drawRect(QRect(20,20,50,50));
//    //移动画家
//    painter.translate(QPoint(100,100));
//    //保存画家的状态
//    painter.save();
//    painter.drawRect(QRect(100,20,50,50));
//    painter.translate(QPoint(100,100));
//    //取出画家的状态
//    painter.restore();
//    painter.drawRect(QRect(100,20,50,50));

    //画图片,首先你要添加图片
    painter.drawPixmap(pox,100,QPixmap(":/picture/untitled.png"));


}
