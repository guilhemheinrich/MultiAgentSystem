#ifndef OVERMIND_H
#define OVERMIND_H

#include <vector>
#include <QObject>

#include "cpplinq.hpp"
#include "abstractagent.h"

const int NB_AGENT_OF_TEAM = 5;

class OverMind : public QObject
{
    Q_OBJECT
private:
   std::vector<AbstractAgent *> _allAgents;

public:
    OverMind();
    std::vector<AbstractAgent *> allAgents() const;
    void setAllAgents(const std::vector<AbstractAgent *> &allAgents);

public slots:
    void updateAgent();
};

#endif // OVERMIND_H
