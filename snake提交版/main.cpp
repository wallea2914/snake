#include "mainwindow.h"

#include"game_ui.h"
#include <QApplication>
#include<QMediaPlayer>
#include<QMediaPlaylist>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    w.show();
    QMediaPlayer *gameSound = new QMediaPlayer;//创建播放器
    QMediaPlaylist *gameList = new QMediaPlaylist;//创建播放列表
    gameList->addMedia(QUrl("qrc:/music/bgm.mp3"));//添加音乐
    gameList->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);//循环播放

    gameSound->setPlaylist(gameList);
    gameSound->setVolume(20);
    gameSound->play();//音乐播放
    //gameSound->stop();//音乐暂停

    return a.exec();
}
