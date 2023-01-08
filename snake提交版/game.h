#ifndef GAME_H
#define GAME_H

#include<vector>
#include<string>
#include<deque>
class Food;
class Snake;
class Game
{
private:
    //本地文件名字
    std::string filename;
public:
    //商城信息
    bool has_a = false;//程蛇        //设为true测试
    bool has_b = false;//ics蛇
    bool has_c = false;
    bool has_d = false;
    bool has_e = false;


    Game();
    Food* food = nullptr;
    Food* food2 = nullptr;
    int snake_num = 1;//测试

    int food_index = 1;//判定生成什么食物
    static int speed;//1000ms刷新

    std::vector<Snake> snakes;

    //金币
    int coins = 0;

    //积分排行榜
    int rank_first = -1;
    int rank_second = -1;
    int rank_third = -1;

    int scores = 0;

    void generate_food();
    void snake_eat_food();
    bool gameover();
    void add_scores(int num);
    void init_game();
    void read_file();
    //void read_game_file();//读游戏存档
    void write_file();
    void save_game();//存档
    void update_coins();//每局游戏结束依据分数更新金币
};

#endif // GAME_H
