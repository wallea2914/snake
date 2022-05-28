#include "shop.h"
#include "ui_shop.h"

shop::shop(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::shop)
{
    ui->setupUi(this);

    setWindowTitle("商城");//设置窗口标题
}

shop::~shop()
{
    delete ui;
}
