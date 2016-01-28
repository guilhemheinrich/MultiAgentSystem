#include "tools.h"

Tools::Tools()
{

}

bool Tools::isInRange(QVector3D position1, QVector3D position2, float dist)
{
    if (position1.distanceToPoint(position2) < dist)  return true ;
}

void Tools::rotOnZ(QVector2D &position, float angle)
{
    QVector2D tmp;
    tmp.setX(cos(angle)*position.x() - sin(angle)*position.y());
    tmp.setY(sin(angle)*position.x() + cos(angle)*position.y());
    position = tmp;
}

float Tools::distToBorder(QVector2D borderStart, QVector2D borderEnd, QVector2D playerPosition, float radius)
{
    QVector3D border = (QVector3D) (borderEnd - borderStart), playerVec = (QVector3D) (playerPosition - borderStart);
    QVector3D projectedPoint = QVector3D::dotProduct(border,playerVec) * border / border.length();
    float rayCast = projectedPoint.distanceToPoint(playerVec);

    if (QVector3D::normal(border,playerVec).z() < 0) return (rayCast-radius);
    return 0;
}



//QVector<float> Tools::pseudoDistToBorder(Border border, QVector2D position)
//{

//}



