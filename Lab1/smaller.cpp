/*
Author: Shahnewaz Azad
Course: CSCI-136
Assignment: Lab1A

Beginner C++ project that gives the smaller of 2 numbers
*/

#include <iostream>

int main(){
    int num1,num2, small;
    std::cout << "Enter the first number: ";
    std::cin >> num1;
    std::cout << "Enter the second number: ";
    std::cin >> num2;
    if(num1 < num2){
        small = num1;
    }
    else{
        small = num2;
    }
    std::cout << "The smaller of the two is " << small << std::endl;

    return 0;
}