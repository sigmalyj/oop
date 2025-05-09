#include "MyGame.h"
#include "Scenes/StartScene.h"
#include "Scenes/GameOverScene.h"
#include "Scenes/BattleScene.h"
#include "Scenes/HelpScene.h" // 新增 HelpScene 头文件

MyGame::MyGame(QWidget *parent) : QMainWindow(parent)
{
    // 初始化视图
    gameOverScene = nullptr;
    battleScene = nullptr;
    helpScene = nullptr;

    view = new QGraphicsView(this);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setCentralWidget(view);

    // 创建 StartScene
    startScene = new StartScene(this);
    view->setScene(startScene);
    view->setFixedSize(1280, 720);
    setFixedSize(view->sizeHint());

    // 连接 StartScene 的按钮点击信号
    connect(startScene, &StartScene::startButtonClicked, this, &MyGame::switchToBattleScene);
    connect(startScene, &StartScene::helpButtonClicked, this, &MyGame::switchToHelpScene); // 新增 Help 按钮信号
}

void MyGame::switchToBattleScene()
{
    if (battleScene) {
        delete battleScene;
        battleScene = nullptr;
    }

    battleScene = new BattleScene(this);
    connect(battleScene, &BattleScene::gameoverSignal, this, &MyGame::switchtogameover);

    view->setScene(battleScene);
    view->setFixedSize(1280, 720);
    setFixedSize(view->sizeHint());
    battleScene->startLoop();
}

void MyGame::switchToHelpScene()
{
    if (helpScene) {
        delete helpScene;
        helpScene = nullptr;
    }

    helpScene = new HelpScene(this);
    connect(helpScene, &HelpScene::returnButtonClicked, this, &MyGame::switchToStartScene); // 连接 Return 按钮信号

    view->setScene(helpScene);
    view->setFixedSize(1280, 720);
    setFixedSize(view->sizeHint());
}

void MyGame::switchToStartScene()
{
    view->setScene(startScene);
    view->setFixedSize(1280, 720);
    setFixedSize(view->sizeHint());
}

void MyGame::switchtogameover(QString text)
{
    if (gameOverScene) {
        delete gameOverScene;
        gameOverScene = nullptr;
    }

    gameOverScene = new GameOverScene(this);
    connect(gameOverScene, &GameOverScene::gameOver, this, &MyGame::exitGame);
    connect(gameOverScene, &GameOverScene::restart, this, &MyGame::restartGame);

    gameOverScene->setSceneRect(0, 0, 1280, 720);
    view->setScene(gameOverScene);
    gameOverScene->showGameOverMessage(text);
    view->setFixedSize(1280, 720);
    setFixedSize(view->sizeHint());

    if (battleScene && battleScene->timer) {
        battleScene->timer->stop();
    }
}

void MyGame::exitGame()
{
    QApplication::quit();
}

void MyGame::restartGame()
{
    switchToBattleScene();
}