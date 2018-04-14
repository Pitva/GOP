/*
 * Casselli.cpp
 *
 *  Created on: Mar 12, 2018
 *      Author: Pitva
 */

#include "Casselli.h"
#include <iostream>
using namespace std;

Casselli::Casselli(CasselliType type, int position, PTR_Effect effect)
{
	this->type = type;
	this->position = position;
	this->playersOn = false;
	this->effect = effect;
}

void Casselli::PrintCasselli()
{
	if (type == Innocuo)
	{
		cout << "\033[0;32m";
	}
	else if (type == Federicolo)
	{
		cout << "\033[0;31m";
	}
	else if (type == Carta)
	{
		cout << "\033[0;35m";
	}

	cout << "|" << this->position << "|";
}

CasselliType Casselli::GetType()
{
	return this->type;
}

int Casselli::GetPosition()
{
	return this->position;
}

PTR_Effect Casselli::GetEffect()
{
	return this->effect;
}

bool Casselli::GetPlayersOn()
{
	return this->playersOn;
}

void Casselli::SetPlayersOn(bool value)
{
	this->playersOn = value;
}

Casselli::~Casselli()
{

}
