#include "widget.h"
#include "ui_widget.h"
#include<QDebug>
#include<QListWidgetItem>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //默认选中，我们默认选中单选按钮性别中的男
    ui->man->setChecked(true);
    //点击女的就打印一行话
    connect(ui->woman,&QRadioButton::clicked,[](){
        qDebug()<<"新年快乐";
    });
    //在多选框进行监听选中状况,选中就打印1
    connect(ui->checkBox_3,&QCheckBox::clicked,[](){
    qDebug()<<"1";
    });
    //另外一种有关监听的独特的用法，选中就打印2，未选中就打印0
    connect(ui->checkBox_3,&QCheckBox::stateChanged,[](int val){
    qDebug()<<val;
    });

    //利用listwidget写诗
    QListWidgetItem * item = new QListWidgetItem("锄禾日当午");
    //使诗默认排版在中间,设置对齐方式,可以去帮助文档查看
    item->setTextAlignment(Qt::AlignHCenter);

    ui->listWidget->addItem(item);
    //第二种添加文字的方式
    //一次性添加很多，利用list容器，但是无法设置剧中
    QStringList list;
    list<<"锄禾日当午"<<"汗滴禾下土"<<"谁之盘中餐"<<"粒粒皆辛苦";
    ui->listWidget->addItems(list);

}

Widget::~Widget()
{
    delete ui;
}
