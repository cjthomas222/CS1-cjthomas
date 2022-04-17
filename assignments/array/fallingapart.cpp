#include <iostream>
#include <iomanip>
#include <array>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cstdio>

using namespace std;

void program();
void readData(int *, int);
void split(int*, int);

int main()
{
//size_t size;
//int *nums = new int[size];
//readData();
program();
return 0;
}

void program() {
    size_t size;
    cout << "This program finds statistical values of some integers entered by the user.\n";
    cout << "How many nubers would like to enter? ";
    cin >> size;
    int *nums = new int[size];
    readData(nums,size);
    split(nums,size);
    delete [] nums;
}

void split(int nums[],int size)
{
    int bob = 0;
    int alice = 0;
    for(int i=0; i < size;i++)
    {
        if(i % 2 == 0)
        {
            alice += nums[i];
        }
        else
        {
            bob += nums[i];
        }
    }
  cout << alice << " " << bob << endl;
}

void readData(int nums[], int size)
{
	//cout << "You've asked to enter " << size << " integers.\n";
	for(int i = 0; i < size; i++) {
		cout << "Enter an integer: ";
		cin >> nums[i];
	}
}
