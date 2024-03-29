#include "food.h"
#include "game.h"
#include "snake.h"
#include<deque>
#include<vector>

int Food::score_cur = 0;

Food::Food(int _x, int _y)
{
    score_cur++;
    x = _x;
    y = _y;
}

void Food::effect(std::vector<Snake>& snakes)
{
    char dir = snakes[snakes.size() - 1].dir;
    int x = snakes[snakes.size() - 1].x;
    int y = snakes[snakes.size() - 1].y;

    if(dir == 'w')
    {
        y += 1;
    }
    else if(dir == 'a')
    {
        x += 1;
    }
    else if(dir == 's')
    {
        y -= 1;
    }
    else
    {
        x -= 1;
    }
    Snake tmp(dir,x,y);
    snakes.push_back(tmp);
}

int Food::get_score()
{
    return Food::score_cur;
}
Food::~Food()
{

}




int Foodwa::score_cur = 0;
Foodwa::Foodwa(int _x, int _y):Food(_x,_y)
{
    Food::score_cur--;
    Foodwa::score_cur--;
    type = 'b';
}
int Foodwa::get_score()
{
    return Foodwa::score_cur;
}
void Foodwa::effect(std::vector<Snake>& snakes)
{
    snakes.pop_back();
}
Foodwa::~Foodwa()
{

}



Foodre::Foodre(int _x, int _y):Food(_x,_y)
{
    type = 'c';
}
void Foodre::effect(std::vector<Snake>& snakes)
{
    Game::speed = Game::speed * 0.9;
    if(Game::speed < 500)//收敛至500即可
        Game::speed = 500;

}
Foodre::~Foodre()
{

}
