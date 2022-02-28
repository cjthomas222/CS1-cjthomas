#include <iostream>
#include <string>

using namespace std;

int main() {
    int grade;
    char grade_answer;
    cout<< "Please enter a grade: ";
    cin>> grade;

    grade_answer = grade_check(grade);

    (grade_answer== 'A') ? (cout << "Your grade is an " << grade_answer << endl) : (cout << "Your grade is a ") grade_answer << endl);

    // if (num > 50){
    //     cout << num << " is positive and larger than 50" << endl;
    // } else if (num < 0) {
    //     cout << num << " is between 0 and 50" << endl;
    // } else if (num < -50) {
    //     cout << num << " is between -50 and 0" << endl;
    // } else {
    //     cout << num << " is zero" << endl;
    // }

    return 0;
    // }

// if (num >= 0){
//     if (num == 0){
//         cout << num << " is zero" << endl;
//     } else {
//         cout << num << "is positive" << endl;
//     } else {
//     cout << num << " is negative" << endl;
//     }   
//     }
// }

