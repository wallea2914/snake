#ifndef CHOOSE_SNAKE_H
#define CHOOSE_SNAKE_H

#include <QWidget>
#include <QPushButton>
class Game;
namespace Ui {
class choose_snake;
}

class choose_snake : public QWidget
{
    Q_OBJECT

public:
    explicit choose_snake(QWidget *parent = nullptr, Game* _game = nullptr);
    ~choose_snake();

    Game* game;

private:
    Ui::choose_snake *ui;

signals:
    void show_game();//像主界面发送信息
    void return_main();
private slots:
    void on_showgame_clicked();
    void on_goback_clicked();
};

#endif // CHOOSE_SNAKE_H
