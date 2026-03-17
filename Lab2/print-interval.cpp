/*
Author: Shahnewaz Azad
Course: CSCI-135
Assignment: Lab2B

Prints out all numbers in the range of L <= i < U
*/

#include <iostream>

int main(){
    int l, u;
    std::cout << "Please enter L: ";
    std::cin >> l;
    std::cout << "Please enter U: ";
    std::cin >> u;
    for(int i = l; i < u; i++){
        std::cout << i << " ";
    }

    return 0;
}