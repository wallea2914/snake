#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QKeyEvent>
#include<QPaintEvent>
#include<QTimer>

#include "shop.h"
#include "rank.h"
#include "gameover.h"
#include "game.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

public:
    void drawPix();//画图
    void keyPressEvent(QKeyEvent *);//重载键盘事件
    void paintEvent(QPaintEvent *);//重载绘图事件

private:
    QPixmap *pix;//双缓冲机制画图
    QImage image_snake;//小图标：蛇、食物
    QImage image_food;
    QImage image_foodwa;
    QImage image_foodre;

    //界面的宽度和高度
    int w;
    int h;
    int step=50; //网格的大小/移动一次的长度

    QTimer* timer;

    shop* myshop;
    rank* myrank;
    gameover* myover;

    Game* game;

    bool stop = false;//暂停状态,空格控制


private slots:
    void timeout();

    void on_begin_clicked();

    void on_save_clicked();

    void on_shop_clicked();

    void on_rank_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
