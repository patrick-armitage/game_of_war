/*******************************************************************************
** Author: Patrick Armitage
** Date: 01/19/2016
** Description: Game methods file which defines the methods of the Game class
** that were prototyped within the Game header file
*******************************************************************************/

#include <iostream>
#include "Game.hpp"

using std::cout;
using std::endl;

/*----------------------------------------------------------------------------*/
/*
    Function Name: Game
    Function Parameters: The game's two players and total number of rounds
    What the function does: Initializes a new Game instance with players,
                            total rounds, and current round set to 1

*/
Game::Game(Player* p1, Player* p2, int numRds) {
    setNumRounds(numRds);
    setPlayerOne(p1);
    setPlayerTwo(p2);
    setCurrentRound(1);
}

/*----------------------------------------------------------------------------*/
/*
    Function Names: setNumRounds, setCurrentRound, setPlayerOne, setPlayerTwo,
                    getNumRounds, getCurrentRound, getPlayerOne, getPlayerTwo
    Functions' Parameters: each setter receives one integer param with the value
                           of the attribute it is going to set
    What the functions do: a series of getters and setters which act as public
                           options to read/write the Game class's private
                           attribute methods
*/

void Game::setNumRounds(int numRds) {
    numRounds = numRds;
}

void Game::setCurrentRound(int currRound) {
    currentRound = currRound;
}

void Game::setPlayerOne(Player* p1) {
    playerOne = p1;
}

void Game::setPlayerTwo(Player* p2) {
    playerTwo = p2;
}

int Game::getNumRounds() {
    return numRounds;
}

int Game::getCurrentRound() {
    return currentRound;
}

Player* Game::getPlayerOne() {
    return playerOne;
}

Player* Game::getPlayerTwo() {
    return playerTwo;
}

/*----------------------------------------------------------------------------*/
/*
    Function Name: playRound
    Function Parameters: N/A
    What the function does: Executes one round of the game, rolling each
                            player's dice and checking to see if the current
                            round is the last round.  When it is, finishes
                            the round and the game, otherwise finishes the
                            current round and increments the currentRound count
*/
void Game::playRound() {
    Player *p1 = getPlayerOne();
    Player *p2 = getPlayerTwo();
    p1->rollDice();
    p2->rollDice();

    int numRounds = getNumRounds();
    int currRound = getCurrentRound();

    if (numRounds == currRound) {
        determineRound();
        determineWinner();
    } else {
        determineRound();
        incRounds();
    }
}

/*----------------------------------------------------------------------------*/
/*
    Function Name: determineRound
    Function Parameters: N/A
    What the function does: Initializes a new Game instance with players,
                            total rounds, and current round set to 1
*/
void Game::determineRound() {
    Player* p1 = getPlayerOne();
    Player* p2 = getPlayerTwo();
    int p1Roll = p1->getLastRoll();
    int p2Roll = p2->getLastRoll();
    int currRound = getCurrentRound();

    if (p1Roll > p2Roll) {
        p1->incWins();
        cout << p1->getPlayerName() << " wins round " << getCurrentRound() << "!!" << endl;
    } else if (p2Roll > p1Roll) {
        p2->incWins();
        cout << p2->getPlayerName() << " wins round " << getCurrentRound() << "!!" << endl;
    } else {
        cout << "Round " << currRound << " is a tie!" << endl;
        p1->incWins();
        p2->incWins();
    }

    setCurrentRound(currRound + 1);
}

/*----------------------------------------------------------------------------*/
/*
    Function Name: determineWinner
    Function Parameters: N/A
    What the function does: Checks to see the number of wins of each of the
                            players and compares them.  If there is a clear
                            winner, declares the winner, otherwise declares
                            the game a tie
*/
void Game::determineWinner() {
    Player* p1 = getPlayerOne();
    Player* p2 = getPlayerTwo();
    int p1Wins = p1->getWins();
    int p2Wins = p2->getWins();


    cout << endl;
    cout << p1->getPlayerName() << " won " << p1Wins << " rounds!" << endl;
    cout << p2->getPlayerName() << " won " << p2Wins << " rounds!" << endl;
    if (p1Wins > p2Wins) {
        cout << p1->getPlayerName() << " is the winner!!!" << endl;
    } else if (p2Wins > p1Wins) {
        cout << p2->getPlayerName() << " is the winner!!!" << endl;
    } else {
        cout << "It's a draw!";
    }

    finishGame();
}


/*----------------------------------------------------------------------------*/
/*
    Function Name: incRounds
    Function Parameters: N/A
    What the function does: Increment the currentRound so that playRound plays
                            the correct round when it is next called
*/
void Game::incRounds() {
    int currRound = getCurrentRound();
    setCurrentRound(currRound++);
}

/*----------------------------------------------------------------------------*/
/*
    Function Name: finishGame
    Function Parameters: N/A
    What the function does: Farewell messages printed for the user before
                            termination of the game program
*/
void Game::finishGame() {
    cout << "Thank you for playing WAR WITH DICE." << endl;
    cout << "Have a nice day!" << endl;
}
