#include "abstractagent.h"

QVector2D AbstractAgent::direction() const
{
    return _direction;
}

void AbstractAgent::setDirection(const QVector2D &direction)
{
    _direction = direction;
}

QVector3D AbstractAgent::position() const
{
    return _position;
}

void AbstractAgent::setPosition(const QVector3D &position)
{
    _position = position;
}

int AbstractAgent::team() const
{
    return _team;
}

void AbstractAgent::setTeam(int team)
{
    _team = team;
}

AbstractAgent::AbstractAgent(int team)
{
    _team = team;
    _moveSpeed = 0.01f;
    _vision = 0.1f;
    _direction = QVector2D(1, 0);
    _position = QVector3D(0, 0, 0);
}

