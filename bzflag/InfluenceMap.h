#include <math.h>
#include "World.h"
#include "LocalPlayer.h"
#include "BZDBCache.h"
#include "playing.h"
#include "RobotPlayer.h"
#include "Player.h"
#include "global.h"

#ifndef INFLUENCE_MAP_H
#define INFLUENCE_MAP_H

#define INF -5
#define C -1

class InfluenceMap
{
public:
    InfluenceMap();
    float getInfluence(float, float);
private:
    int x, y;
private:
    float getDistance(const float[2], const float[2]);
};

#endif
