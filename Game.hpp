/*******************************************************************************
** Author: Patrick Armitage
** Date: 01/19/2016
** Description: Game class prototypes, defining a number of private data
** members used to facilitate the game, getters and setters for those members,
** and functions which enable starting a game, running each round, and
** finishing the game.
*******************************************************************************/

#include "Player.hpp"

#ifndef GAME_HPP
#define GAME_HPP

class Game {
 private:
    int numRounds;
    int currentRound;
    Player* playerOne;
    Player* playerTwo;
 public:
    Game(Player *playerOne, Player *playerTwo, int numRds);
    void setNumRounds(int numRds);
    void setCurrentRound(int currRound);
    void setPlayerOne(Player* p1);
    void setPlayerTwo(Player* p2);
    int getNumRounds();
    int getCurrentRound();
    Player* getPlayerOne();
    Player* getPlayerTwo();
    void startGame();
    void playRound();
    void determineRound();
    void determineWinner();
    void incRounds();
    void finishGame();
};

#endif
