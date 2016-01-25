#include "tools.h"

Tools::Tools()
{

}

bool Tools::isInRange(QVector2D x, QVector2D y, float dist)
{
    if (x.distanceToPoint(y) < dist)  return true ;
}



