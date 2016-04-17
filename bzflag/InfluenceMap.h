#include "RobotPlayer.h"

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
    float getDistance(const float[3], const float[3]);
};

#endif
