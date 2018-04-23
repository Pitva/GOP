/*
 * Effect.cpp
 *
 *  Created on: Mar 12, 2018
 *      Author: Pitva
 */

#include "Effect.h"
#include <string>
#include <iostream>

using namespace std;

Effect::Effect(string description)
{
	this->description = description;
}

void Effect::PrintEffect()
{
	cout << "L'effetto e': " << this->description;
}

void Effect::Deploy(PTR_Player player, PTR_Player player2, int casselliCount = 0)
{

}

Effect::~Effect()
{

}
