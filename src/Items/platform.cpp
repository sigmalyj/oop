#include "platform.h"

PlatForm::PlatForm(QGraphicsItem *parent, const QString &pixmapPath):Item(parent,pixmapPath)
{
    exist =true;

}
bool PlatForm::exists() const
{
    return exist;
}

void PlatForm::setexist(bool exist)
{
    exist=exist;
}

int PlatForm::getplatformlife() const
{
    return platform_life;
}
