#ifndef HELPSCENE_H
#define HELPSCENE_H

#include "Scene.h"
#include <QPushButton>

class HelpScene : public Scene
{
    Q_OBJECT

public:
    explicit HelpScene(QObject *parent = nullptr);

signals:
    void returnButtonClicked();

private:
    QPushButton *returnButton;
};

#endif // HELPSCENE_H