/*
 * Tp.cpp
 *
 *  Created on: Apr 16, 2018
 *      Author: Pitva
 */

#include "Teleport.h"
#include <iostream>

Teleport::Teleport(string description) : Effect(description)
{

}

void Teleport::Deploy(PTR_Player player, PTR_Player player2, int casselliCount)
{
	player->SetPosition(rand() % casselliCount);
}

