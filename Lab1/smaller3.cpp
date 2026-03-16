/*
Author: Shahnewaz Azad
Course: CSCI-136
Assignment: Lab1B

Beginner C++ project that gives the smallest of 3 numbers
*/
#include <iostream>

int main(){
    int num1,num2, num3, smallest;
    std::cout << "Enter the first number: ";
    std::cin >> num1;
    std::cout << "Enter the second number: ";
    std::cin >> num2;
    std::cout << "Enter the third number: ";
    std::cin >> num3;

    if((num1 < num2) && (num1 < num3)){
        smallest = num1;
    }
    else if((num2 < num1)&& (num2<num3)){
        smallest = num2;
    }
    else{
        smallest = num3;
    }
    std::cout << "The smaller of the three is " << smallest << std::endl;

    return 0;
}