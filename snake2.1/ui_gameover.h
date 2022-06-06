/********************************************************************************
** Form generated from reading UI file 'gameover.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEOVER_H
#define UI_GAMEOVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gameover
{
public:
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *gameover)
    {
        if (gameover->objectName().isEmpty())
            gameover->setObjectName(QString::fromUtf8("gameover"));
        gameover->resize(279, 190);
        label = new QLabel(gameover);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(80, 30, 121, 51));
        label->setWordWrap(true);
        label_2 = new QLabel(gameover);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(80, 100, 111, 31));

        retranslateUi(gameover);

        QMetaObject::connectSlotsByName(gameover);
    } // setupUi

    void retranslateUi(QWidget *gameover)
    {
        gameover->setWindowTitle(QCoreApplication::translate("gameover", "Form", nullptr));
        label->setText(QCoreApplication::translate("gameover", "\346\270\270\346\210\217\347\273\223\346\235\237\357\274\201  \346\202\250\347\232\204\345\276\227\345\210\206\346\230\257\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("gameover", "111", nullptr));
    } // retranslateUi

};

namespace Ui {
    class gameover: public Ui_gameover {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEOVER_H
