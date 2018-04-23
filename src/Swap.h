/*
 * Swap.h
 *
 *  Created on: Apr 16, 2018
 *      Author: Pitva
 */

#ifndef SWAP_H_
#define SWAP_H_

#include "Effect.h"

class Swap: public Effect
{
	public:
		Swap(string description);
		void Deploy(PTR_Player &player, PTR_Player &player2);
};

#endif /* SWAP_H_ */
