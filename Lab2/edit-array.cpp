/*
Author: Shahnewaz Azad
Course: CSCI-135
Assignment: Lab2C

Creates array of 10 integers that can be changed while program running
*/

#include <iostream>

int main(){
    int myData[10];
    int ind, val;
    for(int i = 0; i < 10; i++){
        myData[i] = 1;
    }
    do{
        for(int i = 0; i < 10; i++){
            std::cout << myData[i] << " ";
        }
        std::cout << "Input index: ";
        std::cin >> ind;
        std::cout << "Input value: ";
        std::cin >> val;
        myData[ind] = val;
    }while(ind > -1 && ind < 10);
    std::cout << "Index out of range. Exit\n";
    return 0;
}