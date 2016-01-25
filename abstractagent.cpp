#include "abstractagent.h"

AbstractAgent::AbstractAgent(int team)
{
    _team = team;
    _moveSpeed = 0.01f;
    _vision = 0.1f;
    _direction = QVector2D(1, 0);
    _position = QVector3D(0, 0, 0);
}

