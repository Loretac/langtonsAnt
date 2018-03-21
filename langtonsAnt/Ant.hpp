/*********************************************************************
 ** Program name: Project 1 - Langston's Ant
 ** Author: B. Christopher Loreta
 ** Date: 06 Oct 2017
 ** Description:
 
 This file contains the member variables and function prototypes for
 class Ant.
 *********************************************************************/

#ifndef Ant_hpp
#define Ant_hpp

#include <iostream>

using std::string;

class Ant
{
private:
    int xCoord;
    int yCoord;
    char orientation;
    int numRows;
    int numCols;
    
public:
    Ant(int, int, int, int, int **array);
    void makeMove(int **array);
    void printBoard(int **array);

};


#endif /* Ant_hpp */
