/*
 * Effect.h
 *
 *  Created on: Mar 12, 2018
 *      Author: Pitva
 */

#ifndef EFFECT_H_
#define EFFECT_H_

#include "Player.h"
#include <string>
#include <iostream>

using namespace std;

class Effect
{
	public:
		Effect(string description);
		virtual void Deploy(PTR_Player &player, PTR_Player &player2, int casselliCount);
		void PrintEffect();
		virtual ~Effect();

	protected:
		string description;
};

typedef Effect *PTR_Effect;

#endif /* EFFECT_H_ */
