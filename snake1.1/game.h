#ifndef GAME_H
#define GAME_H

#include<vector>
class Food;
class Snake;
class Game
{
private:
    //本次游戏的信息
    int scores = 0;

public:
    Game();
    Food* food = nullptr;
    int snake_num = 1;//测试

    int food_index = 1;//判定生成什么食物
    static int speed;//1000ms刷新

    std::vector<Snake> snakes;

    void generate_food();
    void snake_eat_food();
    void pause();
    bool gameover();
    void add_scores(int num);
    void snake_move();
    void init_game();
};

#endif // GAME_H
