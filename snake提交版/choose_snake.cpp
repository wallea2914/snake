#include "choose_snake.h"
#include "ui_choose_snake.h"
#include"game.h"
#include"snake.h"
#include <QPushButton>
#include <QAction>
//选蛇界面
choose_snake::choose_snake(QWidget *parent, Game* _game) :
    QWidget(parent),
    ui(new Ui::choose_snake)
{
    ui->setupUi(this);
    setWindowTitle("贪吃蛇");//设置窗口标题
    setWindowIcon(QIcon(":/image/main.png"));

    setFixedSize(400,500);

    game = _game;

    ui->normal->setChecked(1);//设为默认选项

    if(!game->has_a)
    {
        ui->cheng->setEnabled(0);
    }
    if(!game->has_b)
    {
        ui->ics->setEnabled(0);
    }
}

choose_snake::~choose_snake()
{
    delete ui;
}

void choose_snake::on_showgame_clicked()
{
    emit show_game();
    if(ui->cheng->isChecked())
    {
        ChengSnake tmp('d',0,0);
        game->snakes[0] = tmp;
        //game->snakes.pop_front();
        //game->snakes.push_front((tmp));
    }
    if(ui->ics->isChecked())
    {
        IcsSnake tmp('d',0,0);
        game->snakes[0] = tmp;
        //game->snakes.pop_front();
        //game->snakes.push_front((tmp));
    }
    this->close();
}


void choose_snake::on_goback_clicked()
{
    emit return_main();
    this->close();
}
