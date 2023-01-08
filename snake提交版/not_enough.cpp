#include "not_enough.h"
#include "ui_not_enough.h"
#include <QPainter>
not_enough::not_enough(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::not_enough)
{
    ui->setupUi(this);
    setWindowTitle("SORRYYYYYY");
    setFixedSize(300,400);
}

not_enough::~not_enough()
{
    delete ui;
}

void not_enough::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/image/joke.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}

void not_enough::on_earn_money_clicked()
{
    emit return_main();
    close();
}
