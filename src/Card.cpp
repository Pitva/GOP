/*
 * Card.cpp
 *
 *  Created on: Mar 12, 2018
 *      Author: Pitva
 */

#include "Card.h"

Card::Card(PTR_Effect effect)
{
	this->effect = effect;
}

Card::~Card()
{
}

PTR_Effect Card::GetEffect()
{
	 return this->effect;
}

