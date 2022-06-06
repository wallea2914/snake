#ifndef RANK_H
#define RANK_H

#include <QWidget>
class Widget;
namespace Ui {
class rank;
}

class rank : public QWidget
{
    Q_OBJECT

public:
    explicit rank(QWidget *parent = nullptr, Widget* a = nullptr);
    ~rank();
    void paintEvent(QPaintEvent *);
private:
    Ui::rank *ui;
    Widget* mainwindow;
private slots:
    void on_goback_clicked();
};

#endif // RANK_H
