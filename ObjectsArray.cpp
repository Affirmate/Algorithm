//Illustrate use of object arrays by storing details of 10 items in an array of objects
#include <iostream>
#include <stdio.h>

using namespace std;

class ITEM
{
private:
    int itemno;
    float price;
public:
    void getdata(int i, float j)
    {
        itemno = i;
        price = j;
    }
    void putdata(void)
    {
        cout << "\nItemno: " << itemno << "\t";
        cout << "\nPrice: " << price << "\n";
    }
};

const int size = 10;
ITEM order[size];

int main()
{
    int ino;
    float cost;
    //Get values for all items
    for(int a=0; a<size; a++)
    {
        cout << "\nEnter itemno & price for item" << a+1 << "\n";
        cin >> ino >> cost;
        order[a].getdata(ino, cost);    //invoke getdata() for a particular object with the given values
    }
    
    //Print details
    for(int a=0; a<size; a++)
    {
        cout << "\nItem " << a+1 << "\n";
        order[a].putdata(); //invoke putdata() for a particular object
    }
    
    return 0;
}
