/*
Author: Shahnewaz Azad
Course: CSCI-136
Assignment: Lab3D

Parses data and prints out date and elevation in reverse
*/



#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
using namespace std;

int main(){
    ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
        cerr << "File cannot be opened for reading." << endl;
        exit(1); // exit if failed to open the file
    }
    string junk;
    getline(fin, junk);
    
    string date, edate, ldate;
    cout << "Enter earlier date: ";
    cin >> edate;
    cout << "Enter later date: ";
    cin >> ldate;
    
    int coun = 0;
    float wele[365];
    string sdate[365];
    

    float estor, eelev, wstor, welev;
    while (fin >> date >> estor >> eelev >> wstor >> welev){
        fin.ignore(INT_MAX, '\n');
        
        if (date >= edate && date <= ldate){
            wele[coun] = welev;
            sdate[coun] = date;
            coun++;
        }
    }
    for (int i = coun; i >= 0; i--){
        cout << sdate[i] << " " << wele[i] << endl;
    }
    fin.close();

    return 0;
}