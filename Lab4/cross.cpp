/*
Author: Shahnewaz Azad
Course: CSCI-135
Assignment: Lab4C

Uses loops to print out a cross pattern using users size
*/

#include <iostream>

int main(){
    int size;
    std::cout << "Input size: ";
    std::cin >> size;
    int l = 0;
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            if (j == l || j == (size-1-l)){
                std::cout << "*";
            }
            else{
                std::cout << " ";
            }
        }
        std::cout << std::endl;
        l++;
    }
    return 0;
}