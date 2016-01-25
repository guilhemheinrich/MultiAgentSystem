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
    QVector2D direction() const;
    void setDirection(const QVector2D &direction);
    QVector3D position() const;
    void setPosition(const QVector3D &position);
    int team() const;
    void setTeam(int team);
};

#endif // ABSTRACTAGENT_H
