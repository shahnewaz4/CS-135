/*
Author: Shahnewaz Azad
Course: CSCI-135
Assignment: Lab12A

Function for returning a vector for n integers
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> makeVector(int n){
    vector<int> vec;
    for(int i = 0; i < n; i++){
        vec.push_back(i);
    }
    return vec;
}

int main(){
    vector<int> vec = makeVector(5);
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i] << " ";
    }
}