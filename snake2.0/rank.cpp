#include "rank.h"
#include "ui_rank.h"
#include "widget.h"
rank::rank(QWidget *parent, Widget* a) :
    QWidget(parent),
    ui(new Ui::rank)
{
    ui->setupUi(this);
    mainwindow = a;
    ui->first->setNum(mainwindow->game->rank_first);
    ui->second->setNum(mainwindow->game->rank_second);
    ui->third->setNum(mainwindow->game->rank_third);
}

rank::~rank()
{
    delete ui;
}
