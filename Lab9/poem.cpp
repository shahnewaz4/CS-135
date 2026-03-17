/*
Author: Shahnewaz Azad
Course: CSCI-135
Assignment: Lab9D
 
Fixing dynamic allocation to fix memory leak

*/



#include <iostream>
using namespace std;

string * createAPoemDynamically() {
    string *p = new string;
    *p = "Roses are red, violets are blue";
    return p;
}

int main() {
    while(true) {
        string *p;
        p = createAPoemDynamically();
        delete p;

        // assume that the poem p is not needed at this point

    }
}