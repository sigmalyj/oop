#include "MyGame.h"
#include "Scenes/StartScene.h"
#include "Scenes/BattleScene.h"

MyGame::MyGame(QWidget *parent) : QMainWindow(parent)
{
    // 初始化视图
    view = new QGraphicsView(this);
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