#include <iostream>
using namespace std;

int addnums(int num1, int num2) {
    int sum;

    sum = num1 + num2;
    return sum;

}
string prompt_name() {
    string name;
    cout<< "Please enter your name: ";
    cin>> name;
    return name;
}

void greeting(){
    cout<< "Hello World" << endl;
}
    int main() {
        // int sum_nums;
        // greeting ();
        // sum_nums = addnums(42,15);
        // return 0;

        // string first_name;
        // first_name = prompt_name();
        greeting(prompt_name());
    }
