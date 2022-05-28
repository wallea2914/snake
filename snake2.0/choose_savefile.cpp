#include "choose_savefile.h"
#include "ui_choose_savefile.h"

choose_savefile::choose_savefile(QWidget *parent, Widget* a) :
    QWidget(parent),
    ui(new Ui::choose_savefile)
{
    ui->setupUi(this);
    mainwindow = a;
}

choose_savefile::~choose_savefile()
{
    delete ui;
}




void choose_savefile::on_continue_2_clicked()
{
    mainwindow->game->read_game_file();
    mainwindow->timer->start(1000);
    close();
}



void choose_savefile::on_newgame_clicked()
{
    mainwindow->game->init_game();
    mainwindow->game->is_saved = false;
    mainwindow->timer->start(1000);
    close();
}

