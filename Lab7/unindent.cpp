/*
Author: Shahnewaz Azad
Course: CSCI-135
Assignment: Lab7A
 
Reads input from cin and prints out each input line with leading spaces removed

*/
#include <iostream>
using namespace std;

string removeLeadingSpaces(string line){
    string rline = "";
    bool check = true;
    for(int i = 0; i < line.size(); i++) {
        if(!(check && isspace(line[i]))) {
            rline += line[i]; //adds to string if not a space
            check = false;
        }
    }
    return rline;
}


int main(){
    string line;
    int count = 0;
    while(getline(cin, line)) {
        for(int i = 0; i < count; i++) {
            cout << "\t";
        }
        cout << removeLeadingSpaces(line) << endl;
    }
    return 0;
}