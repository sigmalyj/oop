#ifndef SWORD_H
#define SWORD_H

#include "../Item.h"
#include "../Mountable.h"

class Sword : public Item, public Mountable
{
public:
    explicit Sword(QGraphicsItem *parent, const QString &pixmapPath);

    void mountToParent() override;

    // void unmount() override;
    int elec_value;
    int ice_value;
    int flame_value;
    QString material;
    int attackdistance;
    QString element;
    QString name;
    void SwordAttack();
    void CompleteSwordAttack();
};

#endif // SWORD_H
