#include "snake.h"

Snake::Snake(char _dir, int _x, int _y)
{
    x = _x;
    y = _y;
    dir = _dir;
}
int Snake::get_score(int k)
{
    return k;
}
IcsSnake::IcsSnake(char _dir, int _x, int _y) :Snake(_dir, _x, _y)
{
}
int IcsSnake::get_score(int k)
{
    return 2 * k;
}
ChengSnake::ChengSnake(char _dir, int _x, int _y) :Snake(_dir, _x, _y)
{
}
int ChengSnake::get_score(int k)
{
    if (k > 0)return k;
    return 0;
}
