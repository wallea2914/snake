#ifndef RANK_H
#define RANK_H

#include <QWidget>
class MainWindow;
namespace Ui {
class rank;
}

class rank : public QWidget
{
    Q_OBJECT

public:
    explicit rank(QWidget *parent = nullptr, MainWindow* a = nullptr);
    ~rank();
    void paintEvent(QPaintEvent *);
private:
    Ui::rank *ui;
    MainWindow* mainwindow;
private slots:

    void on_return_main_clicked();

signals:
    void return_main();//像主界面发送信息
};

#endif // RANK_H
