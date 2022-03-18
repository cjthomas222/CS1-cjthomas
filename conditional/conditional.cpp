#include <iostream>
#include <cstdio>
#include <string>
#include <cassert>
 
using namespace std;
 
void printMenu(void);
 
void getTwoNumbers(double &, double &, double &, double &, double &);
 
double findSum(const double &, const double &,const double &, const double &,const double &);
 
double findProduct(const double &, const double &,const double &, const double &,const double &);

void findAverage(const double &, const double &, double &,const double &, const double &,const double &);
 
double findSmaller(const double &, const double &,const double &, const double &,const double &);
 
double findFloor(const double &, const double &,const double &, const double &, const double &);
 

void test();

bool program();

void clearScreen() {
    #ifdef _WIN32
        system("clS");
    #else
        system("clear");
    #endif
}

int main(int argc, char* argv[]) {
    bool keepRunning = true;
    if(argc == 2 && string(argv[1]) == "test") {
        test();
        exit(EXIT_SUCCESS);
    }
    else {
        while (keepRunning) {
            if (!program())
                break; 
            cin.ignore(100, '\n');
            cout << "Enter to continue...";
            cin.get();
            clearScreen();
        }
    }
    cin.ignore(100, '\n');
    cout << "Enter to quit the program.\n";
    cout << "Good bye..." << endl;
    cin.get();
    return 0;
}

void printMenu(void) {
    cout << "Menu options:\n";
    cout << "[1] Add two numbers\n";
    cout << "[2] Subtract two numbers\n";
    cout << "[3] Multiply two numbers\n";
    cout << "[4] Divide two numbers\n";
    cout << "[5] Find larger of two numbers\n";
    cout << "[6] Find smaller of two numbers\n";
    cout << "[7] Find average of two numbers\n";
    cout << "[8] Quit the program\n";
    cout << "Enter one of the menu options [1-8]: ";
}

void getTwoNumbers(double &n1, double &n2,double &n3, double &n4,double &n5) {
    cout << "Enter five numbers separated by a space: ";
    cin >> n1 >> n2 >> n3 >> n4 >> n5;
}

double findSum(const double &n1, const double &n2, const double &n3,const double &n4,const double &n5) {
    return (n1 + n2 + n3 + n4 + n5);
}

double findProduct(const double &n1, const double &n2, const double &n3,const double &n4,const double &n5) {
    return (n1 * n2 * n3 * n4 * n5);
}

void findAverage(const double &n1, const double &n2, double &avg, const double &n3,const double &n4,const double &n5) {
    avg = ((n1+n2+n3+n4+n5)/5);
}

double findLarger(const double &n1, const double &n2, const double &n3,const double &n4,const double &n5) {
    double larger = (n1 >= n2 >= n3 >= n4 >= n5 ) ? n1 : n5;
    return larger;
}
double findDifference(const double &n1, const double &n2) {
    return (n1 - n2);
}

double findProduct(const double &n1, const double &n2) {
    return (n1 * n2);
}


double findSmaller(const double &n1, const double &n2) {
    double smaller = (n1 <= n2) ? n1: n2;
    return smaller;
}

double findQuotient(const double &n1, const double &n2) {
    return (n1/n2);
}

void test() {
    assert(findSum(-5, 10.5) == 5.5);
    assert(findSum(7, 8) == 15);
    assert(findSum(5, 5) == 10);

    assert(findDifference(10,8) == 2);
    assert(findDifference(20,12) == 8);
    assert(findDifference(20.5,9) == 11.5);

    assert(findProduct(10,2) == 20);
    assert(findProduct(20,4) == 80);
    assert(findProduct(5,5) == 25);

    double larAnswer = findProduct(5.5,4);
    double larExpect = 5.5;
    assert(larAnswer == larExpect);
    assert(findLarger(20,12) == 20);

    double smaAnswer = findSmaller(5.5,4);
    double smaExpect = 4;
    assert(smaAnswer == smaExpect);
    assert(findSmaller(20,12) == 12);

    double quoAnswer = findQuotient(5,2.5);
    double quoExpect = 2;
    assert(quoAnswer == quoExpect);
    assert(findQuotient(20,4) == 5);

    double avgAnswer = 0;
    findAverage(20,10,avgAnswer);
    double avgExpect = 15;
    assert(avgAnswer == avgExpect);
    findAverage(36,12,avgAnswer);
    assert(avgAnswer == 24);

    printf("%s\n", "all test cases passed...");
}


bool program() {
    int option = 1;
    double num1=0, num2=0;
    printMenu();
    do {
        if (cin >> option && option >= 1 && option <= 8) {
            break;
        }
        else {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid option, please enter a value between 1 and 8" << endl;
        }
    } while (true);
            
    switch(option) {
        case 1:
        {
            getTwoNumbers(num1, num2);
            double sum = findSum(num1, num2);
            printf("The sum of your numbers is %.2f + %.2f = %.2f\n", num1, num2, sum);
            break;
        }
        case 2:
        {
            getTwoNumbers(num1,num2);
            double sum2 = findDifference(num1, num2);
            printf("The difference of your numbers is %.2f - %.2f = %.2f\n", num1, num2,sum2);
            break;
        }
        case 3:
        {
            getTwoNumbers(num1,num2);
            double sum3 = findProduct(num1,num2);
            printf("The product of your numbers is %.2f * %.2f = %.2f\n", num1, num2,sum3);
            break;
        }

        case 4:
        {
            getTwoNumbers(num1,num2);
            double sum4 = findQuotient(num1,num2);
            printf("The quotient of your numbers is %.2f / %.2f = %.2f\n", num1, num2,sum4);
            break;
        }
        

        case 5:
        {
            getTwoNumbers(num1, num2);
            double max = findLarger(num1, num2);
            printf("Larger between %.2f & %.2f is %.2f\n", num1, num2, max);
            break;
        }

        case 6:
        {
            getTwoNumbers(num1, num2);
            double low = findSmaller(num1, num2);
            printf("Smaller between %.2f & %.2f is %.2f\n", num1, num2, low);
            break;
        }
        
        case 7:
        {
            double avg = 0;
            getTwoNumbers(num1, num2);
            findAverage(num1, num2, avg);
            printf("The average of your two number %.2f\n", avg);
            break;
        }
        case 8:
        default: 
            return false;
    }
    return true;
}