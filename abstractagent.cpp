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
    _vision = 0.1f;
    _state = new Explore();

    float angle = std::rand() % 360 + 1;
    angle = (angle * M_PI) / 180.0;
    _direction = QVector2D(1, 0);
    Tools::rotOnZ(_direction, angle);

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
    _position += _direction * _moveSpeed;
}
