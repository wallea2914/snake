QT       += core gui
QT += multimediawidgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
CONFIG+=sdk_no_version_check
QMAKE_MACOSX_DEPLOYMENT_TARGET=10.15
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    choose_snake.cpp \
    food.cpp \
    game.cpp \
    game_ui.cpp \
    gameover.cpp \
    main.cpp \
    mainwindow.cpp \
    not_enough.cpp \
    rank.cpp \
    shop.cpp \
    snake.cpp

HEADERS += \
    choose_snake.h \
    food.h \
    game.h \
    game_ui.h \
    gameover.h \
    mainwindow.h \
    not_enough.h \
    rank.h \
    shop.h \
    snake.h

FORMS += \
    choose_snake.ui \
    game_ui.ui \
    gameover.ui \
    mainwindow.ui \
    not_enough.ui \
    rank.ui \
    shop.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

