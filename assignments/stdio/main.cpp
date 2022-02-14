#include <iostream>
#include <string>

using namespace std;
//this game runs through letters that are picked by the user. If specific letters arent't picked...
//the user loses.
int main()
{
    string fullName;
    cout << "Hey what's your name? ";
    getline (cin, fullName);
    cout << "Hey " << fullName << "!";
    string line1 = " The hangman game is under construction, maybe you'll get to play it in a few weeks...";
    cout << line1 << endl;
    string line2 = "This is what various stages of the hangman game will look like...";
    cout << line2 << endl;


    string string[8] = {"|-----------------" , "|/" , "|" , "|" , "|" , "|" , "|", "==========="};

    

    for(int j = 0; j <= 6; j++)
    {
        if(j == 1)
        {
            string[j] += "               0";
        }
        else if( j == 2)
        {
            string[j] += "                |";
        }
        else if ( j==3 )
        {
            string[2] = "|               /|";
        }
        else if ( j==4 )
        {
            string[2] = "|               /|\\";
        }
        else if ( j == 5)
        {
            string[3] = "|               /";
        }
        else if(j == 6)
        {
            string[3] = "|               / \\";
        }


        for(int i = 0; i <= 7; i++)
        {
            cout << string[i] << endl;
        }
    }


/*
    cout << "Stage 1" << endl;
    cout << "|-----------------" << endl << "|/" << endl << "|" << endl << "|" << endl << "|" << endl;						
    cout << "|" << endl << "|" << endl << "===========" << endl;      

    string stage2 =   
    cout << "Stage 2" << endl;
    cout << "|-----------------" << endl << "|/                0" << endl << "|" << endl << "|" << endl << "|" << endl;						
    cout << "|" << endl << "|" << endl << "===========" << endl;      
*/
    return 0;
}