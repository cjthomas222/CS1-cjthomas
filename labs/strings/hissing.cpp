/*
Kattis - Hissing Microphone Problem
By: Connor Thomas
Date: 4/5/22
Hissing Microphone Problem Statement: https://open.kattis.com/problems/hissingmicrophone
Algorithm steps:
1. Read string
2. find "ss" substring in the string
    - if found, print "hiss"
    - otherwise, print "no hiss"
*/

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

// function prototypes
string answer(const string &line);
void testAnswer();
void solve();

int main(int argc, char* argv[]) {
    if (argc == 2 and string(argv[1]) == "test")
        testAnswer();
    else
        solve();
}

string answer(const string &line) {
    bool check = false;
    for(int i = 0; i <= line.length(); i++)
    {
        if(line[i] == 's' && line[i+1] == 's')
        {
            check = true;
                
        }
        if(check = true)
        {
            return "hiss";
        }
        else
        {
        return "no hiss";
        }
    }
}

// unit testing answer()
void testAnswer() {
    // FIXME4
    // write at least two test cases to test answer()
    cerr << "All test cases passed!\n";
}

// solving the problem for kattis
void solve() {
    string line;
    // string consists of only lowercase letters (no spaces) upto 30 chars
    // FIXME5
    // read string into line
    cout << answer(line) << endl;
}