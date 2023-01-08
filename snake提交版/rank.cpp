#include "rank.h"
#include "ui_rank.h"
#include "mainwindow.h"
#include <QPainter>
#include <QIcon>
rank::rank(QWidget *parent, MainWindow* a) :
    QWidget(parent),
    ui(new Ui::rank)
{
    ui->setupUi(this);
    mainwindow = a;
    ui->first->setNum(mainwindow->mygameui->game->rank_first);
    ui->second->setNum(mainwindow->mygameui->game->rank_second);
    ui->third->setNum(mainwindow->mygameui->game->rank_third);
    setFixedSize(600,800);
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

rank::~rank()
{
    delete ui;
}

void rank::on_return_main_clicked()
{
    emit return_main();
    this->close();
}

