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
    void helpButtonClicked(); // 新增 Help 按钮信号

private:
    QPushButton *startButton;
    QPushButton *helpButton; // 新增 Help 按钮
};

#endif // STARTSCENE_H