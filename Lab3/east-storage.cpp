/*
Author: Shahnewaz Azad
Course: CSCI-136
Assignment: Lab3A

Prints out the storage for the basin at the given date based on the tsv
*/


#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
using namespace std;


int main() {
    ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
        cerr << "File cannot be opened for reading." << endl;
        exit(1); // exit if failed to open the file
    }
    
    string junk, date, sdate;
    getline(fin, junk);
    float estor;

    cout << "Enter date in MM/DD/YYYY format: ";
    cin >> date;
    while (fin >> sdate >> estor){
        fin.ignore(INT_MAX, '\n');
        if (sdate == date){
            cout << "East basin storage: " << estor << " billion gallons";
            break;
        }
    }
    fin.close();
    return 0;
}

