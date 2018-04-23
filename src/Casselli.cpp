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
	if (type == E_Harmless)
	{
		cout << "\033[0;32m";		//green
	}
	else if (type == E_Effect)
	{
		cout << "\033[0;33m";		//yellow
	}
	else if (type == E_Swap)
	{
		cout << "\033[0;96m" ;		//cyan high intensity
	}
	else if (type == E_Stop)
	{
		cout << "\033[0;91m";		//red High intensity
	}
	else if (type == E_Teleport)
	{
		cout << "\033[1;34m";		//bold blue
	}
	else if (type == E_Card)
	{
		cout << "\033[0;35m";		//purple
	}

	cout << "|" << this->position << "|" << " ";
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
