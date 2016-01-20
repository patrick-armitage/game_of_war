/*******************************************************************************
** Author: Patrick Armitage
** Date: 01/19/2016
** Description: Die class prototypes, which include one private data member,
** getters and setters, and a virtual method roll() which calculates dice roll
** and is overwritten by the child class.
*******************************************************************************/

#ifndef DIE_HPP
#define DIE_HPP

class Die {
 protected:
    int sides;
 public:
    Die(int sides);
    void setSides(int sides);
    int getSides();
    virtual int roll();
};

#endif
