/*
 * Dice.h
 *
 *  Created on: Apr 9, 2018
 *      Author: Pitva
 */

#ifndef DICE_H_
#define DICE_H_

class Dice {
	public:
		Dice();
		Dice(int faces);
		int Roll();
		virtual ~Dice();

	protected:
		int faces;
};

#endif /* DICE_H_ */
