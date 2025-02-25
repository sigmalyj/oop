#ifndef PLATFORM_H
#define PLATFORM_H
#include"Item.h"
class PlatForm:public Item
{
public:
   explicit PlatForm(QGraphicsItem *parent, const QString &pixmapPath);
};

#endif // PLATFORM_H
