#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <QMainWindow>


class MyWindow : public QMainWindow
{
    Q_OBJECT

public:
    MyWindow(QWidget *parent = 0);
    ~MyWindow();
};

#endif // MYWINDOW_H
