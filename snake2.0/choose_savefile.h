#ifndef CHOOSE_SAVEFILE_H
#define CHOOSE_SAVEFILE_H

#include <QWidget>
#include "widget.h"

namespace Ui {
class choose_savefile;
}

class choose_savefile : public QWidget
{
    Q_OBJECT

public:
    explicit choose_savefile(QWidget *parent = nullptr, Widget* a = nullptr);
    ~choose_savefile();

private slots:


    void on_continue_2_clicked();

    void on_newgame_clicked();

private:
    Ui::choose_savefile *ui;
    Widget* mainwindow;
};

#endif // CHOOSE_SAVEFILE_H
