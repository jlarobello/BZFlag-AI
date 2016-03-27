/*
 * Defines the classes used for decision trees.
 *
 * Part of the Artificial Intelligence for Games system.
 *
 * Copyright (c) Ian Millington 2003-2006. All Rights Reserved.
 *
 * This software is distributed under licence. Use of this software
 * implies agreement with all terms and conditions of the accompanying
 * software licence.
 */
#include "dectree.h"

namespace aicore
{
    /*
     * Function Name: Decision
     * Desc: Returns decision with Decision.
     * Params: bot - current robot
     *         dt - game time
     * Return: DecisionTreeNode*
     */
    DecisionTreeNode* Decision::makeDecision(RobotPlayer* bot, float dt)
    {
        // Choose a branch based on the getBranch method
        if (getBranch(bot, dt)) {
            // Make sure its not null before recursing.
            if (trueBranch == NULL) return NULL;
            else return trueBranch->makeDecision(bot, dt);
        }
        else {
            // Make sure its not null before recursing.
            if (falseBranch == NULL) return NULL;
            else return falseBranch->makeDecision(bot, dt);
        }
    }

    /*
     * Function Name: makeDecision
     * Desc: Returns decision action with DecisionPtr
     * Params: bot - currrent robot
     *         dt - game time
     * Return: DecisionTreeNode*
     */
    DecisionTreeNode* DecisionPtr::makeDecision(RobotPlayer* bot, float dt)
    {
        // Choose a branch based on the getBranch method
        if (getBranch(bot, dt)) {
            // Make sure its not null before recursing.
            if (trueBranch == NULL) return NULL;
            else return trueBranch->makeDecision(bot, dt);
        }
        else {
            // Make sure its not null before recursing.
            if (falseBranch == NULL) return NULL;
            else return falseBranch->makeDecision(bot, dt);
        }
    }

    /*
     * Function Name: getBranch
     * Desc: uses specified decFuncPtr in node to get decision.
     * Params: bot - the current robot
     *         dt - game time
     * Return: bool
     */
    bool DecisionPtr::getBranch(RobotPlayer* bot, float dt)
    {
        return (bot->*decFuncPtr)(dt);
    }

    // Set up the trees
    void DecisionTrees::init()
    {
        // set up doUpdateMotion
        doUpdateMotionDecisions[0].decFuncPtr  = &RobotPlayer::amAlive;
        doUpdateMotionDecisions[0].trueBranch  = &doUpdateMotionDecisions[1];
        doUpdateMotionDecisions[0].falseBranch = &doUpdateMotionActions[0];

        doUpdateMotionDecisions[1].decFuncPtr  = &RobotPlayer::beingShotAt;
        doUpdateMotionDecisions[1].trueBranch  = &doUpdateMotionActions[1];
        doUpdateMotionDecisions[1].falseBranch = &doUpdateMotionActions[2];

        doUpdateMotionActions[0].actFuncPtr = &RobotPlayer::doNothing;
        doUpdateMotionActions[1].actFuncPtr = &RobotPlayer::evade;
        doUpdateMotionActions[2].actFuncPtr = &RobotPlayer::followPath;

        // set up dropFlag
        dropFlagDecision[0].decFuncPtr  = &RobotPlayer::amAlive;
        dropFlagDecision[0].trueBranch  = &dropFlagDecision[1];
        dropFlagDecision[0].falseBranch = &dropFlagActions[0];

        dropFlagDecision[1].decFuncPtr  = &RobotPlayer::isBotHoldingFlag;
        dropFlagDecision[1].trueBranch  = &dropFlagDecision[2];
        dropFlagDecision[1].falseBranch = &dropFlagActions[0];

        dropFlagDecision[2].decFuncPtr  = &RobotPlayer::isStickyFlag;
        dropFlagDecision[2].trueBranch  = &dropFlagActions[0];
        dropFlagDecision[2].falseBranch = &dropFlagDecision[3];

        dropFlagDecision[3].decFuncPtr  = &RobotPlayer::isTeamFlag;
        dropFlagDecision[3].trueBranch  = &dropFlagDecision[4];
        dropFlagDecision[3].falseBranch = &dropFlagActions[1];

        dropFlagDecision[4].decFuncPtr  = &RobotPlayer::isMyTeamFlag;
        dropFlagDecision[4].trueBranch  = &dropFlagActions[1];
        dropFlagDecision[4].falseBranch = &dropFlagActions[0];

        dropFlagActions[0].actFuncPtr = &RobotPlayer::doNothing;
        dropFlagActions[1].actFuncPtr = &RobotPlayer::dropFlag;

        // set up shot
        shotDecisions[0].decFuncPtr  = &RobotPlayer::amAlive;
        shotDecisions[0].trueBranch  = &shotDecisions[1];
        shotDecisions[0].falseBranch = &shotActions[0];

        shotDecisions[1].decFuncPtr  = &RobotPlayer::isFiringStatusReady;
        shotDecisions[1].trueBranch  = &shotDecisions[2];
        shotDecisions[1].falseBranch = &shotActions[0];

        shotDecisions[2].decFuncPtr  = &RobotPlayer::isTimerReady;
        shotDecisions[2].trueBranch  = &shotDecisions[3];
        shotDecisions[2].falseBranch = &shotActions[0];

        shotDecisions[3].decFuncPtr  = &RobotPlayer::willShotNotMiss;
        shotDecisions[3].trueBranch  = &shotDecisions[4];
        shotDecisions[3].falseBranch = &shotActions[0];

        shotDecisions[4].decFuncPtr  = &RobotPlayer::isBuildingsInWay;
        shotDecisions[4].trueBranch  = &shotActions[0];
        shotDecisions[4].falseBranch = &shotDecisions[5];

        shotDecisions[5].decFuncPtr  = &RobotPlayer::isTeammatesInWay;
        shotDecisions[5].trueBranch  = &shotActions[1];
        shotDecisions[5].falseBranch = &shotActions[2];

        shotActions[0].actFuncPtr = &RobotPlayer::doNothing;
        shotActions[1].actFuncPtr = &RobotPlayer::resetShotTimer;
        shotActions[2].actFuncPtr = &RobotPlayer::fireBotShot;
    }

    // Decisions
    DecisionPtr DecisionTrees::doUpdateMotionDecisions[2];
    DecisionPtr DecisionTrees::shotDecisions[6];
    DecisionPtr DecisionTrees::dropFlagDecision[5];

    // Actions
    ActionPtr DecisionTrees::doUpdateMotionActions[3];
    ActionPtr DecisionTrees::shotActions[3];
    ActionPtr DecisionTrees::dropFlagActions[2];

}; // end of namespace
