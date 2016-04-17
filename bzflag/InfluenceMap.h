#include <math.h>
#include "World.h"
#include "LocalPlayer.h"
#include "BZDBCache.h"
#include "playing.h"
#include "RobotPlayer.h"

#define SCALE BZDBCache::tankRadius;
#define INF -5
#define C -1

class InfluenceMap
{
public:
    InfluenceMap();
    int getInfluence(int, int);
private:
    int x, y;
private:
    float getDistance(const float[2], const float[2]);
};