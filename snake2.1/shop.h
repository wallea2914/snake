#ifndef SHOP_H
#define SHOP_H

#include <QWidget>

namespace Ui {
class shop;
}

class shop : public QWidget
{
    Q_OBJECT

public:
    explicit shop(QWidget *parent = nullptr);
    ~shop();
    void paintEvent(QPaintEvent *);

private:
    Ui::shop *ui;
private slots:
    void on_closeshop_clicked();
};

#endif // SHOP_H
