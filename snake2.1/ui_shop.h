/********************************************************************************
** Form generated from reading UI file 'shop.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOP_H
#define UI_SHOP_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_shop
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QToolButton *toolButton;
    QToolButton *toolButton_2;
    QTextEdit *textEdit;
    QTextEdit *textEdit_2;
    QPushButton *closeshop;
    QLabel *label;

    void setupUi(QWidget *shop)
    {
        if (shop->objectName().isEmpty())
            shop->setObjectName(QString::fromUtf8("shop"));
        shop->resize(498, 381);
        QFont font;
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        shop->setFont(font);
        shop->setStyleSheet(QString::fromUtf8(""));
        pushButton = new QPushButton(shop);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(50, 250, 80, 21));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        pushButton_2 = new QPushButton(shop);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(220, 250, 80, 21));
        pushButton_2->setIcon(icon);
        toolButton = new QToolButton(shop);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(50, 110, 81, 61));
        toolButton->setStyleSheet(QString::fromUtf8("image: url(:/image/\346\234\210\344\272\256.png);"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/\346\234\210\344\272\256.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon1);
        toolButton->setIconSize(QSize(40, 40));
        toolButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        toolButton->setAutoRaise(true);
        toolButton_2 = new QToolButton(shop);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        toolButton_2->setGeometry(QRect(220, 110, 81, 61));
        toolButton_2->setStyleSheet(QString::fromUtf8("image: url(:/image/\345\244\252\351\230\263.png);"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/image/\345\244\252\351\230\263.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon2);
        toolButton_2->setIconSize(QSize(40, 40));
        toolButton_2->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        toolButton_2->setAutoRaise(true);
        textEdit = new QTextEdit(shop);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(50, 180, 121, 51));
        textEdit->setStyleSheet(QString::fromUtf8("font: 13pt \"Libian SC\";"));
        textEdit_2 = new QTextEdit(shop);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setGeometry(QRect(220, 180, 201, 51));
        closeshop = new QPushButton(shop);
        closeshop->setObjectName(QString::fromUtf8("closeshop"));
        closeshop->setGeometry(QRect(320, 300, 113, 32));
        label = new QLabel(shop);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 20, 441, 71));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Libian SC"));
        font1.setPointSize(24);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("font: 24pt \"Libian SC\";"));

        retranslateUi(shop);

        QMetaObject::connectSlotsByName(shop);
    } // setupUi

    void retranslateUi(QWidget *shop)
    {
        shop->setWindowTitle(QCoreApplication::translate("shop", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("shop", "\350\264\255\344\271\260", nullptr));
        pushButton_2->setText(QCoreApplication::translate("shop", "\350\264\255\344\271\260", nullptr));
        toolButton->setText(QCoreApplication::translate("shop", "\346\234\210\344\272\256\350\233\207", nullptr));
        toolButton_2->setText(QCoreApplication::translate("shop", "\345\244\252\351\230\263\350\233\207", nullptr));
        textEdit->setHtml(QCoreApplication::translate("shop", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Libian SC'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'.AppleSystemUIFont'; font-weight:600; text-decoration: underline;\">\351\207\221\345\270\201\350\212\261\350\264\271\357\274\232100</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'.AppleSystemUIFont'; font-weight:600; text-decoration: underline;\">\345\217\257\344\273\245\345\260\206\345\276\227\345\210\206\347\277\273\345\200\215\357\274\201</span></p></body></html>", nullptr));
        textEdit_2->setHtml(QCoreApplication::translate("shop", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'.AppleSystemUIFont'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'.AppleSystemUIFont'; font-weight:600; text-decoration: underline;\">\351\207\221\345\270\201\350\212\261\350\264\271\357\274\232200</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'.AppleSystemUIFont'; font-weight:600; text-decoration: underline;\">\345\217\257\344\273\245\345\260\206\345\276\227\345\210\206\347\232\204\345\212\240\345\210\206\345\222\214\346\211\243\345\210\206\351\242\240\345\200\222\357\274\201"
                        "</span></p></body></html>", nullptr));
        closeshop->setText(QCoreApplication::translate("shop", "\351\200\200\345\207\272\345\225\206\345\237\216", nullptr));
        label->setText(QCoreApplication::translate("shop", "\346\254\242\350\277\216\346\235\245\345\210\260\345\225\206\345\272\227\357\274\201\n"
"\346\234\254\345\272\227\347\273\235\345\257\271\350\211\257\345\277\203\345\225\206\345\256\266\357\274\214\347\253\245\345\217\237\346\227\240\346\254\272\357\275\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class shop: public Ui_shop {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOP_H
