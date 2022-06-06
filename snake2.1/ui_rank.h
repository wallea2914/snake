/********************************************************************************
** Form generated from reading UI file 'rank.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RANK_H
#define UI_RANK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_rank
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *first;
    QLabel *second;
    QLabel *third;
    QPushButton *goback;

    void setupUi(QWidget *rank)
    {
        if (rank->objectName().isEmpty())
            rank->setObjectName(QString::fromUtf8("rank"));
        rank->resize(400, 300);
        label = new QLabel(rank);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 90, 40, 12));
        label_2 = new QLabel(rank);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(220, 90, 40, 12));
        label_3 = new QLabel(rank);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(60, 140, 40, 16));
        label_4 = new QLabel(rank);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(60, 190, 40, 12));
        label_5 = new QLabel(rank);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(60, 240, 40, 12));
        first = new QLabel(rank);
        first->setObjectName(QString::fromUtf8("first"));
        first->setGeometry(QRect(200, 140, 40, 12));
        second = new QLabel(rank);
        second->setObjectName(QString::fromUtf8("second"));
        second->setGeometry(QRect(200, 190, 40, 12));
        third = new QLabel(rank);
        third->setObjectName(QString::fromUtf8("third"));
        third->setGeometry(QRect(200, 240, 40, 12));
        goback = new QPushButton(rank);
        goback->setObjectName(QString::fromUtf8("goback"));
        goback->setGeometry(QRect(280, 260, 113, 32));

        retranslateUi(rank);

        QMetaObject::connectSlotsByName(rank);
    } // setupUi

    void retranslateUi(QWidget *rank)
    {
        rank->setWindowTitle(QCoreApplication::translate("rank", "Form", nullptr));
        label->setText(QCoreApplication::translate("rank", "\346\216\222\345\220\215", nullptr));
        label_2->setText(QCoreApplication::translate("rank", "\347\247\257\345\210\206", nullptr));
        label_3->setText(QCoreApplication::translate("rank", "1", nullptr));
        label_4->setText(QCoreApplication::translate("rank", "2", nullptr));
        label_5->setText(QCoreApplication::translate("rank", "3", nullptr));
        first->setText(QCoreApplication::translate("rank", "TextLabel", nullptr));
        second->setText(QCoreApplication::translate("rank", "TextLabel", nullptr));
        third->setText(QCoreApplication::translate("rank", "TextLabel", nullptr));
        goback->setText(QCoreApplication::translate("rank", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class rank: public Ui_rank {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RANK_H
