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

private:
    Ui::rank *ui;
    Widget* mainwindow;
};

#endif // RANK_H
