#include <iostream>
#include <string>
#include <array>
#include <cmath>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <iomanip>
#include "header.h"


using namespace std;

int main(int argc, char *argv[])
{
bool keepRunning = false;
while(!keepRunning){
clearScreen();
int guesses;
size_t num_words = 20;
string word[num_words];
//hangman input[num_words];
string infile = "words.txt"; 
//ifstream fin(infile);
//clearScreen();
readData(word,num_words,infile);
randomWord(word);
welcome();
game(word, num_words,guesses);
char v;
    cout << "Enter Y/y to continue running program" << endl;
    cin >> v;
    if(v == 'y' || v == 'Y'){
        keepRunning = false;
    }else {
        keepRunning = true;
    }
}
//fin.close();
return 0;
}

