#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QCloseEvent>
#include"game_ui.h"
#include"rank.h"
#include"shop.h"
#include"gameover.h"
#include"choose_snake.h"
#include"game.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    Game_ui* mygameui;//游戏界面
    shop* myshop;//商城界面
    rank* myrank;//排行界面
    gameover* myover;//游戏结束界面
    choose_snake* mysnake;//选蛇界面
    Game* game;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void reshow();
    void paintEvent(QPaintEvent *);
    void show_game();//打开游戏界面，主界面与游戏界面中间隔了一个选蛇界面
    void closeEvent(QCloseEvent* );//重写窗口关闭事件，就算从右上角退出也会正常保存文件

private slots:
    void on_start_clicked();//先打开的是选蛇界面

    void on_shop_clicked();

    void on_rank_clicked();

    void on_exit_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
