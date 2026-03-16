/*
Author: Shahnewaz Azad
Course: CSCI-135
Assignment: Lab6A

Program takes line and prints characters in ascii code line by line
*/

#include <iostream>
#include <cctype>

int main(){
    std::string line;
    std::cout << "Input line: ";
    getline(std::cin, line);
    for(int i = 0; i < line.length(); i ++){
        std::cout << line[i] << " " << (int)line[i] << std::endl;
    }
}