//Write a C++ program that uses an area() function for the calculation of area of a triangle or a rectangle or a square. Number of sides suggest about the shape for which area is to be calculated


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float area(float a, float b, float c)   //Triangle
{
    float s, ar;
    s = (a+b+c)/2;
    ar = sqrt(s*(s-a)*(s-b)*(s-c));
    return ar;
}

float area(float a, float b)        //Rectangle
{
    return a*b;
}

float area(float a)     //Square
{
    return a*a;
}

int main()
{
    system("cls");
    int choice, s1, s2, s3, ar;
    do
    {
        std::cout << "\nArea Main Menu\n";
        std::cout << "\n1. Triangle";
        std::cout << "\n2. Rectangle";
        std::cout << "\n3. Square";
        std::cout << "\n4. Exit\n";
        std::cout << "\nEnter your choice (1-4): ";
        std::cin >> choice;
        
        switch(choice)
        {
            case 1: std::cout << "\nEnter 3 sides\n";
                std::cin >> s1 >> s2 >> s3;
                ar = area(s1, s2, s3);
                std::cout << "\nArea: " << ar;
                break;
            case 2: std::cout << "\nEnter 2 sides\n";
                std::cin >> s1 >> s2;
                ar = area(s1, s2);
                std::cout << "\nArea: " << ar;
                break;
            case 3: std::cout << "\nEnter 1 side\n";
                std::cin >> s1;
                ar = area(s1);
                std::cout << "\nArea: " << ar;
                break;
            case 4: break;
        }
    } while(choice > 0 && choice < 4);
        
    return 0;
        
}
