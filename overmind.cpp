#include "overmind.h"

std::vector<AbstractAgent *> OverMind::allAgents() const
{
    return _allAgents;
}

void OverMind::setAllAgents(const std::vector<AbstractAgent *> &allAgents)
{
    _allAgents = allAgents;
}

OverMind::OverMind()
{
    for(int i = 0; i < NB_AGENT_OF_TEAM; i++)
    {
        _allAgents.push_back(new AbstractAgent(1));
        _allAgents.push_back(new AbstractAgent(2));
    }
}

