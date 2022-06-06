/********************************************************************************
** Form generated from reading UI file 'choose_savefile.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOOSE_SAVEFILE_H
#define UI_CHOOSE_SAVEFILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_choose_savefile
{
public:
    QPushButton *continue_2;
    QPushButton *newgame;
    QLabel *label;

    void setupUi(QWidget *choose_savefile)
    {
        if (choose_savefile->objectName().isEmpty())
            choose_savefile->setObjectName(QString::fromUtf8("choose_savefile"));
        choose_savefile->resize(400, 300);
        continue_2 = new QPushButton(choose_savefile);
        continue_2->setObjectName(QString::fromUtf8("continue_2"));
        continue_2->setGeometry(QRect(60, 147, 80, 31));
        newgame = new QPushButton(choose_savefile);
        newgame->setObjectName(QString::fromUtf8("newgame"));
        newgame->setGeometry(QRect(220, 147, 80, 31));
        label = new QLabel(choose_savefile);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 50, 241, 81));

        retranslateUi(choose_savefile);

        QMetaObject::connectSlotsByName(choose_savefile);
    } // setupUi

    void retranslateUi(QWidget *choose_savefile)
    {
        choose_savefile->setWindowTitle(QCoreApplication::translate("choose_savefile", "Form", nullptr));
        continue_2->setText(QCoreApplication::translate("choose_savefile", "\347\273\247\347\273\255\346\270\270\346\210\217", nullptr));
        newgame->setText(QCoreApplication::translate("choose_savefile", "\346\226\260\347\232\204\346\270\270\346\210\217", nullptr));
        label->setText(QCoreApplication::translate("choose_savefile", "\346\243\200\346\265\213\345\210\260\346\234\211\346\234\252\345\256\214\346\210\220\347\232\204\346\270\270\346\210\217\345\255\230\346\241\243\343\200\202  \n"
"\346\230\257\345\220\246\347\273\247\347\273\255\357\274\237", nullptr));
    } // retranslateUi

};

namespace Ui {
    class choose_savefile: public Ui_choose_savefile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOOSE_SAVEFILE_H
