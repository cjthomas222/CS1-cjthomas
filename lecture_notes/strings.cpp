#include <iostream>
#include <string>

using namespace std;

int main(int argc, char*argv[])
{
    char somestring[] = "This is a c-string";
    // cout << "somestring = " << somestring[8] << endl; //pulls the "a" from somestring
    size_t stringlength = 0;
    string firstname = "Connor";
    string lastname = "Thomas";
    string fullname;

    fullname = firstname + " " + lastname;
    size_t i =0;
    while(fullname[i] != '\0'){
        cout << i << ": " << fullname[i] << endl;
        i++;
    }

    // stringlength = fullname.length();
    // cout << "The length of our string is : " << stringlength << endl;

    // for (size_t i=0; i < stringlength; i++) {
    //     if (i == 7){
    //         fullname.at(i) = "W";
        //}
        // cout << i << ": " fullname[i] << endl;
        // cout << i << ": " <<fullname.at(1) << endl;
    //}
cout << "Your full name is: " << fullname << endl;
}