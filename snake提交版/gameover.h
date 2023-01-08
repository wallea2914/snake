#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <QWidget>

namespace Ui {
class gameover;
}

class gameover : public QWidget
{
    Q_OBJECT

public:
    explicit gameover(QWidget *parent = nullptr, int final_scores = 0);
    ~gameover();
    void paintEvent(QPaintEvent *);
public:
    Ui::gameover *ui;
private slots:
    //void on_overback_clicked();
    //void on_return_2_clicked();
    void on_return_main_clicked();

signals:
    void return_main();//像主界面发送信息
};

#endif // GAMEOVER_H
