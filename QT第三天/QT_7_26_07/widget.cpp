#include "widget.h"
#include "ui_widget.h"
#include<QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //QTableWidegt控件使用
    //告诉控件一共有多少列
    QStringList list;
    list<<"姓名"<<"性别"<<"年龄";
    ui->tableWidget->setColumnCount(list.size());
    //设置水平方向的头
    ui->tableWidget->setHorizontalHeaderLabels(list);


     //准备数据
    QStringList namelist;
    namelist<<"李白"<<"安琪拉"<<"东皇太一"<<"小旋风"<<"李旭";
    //设置行数
    ui->tableWidget->setRowCount(namelist.size());
    //设置正文
    //ui->tableWidget->setItem(0,0,QTableWidgetItem("亚瑟"));
    //准备性别
    QStringList sexlist;
    sexlist<<"男"<<"女"<<"男"<<"女"<<"男";
    //准备年龄
    QStringList nianling;
    nianling<<"20"<<"22"<<"44"<<"60"<<"5";
    //使用循环添加信息
    for(int i = 0;i < 5;i++)
    {
        int col = 0;
        ui->tableWidget->setItem(i,col++,new QTableWidgetItem(namelist[i]));

        //添加性别
        ui->tableWidget->setItem(i,col++,new QTableWidgetItem(sexlist[i]));
        //添加年龄
        ui->tableWidget->setItem(i,col++,new QTableWidgetItem(nianling[i]));
        //int 转 string
        //QString::number(int);

    }
    //点击按钮添加信息
    connect(ui->btn1,&QPushButton::clicked,[=](){
       //先判断有没有赵云，有的话就不添加了
        bool ifempty = ui->tableWidget->findItems("赵云",Qt::MatchExactly).empty();
        if(ifempty)
        {
            ui->tableWidget->insertRow(0);  //这一行做的是插入操作，没有这一行的话就是替换操作
            ui->tableWidget->setItem(0,0,new QTableWidgetItem("赵云"));
            ui->tableWidget->setItem(0,1,new QTableWidgetItem("男"));
            ui->tableWidget->setItem(0,2,new QTableWidgetItem("28"));
        }
        else  //打印警告信息
        {
            QMessageBox::warning(this,"警告","已经添加过了");
        }

    //点击按钮删除赵云
        connect(ui->btn2,&QPushButton::clicked,[=](){
            bool ifempty = ui->tableWidget->findItems("赵云",Qt::MatchExactly).empty();
            if(ifempty)
            {
                QMessageBox::warning(this,"警告","已经删除过了");
            }
            else
            {
                //找到所要删除的行
                int row = ui->tableWidget->findItems("赵云",Qt::MatchExactly).first()->row();
                //ui->tableWidget->findItems("赵云",Qt::MatchExactly)返回一个链表
                //.first()从链表中找第一个出现赵云的位置
                //->row();返回其所在行
                //按行删除
                ui->tableWidget->removeRow(row);
            }

        });

    });

}

Widget::~Widget()
{
    delete ui;
}
