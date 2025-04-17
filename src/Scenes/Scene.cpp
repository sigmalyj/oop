//
// Created by gerw on 8/20/24.
//

#include <QDateTime>
#include "Scene.h"

Scene::Scene(QObject *parent) : QGraphicsScene(parent), timer(new QTimer(this)) {
    connect(timer, &QTimer::timeout, this, &Scene::update);
}

void Scene::update()
{
    auto currentTime = QDateTime::currentDateTime().toMSecsSinceEpoch();
    if (lastTime == -1) { // first frame
        deltaTime = 0;
    } else {
        deltaTime = currentTime - lastTime;
    }
    lastTime = currentTime;

    processInput();
    processMovement();
    processPicking();
    fall();
    handlefallthing();
    deletefallthing();
    attack();
    changeweapon();
    cast();
    handlecastthing();
    isgameover();
    changearrow();
    attackanimation();
    burnt();
    elecspread();

}

void Scene::startLoop() {
    timer->start(1000 / 90); // 90FPS
}

void Scene::processInput() {

}

void Scene::processMovement() {

}

void Scene::processPicking() {

}

void Scene::fall()
{

}

void Scene::handlefallthing()
{

}

void Scene::deletefallthing()
{

}

void Scene::fallthing(int x,int num)
{
    Q_UNUSED(x);
    Q_UNUSED(num);
}

void Scene::handleCheatLine()
{

}

void Scene::attack()
{

}

void Scene::changeweapon()
{

}

void Scene::cast()
{

}

void Scene::gravity(Item *)
{

}

void Scene::handlecastthing()
{

}

void Scene::isgameover()
{

}

void Scene::gameover(QString text)
{
    Q_UNUSED(text);
}

void Scene::changearrow()
{

}

void Scene::attackanimation()
{

}

void Scene::burnt()
{

}

void Scene::elecspread()
{

}

