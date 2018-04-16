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
		void Deploy(PTR_Player player);
};

#endif /* SWAP_H_ */
