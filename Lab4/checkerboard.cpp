/*
Author: Shahnewaz Azad
Course: CSCI-135
Assignment: Lab4B

Uses loops to print out a checkerbox pattern using users width and height
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
            if(i%2 == 0 && j%2 == 0){
                std::cout <<"*";
            }
            if(i%2 == 1 && j%2 == 1){
                std::cout <<"*";
            }
            if(i%2 == 0 && j%2 == 1){
                std::cout <<" ";
            }
            if(i%2 == 1 && j%2 == 0){
                std::cout <<" ";
            }
            
        }
        std::cout << "\n";
    }
}