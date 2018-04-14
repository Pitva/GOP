/*
 * Player.h
 *
 *  Created on: Mar 12, 2018
 *      Author: Pitva
 */

#ifndef PLAYER_H_
#define PLAYER_H_
#include <string>
#include <iostream>

using namespace std;

class Player
{
	public:
		Player(string name, char pawn);
		int GetPosition();
		void SetPosition(int value);
		char GetPawn();
		void SetPawn(char value);
		string GetName();
		void Move(int steps);
		void PrintPlayer();
		virtual ~Player();

	protected:
		int position;
		string name;
		char pawn;
};

typedef Player *PTR_Player;

#endif /* PLAYER_H_ */
