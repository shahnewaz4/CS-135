/*
Author: Shahnewaz Azad
Course: CSCI-136
Assignment: Lab3B

Finds the minimum and maximum basin storage in 2018
*/


#include <iostream>
#include <fstream>
#include <climits>
#include <cstdlib>
using namespace std;

int main(){
    fstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
        cerr << "File cannot be opened for reading." << endl;
        exit(1); // exit if failed to open the file
    }
    
    string junk;
    getline(fin, junk);
    float highest, lowest;
    highest = 0;
    lowest = 100;
    string date;
    float estor;
    while (fin >> date >> estor){
        fin.ignore(INT_MAX, '\n');
        
        if(estor > highest){
            highest = estor;
        }
        else if(estor < lowest){
            lowest = estor;
        }
    }
    fin.close();
    cout << "Minimum storage in East basin: " << lowest << "  billion gallons" << endl;
    cout << "Maximum storage in East basin: " << highest << "  billion gallons" << endl;
    
    
    
    return 0;
}
