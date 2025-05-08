#ifndef QT_PROGRAMMING_2024_MYGAME_H
#define QT_PROGRAMMING_2024_MYGAME_H

#include <QGraphicsView>
#include <QMainWindow>
#include "Scenes/Scene.h"
#include "Scenes/GameOverScene.h"
class MyGame : public QMainWindow {
Q_OBJECT

public:
    explicit MyGame(QWidget *parent = nullptr);

    void switchtobattle();
public slots:
    void restartGame();
    void exitGame();
    void switchtogameover(QString text);
private:
    Scene *battleScene;
    GameOverScene *gameOverScene;
    QGraphicsView *view;
};


#endif //QT_PROGRAMMING_2024_MYGAME_H
