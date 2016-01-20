/*******************************************************************************
** Author: Patrick Armitage
** Date: 01/17/2016
** Description: GameBoard methods file which defines the methods of the
** GameBoard class that were prototyped within the GameBoard header file
*******************************************************************************/

#include <iostream>
#include <string>
#include "Die.hpp"
#include "LoadedDie.hpp"
#include "Player.hpp"

using std::cout;
using std::endl;
using std::string;

/*----------------------------------------------------------------------------*/
/*
    Function Name: Player
    Function Parameters: player's name string and dice object instance
    What the function does: Initializes a new Player instance, setting the
                            player's name and dice instance, and setting wins
                            to zero

*/
Player::Player(string playerName, Die *die) {
    setPlayerName(playerName);
    setDie(die);
    setWins(0);
}

/*----------------------------------------------------------------------------*/
/*
    Function Names: setDie, setLastRoll, setWins, setPlayerName, getDie,
                    getLastRoll, getWins, getPlayerName
    Functions' Parameters: each setter receives one param with the value
                           of the attribute it is going to set
    What the functions do: a series of getters and setters which act as public
                           options to read/write the Player class's private
                           attribute methods
*/

void Player::setDie(Die* d) {
    die = d;
}

void Player::setLastRoll(int lR) {
    lastRoll = lR;
}

void Player::setWins(int w) {
    wins = w;
}

void Player::setPlayerName(string pN) {
    playerName = pN;
}

Die* Player::getDie() {
    return die;
}

int Player::getLastRoll() {
    return lastRoll;
}

int Player::getWins() {
    return wins;
}

string Player::getPlayerName() {
    return playerName;
}

/*----------------------------------------------------------------------------*/
/*
    Function Name: incWins
    Function Parameters: N/A
    What the function does: Increments the number of wins a player has by 1

*/
void Player::incWins() {
    wins++;
}

/*----------------------------------------------------------------------------*/
/*
    Function Name: rollDice
    Function Parameters: N/A
    What the function does: calls roll() upon a player's die instance, printing
                            the result of the dice roll and setting the
                            lastRoll to the result

*/
void Player::rollDice() {
    Die *die = getDie();

    int roll = die->roll();
    cout << getPlayerName() << " rolled a " << roll << "!" << endl;
    setLastRoll(roll);
}
