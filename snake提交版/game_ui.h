#ifndef GAME_UI_H
#define GAME_UI_H

#include <QWidget>
#include<QKeyEvent>
#include<QPaintEvent>
#include<QTimer>


#include "gameover.h"
#include "game.h"

namespace Ui {
class Game_ui;
}

class Game_ui : public QWidget
{
    Q_OBJECT

public:
    explicit Game_ui(QWidget *parent = nullptr,Game* _game = nullptr,gameover* _over = nullptr);
    ~Game_ui();

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

    bool stop = false;//暂停状态,空格控制
public:
    Game* game;
    gameover* over;
    QTimer* timer;

private slots:
    void timeout();

    void on_return_main_clicked();

signals:
    void return_main();//像主界面发送信息


private:
    Ui::Game_ui *ui;
};

#endif // GAME_UI_H
