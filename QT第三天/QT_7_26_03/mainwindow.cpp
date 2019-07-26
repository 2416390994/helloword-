#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
#include<QDialog>
#include<QMessageBox>
#include<QColorDialog>
#include<QFileDialog>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    resize(600,400);
    ui->setupUi(this);
    //点击新建菜单项弹出对话框
    connect(ui->actionNew,QAction::triggered,this,[=](){
        //对话框有两种对对话框
        //模态对话框，非模态对话框
        //QDialog dlg(this);
        //dlg.resize(300,200);
        //启动模态对话框
        //dlg.exec();//阻塞
        //qDebug()<<"垃圾你好";

        //非模态对话框
        //QDialog dlg2(this);
        //QDialog * dlg2 = new QDialog(this);
        //dlg2->resize(300,200);
        //dlg2->show();

        //为了防止内存泄漏，设置属性
        //dlg2->setAttribute(Qt::WA_DeleteOnClose);//在点击对话框的叉子的时候，就把创建的内存释放

        //上面都是我们自定义的对话框，实际上系统还为我们创建了好多多对话框
        //使标准的对话框,因为是静态成员变量可以直接使用类来访问，也可以通过对象来访问但是没有必要
        //QMessageBox::critical(this,"错误","critical");//这个是最简单的三个参数的模态对话框
        //QMessageBox::information(this,"信息","information");
        //询问对话框,第四个参数属于询问，有很多默认选项可以从帮助手册中去查找，我们这里选择的是询问 ，保存还是取消,关于第五个参数是一个默认的选项，如果没有第五个参数那么，第四个参数谁在前谁就是默认选项，有了第五个参数，第五个参数肯定得是第四个参数中的其中一个就变成了默认的参数
        //QMessageBox::question(this,"问题","question",QMessageBox::Save | QMessageBox::Cancel,QMessageBox::Cancel);
        //参数1父亲，2标题，3提示内容4按键内省5.关联回车
//        if(QMessageBox::Save == QMessageBox::question(this,"问题","question",QMessageBox::Save | QMessageBox::Cancel,QMessageBox::Cancel))
//        {
//            qDebug()<<"保存";
//        }
//        else
//        {
//            qDebug()<<"取消";
//        }
        //QMessageBox::warning(this,"警告","waring");

        //QColor color =  QColorDialog::getColor(QColor(255,0,0));
        //可以通过返回值获取用户所选择的红，绿，蓝，的分量
        //qDebug()<<color.red()<<color.green()<<color.blue();

        //文件对话框QFileDialog,
        //QString path = QFileDialog::getOpenFileName(this,"打开文件","C:/Users/董晨辉/Pictures/Saved Pictures","(*.jpg)");//打开文件后会返回文件的路径
        //qDebug()<<path;

    });

}

MainWindow::~MainWindow()
{
    delete ui;
}
