#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"gameover.h"
#include"game_ui.h"
#include"shop.h"
#include"rank.h"
#include"game.h"
#include"choose_snake.h"
#include <QPainter>
#include<QCloseEvent>
#include<QMediaPlayer>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("贪吃蛇");//设置窗口标题
    setWindowIcon(QIcon(":/image/main.png"));
    setFixedSize(600,800);

    game = new Game();
    myover = new gameover();
    mygameui = new Game_ui(nullptr, game, myover);//大改
    myshop = new shop(nullptr,game);
    myrank = new rank(nullptr, this);//!!!这里注意构造函数
    mysnake = new choose_snake(nullptr, game);

    connect(myover,&gameover::return_main,this,&MainWindow::reshow);//！！切换主子界面的关键链接
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/image/main.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}
void MainWindow::closeEvent(QCloseEvent*)
{
    game->write_file();
    this->close();
}
MainWindow::~MainWindow()
{
    delete ui;
    //delete game;  //????为什么这里delete会报错
    delete mygameui;//何时删除
    delete myshop;
    delete myrank;
}


void MainWindow::on_start_clicked()
{
    this->hide();
    //mygameui = new Game_ui();
    delete mysnake;
    QMediaPlayer *startSound = new QMediaPlayer;
    startSound->setMedia(QUrl("qrc:/music/pushbutton.mp3"));
    startSound->setVolume(100);
    startSound->play();
    mysnake = new choose_snake(nullptr, game);
    connect(mysnake, &choose_snake::show_game,this,&MainWindow::show_game);
    connect(mysnake, &choose_snake::return_main,this,&MainWindow::reshow);
    mysnake->show();
}

void MainWindow::reshow()
{
    this->show();
}

void MainWindow::on_shop_clicked()
{
    this->hide();
    //myshop = new shop();
    QMediaPlayer *startSound = new QMediaPlayer;
    startSound->setMedia(QUrl("qrc:/music/pushbutton.mp3"));
    startSound->setVolume(100);
    startSound->play();
    /*
    delete myshop;
    myshop = new shop(nullptr, game);
    */
    connect(myshop,&shop::return_main,this,&MainWindow::reshow);//！！切换主子界面的关键链接
    myshop->show();
}



void MainWindow::on_rank_clicked()
{
    this->hide();
    //myrank = new rank();
    QMediaPlayer *startSound = new QMediaPlayer;
    startSound->setMedia(QUrl("qrc:/music/pushbutton.mp3"));
    startSound->setVolume(100);
    startSound->play();
    delete myrank;
    myrank = new rank(nullptr, this);
    connect(myrank,&rank::return_main,this,&MainWindow::reshow);//！！切换主子界面的关键链接
    myrank->show();
}

void MainWindow::on_exit_clicked()
{
    QMediaPlayer *startSound = new QMediaPlayer;
    startSound->setMedia(QUrl("qrc:/music/pushbutton.mp3"));
    startSound->setVolume(100);
    startSound->play();
    game->write_file();
    this->close();
}

void MainWindow::show_game()
{
    connect(mygameui,&Game_ui::return_main,this,&MainWindow::reshow);//打开游戏界面
    mygameui->show();
    mygameui->timer->start();
}
