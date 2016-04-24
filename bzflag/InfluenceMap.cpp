#include "InfluenceMap.h"

InfluenceMap::InfluenceMap()
{

}

float InfluenceMap::getInfluence(float x, float y)
{
    float influence = 0;

    const float nodePos[2] = { x, y };

    for (int i = 1; i <= World::getWorld()->getCurMaxPlayers(); i++)
    {
        Player * p = NULL;
        const float * pos;   // p's position
        float distance = 0; // distance between robot and node

		p = World::getWorld()->getPlayer(i);
        
        if (p != NULL && p->getTeam() != TeamColor::GreenTeam)
        {
            pos = p->getPosition();
            distance   = getDistance(pos, nodePos);
            influence += (distance <= 250) ? ((INFL / distance) + 1) : 0;
        }
    }

    return influence;
}

float InfluenceMap::getDistance(const float pos1[3], const float pos2[3])
{
    float pos[2];
    float distance = 0;

    pos[0] = (pos1[0] - pos2[0]);
    pos[1] = (pos1[1] - pos2[1]);

    distance = hypotf(pos[0], pos[1]);

    return distance;
}
