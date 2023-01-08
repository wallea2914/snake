#include "gameover.h"
#include "ui_gameover.h"
#include <QPainter>
gameover::gameover(QWidget *parent, int final_scores) :
    QWidget(parent),
    ui(new Ui::gameover)
{
    ui->setupUi(this);
    ui->label_2->setNum(final_scores);
    setFixedSize(450,400);
    setWindowTitle("Game Over");
}
void gameover::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/image/gameover.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}
/*
void gameover::on_overback_clicked()
{
    close();
}
*/
gameover::~gameover()
{
    delete ui;
}

/*
void gameover::on_return_2_clicked()
{
    close();
}
*/


void gameover::on_return_main_clicked()
{
    emit return_main();
    close();
}

