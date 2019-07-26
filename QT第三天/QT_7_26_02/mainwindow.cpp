#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //通过ui寻找控件
    //ui->actionnew->setIcon(QIcon("C:/Users/董晨辉/Pictures/Saved Pictures/TIM图片20190704230405.jpg")); //添加图片
    //但是本地资源却不能够被共享，也就是路径下不一定有你所有的东西，所以要添加资源文件，到项目中
    //使用资源文件": + 前缀名+文件名"
    ui->actionnew->setIcon(QIcon(":/picture/untitled.png"));
    ui->actionOpen->setIcon(QIcon(":/picture/TIM图片20190704230405.jpg"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
