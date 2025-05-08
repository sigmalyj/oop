#ifndef GAMEOVERSCENE_H
#define GAMEOVERSCENE_H
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QLabel>
#include <QPushButton>
#include <QApplication>
#include "../Items/Maps/Map.h"
class GameOverScene : public QGraphicsScene {
    Q_OBJECT
public:
    explicit GameOverScene(QObject *parent = nullptr);
    void showGameOverMessage(const QString &message);
    Map* map;
    QPushButton* exitButton;
    QPushButton* restartButton;
    QGraphicsPixmapItem* background;
    QGraphicsTextItem* messageItem;
signals:
    void gameOver();            //发出信号
    void restart();
public slots:
    void exitgame();            //摁下按钮接收信号
    void restartgame();
};
#endif // GAMEOVERSCENE_H
