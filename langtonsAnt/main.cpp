/*********************************************************************
 ** Program name: Project 1 - Langston's Ant
 ** Author: B. Christopher Loreta
 ** Date: 06 Oct 2017
 ** Description:
 
 In this Langton's Ant simulation, white spaces are represented as
 the . (period) symbol and black spaces are represented as the #
 symbol. The ant is the * symbol, and it begins the simulation facing
 the North (up) direction.
 
 
 The two basic rules of Langton's Ant simulation are as follows:
 
 If the ant is on a white space, turn right 90 degrees and change the
 space to black.
 If the ant is on a black space, turn left 90 degrees and change the
 space to white.
 
 In addition, if the ant encounters a boundary (edge of the bounds),
 the ant will change direction as originally instructed but will
 remain in its current space to end the current move.
 *********************************************************************/

#include <iostream>
#include "Game.hpp"

using std::cout;
using std::endl;
using std::string;

int main() {
    
    string choice;
    Game newGame1;
    
    choice = newGame1.menu("1. Start simulation", "2. Quit");
    
    while(choice == "1")
    {
        newGame1.play();
        choice = newGame1.menu("1. Play again", "2. Quit");
    }
    
    cout << "Program terminating." << endl; // choice = 2
    
    return 0;
}
