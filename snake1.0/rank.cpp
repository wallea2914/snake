#include "rank.h"
#include "ui_rank.h"

rank::rank(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::rank)
{
    ui->setupUi(this);
}

rank::~rank()
{
    delete ui;
}
