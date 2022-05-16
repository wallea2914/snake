#ifndef FOOD_H
#define FOOD_H

#include<vector>
class Snake;

class Food
{
private:

public:
    Food(int _x, int _y);
    static int score_cur;
    int x;
    int y;
    virtual void effect(std::vector<Snake>& snakes);
    virtual ~Food();
};

#endif // FOOD_H
