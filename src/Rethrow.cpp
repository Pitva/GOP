/*
 * ReThow.cpp
 *
 *  Created on: Apr 16, 2018
 *      Author: Pitva
 */

#include "Rethrow.h"

Rethrow::Rethrow(string description) : Effect(description)
{

}

void Rethrow::Deploy(PTR_Player player, PTR_Player player2, int casselliCount)
{
	int h = 0;
	h = rand() % 6 + 1;
	cout << "Risultato del dado: " << h;
	player->Move(h);
}
