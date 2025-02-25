#ifndef BOW_H
#define BOW_H
#include "../Item.h"
#include "../Mountable.h"

class Bow : public Item, public Mountable
{
public:
    explicit Bow(QGraphicsItem *parent, const QString &pixmapPath);

    void mountToParent() override;

    // void unmount() override;

    int elec_value;             //三种属性攻击值
    int ice_value;
    int flame_value;
    QString material;           //材料
    int attackdistance;         //射程
    QString element;            //元素属性
    QString name;               //武器名称
    int arrownum;               //一次可射出箭头数量
};
#endif // BOW_H
