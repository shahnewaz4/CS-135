/*
Author: Shahnewaz Azad
Course: CSCI-135
Assignment: Lab7B
 
Reads input from cin and indents properly

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

int countChar(string line, char c){
    int count = 0;
    for(int i = 0; i < line.length(); i++){
        if(line[i] == c){
            count ++;
        }
    }
    return count;
}

int main(){
    string line, fline;
    int count = 0;

    while(getline(cin, line)) {
        
        line = removeLeadingSpaces(line);
        int open = countChar(line, '{');
        int close = countChar(line, '}');
        if(close > open){
            count -= close - open;
        }
        for(int i = 0; i < count; i++){
            cout << "\t";
        }
        cout << line << endl;
        
        if(open > close){
            count += open - close;
        }
    }
    return 0;
}

