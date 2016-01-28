#ifndef BORDER
#define BORDER
#include <QVector2D>


static const QVector2D vec = QVector2D(1,1);
struct Border{
    QVector2D upperRight = QVector2D(1.0, 1.0);
    QVector2D bottomRight = QVector2D(1.0,-1.0);
    QVector2D bottomLeft = QVector2D(-1.0,-1.0);
    QVector2D upperLeft = QVector2D(-1.0,1.0);
};
#endif // BORDER

