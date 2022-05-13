#include <iostream>
#include <string>
#include <array>
#include <cmath>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <iomanip>

using namespace std;

struct Student
{
    string fname;
    string lname;
    int g1, g2, g3, g4;
};

int readData(string, Student grades[], const size_t &);
int printgrades(Student grades[], const size_t &);
float getAverage(Student grades[], const size_t &, int);
char grade(int);
int min1(Student grades[], const size_t &);

int main(int argc, char*argv[])
{
size_t arr_size = 11;
size_t num_students;
Student grades[arr_size];
string infilename = "grading.txt";
// ifstream infile(infilename); //reads in file
// infile.open(infilename);

num_students = readData(infilename, grades, arr_size);

//average(grades,num_students);

printgrades(grades,num_students);

// infile.close();
return 0;
}

int readData(string infilename,Student grades[], const size_t &num_students)
{
    string tmp; //buffer
    size_t cnt = 0;
    ifstream infile(infilename);
    // getline(infile, tmp);
    // cout << "DEBUG: " << tmp << endl;
    //infile.open(infilename); //open input file
    //cout << "DEBUG: inside readdata before while" << endl;
    while(getline(infile, tmp))//reads file until there is no more lines to read
    {
        Student each; //creates new struct for each iteration for each student
        // grades[cnt] = each;
        
        //cout << "DEBUG: " << tmp;
        stringstream ss(tmp);
        ss >> grades[cnt].fname >> grades[cnt].lname >> grades[cnt].g1 >> grades[cnt].g2 >> grades[cnt].g3 >> grades[cnt].g4;
        //cout << each.fname<<  " " << each.lname <<  " " << each.g1 <<  " " << each.g2 <<  " " << each.g3  <<  " "<< each.g4 << endl;
        cnt++;
    }
    //cout << "DEBUG: after while" << endl;
    infile.close();
    return cnt;
}

int printgrades(Student grades[], const size_t &num_students)
{
    //int count;
    cout << "==============================================================================" << endl;
    cout << "fname  lname        test1   test2   test3   test4   avg.   grade" << endl;
    cout << "==============================================================================" << endl;
    for(int i = 0; i < num_students; i++)
    {
        cout << grades[i].fname << "  " << grades[i].lname << "        " << grades[i].g1 << "     " << grades[i].g2 << "     " << grades[i].g3 << "     " << grades[i].g4 << "     ";
        int avg = getAverage(grades,num_students,i);
        char letter = grade(avg);
        cout << avg << "    "<<  letter << endl;
    }
    cout << "***************************************************" << endl;
    float test1;
    float test2;
    float test3;
    float test4;
    for(int j = 0; j <= 10; j++)
    {
        //cout << grades[i].g2;

        test1 += grades[j].g1;

        test2 += grades[j].g2;
        
        test3 += grades[j].g3;
        
        test4 += grades[j].g4;
        
        
        //getAverage(num_students(i)) << endl; 
        //average(num_students) << endl;
        //cout << each[i].fname << "         " << each[i].lname << "         " << each[i].g1 << "   " << each[i].g2 << "   " << each[i].g3 << "   " << each[i].g4 << "   " << endl;//average(i) << endl; 
    }
    test1 = test1/11;
    test2 = test2/11;
    test3 = test3/11;
    test4 = test4/11;

    cout << "Class Averages:       " << test1 << "  " << test2 << "  " << test3 << "  " << test4 << endl;
    //int mini1 = min1(grades,num_students);
    //cout << mini1;
    int min1 = grades[0].g1;
    for(int n = 0; n < 11; n++)
    {
        if(min1 < grades[n].g1)
        {
            min1 = grades[n].g1;
        }
    }
    cout << min1 << endl;
    return 0;
}

float getAverage(Student grades[], const size_t &num_students, int n)
{
    float average = 0;
    //size_t count = 0;
    //for(size_t n = 0; n < num_students; n++)
    //{
        //average= average + grades[arr_size];
        average += grades[n].g1;
        average += grades[n].g2;
        average += grades[n].g3;
        average += grades[n].g4;
        average = average/4;  
        //cout << average << endl;
        return average;
        //average = 0;
    //}
  //cout << average;
}



char grade(int n)
{
    if(n >= 90)
    {
        return 'A';
    }
    else if(n >= 80)
    {
        return 'B';
    }
    else if(n>= 70)
    {
        return 'C';
    }
    else if(n>=60)
    {
        return 'D';
    }
    else
    {
        return 'F';
    }
    return 0;
}

// int min1(Student grades[], const size_t &num_students)
// {
//     int min = 0;
//     for(int i = 0; i < num_students; i++)
//     {
//         if(grades[i].g1 < grades[i+1].g1)
//         {
//             min = grades[i+1].g1;
//         }
//     }
// }
// if (infile.is_open())  
// {
//     for (i = 0; i < size; i++) 
//     {
//         infile >> nums[i];
//         cout << nums[i] << " ";
//      }

//         infile.close();// close input file
//     }
//     else {
//         cout << "Can't find input file " << infilename << endl;
//     }
//}