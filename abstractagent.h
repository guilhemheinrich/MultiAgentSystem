#ifndef ABSTRACTAGENT_H
#define ABSTRACTAGENT_H

#include <iostream>

#include <QDebug>
#include <QVector2D>
#include <QVector3D>

#include <ctime>
#include <cmath>

#include "tools.h"
#include "StateAgent/stateagent.h"
#include "StateAgent/explore.h"

class AbstractAgent
{
private:
    int _team;
    float _moveSpeed;
    float _vision;
    QVector2D _direction;
    QVector3D _position;

    StateAgent* _state;
public:
    AbstractAgent(int);
    QVector2D direction() const;
    void setDirection(const QVector2D &direction);
    QVector3D position() const;
    void setPosition(const QVector3D &position);
    int team() const;
    void update();
    StateAgent *state() const;
    void setState(StateAgent *state);
};

#endif // ABSTRACTAGENT_H
