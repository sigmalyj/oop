#ifndef ARROW_H
#define ARROW_H

#include "../Item.h"
#include "../Mountable.h"

class Arrow : public Item, public Mountable
{
public:
    explicit Arrow(QGraphicsItem *parent, const QString &pixmapPath);

    void mountToParent() override;

    // void unmount() override;
    int elec_value;             //三种元素的攻击值
    int ice_value;
    int flame_value;
    int flydistance;            //飞行距离
    QString element;            //元素属性
    QString name;               //箭头名称
};
#endif // ARROW_H
