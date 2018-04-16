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
	cout << "L'effetto è: " << this->description;
}

Effect::~Effect()
{

}
