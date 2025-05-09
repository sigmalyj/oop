#ifndef QT_PROGRAMMING_2024_MYGAME_H
#define QT_PROGRAMMING_2024_MYGAME_H

#include <QGraphicsView>
#include <QMainWindow>
#include "Scenes/Scene.h"
#include "Scenes/GameOverScene.h"
#include "Scenes/StartScene.h"
#include "Scenes/HelpScene.h"

class MyGame : public QMainWindow {
Q_OBJECT

public:
    explicit MyGame(QWidget *parent = nullptr);
    void switchToBattleScene(); // 切换到战斗场景
    void switchtobattle();
    void switchToStartScene(); // 切换到开始场景
    void switchToHelpScene();
public slots:
    void restartGame();
    void exitGame();
    void switchtogameover(QString text);
private:
    Scene *battleScene;
    GameOverScene *gameOverScene;
    StartScene *startScene;
    HelpScene *helpScene;
    QGraphicsView *view;
};


#endif //QT_PROGRAMMING_2024_MYGAME_H
