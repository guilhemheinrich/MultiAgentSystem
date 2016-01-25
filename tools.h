#ifndef TOOLS_H
#define TOOLS_H

#include <QVector2D>
#include <QVector3D>
#include <cmath>

class Tools
{
public:
    Tools();

    static bool isInRange(QVector3D position1, QVector3D position2, float dist);
    static void rotOnZ(QVector2D &direction, float angle);
};

#endif // TOOLS_H
