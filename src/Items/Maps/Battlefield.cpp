#include "Battlefield.h"

Battlefield::Battlefield(QGraphicsItem *parent) : Map(parent, ":/Items/Maps/Battlefield/FZPW8Lc.png") {}

qreal Battlefield::getFloorHeight() {
    auto sceneRect = sceneBoundingRect();
    return (sceneRect.top() + sceneRect.bottom()) * 0.63;
}
