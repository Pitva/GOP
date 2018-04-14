/*
 * Casselli.h
 *
 *  Created on: Mar 12, 2018
 *      Author: Pitva
 */

#ifndef CASSELLI_H_
#define CASSELLI_H_

#include "Effect.h"
#include "Player.h"
#include <string>
#include <queue>
#include <iostream>

using namespace std;

enum CasselliType
{
	Innocuo,
	Federicolo,
	Carta
};

class Casselli {
	public:
		Casselli(CasselliType type, int position, PTR_Effect effect);
		int GetPosition();
		PTR_Effect GetEffect();
		CasselliType GetType();
		bool GetPlayersOn();
		void SetPlayersOn(bool value);
		virtual void PrintCasselli();
		virtual ~Casselli();

	protected:
		CasselliType type;
		bool playersOn;
		int position;
		PTR_Effect effect;
};

typedef Casselli *PTR_Casselli;

#endif /* CASSELLI_H_ */
