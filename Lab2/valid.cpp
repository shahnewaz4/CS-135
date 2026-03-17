/*
Author: Shahnewaz Azad
Course: CSCI-135
Assignment: Lab2A

Prints the squared number as long it is within the range
*/

#include <iostream>

int main(){
    int num;
    std::cout << "Please enter an integer: ";
    std::cin >> num;
    while(num < 1 || num > 99){
        std::cout << "Please re-enter: ";
        std::cin >> num;
    }
    std::cout << "Number squared is " << num*num << std::endl;
}