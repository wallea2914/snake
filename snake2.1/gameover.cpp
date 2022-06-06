#include "gameover.h"
#include "ui_gameover.h"

gameover::gameover(QWidget *parent, int final_scores) :
    QWidget(parent),
    ui(new Ui::gameover)
{
    ui->setupUi(this);
    ui->label_2->setNum(final_scores);
}

gameover::~gameover()
{
    delete ui;
}
