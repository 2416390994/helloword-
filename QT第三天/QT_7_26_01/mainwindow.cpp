#include "mainwindow.h"
#include<QMenuBar>
#include<QToolBar>
#include<QLabel>
#include<QStatusBar>
#include<QDockWidget>
#include<QTextEdit>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->resize(600,400);
    //包含菜单栏，只能有一个
    QMenuBar * bar = menuBar();  //一般这里不接受返回值也可以创建成功只是之后要使用，这个东西来做一些操作必须借助其返回值，所以一般这里都是指定好返回值
    //将菜单栏放到窗口中
    this->setMenuBar(bar);//这里不写this也可以默认就在本窗口下
    //菜单栏没有东西则不显示
    QMenu *fileMenu = bar->addMenu("文件");
    QMenu *editMenu = bar->addMenu("编辑");
    //添加菜单项
    QAction * newAction1 = fileMenu->addAction("新建");
   //添加分割线,添加分割线要借助上一行的文件
    fileMenu->addSeparator();
    QAction * newAction2 = fileMenu->addAction("打开");
    QAction * newAction3 = fileMenu->addAction("属性");

    //添加工具栏，工具栏可以有多个
    QToolBar * toolBar = new QToolBar(this);//指定父亲
    addToolBar(Qt::LeftToolBarArea,toolBar);//Qt::LeftToolBarArea默认停靠范围，这个是靠左，其他的 可以通过查帮助文档晓得
    //只允许左右侧停靠
    toolBar->setAllowedAreas(Qt::LeftToolBarArea | Qt::RightToolBarArea);
    //设置不允许浮动,参数是布尔值，不让动就设置false
    toolBar->setFloatable(false);
    //设置移动(设置之后上面的设置都失效)
    toolBar->setMovable(false);
    //工具栏添加菜单项
    toolBar->addAction(newAction1);  //把新建添加到工具栏
    toolBar->addSeparator();//添加分割线
    toolBar->addAction(newAction2);  //把打开添加到工具栏

    //状态栏，只能有一个
    QStatusBar * stBar = statusBar();
    setStatusBar(stBar);//将状态栏放到当前窗口
    //
    QLabel * label1 = new QLabel("提示信息",this);
    stBar->addWidget(label1);//将提示信息放到状态栏位置
    QLabel * label2 = new QLabel("右侧提示信息",this);
    stBar->addPermanentWidget((label2));

    //铆接部件也叫浮动窗口
    QDockWidget * dock = new QDockWidget;
    //添加铆接部件到窗口中
    addDockWidget(Qt::BottomDockWidgetArea,dock);
    //api
    //设置停靠范围,默认是上下左右都可以停靠，设置完之后只有设置的位置可以停靠
    dock->setAllowedAreas(Qt::BottomDockWidgetArea | Qt::TopDockWidgetArea);


    //铆接部件会围着核心部件
    //文本编辑器，核心部件只能有一个
    QTextEdit *edit = new QTextEdit;
    setCentralWidget(edit);


}

MainWindow::~MainWindow()
{

}
