#include "shop.h"
#include "ui_shop.h"
#include <QAction>
#include <QPushButton>
#include <QPainter>
#include <QIcon>
#include <QLabel>
shop::shop(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::shop)
{
    ui->setupUi(this);

    setFixedSize(450,400);
    setWindowIcon(QIcon(":/image/shop.png"));
    setWindowTitle("商城");//设置窗口标题
}
//背景图
void shop::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/image/shopbackground.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}
void shop::on_closeshop_clicked()
{
    close();
}
shop::~shop()
{
    delete ui;
}
