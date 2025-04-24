#ifndef PLATFORM_H
#define PLATFORM_H
#include"Item.h"
class PlatForm:public Item
{
public:
   explicit PlatForm(QGraphicsItem *parent, const QString &pixmapPath);
    bool exists() const; //判断物品是否存在
   bool exist=true;
    void setexist(bool exist); //设置物品是否存在
   int platform_life=5;
    int getplatformlife() const; //获取物品生命值
};

#endif // PLATFORM_H
