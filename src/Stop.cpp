/*
 * Stop.cpp
 *
 *  Created on: Apr 16, 2018
 *      Author: Pitva
 */

#include "Stop.h"

Stop::Stop(string description) : Effect(description)
{

}

void Stop::Deploy(PTR_Player player, PTR_Player player2, int casselliCount)
{
	player->SetStop(true);
}
