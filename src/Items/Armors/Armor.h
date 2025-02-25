#ifndef QT_PROGRAMMING_2024_ARMOR_H
#define QT_PROGRAMMING_2024_ARMOR_H

#include "../Item.h"
#include "../Mountable.h"

class Armor : public Item, public Mountable
{
public:
    explicit Armor(QGraphicsItem *parent, const QString &pixmapPath);

    void mountToParent() override;

    void unmount() override;

    int pro_elec;               //对三种元素的防御值
    int pro_ice;
    int pro_flame;
    QString name;
};


#endif //QT_PROGRAMMING_2024_ARMOR_H
