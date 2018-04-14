/*
 * Card.h
 *
 *  Created on: Mar 12, 2018
 *      Author: Pitva
 */

#ifndef CARD_H_
#define CARD_H_
#include <string>
#include <iostream>

#include "Effect.h"
using namespace std;

class Card {
	public:
		Card(PTR_Effect effect);
		PTR_Effect GetEffect();
		virtual ~Card();

	protected:
		PTR_Effect effect;
};



#endif /* CARD_H_ */
