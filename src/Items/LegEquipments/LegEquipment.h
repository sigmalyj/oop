#ifndef QT_PROGRAMMING_2024_LEGEQUIPMENT_H
#define QT_PROGRAMMING_2024_LEGEQUIPMENT_H


#include "../Item.h"
#include "../Mountable.h"

class LegEquipment: public Item ,public Mountable{
public:
    explicit LegEquipment(QGraphicsItem *parent, const QString &pixmapPath);

    void mountToParent() override;

    void unmount()override;
    int pro_elec;               //对三种属性的防御值
    int pro_ice;
    int pro_flame;
    QString name;

};


#endif //QT_PROGRAMMING_2024_LEGEQUIPMENT_H
