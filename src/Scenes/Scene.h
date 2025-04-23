#ifndef QT_PROGRAMMING_2024_SCENE_H
#define QT_PROGRAMMING_2024_SCENE_H

#include <QGraphicsScene>
#include <QTimer>
#include"../Items/Item.h"
class Scene : public QGraphicsScene {
Q_OBJECT

public:
    explicit Scene(QObject *parent);

    void startLoop();

    virtual void processInput();

    virtual void processMovement();

    virtual void processPicking();

    virtual void fall();

    virtual void handlefallthing();

    virtual void deletefallthing();

    virtual void fallthing(int x,int num);

    virtual void handleCheatLine();

    virtual void attack();

    virtual void changeweapon();

    virtual void cast();

    virtual void gravity(Item *,qreal g=0.015);

    virtual void handlecastthing();

    virtual void isgameover();

    virtual void gameover(QString text);

    virtual void changearrow();

    virtual void attackanimation();

    virtual void burnt();

    virtual void elecspread();

    QTimer *timer;
protected slots:

    virtual void update();

protected:
    qint64 deltaTime{};

private:

    qint64 lastTime{-1};
};


#endif //QT_PROGRAMMING_2024_SCENE_H
