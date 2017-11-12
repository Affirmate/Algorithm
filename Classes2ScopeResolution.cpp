//Illustrate the functioning of the scope resolution operator
#include <iostream>
#include <stdio.h>

using namespace std;
int a = 10;
int main()
{
    int a = 15;
    cout << "\nmain()" << "\n";
    cout << "a = " << a << "\n";    //a = 15 local to main()
    cout << "::a = " << ::a << "\n";    //Global a = 10
    {
        int a = 25; //a = 25 local to inner block
        cout << "a = " << a;
        cout << "::a = " << ::a; //Global a = 10
    }
    
    return 0;
}
