#ifndef TOOLS_H
#define TOOLS_H

#include <QVector2D>
#include <QVector3D>
#include <cmath>

class Tools
{
public:
    Tools();

    static bool isInRange(QVector3D x, QVector3D y, float dist);
    static void rotOnZ(QVector2D &x, float angle);
};

#endif // TOOLS_H
