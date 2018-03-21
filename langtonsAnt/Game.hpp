/*********************************************************************
 ** Program name: Project 1 - Langston's Ant
 ** Author: B. Christopher Loreta
 ** Date: 06 Oct 2017
 ** Description:
 
 This file contains member variables and function prototypes for the
 class Game. 
 *********************************************************************/

#ifndef Game_hpp
#define Game_hpp

#include <iostream>
#include "Ant.hpp"

using std::string;

class Game
{
private:
    
public:
    void play();
    string menu(string, string);
    int inputVal(int minimum, int maximum);
};


#endif /* Game_hpp */
