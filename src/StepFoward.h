/*
 * StepFoward.h
 *
 *  Created on: Apr 16, 2018
 *      Author: Pitva
 */

#ifndef STEPFOWARD_H_
#define STEPFOWARD_H_

#include "Effect.h"

class StepFoward: public Effect
{
	public:
		StepFoward(string description);
		void Deploy(PTR_Player player);
};

#endif /* STEPFOWARD_H_ */
