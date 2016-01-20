#include <iostream>
#include <string>

#include "Player.hpp"
#include "Die.hpp"
#include "LoadedDie.hpp"
#include "Game.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {
    /* Initialize empty config vars */
    string p1Name, p2Name, p1HasLoaded, p2HasLoaded;
    int p1DieSides, p2DieSides, numRounds;
    Die *p1Die, *p2Die;

    /* Get Player 1 Info */
    cout << "Welcome to the Game of WAR~" << endl;
    cout << "Please input the name of Player 1: ";
    cin >> p1Name;
    cout << "How many-sided dice does " << p1Name << " possess? ";
    cin >> p1DieSides;
    cout << "Is " << p1Name << "'s " << p1DieSides << "-sided die loaded? [Y/N] ";
    cin >> p1HasLoaded;

    /* Initialize either Die or LoadedDie for Player 1 */
    if (p1HasLoaded == "Y") {
        cout << "Really?  That doesn't seem fair, but, as you wish..." << endl;
        LoadedDie* ld1 = new LoadedDie(p1DieSides);
        p1Die = ld1;
    } else {
        p1Die = new Die(p1DieSides);
    }

    /* Get Player 2 Info */
    cout << "Please input the name of Player 2: ";
    cin >> p2Name;
    cout << "How many-sided dice does " << p2Name << " possess? ";
    cin >> p2DieSides;
    cout << "Is " << p2Name << "'s " << p2DieSides << "-sided die loaded? [Y/N] ";
    cin >> p2HasLoaded;

    /* Initialize either Die or LoadedDie for Player 2 */
    if (p2HasLoaded == "Y") {
        if (p1HasLoaded == "Y") {
            cout << "Okay, at least they're evenly matched now!" << endl;
        } else {
            cout << "Really?  That doesn't seem fair, but, as you wish..." << endl;
        }

        LoadedDie* ld2 = new LoadedDie(p1DieSides);
        p2Die = ld2;
    } else {
        cout << "Alright...  I'm rooting for the underdog.  Go " << p2Name << "!!" << endl;
        p2Die = new Die(p2DieSides);
    }

    /* Get number of Game rounds */
    cout << "For how many rounds do you want ";
    cout << p1Name << " and " << p2Name << " to play for? ";
    cin >> numRounds;
    cout << "Thanks!  Now let's start the game..." << endl;
    cin.ignore();
    cout << "Press Enter for each round...";
    cin.ignore();

    /* Initialize Game */
    Player p1(p1Name, p1Die);
    Player p2(p2Name, p2Die);
    Game game(&p1, &p2, numRounds);

    /* Game Loop */
    for (int i = 0; i < numRounds; i++) {
        cout << endl << "Starting round " << i + 1 << "..." << endl;
        game.playRound();
        cin.ignore();  // this forces user to press "return" key
    }

    return 0;
}
