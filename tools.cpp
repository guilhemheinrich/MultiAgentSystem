#include "tools.h"

Tools::Tools()
{

}

bool Tools::isInRange(QVector3D x, QVector3D y, float dist)
{
    if (x.distanceToPoint(y) < dist)  return true ;
}

void Tools::rotOnZ(QVector2D &x, float angle)
{
    QVector2D tmp;
    tmp.setX(cos(angle)*x.x() - sin(angle)*x.y());
    tmp.setY(sin(angle)*x.x() + cos(angle)*x.y());
    x = tmp;
}



