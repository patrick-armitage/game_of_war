/*******************************************************************************
** Author: Patrick Armitage
** Date: 01/19/2016
** Description: Die methods file which defines the methods of the
** die class that were prototyped within the GameBoard header file
*******************************************************************************/

#include <stdlib.h>
#include <iostream>
#include "Die.hpp"

using std::cout;
using std::endl;

/*----------------------------------------------------------------------------*/
/*
    Function Name: Die
    Function Parameters: integer number of sides
    What the function does: initializes a new instance of the Die class,
                            setting number of sides to the provided sides arg
*/
Die::Die(int sides) {
    setSides(sides);
}

/*----------------------------------------------------------------------------*/
/*
    Function Names: getSides, setSides
    Functions' Parameters: setSides has an integer sides parameter
    What the functions do: getters and setters which act as public options to
                           read/write the Die class's private attribute methods
*/

void Die::setSides(int s) {
    sides = s;
}

int Die::getSides() {
    return sides;
}

/*----------------------------------------------------------------------------*/
/*
    Function Name: roll
    Function Parameters: N/A
    What the function does: calculates a random rolled integer between 1 and the
                            number of sides of the dice being rolled
*/
int Die::roll() {
    // unsigned int seed;
    int roll;
    int sides = getSides() - 1;

    // return a random number between 1 and number of sides
    roll = (rand() % sides) + 1;
    return roll;
}
