#ifndef ABSTRACTAGENT_H
#define ABSTRACTAGENT_H

#include <QVector2D>
#include <QVector3D>

class AbstractAgent
{
private:
    int _team;
    float _moveSpeed;
    float _vision;
    QVector2D _direction;
    QVector3D _position;
public:
    AbstractAgent(int);
};

#endif // ABSTRACTAGENT_H
