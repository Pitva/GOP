/*
 * RethrowTryhard.cpp
 *
 *  Created on: Apr 23, 2018
 *      Author: Pitva
 */

#include "RethrowTryhard.h"

RethrowTryhard::RethrowTryhard(string description) : Effect(description)
{

}

void RethrowTryhard::Deploy(PTR_Player player)
{
	int h = 0;
	h = rand() % 20 + 1;
	cout << "Ritiro del dado: " << h;
	player->SetPosition(player->GetPosition() + h);
	player->SetStop(true);
}
