#include "widget.h"
#include "ui_widget.h"
#include<QStringList>
#include<QMovie>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //点击按钮切换容器
    connect(ui->pushButton,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(0);
    });
    connect(ui->pushButton_2,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(1);
    });

    //下拉框
    QStringList * list = new QStringList;
    *list<<"拖拉机"<<"拉拖机"<<"机拉拖";
    ui->comboBox->addItems(*list);

    //第二种给下拉框增加选项的方式
    ui->comboBox->addItem("拉粪车");

    //点击按钮选择拖拉机，根据索引
    connect(ui->pushButton_3,&QPushButton::clicked,[=](){
        ui->comboBox->setCurrentIndex(2);
    });
    //第二种根据文本选择
    connect(ui->pushButton_8,&QPushButton::clicked,[=](){
        ui->comboBox->setCurrentText("拉粪车");
        });

    //利用QLable显示图片
    ui->label->setPixmap(QPixmap(":/picture/untitled.png"));

    //利用QLable增加动图
    QMovie * css = new QMovie(":/picture/7d9998a560fa873689bc53b483ebb261[1].gif");
    ui->label_2->setMovie(css);
    //还要播放git图片
    css->start();
}

Widget::~Widget()
{
    delete ui;
}
