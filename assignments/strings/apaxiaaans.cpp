#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <cassert>

using namespace std;
string answer(const string &line);
void solve();
void testanswer();

int main(int argc, char* argv[])
{  
if (argc == 2 and string(argv[1]) == "test")
    testanswer(); //tests function in main
else
    solve();//outputs code
}

string answer(const string &line) //goes through function, eliminating any double letters
{
    string name ="";
    long int s = line.length();
    for(long int i = 0; i<s; i++)
    {
        if(line[i] != line[i-1])
        {
             name += line[i];
        } 
    }
    return name;
}

void testanswer() { //tests answer to make sure it is outputting correctly
    assert(answer("connor")=="conor");
    assert(answer("roobert")== "robert");
    assert(answer("apaxiaaans")== "apaxians");
    cout << "All test cases passed!\n";
}

void solve() {
    string line;
    getline(cin,line); //gets input from user
    cout << answer(line) << endl; //outputs answer
}