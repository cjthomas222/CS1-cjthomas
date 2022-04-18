#include <iostream>
#include <iomanip>
#include <array>
#include <cassert>

using namespace std;

//void program();
void readData(int *, int);
void split(int*, int);
void bubbleSort(int *, int);

int main()
{
    //program(nums,size);
    size_t size;
    // cout << "This program finds statistical values of some integers entered by the user.\n";
    // cout << "How many nubers would like to enter? ";
    cin >> size;
    int *nums = new int[size];
    readData(nums,size);
    //bubbleSort(nums,size);
    split(nums,size);
    //bubbleSort(nums,size);
    delete [] nums;
}

// void program() {
//     size_t size;
//     // cout << "This program finds statistical values of some integers entered by the user.\n";
//     // cout << "How many nubers would like to enter? ";
//     cin >> size;
//     int *nums = new int[size];
//     readData(nums,size);
//     split(nums,size);
//     //bubbleSort(nums,size);
//     delete [] nums;
// }

void split(int nums[],int size)
{
    int bob = 0;
    int alice = 0;
    // int temp1 = 0;
    // int temp2 = 0;
    
    for(int i=0; i <= size;i++)
    {
        bubbleSort(nums,size);
        if(i % 2 == 0)
        {
            // if(nums[i] > temp1)
            // {
            // temp1 = nums[i];
            // nums[i] = 0;
           
            // }
            alice += nums[i];
            //temp1 = 0;
        }
        else
        {
            // if(nums[i] > temp2)
            // {
            // temp2 = nums[i];
            // nums[i] = 0;
            
            // }
            bob += nums[i];
            //temp2 = 0;
    }
    }
  cout << alice << " " << bob << endl;
}

void readData(int nums[], int size)
{
	//cout << "You've asked to enter " << size << " integers.\n";
	for(int i = 0; i < size; i++) {
		//cout << "Enter an integer: ";
		cin >> nums[i];
	}
}

void bubbleSort(int nums[], int size) 
{
	long int i, j;
	bool sorted = false;
	for (i = 0; i < size-1; i++) {
    	sorted = true;
		for (j = size-1; j >=0 ; j--) {
			if (nums[j] < nums[j+1])
            {
                swap(nums[j], nums[j+1]); 
				sorted = false;
			}
		}
		if (sorted) break;
	}
//      for(int z=0; z<size; z++)
//         cout<<nums[z]<<" ";
 }

void test(int nums[], int size)
{
    int test1[3] = {3,1,2};
	assert(split(test1, size) == "5 2");
} 