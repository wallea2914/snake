/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *begin;
    QPushButton *save;
    QPushButton *shop;
    QPushButton *rank;
    QPushButton *exit;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *coins;
    QLabel *scores;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(900, 600);
        verticalLayoutWidget = new QWidget(Widget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(710, 140, 160, 281));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        begin = new QPushButton(verticalLayoutWidget);
        begin->setObjectName(QString::fromUtf8("begin"));
        begin->setAutoDefault(false);

        verticalLayout->addWidget(begin);

        save = new QPushButton(verticalLayoutWidget);
        save->setObjectName(QString::fromUtf8("save"));

        verticalLayout->addWidget(save);

        shop = new QPushButton(verticalLayoutWidget);
        shop->setObjectName(QString::fromUtf8("shop"));

        verticalLayout->addWidget(shop);

        rank = new QPushButton(verticalLayoutWidget);
        rank->setObjectName(QString::fromUtf8("rank"));

        verticalLayout->addWidget(rank);

        exit = new QPushButton(verticalLayoutWidget);
        exit->setObjectName(QString::fromUtf8("exit"));

        verticalLayout->addWidget(exit);

        verticalLayoutWidget_2 = new QWidget(Widget);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(799, 30, 71, 80));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        coins = new QLabel(verticalLayoutWidget_2);
        coins->setObjectName(QString::fromUtf8("coins"));

        verticalLayout_2->addWidget(coins);

        scores = new QLabel(verticalLayoutWidget_2);
        scores->setObjectName(QString::fromUtf8("scores"));

        verticalLayout_2->addWidget(scores);

        verticalLayoutWidget_3 = new QWidget(Widget);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(710, 30, 71, 80));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget_3);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_3->addWidget(label);

        label_2 = new QLabel(verticalLayoutWidget_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_3->addWidget(label_2);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        begin->setText(QCoreApplication::translate("Widget", "\345\274\200\345\247\213\346\270\270\346\210\217", nullptr));
        save->setText(QCoreApplication::translate("Widget", "\345\255\230\346\241\243", nullptr));
        shop->setText(QCoreApplication::translate("Widget", "\345\225\206\345\237\216", nullptr));
        rank->setText(QCoreApplication::translate("Widget", "\346\216\222\350\241\214\346\246\234", nullptr));
        exit->setText(QCoreApplication::translate("Widget", "\351\200\200\345\207\272\346\270\270\346\210\217", nullptr));
        coins->setText(QCoreApplication::translate("Widget", "0", nullptr));
        scores->setText(QCoreApplication::translate("Widget", "0", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\351\207\221\345\270\201\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "\347\247\257\345\210\206\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
