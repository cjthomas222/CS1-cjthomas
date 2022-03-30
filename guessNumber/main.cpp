#include <iostream>
#include <cstring>
#include <time.h>
#include <cassert>
#include <cstdio>
#include <string>

using namespace std;

int randomNumber();
void readNumber(int&);
int guessNumber(int, int);
void game(int, int);

void test();

int main()
{
bool keepRunning = false;
while(!keepRunning){
int x;
int y;
srand( time(NULL));
string name = "";
test();
cout << "What is your first name?" << endl;
cin >> name;
cout << "Hello " << name << ", welcome to my guess the number game!" << endl;
x = randomNumber();
game(x,y);
char v;
    cout << "Enter Y/y to continue running program" << endl;
    cin >> v;
    if(v == 'y' || v == 'Y'){
        keepRunning = false;
    }else {
        keepRunning = true;
    }
}
return 0;
}

int randomNumber()
{

int x = (rand() % (20-2) + 1);
return x;
}

void readNumber(int& y){
    cout << "Please pick a number between 1 and 20" << endl;
    cin >> y;
    
    if(y>21 || y<0){
        cout<< "Your number must be between 1 and 20" << endl;
    }
}

int checkGuess(int x, int y){
    //randomNumber(x);
    //readNumber(y);
    if(x==y){
        return 0;
    }
    else if(y>x)
    {
        return -1;
    }
    else if(x>y)
    {
        return 2;
    } 
    else 
    {
        return 0;
    }
}


void game(int x, int y){
    //randomNumber();
    //readNumber(y);
    for(int i=0; i<=5;i++)
    {
        int G = checkGuess(x,y);
        readNumber(y);
        if(G == 0)
        {
            cout << "Congrats, you guessed it!!!"<< endl;
            break;
        }
        else if(G==-1 && i<5)
        {
            cout << "Lower!" << endl;
        }
        else if(G==2 && i<5)
        {
            cout << "Higher!" <<endl;
        }
        else if((i=5))
        {
    cout << "You lost!!! The random number was " << x << endl;   
    }
}
}
void test() {
assert(checkGuess(5,5)==0);
assert(checkGuess(5,4)==2);
assert(checkGuess(4,5)==-1);

printf("%s\n", "all test cases passed...");
}
// if( x == y)
// {
//     cout << "You guessed it";
// 
// else
// {

// }
// return x;
// }