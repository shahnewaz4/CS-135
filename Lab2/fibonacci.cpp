/*
Author: Shahnewaz Azad
Course: CSCI-136
Assignment: Lab2D

Computes and prints Fibonacci numbers from F(0) to F(59)
*/

#include <iostream>

int main(){
    int fib[60];
    fib[0] =0;
    fib[1] = 1;
    for(int i = 2; i < 60; i++){
        fib[i] = fib[i-1]+fib[i-2];
    }
    for(int i = 0; i < 60; i++){
        std::cout << fib[i] << std::endl;
    }
    return 0;
}