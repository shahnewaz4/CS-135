/*
Author: Shahnewaz Azad
Course: CSCI-135
Assignment: Lab3C

Takes a range and prints if East or West had a higher elevation
*/



#include <iostream>
#include <fstream>
#include <climits>
#include <cstdlib>
using namespace std;

int main(){
    ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
        cerr << "File cannot be opened for reading." << endl;
        exit(1); // exit if failed to open the file
    }
    
    string junk;
    string date, date1, date2;

    getline(fin, junk);
    
    cout << "Enter starting date: ";
    cin >> date1;
    cout << "Enter ending date: ";
    cin >> date2;
    
    
    float estor, eelev, wstor, welev;
    while (fin >> date >> estor >> eelev >> wstor >> welev){
        fin.ignore(INT_MAX, '\n');
        if (date >= date1 && date <= date2){
            if (eelev > welev){
                cout << date << " East" << endl;
            }
            else if (welev > eelev){
                cout << date << " West" << endl;
            }
            else if (eelev == welev){
                cout << date << " Equal" << endl;
            }
        }
                
    }
    fin.close();
    
    return 0;
}