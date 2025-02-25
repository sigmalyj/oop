#ifndef QT_PROGRAMMING_2024_BATTLEFIELD_H
#define QT_PROGRAMMING_2024_BATTLEFIELD_H


#include "Map.h"

class Battlefield: public Map {
public:
    explicit Battlefield(QGraphicsItem *parent= nullptr);

    qreal getFloorHeight() override;        //更新地板高度
};


#endif //QT_PROGRAMMING_2024_BATTLEFIELD_H
