#include "InfluenceMap.h"
#include "AStarNode.h"
#include <math.h>
#include "common.h"
#include "BZDBCache.h"
#include "World.h"
#include "playing.h" // needed for controlPanel
#include "InfluenceMap.h"

InfluenceMap::InfluenceMap()
{

}

float InfluenceMap::getInfluence(float x, float y)
{
    float influence = 0;

    const float nodePos[2] = { x, y };

    for (int i = 0; i <= World::getWorld()->getCurMaxPlayers(); i++)
    {
        Player * p = NULL;
        const float * pos;   // p's position
        float distance = 0; // distance between robot and node
/*
		if (i < World::getWorld()->getCurMaxPlayers())
			p = World::getWorld()->getPlayer(i);
		else
			p = LocalPlayer::getMyTank();
		*/
		p = World::getWorld()->getPlayer(i);

		pos = p->getPosition();
        char buffer[256];
        sprintf(buffer, "Works: %f", World::getWorld()->getCurMaxPlayers());
        controlPanel->addMessage(buffer);
        if (p != NULL && p->getTeam() != TeamColor::GreenTeam)
        {
            distance   = getDistance(pos, nodePos);
            influence += ((INF / distance) + 1);
        }
    }

    return influence;
}

float InfluenceMap::getDistance(const float pos1[2], const float pos2[2])
{
    float pos[2];
    float distance = 0;

    pos[0] = (pos1[0] - pos2[0]);
    pos[1] = (pos1[1] - pos2[1]);

    distance = hypotf(pos[0], pos[1]);

    return distance;
}
