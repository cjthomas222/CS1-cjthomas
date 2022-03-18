#include <iostream>
#include <cstdio>
#include <string>
#include <cassert>
#include <cmath>

using namespace std;

void printMenu(void);

void getTwoNumbers(double &, double &, double &, double &, double &);

double findSum(const double &, const double &, const double &, const double &, const double &);

double findProduct(const double &, const double &, const double &, const double &, const double &);

double findAverage(const double &, const double &, const double &, const double &, const double &, const double);

double findSmaller(const double &, const double &, const double &, const double &, const double &);

string findFloor(const double &, const double &, const double &, const double &, const double &);

string name = "";

void test();

bool program();

void clearScreen()
{
#ifdef _WIN32
    system("clS");
#else
    system("clear");
#endif
}

int main(int argc, char *argv[])
{
    cout << "Hello, what is your name?" << endl;
    getline(cin, name);

    bool keepRunning = true;
    if (argc == 2 && string(argv[1]) == "test")
    {
        test();
        exit(EXIT_SUCCESS);
    }
    else
    {
        while (keepRunning)
        {
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

void printMenu(void)
{
    cout << "Menu options:\n";
    cout << "[1] Add 5 numbers\n";
    cout << "[2] Calculates sum of five numbers\n";
    cout << "[3] Find average of five numbers\n";
    cout << "[4] Find larger of five numbers\n";
    cout << "[5] Find smaller of five numbers\n";
    cout << "[6] Find floor of sum of five numbers\n";
    cout << "[7] Quit the program\n";
    cout << "Enter one of the menu options [1-7]: ";
}

void getFiveNumbers(double &n1, double &n2, double &n3, double &n4, double &n5)
{
    cout << "Enter five numbers separated by a space," << name << ": ";
    cin >> n1 >> n2 >> n3 >> n4 >> n5;
}

double findSum(const double &n1, const double &n2, const double &n3, const double &n4, const double &n5)
{
    return (n1 + n2 + n3 + n4 + n5);
}

double findProduct(const double &n1, const double &n2, const double &n3, const double &n4, const double &n5)
{
    return (n1 * n2 * n3 * n4 * n5);
}

double findAverage(const double &n1, const double &n2, const double &n3, const double &n4, const double &n5)
{
    return ((n1 + n2 + n3 + n4 + n5) / 5);
}

double findLarger(const double &num1, const double &num2, const double &num3, const double &num4, const double &num5)
{
    if (num1 >= num2 && num1 >= num3 && num1 >= num4 && num1 >= num5)
    {
        return num1;
    }
    else if (num2 >= num1 && num2 >= num3 && num2 >= num4 && num2 >= num5)
    {
        return num2;
    }
    else if (num3 >= num1 && num3 >= num2 && num3 >= num4 && num3 >= num5)
    {
        return num3;
    }
    else if (num4 >= num1 && num4 >= num2 && num4 >= num3 && num4 >= num5)
    {
        return num4;
    }
    else
    {
        return num5;
    }
}

double findSmaller(const double &num1, const double &num2, const double &num3, const double &num4, const double &num5)
{
    if (num1 <= num2 && num1 <= num3 && num1 <= num4 && num1 <= num5)
    {
        return num1;
    }
    else if (num2 <= num1 && num2 <= num3 && num2 <= num4 && num2 <= num5)
    {
        return num2;
    }
    else if (num3 <= num1 && num3 <= num2 && num3 <= num4 && num3 <= num5)
    {
        return num3;
    }
    else if (num4 <= num1 && num4 <= num2 && num4 <= num3 && num4 <= num5)
    {
        return num4;
    }
    else
    {
        return num5;
    }
}
string findFloor(const double &n1, const double &n2, const double &n3, const double &n4, const double &n5)
{
    float total = n1 + n2 + n3 + n4 + n5;
    int x = floor(total);

    if (x % 2 == 0)
    {
        return " Even ";
    }
    else if (x % 3 == 0)
    {
        return " Odd ";
    }
    else
    {
        return " Zero ";
    }
}

void test()
{
    assert(findSum(5, 10.5, 10, 5, 3) == 33.5);
    assert(findSum(7, 8, 7, 8, 7) == 37);
    assert(findSum(5, 5, 5, 5, 5) == 25);

    assert(findProduct(10,2,1,2,1) == 40);
    assert(findProduct(20,4,2,2,1) == 320);
    assert(findProduct(5,5,4,1,1) == 100);

    assert(findLarger(20,12,13,8,2) == 20);
    assert(findLarger(80,99,101,100,20) == 101);
    assert(findLarger(55,10,25,8,40) == 55);

    assert(findSmaller(20,12,13,8,2) == 2);
    assert(findSmaller(80,99,101,100,20) == 20);
    assert(findSmaller(55,10,25,8,40) == 8);

    assert(findFloor(5.5,4,4,5,1) == "Odd");
    assert(findFloor(5,4,3,2,1) == "Odd");
    assert(findFloor(5.5,6.5,5.49,0,1) == "Even");

    assert(findAverage(5,5,5,5,5) == 5);
    assert(findAverage(10,5,10,5,10) == 8);
    assert(findAverage(1,1,1,1,1) == 1);

    printf("%s\n", "all test cases passed...");
}

bool program()
{
    int option = 1;
    double n1 = 0, n2 = 0, n3 = 0, n4 = 0, n5 = 0;
    printMenu();
    do
    {
        if (cin >> option && option >= 1 && option <= 8)
        {
            break;
        }
        else
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid option, please enter a value between 1 and 8" << endl;
        }
    } while (true);

    switch (option)
    {
    case 1:
    {
        getFiveNumbers(n1, n2, n3, n4, n5);
        double sum = findSum(n1, n2, n3, n4, n5);
        printf("The sum of your numbers is %.2f %.2f + %.2f + %.2f + %.2f= %.2f\n", n1, n2, n3, n4, n5, sum);
        break;
    }
    case 2:
    {
        getFiveNumbers(n1, n2, n3, n4, n5);
        double sum2 = findProduct(n1, n2, n3, n4, n5);
        printf("The product of your numbers is %.2f * %.2f * %.2f * %.2f * %.2f = %.2f\n", n1, n2, n3, n4, n5, sum2);
        break;
    }
    case 3:
    {
        double avg;
        getFiveNumbers(n1, n2, n3, n4, n5);
        avg = findAverage(n1, n2, n3, n4, n5);
        printf("The average of your five numbers is %.2f\n", avg);
        break;
    }

    case 4:
    {
        getFiveNumbers(n1, n2, n3, n4, n5);
        double max = findLarger(n1, n2, n3, n4, n5);
        printf("Your largest number is %.2f\n", max);
        break;
    }

    case 5:
    {
        getFiveNumbers(n1, n2, n3, n4, n5);
        double low = findSmaller(n1, n2, n3, n4, n5);
        printf("Your smallest number is %.2f\n", low);
        break;
    }

    case 6:
    {
        getFiveNumbers(n1, n2, n3, n4, n5);
        cout << "The floor of your numbers is" << findFloor(n1, n2, n3, n4, n5);
    }
    case 7:
    default:
        return false;
    }
    return true;
}