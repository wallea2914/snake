#ifndef RANK_H
#define RANK_H

#include <QWidget>

namespace Ui {
class rank;
}

class rank : public QWidget
{
    Q_OBJECT

public:
    explicit rank(QWidget *parent = nullptr);
    ~rank();

private:
    Ui::rank *ui;
};

#endif // RANK_H
