#include <string>
#include "LocalPlayer.h"

#ifndef MANAGER_H_
#define MANAGER_H_

using namespace std;

class Manager
{
public:
    Manager();
    PlayerId& getLeader();
    void setLeader(PlayerId&);
    void addRobot(PlayerId&);
    void getRobot(PlayerId&);
    bool isDead(PlayerId&);
    bool isAttacker(PlayerId&);
    bool isDefender(PlayerId&);
private:
    int numRobots = 0;
    PlayerId& leader;
};

#endif
