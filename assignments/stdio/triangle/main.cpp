
#include <iostream>
#include <cmath>
#include <string>
//this program calculates information about a triangle based on 3 inputs from the user
using namespace std;

int main(){
double side1= 0 , side2 = 0 , side3= 0 , area= 0 , perimeter= 0 , s = 0 , x= 0;

cout << "Please Enter 3 Side Lengths: " << endl;
cin>> side1 >> side2 >> side3;
/*
cout << "Please Enter Side 2 Length" << endl;
cin>> side2;

cout << "Please Enter Side 3 Length" << endl;
cin>> side3;
*/
perimeter= side1+ side2+ side3;
s= perimeter/2;

x = s * (s-side1) * (s-side2) * (s-side3);

area = sqrt(x);

cout << "Area = " << area << endl;
cout << "Perimeter = " << perimeter << endl;
/*side1 -= semi;
side2 -= semi;
side3 -= semi;
*/
//cout<< side1 << side2 << side3 << "\n\n\n" << area;

}