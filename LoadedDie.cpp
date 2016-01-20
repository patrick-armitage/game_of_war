/*******************************************************************************
** Author: Patrick Armitage
** Date: 01/17/2016
** Description: LoadedDie methods file which defines the methods of the
** LoadedDie class that were prototyped within the GameBoard header file
*******************************************************************************/
#include <stdlib.h>
#include <iostream>

#include "Die.hpp"
#include "LoadedDie.hpp"

using std::cout;
using std::endl;

/*----------------------------------------------------------------------------*/
/*
    Function Name: LoadedDie
    Function Parameters: integer number of dice sides
    What the function does: initializes a new instance of the LoadedDie class,
                            and also initializes and instance of the parent
                            Die class
*/
LoadedDie::LoadedDie(int sides) : Die(sides) {}

/*----------------------------------------------------------------------------*/
/*
    Function Name: roll
    Function Parameters: N/A
    What the function does: overwrites the parent Die::roll() method,
                            calculating instead a "loaded" version of the dice
                            roll which never equals less than half the number
                            of sides of the LoadedDie instance
*/
int LoadedDie::roll() {
    int roll;
    int sides = getSides();

    int mod = sides / 2;
    // this ensures a roll of greater than half of sides (loaded dice, remember?)
    roll = (rand() % mod) + mod;
    return roll;
}
