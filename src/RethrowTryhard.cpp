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

void RethrowTryhard::Deploy(PTR_Player player, PTR_Player player2, int casselliCount)
{
	int h = 0;
	h = rand() % 20 + 1;
	cout << "Ritiro del dado: " << h;
	string waitToDeploy = "";
	cin >> waitToDeploy;
	player->SetPosition(player->GetPosition() + h);
	player->SetStop(true);
}
