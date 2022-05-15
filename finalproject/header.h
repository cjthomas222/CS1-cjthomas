#pragma once
#include <iostream>
#include <string>
#include <array>
#include <cmath>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <iomanip> 


using namespace std;

const int maxTries = 5;

// struct hangman
// {
// string word;
// };

int readData(string word[], const size_t &, string);
void welcome();
string randomWord(string word[]);
void printPicture(int);
void game(string word[], const size_t &, int);

int readData(string word[], const size_t &num_words, string infile)
{
    //string word[num_words];
    string tmp;
    int cnt = 0; 
    ifstream fin(infile);
    while(getline(fin, tmp))
    {
        stringstream ss(tmp);
        ss >> word[cnt];
        cnt++;
    }
    fin.close();
    // for(int i = 0; i < num_words; i++)
    // {
    //     cout << word[i] << endl;

    // }
    return cnt;
}

void welcome()
{
    cout << "Hello and welcome to my game of Hangman!" << endl;
    cout << "You have 5 tries to guess my word" << endl;
}

void game(string word[], const size_t &num_words, int guesses)
{
    string random = randomWord(word);
    guesses = 5;
    char letter;
    int successes = 0;
    bool match;
    //int size = wo[].size();
    string blank = "";
    for(int n = 0; n < random.length(); n ++)
    {
        blank += "_";
    }
    cout << blank << endl;
    //cout << random;
    while(guesses > 0 && successes <= random.length()-1)
    {
        //cout << random.length() << " " << guesses << endl;
        int temp = successes;
        cout << "Guess a letter" << endl;
        cin >> letter;
        match = false;
        for(int i = 0; i < random.length(); i++)
        {
            
            if(letter == random[i])
            {
                blank[i] = letter;
                successes++;
                match = true;
                //cout << "Nice!" << endl;
            }
            //letter = ' ';
        }
        if(temp == successes)
        {
            guesses--;
            cout << "Try Again! You have " << guesses << " more guesses" << endl;
        }
        if(match == true)
        {
            cout << "Nice!" << endl;
        }
       cout << blank << endl;
       printPicture(guesses);
    }
    if(guesses == 0)
    {
        cout << "You lost! Your word was " << random << ". Try again?" << endl;
    }
    else if(guesses > 0)
    {
        cout << "Congrats!!! You won with " << guesses << " guesses left!" << endl;
    }
}

string randomWord(string word[])
{
    srand(time(NULL));
    int i = rand() % 20;
    //cout << word[i];
    return word[i];
}

void printPicture(int guesses)
{
    if(guesses == 5)
    {
        cout << "_________________" << endl;
		cout << " |        |      " << endl;
		cout << " |        |      " << endl;
		cout << " |               " << endl;
		cout << " |               " << endl;
		cout << " |               " << endl;
		cout << " |               " << endl;
		cout << " |               " << endl;
		cout << " |               " << endl;
		cout << " |               " << endl;
		cout << " |               " << endl;
    }
    if(guesses == 4)
    {
        cout << "_________________" << endl;
		cout << " |        |      " << endl;
		cout << " |        |      " << endl;
		cout << " |        0      " << endl;
		cout << " |               " << endl;
		cout << " |               " << endl;
		cout << " |               " << endl;
		cout << " |               " << endl;
		cout << " |               " << endl;
		cout << " |               " << endl;
		cout << " |               " << endl;
    }
    if(guesses == 3)
    {
        cout << "_________________" << endl;
		cout << " |        |      " << endl;
		cout << " |        |      " << endl;
		cout << " |        0      " << endl;
		cout << " |       /|      " << endl;
		cout << " |        |      " << endl;
		cout << " |               " << endl;
		cout << " |               " << endl;
		cout << " |               " << endl;
		cout << " |               " << endl;
		cout << " |               " << endl;
    }
     if(guesses == 2)
    {
        cout << "_________________" << endl;
		cout << " |        |      " << endl;
		cout << " |        |      " << endl;
		cout << " |        0      " << endl;
		cout << " |       /|\\    " << endl;
		cout << " |        |      " << endl;
		cout << " |               " << endl;
		cout << " |               " << endl;
		cout << " |               " << endl;
		cout << " |               " << endl;
		cout << " |               " << endl;

    }
     if(guesses == 1)
    {
        cout << "_________________" << endl;
		cout << " |        |      " << endl;
		cout << " |        |      " << endl;
		cout << " |        0      " << endl;
		cout << " |       /|\\    " << endl;
		cout << " |        |      " << endl;
		cout << " |       /       " << endl;
		cout << " |               " << endl;
		cout << " |               " << endl;
		cout << " |               " << endl;
		cout << " |               " << endl;

    }
    if(guesses == 0)
    {
        cout << "_________________" << endl;
		cout << " |        |      " << endl;
		cout << " |        |      " << endl;
		cout << " |        0      " << endl;
		cout << " |       /|\\    " << endl;
		cout << " |        |      " << endl;
		cout << " |       / \\    " << endl;
		cout << " |               " << endl;
		cout << " |               " << endl;
		cout << " |               " << endl;
		cout << " |               " << endl;

    }
}

void clearScreen() {
    // use "cls" in windows and "clear" command in Mac and Linux
    #ifdef _WIN32
        system("clS");
    #else
        system("clear");
    #endif
}