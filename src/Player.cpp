/*
 * Player.cpp
 *
 *  Created on: Mar 12, 2018
 *      Author: Pitva
 */

#include "Player.h"

Player::Player(string name, char pawn)
{
	this->name = name;
	this->pawn = pawn;
	this->position = 0;
	this->stop = false;
}

void Player::PrintPlayer()
{
	cout << "Nome: " << this->name << ", ";
	cout << "Pedina: " << this->pawn << ", ";
	cout << "Posizione: " << this->position << "; ";
}

string Player::GetName()
{
	return this->name;
}

int Player::GetPosition()
{
	return this->position;
}

void Player::SetPosition(int value)
{
	this->position = this->position + value;
}

char Player::GetPawn()
{
	return this->pawn;
}

void Player::SetPawn(char value)
{
	this->pawn = value;
}

bool Player::GetStop()
{
	return this->stop;
}

void Player::SetStop(bool value)
{
	this->stop = value;
}

void Player::Move(int steps)
{
	this->position += steps;
}

Player::~Player()
{

}
