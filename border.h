#ifndef BORDER
#define BORDER

struct Border{
    QVector2D upperRight = QVector2D(1.0, 1.0);
    QVector2D bottomRight = QVector2D(1.0,-1.0);
    QVector2D bottomLeft = QVector2D(-1.0,-1.0);
    QVector2D upperLeft = QVector2D(-1.0,1.0);
};
#endif // BORDER

