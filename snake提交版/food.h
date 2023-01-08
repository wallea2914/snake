#ifndef FOOD_H
#define FOOD_H

#include<deque>
#include<vector>
class Snake;
class Game;
//普通食物
class Food
{
private:

public:
    Food(int _x, int _y);
    static int score_cur;
    int x;
    int y;
    char type = 'a';


    virtual void effect(std::vector<Snake>& snakes);
    virtual ~Food();

    virtual int get_score();
};


//wa食物
class Foodwa:public Food
{
private:

public:
    Foodwa(int _x, int _y);
    static int score_cur;
    virtual void effect(std::vector<Snake>& snakes);
    virtual int get_score();
    virtual ~Foodwa();
};


//re食物
class Foodre:public Food
{
public:
    Foodre (int _x, int _y);
    virtual void effect(std::vector<Snake>& snakes);
    virtual ~Foodre();
};

#endif // FOOD_H
