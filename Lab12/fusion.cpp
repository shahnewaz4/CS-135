/*
Author: Shahnewaz Azad
Course: CSCI-135
Assignment: Lab12C

Function for combining 2 vectors in ascending order
*/


#include <iostream>
#include <vector>

using namespace std;



void gogeta(vector<int> &goku, vector<int> &vegeta){
    for(int i = 0; i < vegeta.size(); i++){
        bool inserted = false;
        for(int j = 0; j < goku.size(); j++){
            if(vegeta[i] < goku[j]){
                goku.insert(goku.begin()+j,vegeta[i]);
            }
        }
        if(!inserted){
            goku.push_back(vegeta[i]);
        }
    }
    vegeta.clear();
}

int main(){
    vector<int> v1{1,2,3};
    vector<int> v2{4,5};

    gogeta(v1, v2); // v1 is now [1,2,3,4,5] and v2 is empty.
    for(int i = 0; i < v1.size(); i++){
        cout << v1[i];
    }
    cout << endl;
    
    return 0;
}