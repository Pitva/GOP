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

void Swap::Deploy(PTR_Player player, PTR_Player player2)
{
	int tmp = player->GetPosition();
	player->SetPosition(player2->GetPosition());
	player2->SetPosition(tmp);
}
