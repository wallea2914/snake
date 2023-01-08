#ifndef SHOP_H
#define SHOP_H

#include <QWidget>
#include <QPushButton>
#include "game.h"
#include "not_enough.h"
namespace Ui {
class shop;
}

class shop : public QWidget
{
    Q_OBJECT

public:
    explicit shop(QWidget *parent = nullptr,Game * _game=nullptr);
    Game *game;
    not_enough *my_enough;
    ~shop();
    void paintEvent(QPaintEvent *);
    void button_motionless(QPushButton &b);
    void buya();
    void buyb();
private:
    Ui::shop *ui;
private slots:


    void on_close_shop_clicked();

    void on_buymoon_clicked();

    void on_buysun_clicked();

signals:
    void return_main();//像主界面发送信息
};

#endif // SHOP_H
