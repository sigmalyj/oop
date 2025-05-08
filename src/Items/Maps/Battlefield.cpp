#include "Battlefield.h"

Battlefield::Battlefield(QGraphicsItem *parent) : Map(parent, ":/Items/Maps/Battlefield/Arena.png") {}

qreal Battlefield::getFloorHeight() {
    auto sceneRect = sceneBoundingRect();
    return (sceneRect.top() + sceneRect.bottom()) * 0.63;
}
