#ifndef TOOLS_H
#define TOOLS_H

#include <iostream>

#include <QVector2D>
#include <QVector3D>
#include <cmath>
#include "border.h"

class Tools
{
public:
    Tools();

    static bool isInRange(QVector3D position1, QVector3D position2, float dist);
    static QVector2D rotOnZ(QVector2D direction, float angle);
    static float distToBorder(QVector2D borderStart, QVector2D borderEnd, QVector3D playerPosition, float radius);
    static QVector2D randomDirection();
};

#endif // TOOLS_H
