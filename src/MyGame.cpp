#include "MyGame.h"
#include "Scenes/BattleScene.h"

MyGame::MyGame(QWidget *parent) : QMainWindow(parent)
{
    battleScene = new BattleScene(this);
    view = new QGraphicsView(this);
    view->setScene(battleScene);
    view->setFixedSize((int) view->scene()->width(), (int) view->scene()->height());
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setCentralWidget(view);
    setFixedSize(view->sizeHint());
    battleScene->startLoop();
}
