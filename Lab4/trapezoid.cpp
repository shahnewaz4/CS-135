/*
Author: Shahnewaz Azad
Course: CSCI-135
Assignment: Lab4E

Uses loops to print out an upside down trapezoid pattern using users size
taking into account if it is possible
*/


#include <iostream>
using namespace std;

int main(){
    int inp;
    cout << "Input side length: ";
    cin >> inp;
    cout << "Shape : " << endl;
    int l = -1;
    for (int i = 0; i < inp; i++){
        for (int j = 0; j < inp; j++){
            if (j > l){
                cout << "*";
            }
            else {
                cout << " ";
            }
        }
        cout << endl;
        l++;
    }

    return 0;
}
