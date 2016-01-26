#include "overmind.h"

OverMind::OverMind()
{
    std::srand(std::time(NULL));
    for(int i = 0; i < NB_AGENT_OF_TEAM; i++)
    {
        _allAgents.push_back(new AbstractAgent(1));
        _allAgents.push_back(new AbstractAgent(2));
    }
}

std::vector<AbstractAgent *> OverMind::allAgents() const
{
    return _allAgents;
}

void OverMind::setAllAgents(const std::vector<AbstractAgent *> &allAgents)
{
    _allAgents = allAgents;
}

void OverMind::updateAgent()
{
    for(AbstractAgent *agent : _allAgents)
    {
        agent->update();
    }
}
