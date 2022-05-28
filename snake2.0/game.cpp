#include "game.h"
#include "food.h"
#include "snake.h"
#include "gameover.h"
#include<fstream>
using namespace std;


#include <QTime>
#include <QtGlobal>

#include <QRandomGenerator>

int Game::speed = 1000;

Game::Game()
{
    filename = "d:/snake_file.txt";
    read_file();
    init_game();
}

void Game::generate_food()
{
    int tmp_x = 0;
    int tmp_y = 0;
    int type = 0;
    //第一个
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

    //生成不同的食物
    type = QRandomGenerator::global()->bounded( 0, 100);
    if(type % 3 == 0)
        food = new Food(tmp_x, tmp_y);
    else if(type % 3 == 1)
        food = new Foodwa(tmp_x, tmp_y);
    else if(type % 3 == 2)
        food = new Foodre(tmp_x, tmp_y);
    //第二个
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
        if(tmp_x == food->x && tmp_y == food->y)
            flag = false;
        if(flag)
            break;
    }
    type = QRandomGenerator::global()->bounded( 0, 100);
    if(type % 3 == 0)
        food2 = new Food(tmp_x, tmp_y);
    else if(type % 3 == 1)
        food2 = new Foodwa(tmp_x, tmp_y);
    else if(type % 3 == 2)
        food2 = new Foodre(tmp_x, tmp_y);
}
void Game::snake_eat_food()
{
    if(food)
    {
        if(snakes[0].x == food->x && snakes[0].y == food->y)
        {
            add_scores(food->score_cur);
            food->effect(snakes);
            snake_num = snakes.size();
            delete food;
            food = nullptr;
            generate_food();
        }
        else if(snakes[0].x == food2->x && snakes[0].y == food2->y)
        {
            add_scores(food2->score_cur);
            food2->effect(snakes);
            snake_num = snakes.size();
            delete food2;
            food2 = nullptr;
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
            if(scores >= rank_first)
            {
                rank_third = rank_second;
                rank_second = rank_first;
                rank_first = scores;
            }
            else if(scores >= rank_second)
            {
                rank_third = rank_second;
                rank_second = scores;
            }
            else if(scores >= rank_third)
            {
                rank_third = scores;
            }
            update_coins();
            init_game();
            return true;
        }
    }
    for(int i = 0;i < snake_num;i++)//自己咬自己
    {
        for(int j = i + 1;j < snake_num;j++)
        {
            if(snakes[i].x == snakes[j].x && snakes[i].y == snakes[j].y)
            {
                class gameover* myover = new class gameover(nullptr, scores);
                myover->show();
                //更新排行榜
                if(scores >= rank_first)
                {
                    rank_third = rank_second;
                    rank_second = rank_first;
                    rank_first = scores;
                }
                else if(scores >= rank_second)
                {
                    rank_third = rank_second;
                    rank_second = scores;
                }
                else if(scores >= rank_third)
                {
                    rank_third = scores;
                }
                update_coins();
                init_game();
                return true;
            }
        }
    }
    return false;
}

void Game::add_scores(int num)
{
    scores += num;
}

void Game::init_game()
{
        scores = 0;
        snake_num = 1;
        snakes.clear();
        for(int i = 0;i < snake_num;i++)
        {
            Snake tmp('d',0,0);
            snakes.push_back(tmp);
        }

        if(food)
            delete food;
        food = new Food(10,10);
        if(food2)
            delete food2;
        food2 = new Food(9,10);

}

void Game::read_file()
{
    //读取本地文件

    ifstream fin(filename, ios::binary | ios::in);
    if(!fin)
    {
        init_game();
        return;
    }
    //读取金币数 4
    fin.read((char *)&coins, sizeof(coins));
    //读取排行榜 12
    fin.read((char *)&rank_first, sizeof(rank_first));
    fin.read((char *)&rank_second, sizeof(rank_second));
    fin.read((char *)&rank_third, sizeof(rank_third));
    //读取商城信息 5
    fin.read((char *)&has_a, sizeof(has_a));
    fin.read((char *)&has_b, sizeof(has_b));
    fin.read((char *)&has_c, sizeof(has_c));
    fin.read((char *)&has_d, sizeof(has_d));
    fin.read((char *)&has_e, sizeof(has_e));

    //读取存档
    fin.read((char *)&is_saved, sizeof(is_saved));
    /*
    if(is_saved)
    {
        //读取积分
        fin.read((char *)&scores, sizeof(scores));
        //读取食物信息
        int food_x1,food_y1,food_x2,food_y2;
        char food_type1,food_type2;
        fin.read((char *)&food_x1, sizeof(food_x1));
        fin.read((char *)&food_y1, sizeof(food_y1));
        fin.read((char *)&food_x2, sizeof(food_x2));
        fin.read((char *)&food_y2, sizeof(food_y2));
        fin.read(&food_type1, sizeof(food_type1));
        fin.read(&food_type2, sizeof(food_type2));
        if(food)
            delete food;
        if(food2)
            delete food2;
        if(food_type1 == 'a')
            food = new Food(food_x1, food_y1);
        else if(food_type1 == 'b')
            food = new Foodwa(food_x1, food_y1);
        else if(food_type1 == 'c')
            food = new Foodre(food_x1, food_y1);

        if(food_type2 == 'a')
            food2 = new Food(food_x2, food_y2);
        else if(food_type2 == 'b')
            food2 = new Foodwa(food_x2, food_y2);
        else if(food_type2 == 'c')
            food2 = new Foodre(food_x2, food_y2);


        //读取蛇
        fin.read((char *)&snake_num, sizeof(snake_num));
        snakes.clear();
        for(int i = 0;i < snake_num;i++)
        {
            int snake_x,snake_y;
            char dir;
            char snake_type;
            fin.read((char *)&snake_x, sizeof(snake_x));
            fin.read((char *)&snake_y, sizeof(snake_y));
            fin.read(&dir, sizeof(dir));
            fin.read(&snake_type, sizeof(snake_type));

            snakes.push_back(Snake(dir, snake_x, snake_y));
        }
    }
    else
    {
        init_game();
    }
    */
    fin.close();
}

void Game::read_game_file()
{
    ifstream fin(filename, ios::binary | ios::in);
    long location = fin.tellg();
    location = 21;
    fin.seekg(location, ios::beg);

    fin.read((char *)&is_saved, sizeof(is_saved));
    if(is_saved)
    {
        //读取积分
        fin.read((char *)&scores, sizeof(scores));
        //读取食物信息
        int food_x1,food_y1,food_x2,food_y2;
        char food_type1,food_type2;
        fin.read((char *)&food_x1, sizeof(food_x1));
        fin.read((char *)&food_y1, sizeof(food_y1));
        fin.read((char *)&food_x2, sizeof(food_x2));
        fin.read((char *)&food_y2, sizeof(food_y2));
        fin.read(&food_type1, sizeof(food_type1));
        fin.read(&food_type2, sizeof(food_type2));
        if(food)
            delete food;
        if(food2)
            delete food2;
        if(food_type1 == 'a')
            food = new Food(food_x1, food_y1);
        else if(food_type1 == 'b')
            food = new Foodwa(food_x1, food_y1);
        else if(food_type1 == 'c')
            food = new Foodre(food_x1, food_y1);

        if(food_type2 == 'a')
            food2 = new Food(food_x2, food_y2);
        else if(food_type2 == 'b')
            food2 = new Foodwa(food_x2, food_y2);
        else if(food_type2 == 'c')
            food2 = new Foodre(food_x2, food_y2);


        //读取蛇
        fin.read((char *)&snake_num, sizeof(snake_num));
        snakes.clear();
        for(int i = 0;i < snake_num;i++)
        {
            int snake_x,snake_y;
            char dir;
            char snake_type;
            fin.read((char *)&snake_x, sizeof(snake_x));
            fin.read((char *)&snake_y, sizeof(snake_y));
            fin.read(&dir, sizeof(dir));
            fin.read(&snake_type, sizeof(snake_type));

            snakes.push_back(Snake(dir, snake_x, snake_y));
        }
    }
    fin.close();
}

void Game::write_file()
{
    ofstream fout(filename, ios::binary | ios::out);
    //写入金币数
    fout.write((char *)&coins, sizeof(coins));
    //写入排行榜
    fout.write((char *)&rank_first, sizeof(rank_first));
    fout.write((char *)&rank_second, sizeof(rank_second));
    fout.write((char *)&rank_third, sizeof(rank_third));
    //写入商城信息
    fout.write((char *)&has_a, sizeof(has_a));
    fout.write((char *)&has_b, sizeof(has_b));
    fout.write((char *)&has_c, sizeof(has_c));
    fout.write((char *)&has_d, sizeof(has_d));
    fout.write((char *)&has_e, sizeof(has_e));
    //写入存档
    fout.write((char *)&is_saved, sizeof(is_saved));
    if(is_saved)
    {
        //写入积分
        fout.write((char *)&scores, sizeof(scores));
        //写入食物信息
        fout.write((char *)&(food->x), sizeof(food->x));
        fout.write((char *)&(food->y), sizeof(food->y));
        fout.write((char *)&(food2->x), sizeof(food2->x));
        fout.write((char *)&(food2->y), sizeof(food2->y));
        fout.write(&food->type, sizeof(food->type));
        fout.write(&food2->type, sizeof(food2->type));
        //写入蛇
        fout.write((char *)&snake_num, sizeof(snake_num));

        for(int i = 0;i < snake_num;i++)
        {
            char snake_type = 'a';//这里蛇的派生还没写，需要改写
            fout.write((char *)&snakes[i].x, sizeof(snakes[i].x));
            fout.write((char *)&snakes[i].y, sizeof(snakes[i].y));
            fout.write(&snakes[i].dir, sizeof(snakes[i].dir));
            fout.write(&snake_type, sizeof(snake_type));
        }
    }
    fout.close();

}

void Game::save_game()
{
    is_saved = true;
    write_file();
}

void Game::update_coins()
{
    coins += scores;
}
