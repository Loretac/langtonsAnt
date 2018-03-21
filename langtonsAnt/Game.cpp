/*********************************************************************
 ** Program name: Project 1 - Langston's Ant
 ** Author: B. Christopher Loreta
 ** Date: 06 Oct 2017
 ** Description:
 
 This file contains implementation of Game class member functions.
 *********************************************************************/

#include <iostream>
#include "Game.hpp"
#include <sstream>

using std::cout;
using std::endl;
using std::string;
using std::getline;


/*********************************************************************
 The inputVal function validates the user's input. In this program,
 the only valid inputs are integers that fall between a certain minimum
 and maximum. The function takes those two values as parameters and
 returns after validation a value provided by the user. Stringstream
 process retrieved from here:
 
 https://stackoverflow.com/questions/200090/how-do-you-convert-a-c-string-to-an-int
 *********************************************************************/
int Game::inputVal(int minimum, int maximum)
{
    int returnVal;
    string myString;
    
    std::getline(std::cin, myString);
    std::stringstream str(myString);
    
    str >> returnVal;
    
    while (!returnVal || returnVal < minimum || returnVal > maximum)
    {
        str.str("");
        str.clear();
        std::cout << "Invalid. Try again." << endl;
        
        std::getline(std::cin, myString);
        std::stringstream str(myString);
        str >> returnVal;
    }
    str.str(""); // Clear the string
    str.clear(); // Clear the flag
    
    return returnVal; // Return the validated input
}

/*********************************************************************
The menu function runs to begin the program, prompting the user for a
 choice in the form of a number (saved as string). The menu function
 can be used in other applications, with the parameters being the
 applicable menu options.
 *********************************************************************/
string Game::menu(string option1, string option2)
{
    string input;
    cout << option1 << endl;
    cout << option2 << endl;
    cout << "Enter your choice: ";
    getline(std::cin, input);
    
    while (input != "1" &&
           input != "2") // Basic input validation
    {
        cout << "Please choose a valid option." << endl;
        getline(std::cin, input);
    }
    
    return input;
}

/*********************************************************************
 The play function runs for the duration of the game, starting when
 the user chooses to play from the opening menu. It begins by prompting
 the user for starting information: Number of rows and columns to set
 the boundaries, number of steps the ant takes during the simulation,
 and which row and column the ant will start. It runs each of these
 inputs from the user through the inputVal function described above.
 After creating the array containing the board and the ant object,
 the makeMove and printBoard functions run as many times as there are
 remaining steps.
 *********************************************************************/
void Game::play()
{
    int numRows;
    int numCols;
    int numSteps;
    int startingRow;
    int startingCol;
    
    cout << "Enter number of rows between 1 and 75." << endl;
    numRows = inputVal(1, 75);

    cout << "Enter number of columns between 1 and 75." << endl;
    numCols = inputVal(1, 75);

    cout << "How many steps? (Max 20,000)" << endl;
    numSteps = inputVal(1, 20000);
    
    cout << "What row will the ant start? (Between 1 and " << numRows << ".)" << endl;
    startingRow = inputVal(1, numRows) - 1;

    cout << "What column will the ant start? (Between 1 and " << numCols << ".)" << endl;
    startingCol = inputVal(1, numCols) - 1;
    
    cout << "Starting simulation..." << endl;
    
    // Dynamically allocate space for array
    int **array = new int*[numRows];
    for(int i = 0; i < numRows; i++)
        array[i] = new int[numCols];
    
    // Create an Ant object
    Ant myAnt(startingRow, startingCol, numRows, numCols, array);
    
    // Print the board before the first move
    myAnt.printBoard(array);
    
    for (int i = 0; i < numSteps; i++)
    {
        myAnt.makeMove(array);
        myAnt.printBoard(array);
    }
}
