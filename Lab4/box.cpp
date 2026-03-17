/*
Author: Shahnewaz Azad
Course: CSCI-135
Assignment: Lab4A

Uses loops to print out a box using users width and height
*/


#include <iostream>

int main(){
    int wid, hei;
    std::cout << "Inuput width: ";
    std::cin >> wid;
    std::cout << "Input height: ";
    std::cin >> hei;
    std::cout << "Shape: \n";
    for(int i = 0; i < hei; i++){
        for(int j = 0; j < wid; j++){
            std::cout <<"*";
        }
        std::cout << "\n";
    }
}