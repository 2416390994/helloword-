#include "smallwidget.h"
#include "ui_smallwidget.h"

SmallWidget::SmallWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SmallWidget)
{
    ui->setupUi(this);
    //QSpinBox移动Slider跟着移动
    void(QSpinBox:: * signal)(int) = &QSpinBox::valueChanged;//这里我们使用了函数指针因为我们发现第二个函数信号发生了函数重载，也就是说我们必须使用指定参数的函数，所以我们这里使用了函数指针来指定重载的函数
    connect(ui->spinBox,signal,ui->horizontalSlider,&QSlider::setValue);//我感觉学Qt一定要先学会看手册，手册太难看了，要疯了
    //上面只是实现了QSpinBox移动Slider跟着移动，接着连接信号和槽使Slide移动QSpinBox跟着移动
    connect(ui->horizontalSlider,&QSlider::valueChanged,ui->spinBox,&QSpinBox::setValue);
}

SmallWidget::~SmallWidget()
{
    delete ui;
}
void SmallWidget::setValue(int v)
{
    ui->spinBox->setValue(v);
}
int SmallWidget::getValue()
{
    return ui->spinBox->value();
}
