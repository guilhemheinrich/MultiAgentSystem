#ifndef OVERMIND_H
#define OVERMIND_H

#include <vector>

#include "cpplinq.hpp"
#include "abstractagent.h"

const int NB_AGENT_OF_TEAM = 5;

class OverMind
{
private:
   std::vector<AbstractAgent *> _allAgents;

public:
    OverMind();
    std::vector<AbstractAgent *> allAgents() const;
    void setAllAgents(const std::vector<AbstractAgent *> &allAgents);
};

#endif // OVERMIND_H
