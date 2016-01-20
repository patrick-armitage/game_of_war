/*******************************************************************************
** Author: Patrick Armitage
** Date: 01/19/2016
** Description: LoadedDie class prototype which inherits functionality from the
** Die parent class and adds only its own constructor, and overrides the
** parent's roll() class in order to reflect logic for a loaded roll.
*******************************************************************************/

#include "Die.hpp"

#ifndef LOADEDDIE_HPP
#define LOADEDDIE_HPP

class LoadedDie : public Die {
 public:
    LoadedDie(int sides);
    virtual int roll();
};

#endif
