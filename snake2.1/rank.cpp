#include "rank.h"
#include "ui_rank.h"
#include "widget.h"
#include <QPainter>
#include <QIcon>
rank::rank(QWidget *parent, Widget* a) :
    QWidget(parent),
    ui(new Ui::rank)
{
    ui->setupUi(this);
    mainwindow = a;
    ui->first->setNum(mainwindow->game->rank_first);
    ui->second->setNum(mainwindow->game->rank_second);
    ui->third->setNum(mainwindow->game->rank_third);
    setFixedSize(450,400);
    setWindowIcon(QIcon(":/image/shop.png"));
    setWindowTitle("排行榜");//设置窗口标题
}
void rank::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/image/littlewhitecloud.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}
void rank::on_goback_clicked()
{
    close();
}
rank::~rank()
{
    delete ui;
}
