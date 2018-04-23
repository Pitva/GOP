/*
 * StepBack.cpp
 *
 *  Created on: Apr 16, 2018
 *      Author: Pitva
 */

#include "StepBack.h"

StepBack::StepBack(string description) : Effect(description)
{

}

void StepBack::Deploy(PTR_Player player, PTR_Player player2, int casselliCount)
{
	player->SetPosition(player->GetPosition() - (rand() % 3 + 1));
}
