/*
Author: Shahnewaz Azad
Course: CSCI-135
Assignment: Project 1A

Direction reader for maze input
*/



#include <iostream>
using namespace std;



int main(){
    string file_input;
    while (cin >> file_input){
        if (file_input == "R"){
            cout << "Right";
        }
        else if (file_input == "L"){
            cout << "Left";
        }
        else if (file_input == "D"){
            cout << "Down";
        }
        else if (file_input == "U"){
            cout << "Up";
        }
    }
    return 0;
}