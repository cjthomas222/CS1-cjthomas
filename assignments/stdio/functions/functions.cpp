#include <iostream>
#include <cmath>
#include <iomanip>
#include <cassert>
#include <string>

using namespace std;

//template<class t1,class t2>
float addition(float x, float y);
//template<class t1,class t2>
float multiplication(float x, float y);
//template<class t1,class t2>
float division(float x, float y);
//template<class t1,class t2>
float subtraction(float x, float y);
//template<class t1,class t2>
float remain(float x,float y);
//template<class t1,class t2>
float power(float x, float y);
//template<class t1,class t2>
float square(float x);
float num1 = 0.0;
float num2 = 0.0;
void test1(float num1,float num2);

int main()
{
    cout << "Enter first value: ";
    cin >> num1;
    cout << "Enter second value: ";
    cin >> num2;

    cout << "The result of adding your two numbers is: " << addition(num1,num2) << endl;
    cout << "The result of multiplying your two numbers is: "<< multiplication(num1,num2) << endl;
    cout << "The result of division your two numbers is: "<< division(num1, num2) << endl;
    cout << "The result of subtraction your two numbers is: " << subtraction(num1,num2) << endl;
    cout << "The result of remainder your two numbers is: " << remainder(num1,num2) << endl;
    cout << "The result of raising your first number to the power of your second number is: "<< power(num1,num2)<< endl;
    cout << "The result of square rooting your first number is: "<< square(num1) << endl;

    test1(4,5);
}

float addition(float a,float z)
{
    float total = a+z;
    return total;
}

float multiplication(float x,float y)
{
    float total = x*y;
     return total;
}

float division(float x,float y)
{
    float total = x/y;
    return total;
}

float subtraction(float x,float y)
{
    float total = y-x;
    return total;
}

float remain(float x,float y)
{
    float total =((int)x%(int)y);
    return total;
} 

float power( float x, float y)
{
    float total = pow(x,y);
    return total;
}

float square(float x)
{
    float a = sqrt(x);
    return a;
}

void test1(float num1,float num2)
{
    const float epsilon = 1e-2;
    float answer = 15.2;
    float result = addition(8.7,6.5);
    assert(abs(result-answer) <= epsilon);
    float f = multiplication(8.7,6.5);
    float u = 56.55;
    assert(abs(f-u) <= epsilon);
    float c = subtraction(8.7,6.5);
    float d = -2.2;
    assert(abs(c-d) <= epsilon);
    float b = division(8.7,6.5);
    float a = 1.33846;
    assert(abs(b-a) <= epsilon);
     float p = remain(8.7,6.5);
    float o = 2.2;
    assert(abs(p==o) <= epsilon);
     float r = power(8.7,6.5);
    float n = 1279010;
    assert(abs(r==n) <= epsilon);
    float m = square(8.7);
    float e = 2.94957624;
    assert(abs(m-e) <= epsilon);
    cout << "All Tests Passed"<< endl;
}