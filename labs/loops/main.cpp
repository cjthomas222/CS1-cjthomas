/*
    Loops Lab
    Updated By: Connor Thomas
    CSCI 111
    Date: 3/26/2022    Program prints geometric shapes of given height with * using loops
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <cassert>
#include <iomanip>

using namespace std;

bool program();


void printTriangle(int height) {
    //Function takes height as an argument to print the triangle
    //of that height with *
    int row = 1;
    // row
    while (row <= height) {
        // column
        for(int col = 1; col<=row; col++)
            cout << "* ";
        row += 1;
        cout << endl;
    }
}


void printFlippedTriangle(int height) {
//     /* 
//     Implement the function that takes height as an argument
//     and prints a triangle with * of given height.
//     Triangle of height 5, e.g., should look like the following.
//     * * * * *
//     * * * *
//     * * *
//     * *
//     *
    
//     */
//     // FIXME3 ...
int row = height;
    // row
    while (row >= 0) {
        // column
        for(int col = 1; col<=row; col++)
            cout << "* ";
        row -= 1;
        cout << endl;
    }
}


// /*  
// FIXME4
// Design and implement a function that takes an integer as height and
// prints square of the given height with *.
// Square of height 5, e.g., would look like the following.
// *  *  *  *  *  
// *  *  *  *  *   
// *  *  *  *  *   
// *  *  *  *  *   
// *  *  *  *  *   
// */
void printSquare(int height) { 
    int row = height;
    // row
    while (row >= 0) {
        // column
        for(int col = height; col>=0;col--)
            cout << "* ";
        cout << endl;
        row--;
    }
    
}


// function clears the screen system call
// NOTE: system call is not a security best pracice!
void clearScreen() {
    // use "cls" in windows and "clear" command in Mac and Linux
    #ifdef _WIN32
        system("clS");
    #else
        system("clear");
    #endif
}

    // FIXME5 add a loop to make the program to continue to run until the user wants to quit
int main(int argc, char* argv[]) {
    bool keepRunning = false;
    while(!keepRunning){
    clearScreen();

    // FIXME6 call clearScreen function to clear the screen for each round of the loop
    int height;
    cout << "Program prints geometric shapes of given height with *\n";
    cout << "Please enter the height of the shape: ";
    cin >> height;
    // call printTriangle function passing user entered height
    printTriangle(height);

    cout<< endl;
    // FIXME7
    // Call printFlippedTriangle passing proper argument
    printFlippedTriangle(height);
    // Manually test the function
    cout << endl;
    // FIXME6
    printSquare(height);
    // Call the function defined in FIXME4 passing proper argument
    // Manually test the function

    // FIXME9
    char x;
    cout << "Enter Y/y to continue running program" << endl;
    cin >> x;
    if(x == 'y' || x == 'Y'){
        keepRunning = false;
    }else {
        keepRunning = true;
    }
    }
    // FIXME10
    // Use conditional statements to break the loop or continue the loop

    return 0;
}
