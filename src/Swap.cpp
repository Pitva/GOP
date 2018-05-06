/*
 * Swap.cpp
 *
 *  Created on: Apr 16, 2018
 *      Author: Pitva
 */

#include "Swap.h"

Swap::Swap(string description) : Effect(description)
{

}

void Swap::Deploy(PTR_Player player, PTR_Player player2, int casselliCount)
{
	int tmp = player->GetPosition();
	player->MoveTo(player2->GetPosition());
	player2->MoveTo(tmp);
}
