#include "StartScene.h"
#include <QGraphicsProxyWidget>
#include <QBrush>
#include <QPixmap>
#include <QFont>

StartScene::StartScene(QObject *parent) : Scene(parent)
{
    // 加载背景图片
    QPixmap pixmap(":/Items/Maps/StartScene/StartScene.jpg");
    setBackgroundBrush(QBrush(pixmap.scaled(1280, 720, Qt::KeepAspectRatioByExpanding)));
    setSceneRect(0, 0, 1280, 720);

    // 创建 Start 按钮
    startButton = new QPushButton("Start");
    startButton->setFixedSize(300, 120);
    QFont font("Algerian", 40, QFont::Bold, true);
    startButton->setFont(font);

    // 设置 Start 按钮样式表
    startButton->setStyleSheet(
        "QPushButton {"
        "    background-color: transparent;"
        "    color: white;"
        "}"
        "QPushButton:hover {"
        "    background-color: rgba(255, 255, 255, 50); /* 浅透明蒙版 */"
        "    color: black;"
        "}"
        "QPushButton:pressed {"
        "    background-color: rgba(255, 255, 255, 100); /* 更深的透明蒙版 */"
        "    color: gray;"
        "}"
    );

    QGraphicsProxyWidget *startProxy = addWidget(startButton);
    startProxy->setPos(1280 - startButton->width() - 100, (720 - startButton->height()) / 3);

    connect(startButton, &QPushButton::clicked, this, &StartScene::startButtonClicked);

    // 创建 Help 按钮
    helpButton = new QPushButton("Help");
    helpButton->setFixedSize(300, 120);
    helpButton->setFont(font);

    // 设置 Help 按钮样式表
    helpButton->setStyleSheet(
        "QPushButton {"
        "    background-color: transparent;"
        "    color: white;"
        "}"
        "QPushButton:hover {"
        "    background-color: rgba(255, 255, 255, 50); /* 浅透明蒙版 */"
        "    color: black;"
        "}"
        "QPushButton:pressed {"
        "    background-color: rgba(255, 255, 255, 100); /* 更深的透明蒙版 */"
        "    color: gray;"
        "}"
    );

    QGraphicsProxyWidget *helpProxy = addWidget(helpButton);
    helpProxy->setPos(1280 - helpButton->width() - 100, (720 - helpButton->height()) * 2 / 3);

    connect(helpButton, &QPushButton::clicked, this, &StartScene::helpButtonClicked);
}
