#pragma once 

#include "Vehicle.h"
#include "Highway.h"

struct HighwayPatrol : Vehicle 
{
    HighwayPatrol();
    ~HighwayPatrol() override;

    void scanHighway(Highway* h);

    void pullOver( Vehicle* v, bool willArrest, Highway* h );
};
