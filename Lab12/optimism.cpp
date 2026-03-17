/*
Author: Shahnewaz Azad
Course: CSCI-135
Assignment: Lab12B

Function for returning all positive values in vector
*/


#include <iostream>
#include <vector>

using namespace std;



vector<int> goodVibes(const vector<int>& v){
    vector<int> pos;
    for(int i = 0; i < v.size(); i++){
        if(v[i] > 0){
            pos.push_back(v[i]);
        }
    }
    return pos;
}

int main(){
    vector<int> v{1,2,-1,3,4,-1,6};

    vector<int> pos = goodVibes(v); // returns [1,2,3,4,6]
    for(int i = 0; i < pos.size(); i++){
        cout << pos[i] << " ";
    }
    return 0;
}