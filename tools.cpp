#include "tools.h"

Tools::Tools()
{

}

bool Tools::isInRange(QVector3D position1, QVector3D position2, float dist)
{
    if (position1.distanceToPoint(position2) < dist)  return true ;
}

QVector2D Tools::rotOnZ(QVector2D direction, float angle)
{
    QVector2D tmp;
    tmp.setX(cos(angle)*direction.x() - sin(angle)*direction.y());
    tmp.setY(sin(angle)*direction.x() + cos(angle)*direction.y());
    return tmp;
}

float Tools::distToBorder(QVector2D borderStart, QVector2D borderEnd, QVector3D playerPosition, float radius)
{
    QVector3D border = (QVector3D) (borderEnd - borderStart);
    QVector3D playerVec = (QVector3D) (playerPosition - borderStart);
    QVector3D projectedPoint = QVector3D::dotProduct(border,playerVec) * border / border.length();
    float rayCast = projectedPoint.distanceToPoint(playerVec);

    if (QVector3D::normal(border,playerVec).z() < 0)
        return (rayCast-radius);
    return 0;
}

QVector2D Tools::randomDirection()
{
    float angle = std::rand() % 360 + 1;
    angle = (angle * M_PI) / 180.0;
    return rotOnZ(QVector2D(1, 0), angle);
}

//Return a direction according to a prefered direction and an angle window
QVector2D Tools::randomDirection(QVector2D direction, int angleWindow)
{
    float angle = std::rand() % angleWindow + 1;
    angle = (angle * M_PI) / 180.0;
    return rotOnZ(direction, angle);
}
