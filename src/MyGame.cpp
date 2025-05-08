#include "MyGame.h"
#include "Scenes/StartScene.h"
#include "Scenes/GameOverScene.h"
#include "Scenes/BattleScene.h"

MyGame::MyGame(QWidget *parent) : QMainWindow(parent)
{
    // 初始化视图
    gameOverScene=new GameOverScene(this);
    view = new QGraphicsView(this);
    //view->setScene(battleScene);
    //connect(gameOverScene, &GameOverScene::gameOver, this, &MyGame::exitGame);
    connect(gameOverScene, &GameOverScene::restart, this, &MyGame::restartGame);
    //connect(battleScene, &BattleScene::gameoverSignal, this, &MyGame::switchtogameover);
    //view->setFixedSize((int) view->scene()->width(), (int) view->scene()->height());
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setCentralWidget(view);

    // 创建 StartScene
    startScene = new StartScene(this);
    view->setScene(startScene);
    view->setFixedSize((int)startScene->width(), (int)startScene->height());
    setFixedSize(view->sizeHint());

    // 连接 StartScene 的按钮点击信号
    connect(startScene, &StartScene::startButtonClicked, this, &MyGame::switchToBattleScene);
}

void MyGame::switchToBattleScene()
{
    // 切换到 BattleScene
    battleScene = new BattleScene(this);
    view->setScene(battleScene);
    view->setFixedSize((int)battleScene->width(), (int)battleScene->height());
    setFixedSize(view->sizeHint());
    battleScene->startLoop();

}

void MyGame::switchtogameover(QString text)
{
    if(gameOverScene)
    {
        delete gameOverScene;
    }
    gameOverScene = new GameOverScene(this);
    connect(gameOverScene, &GameOverScene::gameOver, this, &MyGame::exitGame);
    connect(gameOverScene, &GameOverScene::restart, this, &MyGame::restartGame);
    gameOverScene->setSceneRect(0, 0, 1280, 720);
    view->setScene(gameOverScene);
    gameOverScene->showGameOverMessage(text);
    view->setFixedSize((int) view->scene()->width(), (int) view->scene()->height());
    setFixedSize(view->sizeHint());
    battleScene->timer->stop();
}

void MyGame::switchtobattle()
{
    if(battleScene)
    {
        delete battleScene;
    }
    // if(gameOverScene)
    // {
    //     delete gameOverScene;
    // }
    // gameOverScene = new GameOverScene(this);
    connect(gameOverScene, &GameOverScene::gameOver, this, &MyGame::exitGame);
    connect(gameOverScene, &GameOverScene::restart, this, &MyGame::restartGame);
    battleScene = new BattleScene(this);
    connect(battleScene, &BattleScene::gameoverSignal, this, &MyGame::switchtogameover);

    view->setScene(battleScene);
    view->setFixedSize((int) view->scene()->width(), (int) view->scene()->height());
    setFixedSize(view->sizeHint());
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setCentralWidget(view);
    battleScene->startLoop();
}

void MyGame::exitGame()
{
    QApplication::quit();
}
void MyGame::restartGame()
{
    switchtobattle();
}

