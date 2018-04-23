/*
 * ReThow.h
 *
 *  Created on: Apr 16, 2018
 *      Author: Pitva
 */

#ifndef RETHROW_H_
#define RETHROW_H_

#include "Effect.h"

class Rethrow: public Effect
{
	public:
		Rethrow(string description);
		void Deploy(PTR_Player &player);
};

#endif /* RETHROW_H_ */
