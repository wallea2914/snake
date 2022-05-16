#include "game.h"
#include "food.h"
#include "snake.h"
#include "gameover.h"

#include <QTime>
#include <QtGlobal>

#include <QRandomGenerator>


Game::Game()
{
    for(int i = 0;i < snake_num;i++)
    {
        Snake tmp('d',0,0);
        snakes.push_back(tmp);
    }
    food = new Food(10,10);
}

void Game::generate_food()
{
    int tmp_x = 0;
    int tmp_y = 0;
    while(1)
    {
        tmp_x = QRandomGenerator::global()->bounded( 0, 10);
        tmp_y = QRandomGenerator::global()->bounded( 0, 10);

        bool flag = true;
        for(int i = 0;i < snake_num;i++)
        {
            if(snakes[i].x == tmp_x && snakes[i].y == tmp_y)
            {
                flag = false;
            }
        }
        if(flag)
            break;
    }

    food = new Food(tmp_x, tmp_y);
}
void Game::snake_eat_food()
{
    if(food)
    {
        if(snakes[0].x == food->x && snakes[0].y == food->y)
        {
            add_scores(Food::score_cur);
            food->effect(snakes);
            snake_num = snakes.size();
            delete food;
            food = nullptr;
            generate_food();
        }
    }
}
void Game::pause()
{

}
bool Game::gameover()
{
    for(int i = 0;i < snake_num;i++)//出边界，这里还没有写wall类，暂且代替
    {
        if(snakes[i].x < 0 || snakes[i].x > 12 || snakes[i].y < 0 || snakes[i].y > 12)
        {
            class gameover* myover = new class gameover(nullptr, scores);
            myover->show();
            return true;
        }
    }
    for(int i = 0;i < snake_num;i++)//自己咬自己
    {
        for(int j = i + 1;j < snake_num;j++)
        {
            if(snakes[i].x == snakes[j].x && snakes[i].y == snakes[j].y)
            {

            }
        }
    }
    return false;
}
void Game::snake_move()
{

}
void Game::add_scores(int num)
{
    scores += num;
}
