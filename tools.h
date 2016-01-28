#ifndef TOOLS_H
#define TOOLS_H

#include <QVector2D>
#include <QVector3D>
#include <cmath>
#include "border.h"

class Tools
{
public:
    Tools();

    static bool isInRange(QVector3D position1, QVector3D position2, float dist);
    static void rotOnZ(QVector2D &position, float angle);
    static float distToBorder(QVector2D borderStart, QVector2D borderEnd, QVector2D playerPosition, float radius);
//    static QVector<float> insidePolygon(QVector2D polygonPoints, QVector2D position);
};

#endif // TOOLS_H
