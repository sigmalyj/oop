#ifndef STARTSCENE_H
#define STARTSCENE_H

#include "Scene.h"
#include <QPushButton>

class StartScene : public Scene
{
    Q_OBJECT

public:
    explicit StartScene(QObject *parent = nullptr);

signals:
    void startButtonClicked();

private:
    QPushButton *startButton;
};

#endif // STARTSCENE_H