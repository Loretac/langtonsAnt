/*********************************************************************
 ** Program name: Project 1 - Langston's Ant
 ** Author: B. Christopher Loreta
 ** Date: 06 Oct 2017
 ** Description:
 
 This file contains implementation of Ant class member functions.
 
 Array object legend:
 White space = 0
 Black space = 1
 Ant on white space = 2
 Ant on black space = 3
 *********************************************************************/

#include "Ant.hpp"

/*********************************************************************
 Constructor that initializes the ant's position and sets the size
 of the array. It also initializes the ant's orientation to North.
 *********************************************************************/
Ant::Ant(int xStarting, int yStarting, int startingRows,
         int startingCols, int **array)
{
    xCoord = xStarting;
    yCoord = yStarting;
    
    numRows = startingRows;
    numCols = startingCols;
    
    orientation = 'N';
    
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {array[i][j] = 0;} // Initialize each space to white
    }
    
    array[xCoord][yCoord] = 2; // Ant begins on white space
}

/*********************************************************************
 This function runs for each move made by the ant. It takes as its
 sole parameter a pointer to the array containing the board. The
 function is comprised of four distinct (if) statements, one for each
 cardinal direction in which the ant is facing, represented by the
 orientation variable. If the ant's next move is outside the boundary
 of the array, it will change orientation as expected but remain in
 its current row and column for the move.
 *********************************************************************/
void Ant::makeMove(int **array)
{
    std::cout << "Move made." << std::endl;
    
    if (orientation == 'N') // Ant is facing North
    {
        if (array[xCoord][yCoord] == 2) // Ant currently on white space
        {
            orientation = 'E';
            
            if (yCoord != numCols - 1)
            {
                if(array[xCoord][yCoord+1] == 0) // if space to right is white
                    // Set space to right as "ant on white space"
                    {array[xCoord][yCoord+1] = 2;}
            
                else if(array[xCoord][yCoord+1] == 1) // if space to right is black
                    // Set space to right as "ant on black space"
                    {array[xCoord][yCoord+1] = 3;}
            
                array[xCoord][yCoord] = 1; // Set original space to black
                yCoord = yCoord+1; // Change position of ant
            }
        }
        
        else if (array[xCoord][yCoord] == 3) // Ant currently on black space
        {
            orientation = 'W';
            
            if (yCoord != 0)
            {
                if(array[xCoord][yCoord-1] == 0) // if space to left is white
                    // Set space to left as "ant on white space"
                    {array[xCoord][yCoord-1] = 2; }
            
                else if(array[xCoord][yCoord-1] == 1) // if space to left is black
                    // Set space to left as "ant on black space"
                    {array[xCoord][yCoord-1] = 3; }
            
                array[xCoord][yCoord] = 0; // Set original space to white
                yCoord = yCoord-1; // Change position of ant
            }
        }
    }
    
    else if (orientation == 'E') // Ant is facing East
    {
        if (array[xCoord][yCoord] == 2) // Ant currently on white space
        {
            orientation = 'S';
            
            if (xCoord != numRows - 1)
            {
                if(array[xCoord+1][yCoord] == 0) // if space below is white
                    // Set space below as "ant on white space"
                {array[xCoord+1][yCoord] = 2;}
            
                else if(array[xCoord+1][yCoord] == 1) // if space below is black
                    // Set space below as "ant on black space"
                    {array[xCoord+1][yCoord] = 3;}
            
                array[xCoord][yCoord] = 1; // Set original space to black
                xCoord = xCoord+1; // Change position of ant
            }
        }
        
        else if (array[xCoord][yCoord] == 3) // Ant currently on black space
        {
            orientation = 'N';
            
            if (xCoord != 0)
            {
                if(array[xCoord-1][yCoord] == 0) // if space above is white
                    // Set space above as "ant on white space"
                    {array[xCoord-1][yCoord] = 2;}
            
                else if(array[xCoord-1][yCoord] == 1) // if space above is black
                    // Set space above as "ant on black space"
                    {array[xCoord-1][yCoord] = 3;}
            
                array[xCoord][yCoord] = 0; // Set original space to white
                xCoord = xCoord-1; // Change position of ant
            }
        }
    }
    
    else if (orientation == 'S') // Ant is facing South
    {
        if (array[xCoord][yCoord] == 2) // Ant currently on white space
        {
            orientation = 'W';
            
            if (yCoord != 0)
            {
                if(array[xCoord][yCoord-1] == 0) // if space to the left is white
                    // Set space to left as "ant on white space"
                    {array[xCoord][yCoord-1] = 2;}
            
                else if(array[xCoord][yCoord-1] == 1) // if space to the left is black
                    // Set space to left as "ant on black space"
                    {array[xCoord][yCoord-1] = 3;}
            
                array[xCoord][yCoord] = 1; // Set original space to black
                yCoord = yCoord-1;
            }
        }
        
        else if (array[xCoord][yCoord] == 3) // Ant currently on black space
        {
            orientation = 'E';
            
            if (yCoord != numCols - 1)
            {
                if(array[xCoord][yCoord+1] == 0) // if space to the right is white
                    // Set space to right as "ant on white space"
                    {array[xCoord][yCoord+1] = 2;}
            
                else if(array[xCoord][yCoord+1] == 1) // if space to the right is black
                    // Set space to right as "ant on black space"
                    {array[xCoord][yCoord+1] = 3;}
            
                array[xCoord][yCoord] = 0; // Set original space to white
                yCoord = yCoord+1; // Change position of ant
            }
        }
    }
    
    else if (orientation == 'W') // Ant is facing West
    {
        if (array[xCoord][yCoord] == 2) // Ant currently on white space
        {
            orientation = 'N'; // Change orientation
            
            if (xCoord != 0)
            {
                if(array[xCoord-1][yCoord] == 0) // if space above is white
                    // Set space above as "ant on white space"
                    {array[xCoord-1][yCoord] = 2;}
            
                else if(array[xCoord-1][yCoord] == 1) // if space above is black
                    // Set space above as "ant on black space"
                    {array[xCoord-1][yCoord] = 3;}
            
                array[xCoord][yCoord] = 1; // Set original space to black
                xCoord = xCoord-1; // Change position of ant
            }
        }
        
        else if (array[xCoord][yCoord] == 3) // Ant currently on black space
        {
            orientation = 'S'; // Change orientation
            
            if (xCoord != numRows - 1)
            {
                if(array[xCoord+1][yCoord] == 0) // if space below is white
                    // Set space below as "ant on white space"
                    {array[xCoord+1][yCoord] = 2;}
            
                else if(array[xCoord+1][yCoord] == 1) // if space below is black
                    // Set space below as "ant on black space"
                    {array[xCoord+1][yCoord] = 3;}
            
                array[xCoord][yCoord] = 0; // Set original space to white
                xCoord = xCoord+1; // Change position of ant
            }
        }
    }
}

/*********************************************************************
 This function prints the board. For info about the 0, 1, 2, and 3
 values, see legend at top of this file.
 *********************************************************************/
void Ant::printBoard(int **array)
{
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            if (array [i][j] == 0)
            std::cout << ".";
            
            if (array [i][j] == 1)
                std::cout << "#";
            
            if (array [i][j] == 2 || array[i][j] == 3)
                std::cout << "*";
        }
        std::cout << std::endl;
    }
}
