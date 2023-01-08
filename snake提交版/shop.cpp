#include "shop.h"
#include "ui_shop.h"
#include "game.h"
#include "not_enough.h"
#include <QAction>
#include <QPushButton>
#include <QPainter>
#include <QIcon>
#include <QLabel>
#include<QMediaPlayer>
shop::shop(QWidget *parent,Game *_game) :
    QWidget(parent),
    ui(new Ui::shop)
{
    game=_game;
    ui->setupUi(this);
    ui->coinshave->setNum(game->coins);
    setFixedSize(600,800);
    setWindowIcon(QIcon(":/image/shop.png"));
    setWindowTitle("商城");//设置窗口标题
    my_enough =new not_enough(nullptr);
    if(game->has_a==true)
    {
        ui->buymoon->setDisabled(true);
        ui->buymoon->setText("已购买");
    }
    if(game->has_b==true)
    {
        ui->buysun->setDisabled(true);
        ui->buysun->setText("已购买");
    }
}
//背景图
void shop::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/image/shopbackground.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}
void shop::buya()
{
    if(game->coins<200)
    {
        my_enough->show();
        return;
    }
    else
    {
        game->coins-=200;
        game->has_a=true;
        ui->buymoon->setDisabled(true);
        ui->buymoon->setText("已购买");
    }
    return;
}
void shop::buyb()
{
    if(game->coins<100)
    {
        my_enough->show();
        return;
    }
    else
    {
        game->coins-=100;
        game->has_b=true;
        ui->buysun->setDisabled(true);
        ui->buysun->setText("已购买");
    }
    return;
}
shop::~shop()
{
    delete ui;
}

void shop::on_close_shop_clicked()
{
    emit return_main();
    this->close();
}


void shop::on_buymoon_clicked()
{
    QMediaPlayer *startSound = new QMediaPlayer;
    startSound->setMedia(QUrl("qrc:/music/buy.mp3"));
    startSound->setVolume(50);
    startSound->play();
    buya();
    return;
}

void shop::on_buysun_clicked()
{
    QMediaPlayer *startSound = new QMediaPlayer;
    startSound->setMedia(QUrl("qrc:/music/buy.mp3"));
    startSound->setVolume(50);
    startSound->play();
    buyb();
    return;
}
