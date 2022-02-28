#include <iostream>
#include <string>

namespace my_namespace{
    namespace nested_namespace;
    string firstName;
    char middleInitial;
    unsigned int height;
}

using namespace std;

int main(){
    firstName = "Connor";
    middleInitial = 'J';
    height = 80;
    lastName =" Thomas";

    cout<< "Hello " << firstName
    << " " << lastname
    << " your middle initial is: "
    << middleInitial
    <<" and you are "
    <<height
    <<" inches tall." << endl;
    return 0;
}