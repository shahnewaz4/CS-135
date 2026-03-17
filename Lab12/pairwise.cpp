/*
Author: Shahnewaz Azad
Course: CSCI-135
Assignment: Lab12D

Function for returning pairwise sum
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> sumPairWise(const vector<int> &v1, const vector<int> &v2){
    vector<int> pairwise;
    for(int i = 0; i < max(v1.size(),v2.size()); i++){
        pairwise.push_back(v1[i]+v2[i]);
    }
    return pairwise;
}

int main(){
    vector<int> v1{1,2,3};
    vector<int> v2{4,5};

    vector<int> pair = sumPairWise(v1, v2); // returns [5, 7, 3]
    for(int i = 0; i < pair.size(); i++){
        cout << pair[i] << " ";
    }
    return 0;
}