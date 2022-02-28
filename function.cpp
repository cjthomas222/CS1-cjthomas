#include <iostream>
#include <string>
#include <cassert>

using namespace std;

//int addnums(int,int);
//double addnums(double,double);
//float addnums(float, float);

template <class type1, class type2, class returntype> addnums(type1, type2, returntype);
void tests();

int main(){
    tests();
    cout<< "42 + 15 = " << addnums <int, int, int> (45,15) << endl;
    return 0;
 }

 template <class type1, class type2, class returntype>
 returntype addnums(type1 num1, type2 num2) {
     cout << "DEBUG: templated function" << endl;
     returntype sum;
     sum = num1 + num2;
     return sum;
 }

 void tests(){
     assert(addnums<int,int,int> (45,15) == 60);
     cout << "All test cases passed" << endl;
    }

 template <class returntype2, class inputtype1, class inputtype2>
 returntype2 subnums(inputtype1 num1, inputtype2 num2){
     return num1 - num2;
 }

// float addnums (float num1, float num2){
//     float sum;
//     sum = num1 + num2;
//     return sum;
// }

// double addnums (double num1, double num2){
//     double sum;
//     sum = num1 + num2;
//     return sum;
// }

// int addnums (int num1, int num2){
//     int sum;
//     sum = num1 + num2;
//     return sum;
// }
