#include"GameOverScene.h"
#include "../Items/Maps/Map.h"
#include "../Items/Maps/Battlefield.h"

#include<QDebug>

GameOverScene::GameOverScene(QObject *parent)
{

    setSceneRect(0, 0, 1280, 720);
    QPixmap pixmap(":/Items/Maps/Battlefield/Arena.png");
    QPixmap scaledPixmap = pixmap.scaled(sceneRect().width(), sceneRect().height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    background = new QGraphicsPixmapItem(scaledPixmap);
    background->setPos(0, 0);
    addItem(background);
    // map =new Battlefield();

    exitButton = new QPushButton("Exit");
    exitButton->setGeometry(640-100, 500, 200, 50);
    restartButton = new QPushButton("Restart");
    restartButton->setGeometry(640-100, 400, 200, 50);
    addWidget(exitButton);
    addWidget(restartButton);
    exitButton->setStyleSheet("background-color: red; color: white; font-size: 20px;");
    restartButton->setStyleSheet("background-color: green; color: white; font-size: 20px;");
    exitButton->setFixedSize(200, 50);
    restartButton->setFixedSize(200, 50);
    exitButton->setCursor(Qt::PointingHandCursor);
    restartButton->setCursor(Qt::PointingHandCursor);
    connect(exitButton, &QPushButton::clicked, this, &GameOverScene::exitgame);
    connect(restartButton, &QPushButton::clicked, this, &GameOverScene::restartgame);
}

void GameOverScene::showGameOverMessage(const QString &message)
{
    messageItem = new QGraphicsTextItem(message);
    messageItem->setDefaultTextColor(Qt::black);
    QFont font("Arial", 40);
    font.setBold(true);
    font.setItalic(true);
    messageItem->setFont(font);
    messageItem->setPos(500, 200);
    addItem(messageItem);
}

void GameOverScene::exitgame()
{
    qDebug() << "exitgame";
    emit gameOver(); //发出信号
}

void GameOverScene::restartgame()
{
    qDebug() << "restartgame";
    emit restart(); //发出信号
}
