#ifndef EXPLORE_H
#define EXPLORE_H

#include <QDebug>

#include "stateagent.h"


class Explore : public StateAgent
{
public:
    Explore();
    void doAction() override;
};

#endif // EXPLORE_H
