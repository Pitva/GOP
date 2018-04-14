/*
 * Dice.cpp
 *
 *  Created on: Apr 9, 2018
 *      Author: Pitva
 */

#include "Dice.h"
#include <ctime>
#include <iostream>

using namespace std;

Dice::Dice()
{
	this->faces = 6;
}

Dice::Dice(int faces)
{
	this->faces = faces;
}

int Dice::Roll()
{
	return rand() % this->faces + 1;
}

Dice::~Dice()
{

}
