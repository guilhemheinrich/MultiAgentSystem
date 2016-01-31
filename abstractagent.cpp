#include "abstractagent.h"

StateAgent *AbstractAgent::state() const
{
    return _state;
}

void AbstractAgent::setState(StateAgent *state)
{
    _state = state;
}

AbstractAgent::AbstractAgent(int team)
{
    _team = team;
    _moveSpeed = 0.01f;
    _state = new Explore();
    _visionRadius = 0.5f;
    _collisionRadius = 0.2f;

    _direction = Tools::randomDirection();

    float x = 0.0f + static_cast<float>(std::rand()) / (static_cast<float>(RAND_MAX/(0.5f - 0.0f)));
    float y = 0.0f + static_cast<float>(std::rand()) / (static_cast<float>(RAND_MAX/(0.5f - 0.0f)));
    _position = QVector3D(x, y, 0);
}

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

void AbstractAgent::update()
{
    QVector3D nextPosition = _position + _direction * _moveSpeed;
    if((Tools::distToBorder(Border::UPPER_LEFT, Border::UPPER_RIGHT, nextPosition, _visionRadius) <= 0) ||
            (Tools::distToBorder(Border::UPPER_RIGHT, Border::BOTTOM_RIGHT, nextPosition, _visionRadius) <= 0) ||
            (Tools::distToBorder(Border::BOTTOM_RIGHT, Border::BOTTOM_LEFT, nextPosition, _visionRadius) <= 0) ||
            (Tools::distToBorder(Border::BOTTOM_LEFT, Border::UPPER_LEFT, nextPosition, _visionRadius) <= 0))
        _direction = Tools::randomDirection(_direction,90);
    _position += _direction * _moveSpeed;
}
