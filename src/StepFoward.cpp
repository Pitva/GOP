/*
 * StepFoward.cpp
 *
 *  Created on: Apr 16, 2018
 *      Author: Pitva
 */

#include "StepFoward.h"

StepFoward::StepFoward(string description) : Effect(description)
{

}

void StepFoward::Deploy(PTR_Player player, PTR_Player player2, int casselliCount)
{
	player->Move(+ (rand() % 3 + 1));
}
