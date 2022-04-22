/*
    CS1 - Vector Lab
    Updated by: Connor Thomas #fixed
    Date: 4/20/22 #fixed
    Program: Number system converter  
    The program converts decimal to binary and binary to decimal number system.
    Lab demonstrates the vector application. 
*/

#include <iostream> 
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <cctype>

using namespace std;

using llu = unsigned long long int;

// System specific macro function sysclear that 
// clears console text
// NOTE: system call is not security best practice!
#ifdef _WIN32
#define clearScreen() system ("cls") // not secure!
#else
#define clearScreen() system ("clear") // not secure!
#endif

// converts decimal number to binary representation
void decToBin(llu);

// converts binary number to decimal representation
void binToDec(llu);

// converts decimal number to octal representation
string decToOct(llu);

// converts octal number to decimal number
llu octToDec(string octalNum);

// function to display and capture menu options
int menuOption();

int main()
{
    llu decimalNum, binary;
    int choice;
    string octalNum;
    do {
        clearScreen();
        cout << "Program converts decimal number into binary and vice versa.\n";
        choice = menuOption();
        switch(choice) {
            case 1:
                // FIXME3 # fixed
                cout << "Enter a positive decimal number: ";
                cin >> decimalNum;
                decToBin(decimalNum);
                //cout << "13  decimal = " << decimalNum << " binary " << endl;
                break;
            case 2:
                // FIXME4
                cout << "Enter a binary number: ";
                cin >> binary;
                binToDec(binary);
                //cout << "FIXME\n";
                break;
            case 3:
                cout << "Enter a positive decimal number: ";
                cin >> decimalNum;
                octalNum = decToOct(decimalNum);
                printf("(%llu) base 10 = (%s) base 8\n", decimalNum, octalNum.c_str());
                break;
            case 4:
                cout << "Enter a positive octal number: ";
                cin >> octalNum;
                decimalNum = octToDec(octalNum);
                printf("(%s) base 8 = (%llu) base 10\n", octalNum.c_str(), decimalNum);
                break;
            case 5:
                break;
        }
        if (choice != 5) {
            cin.ignore();
            cout << "Enter to continue...";
            cin.get();
        }
    } while (choice != 5);
    cin.ignore();
    cout << "Good bye! Enter to quit...";
    cin.get();
    return 0;
}

void decToBin(llu num) {
    // FIXME5 - use algorithm step in Ch03-StdInputOutput chapter
    // or use hint from decToOct function
    const int divisor = 2;
    int dividend;
    int quotient, remain;
    string answer;
    answer = ""; 
    quotient = num; 
    while(quotient != 0)
    {
        dividend = quotient;
        remain = dividend%divisor; 
        quotient = dividend/divisor; 
        cout << dividend << '/' << divisor << " => quotient: " << quotient << " remainder: " << remain << endl;
        answer = to_string(remain) + answer; 
    }

    cout << "Your decimal = " << answer << " binary " << endl;
}

void binToDec(llu binary)
{
    // FIXME6 - use algorithm described in Ch03-StdInputOutput chapter
    // or use hints from binToOct function
int dec = 0, i = 0, rem;

  while (binary != 0) {
    rem = binary % 10;
    binary /= 10;
    dec += rem * pow(2, i);
    ++i;
  }
    cout << dec << endl;
    //return binary;
}

string decToOct(llu num)
{
    /*
    Algorithm steps:
    1. repeteadly divide the decimal number by base 8 until the quotient becomes 0
    2. collect the remainder for each division
    3. reverse the order of the remainders 
        - the first remainder is the last digit in octal
    */
    vector<int> octal;
    int divisor = 8; // base 8
    llu quotient = num;
    int remainder;
    // step 1 and 2
    cout << "quotient = " << quotient << endl;
    while (quotient != 0) {
        remainder = quotient%divisor;
        quotient = quotient/divisor;
        octal.push_back(remainder);
        // cout << "quotient = " << quotient << " " << remainder << endl;
    }

    // step 3. convert octal vector into string for easy printing the result
    // collect remainders in reverse order
    string ans = "";
    while(!octal.empty()) {
        // collect from the last element
        ans += to_string(octal.back());
        // remove the last element
        octal.pop_back();
    }
    return ans;
}


llu octToDec(string octalNumber)
{
    /* Algorithm steps:
    1. multiply each octal digit by its place in octal
    2. sum all place value products
    e.g. (173) base 8 = 1x8^2 + 7x8^1 + 3x8^0 = 64+56+3 = (123) base 10
    */
    llu ans = 0;
    int exp;
    // go from last digit to the first digit of octal number
    for(int i = octalNumber.size()-1; i>=0; i--) {
        exp = octalNumber.size()-1 - i;
        int digit = int(octalNumber[i]) - int('0');
        // step 1 and 2
        ans += digit*pow(8, exp);
    }
    return ans;
}

int menuOption() {
    int choice;
    cout << "Menu options: \n"
        << "1. Convert Decimal to Binary Number System\n"
        << "2. Convert Binary to Decimal Number System\n"
        << "3. Convert Decimal to Octal Number System\n"
        << "4. Convert Octal to Decimal Number System\n"
        << "5. Exit the program\n";
    cout << "Enter your choice: [1-5]: ";
    cin >> choice;
    return choice;
}