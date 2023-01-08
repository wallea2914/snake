#ifndef SNAKE_H
#define SNAKE_H


class Snake
{
public:
    int x;
    int y;
    char dir;

    Snake(char _dir, int _x, int _y);
    virtual int get_score(int k);

};
class ChengSnake :public Snake
{
public:

    ChengSnake(char _dir, int _x, int _y);
    virtual int get_score(int k);
};
class IcsSnake :public Snake
{
public:
    IcsSnake(char _dir, int _x, int _y);
    virtual int get_score(int k);
};

#endif // SNAKE_H
