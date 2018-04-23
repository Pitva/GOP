/*
 * Stop.h
 *
 *  Created on: Apr 16, 2018
 *      Author: Pitva
 */

#ifndef STOP_H_
#define STOP_H_

#include "Effect.h"

class Stop: public Effect
{
	public:
		Stop(string description);
		void Deploy(PTR_Player player);
};

#endif /* STOP_H_ */
