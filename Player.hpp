/*******************************************************************************
** Author: Patrick Armitage
** Date: 01/19/2016
** Description: Player class prototypes, defining a number of private data
** members used to facilitate the game, getters and setters for those members,
** and a rollDice function which calls roll() on the *die object.
*******************************************************************************/
#include <string>
#include "Die.hpp"
#include "LoadedDie.hpp"

#ifndef PLAYER_HPP
#define PLAYER_HPP

using std::string;

class Player {
 private:
    Die* die;
    int wins;
    int lastRoll;
    string playerName;
 public:
    Player(string playerName, Die *die);
    void setDie(Die* die);
    void setLastRoll(int lastRoll);
    void setWins(int wins);
    void setPlayerName(string playerName);
    Die* getDie();
    int getLastRoll();
    int getWins();
    string getPlayerName();
    void incWins();
    void rollDice();
};

#endif
