#include <math.h>
#include "World.h"
#include "LocalPlayer.h"
#include "BZDBCache.h"
#include "playing.h"
#include "RobotPlayer.h"

#define INF -5
#define C -1

class InfluenceMap
{
public:
    InfluenceMap();
    double getInfluence(float, float);
private:
    int x, y;
private:
    float getDistance(const float[2], const float[2]);
};