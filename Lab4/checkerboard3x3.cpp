/*
Author: Shahnewaz Azad
Course: CSCI-135
Assignment: Lab4G

Uses loops to print out a checkerbox pattern using users width and height
and a 3 by 3 pattern
*/

#include <iostream>
using namespace std;

int main(){
    bool staw = true;
    bool stah = true;
    int wid, hei;
    cout << "Input width: ";
    cin >> wid;
    cout << "Input height: ";
    cin >> hei;
    cout << "Shape: " << endl;
    
    bool l = staw;
    
    for (int i = -1; i < hei-1; i++){
        for (int j = 1; j < wid+1; j++){
            
            if (staw == true && stah == true){
                cout << "*";
            }
            else {
                cout << " ";
            }
            if (j % 3 == 0){
                staw = !staw;
            }
        }
        cout << endl;
        staw = l;
        if (i % 3 == 0){
            l = !l;
        }


    }
    
    return 0;
}