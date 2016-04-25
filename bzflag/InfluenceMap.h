#include "RobotPlayer.h"
#include "AStarNode.h"
#include <math.h>
#include "common.h"
#include "BZDBCache.h"
#include "World.h"
#include "playing.h" // needed for controlPanel

#ifndef INFLUENCE_MAP_H
#define INFLUENCE_MAP_H

#define INFL 10

class InfluenceMap
{
public:
    InfluenceMap();
    float getInfluence(float, float);
private:
    int x, y;
private:
    float getDistance(const float[3], const float[3]);
};

#endif
