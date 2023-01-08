#ifndef NOT_ENOUGH_H
#define NOT_ENOUGH_H

#include <QWidget>

namespace Ui {
class not_enough;
}

class not_enough : public QWidget
{
    Q_OBJECT

public:
    explicit not_enough(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
    ~not_enough();

private slots:
    void on_earn_money_clicked();

private:
    Ui::not_enough *ui;

signals:
    void return_main();
};

#endif // NOT_ENOUGH_H
