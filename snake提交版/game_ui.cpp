#include "game_ui.h"
#include "ui_game_ui.h"
#include"gameover.h"
#include "shop.h"
#include "snake.h"
#include "food.h"
#include "game.h"
#include "ui_gameover.h"

#include<QMediaPlayer>
#include<QPainter>
#include<QTimer>

Game_ui::Game_ui(QWidget *parent, Game* _game, gameover* _over)
    : QWidget(parent)
    , ui(new Ui::Game_ui)
{
    ui->setupUi(this);
    //ui->begin->setAutoDefault(false);
    //this->setAttribute(Qt::WA_DeleteOnClose,1);//这里表示该窗口变量后默认删除所有该窗口变量


    setWindowTitle("贪吃蛇");//设置窗口标题
    setWindowIcon(QIcon(":/image/main.png"));
    setAutoFillBackground(true);//设置自动填充背景

    setFixedSize(900,600);

    w=size().width();//获取窗口宽度
    h=size().height();//获取窗口高度
    pix=new QPixmap(w * 2 / 3 ,h);
    pix->fill(Qt::yellow);//填充颜色
    image_snake.load(":/image/snake.png");//加载图片，蛇
    image_food.load(":/image/AC.png");//普通食物
    image_foodwa.load(":/image/WA.png");//wa食物
    image_foodre.load(":/image/RE.png");//re食物

    resize(900,600);//调整尺寸

    timer = new QTimer(this);//处理计时器
    connect(timer, SIGNAL(timeout()), this, SLOT(timeout()));

    //game = new Game();
    //大改，后面可以优化所有game，抛弃这个界面的game变量
    game = _game;
    over = _over;

    drawPix();
}

Game_ui::~Game_ui()
{
    delete ui;
}

void Game_ui::drawPix()
{
    pix->fill(Qt::yellow);//重新刷新pix颜色
    QPainter *painter=new QPainter;//创建一个QPainter对象
    QPen pen(Qt::DotLine);//创建QPen对象并设置画笔颜色（点线）
    for (int i=step;i<w * 2 / 3;i=i+step)
    {//按照步进值的间隔绘制纵向的网格线
        painter->begin(pix);
        painter->setPen(pen);
        painter->drawLine(QPoint(i,0),QPoint(i,h));
        painter->end();
    }
    for (int j=step;j<h;j=j+step)
    {//按照步进值的间隔绘制横向的网格线
        painter->begin(pix);
        painter->setPen(pen);
        painter->drawLine(QPoint(0,j),QPoint(w,j));
        painter->end();
    }

    //画蛇
    for(int i = 0;i < game->snake_num;i++)
    {

        painter->begin(pix);
        painter->drawImage(QPoint(game->snakes[i].x * step,game->snakes[i].y * step),image_snake);
        painter->end();
    }

    //画食物
    if(game->food != nullptr)
    {
        painter->begin(pix);
        if(game->food->type == 'a')
            painter->drawImage(QPoint(game->food->x * step,game->food->y * step),image_food);
        else if(game->food->type == 'b')
            painter->drawImage(QPoint(game->food->x * step,game->food->y * step),image_foodwa);
        else if(game->food->type == 'c')
            painter->drawImage(QPoint(game->food->x * step,game->food->y * step),image_foodre);

        painter->end();
    }
    if(game->food2 != nullptr)
    {
        painter->begin(pix);
        if(game->food2->type == 'a')
            painter->drawImage(QPoint(game->food2->x * step,game->food2->y * step),image_food);
        else if(game->food2->type == 'b')
            painter->drawImage(QPoint(game->food2->x * step,game->food2->y * step),image_foodwa);
        else if(game->food2->type == 'c')
            painter->drawImage(QPoint(game->food2->x * step,game->food2->y * step),image_foodre);

        painter->end();
    }


    //这里暂时将显示积分、金币写在这个函数里
    ui->coins->setNum(game->coins);
    ui->scores->setNum(game->scores);
}

//重载键盘按下事件
void Game_ui::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Z)
    {
        if(!stop)
        {
            stop = true;
            timer->stop();
        }
        else
        {
            stop = false;
            timer->start(game->speed);
        }
        return;
    }
    if(stop)
        return;
    //首先调节方向，蛇身
    for(int i = game->snake_num - 1;i > 0;i--)
    {
        game->snakes[i].dir = game->snakes[i - 1].dir;
        if(game->snakes[i].dir == 'w')
        {
            game->snakes[i].y=game->snakes[i].y-1;//上移
        }
        else if(game->snakes[i].dir == 'a')
        {
            game->snakes[i].x=game->snakes[i].x-1;//左移
        }
        else if(game->snakes[i].dir == 'd')
        {
            game->snakes[i].x=game->snakes[i].x+1;//右移
        }
        else
        {
            game->snakes[i].y=game->snakes[i].y+1;//下移
        }


    }
    //蛇头
    if(event->key()==Qt::Key_A)
    {
        game->snakes[0].x=(game->snakes[0].x-1<0)?game->snakes[0].x:game->snakes[0].x-1;//左移
        game->snakes[0].dir = 'a';
    }
    if(event->key()==Qt::Key_D)
    {
        game->snakes[0].x=(game->snakes[0].x+1+(image_snake.width()/step)>w)?game->snakes[0].x:game->snakes[0].x+1;//右移
        game->snakes[0].dir = 'd';
    }
    if(event->key()==Qt::Key_W)
    {
        game->snakes[0].y=(game->snakes[0].y-1<0)?game->snakes[0].y:game->snakes[0].y-1;//上移
        game->snakes[0].dir = 'w';
    }
    if(event->key()==Qt::Key_S)
    {
         game->snakes[0].y=(game->snakes[0].y+1+(image_snake.height() / step)>h)?game->snakes[0].y:game->snakes[0].y+1;//下移
         game->snakes[0].dir = 's';
    }

    game->snake_eat_food();
    if(game->gameover())
    {
        QMediaPlayer *startSound = new QMediaPlayer;
        startSound->setMedia(QUrl("qrc:/music/over.mp3"));
        startSound->setVolume(50);
        startSound->play();

        game->update_coins();
        timer->stop();
        over->ui->label_2->setNum(game->scores);
        over->show();
        game->init_game();
        this->hide();
        //game->update_coins();
    }
    drawPix();//根据调整后的图标位置重新在pix中绘制图像
    update();//更新界面
}

//重载绘图事件函数
void Game_ui::paintEvent(QPaintEvent *)
{
    QPainter painter;
    painter.begin(this);
    painter.drawPixmap(QPoint(0,0),*pix);
    painter.end();
}


//定时器
void Game_ui::timeout()
{
    if(stop)
        return;
    //首先调节方向，蛇身
    for(int i = game->snake_num - 1;i > 0;i--)
    {
        game->snakes[i].dir = game->snakes[i - 1].dir;
        if(game->snakes[i].dir == 'w')
        {
            game->snakes[i].y=game->snakes[i].y-1;//上移
        }
        else if(game->snakes[i].dir == 'a')
        {
            game->snakes[i].x=game->snakes[i].x-1;//左移
        }
        else if(game->snakes[i].dir == 'd')
        {
            game->snakes[i].x=game->snakes[i].x+1;//右移
        }
        else
        {
            game->snakes[i].y=game->snakes[i].y+1;//下移
        }
    }
    //蛇头
    if(game->snakes[0].dir == 'w')
    {
        game->snakes[0].y=game->snakes[0].y-1;//上移
    }
    else if(game->snakes[0].dir == 'a')
    {
        game->snakes[0].x=game->snakes[0].x-1;//左移
    }
    else if(game->snakes[0].dir == 'd')
    {
        game->snakes[0].x=game->snakes[0].x+1;//右移
    }
    else
    {
        game->snakes[0].y=game->snakes[0].y+1;//下移
    }
    game->snake_eat_food();
    timer->stop();
    timer->start(game->speed);//这里是为了改速度，或许可以优化方案
    if(game->gameover())
    {
        QMediaPlayer *startSound = new QMediaPlayer;
        startSound->setMedia(QUrl("qrc:/music/over.mp3"));
        startSound->setVolume(50);
        startSound->play();

        game->update_coins();
        timer->stop();
        over->ui->label_2->setNum(game->scores);
        over->show();
        game->init_game();

        this->hide();

        //game->update_coins();
    }
    drawPix();//根据调整后的图标位置重新在pix中绘制图像
    update();//更新界面
}



void Game_ui::on_return_main_clicked()
{
    emit return_main();
    timer->stop();
    game->init_game();
    this->close();
}

