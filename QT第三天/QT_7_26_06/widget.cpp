#include "widget.h"
#include "ui_widget.h"
#include <QTreeWidgetItem>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{

    ui->setupUi(this);
    //添加头
    ui->treeWidget->setHeaderLabels(QStringList()<<"英雄姓名"<<"英雄介绍");
    //添加项目
    QTreeWidgetItem * list1 = new QTreeWidgetItem(QStringList()<<"力量");
    ui->treeWidget->addTopLevelItem(list1);
    QTreeWidgetItem * list2 = new QTreeWidgetItem(QStringList()<<"敏捷");
    ui->treeWidget->addTopLevelItem(list2);
    QTreeWidgetItem * list3 = new QTreeWidgetItem(QStringList()<<"智力");
    ui->treeWidget->addTopLevelItem(list3);
    //追加子项目
    QStringList hero1;
    QStringList hero2;
    QStringList hero3;
    QStringList hero4;
    QStringList hero5;
    QStringList hero6;
    hero1<<"刚被猪"<<"前排坦克，能在吸收伤害的同时造成客观的范围输出";
    hero2<<"船长"<<"前排坦克，能肉能输出能控场的全能英雄";
    hero3<<"月骑"<<"中排物理输出，可以使用分裂利刃攻击多个目标";
    hero4<<"小鱼人"<<"前排战士，擅长偷取敌人的属性来增加自身的战斗力";
    hero5<<"死灵法师"<<"前排法师坦克，魔法抗性较高，拥有治疗技能";
    hero6<<"巫医"<<"后排辅助法师，可以使用奇特的巫术诅咒敌人与治疗队友";
    QTreeWidgetItem * li1 = new QTreeWidgetItem(hero1);
    list1->addChild(li1);
    QTreeWidgetItem * li2 = new QTreeWidgetItem(hero2);
    list1->addChild(li2);
    QTreeWidgetItem * li3 = new QTreeWidgetItem(hero3);
    list2->addChild(li3);
    QTreeWidgetItem * li4 = new QTreeWidgetItem(hero4);
    list2->addChild(li4);
    QTreeWidgetItem * li5 = new QTreeWidgetItem(hero5);
    list3->addChild(li5);
    QTreeWidgetItem * li6 = new QTreeWidgetItem(hero6);
    list3->addChild(li6);
}

Widget::~Widget()
{
    delete ui;
}
