/*
 * RethrowTryhard.h
 *
 *  Created on: Apr 16, 2018
 *      Author: Pitva
 */

#ifndef RETHROWTRYHARD_H_
#define RETHROWTRYHARD_H_

#include "Effect.h"

class RethrowTryhard : public Effect
{
	public:
		RethrowTryhard(string description);
		void Deploy(PTR_Player player);
};

#endif /* RETHROWTRYHARD_H_ */
