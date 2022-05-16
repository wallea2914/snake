#include "food.h"

#include "snake.h"
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

Food::~Food()
{

}
