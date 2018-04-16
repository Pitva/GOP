/*
 * StepBack.h
 *
 *  Created on: Apr 16, 2018
 *      Author: Pitva
 */

#ifndef STEPBACK_H_
#define STEPBACK_H_

#include "Effect.h"

class StepBack: public Effect
{
	public:
		StepBack(string description);
		void Deploy(PTR_Player player);
};

#endif /* STEPBACK_H_ */