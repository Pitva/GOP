/*
 * Tp.h
 *
 *  Created on: Apr 16, 2018
 *      Author: Pitva
 */

#ifndef TELEPORT_H_
#define TELEPORT_H_

#include "Effect.h"

class Teleport: public Effect
{
	public:
		Teleport(string description);
		void Deploy(PTR_Player player);
};

#endif /* TELEPORT_H_ */