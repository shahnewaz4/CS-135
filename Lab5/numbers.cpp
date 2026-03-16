/*
Author: Shahnewaz Azad
Course: CSCI-135
Assignment: Lab5

Implementation of functions isDivisibleBy, isPrime, nextPrime, countPrimes
isTwinPrime, nextTwinPrime, and largestTwinPrime
*/

#include <iostream>

bool isDivisibleBy(int n, int d){
    if(n%d == 0){
        return true;
    }
    else{
        return false;
    }
}

bool isPrime(int n){
    for(int i = 2; i < n; i++){
        if(isDivisibleBy(n,i)==true){
            return false;
        }
    }
    return true;
}

int nextPrime(int n){
    int nnum = n+1;
    while(isPrime(nnum)==false){
        nnum++;
    }
    return nnum;
}

int countPrimes(int a, int b){
    int count = 0;
    for(int i = a; i < b+1; i++){
        if(isPrime(i) == true){
            count++;
        }
    }
    return count;
}

bool isTwinPrime(int n){
    if(isPrime(n-2) || isPrime(n+2)){
        return true;
    }
    else{
        return false;
    }
}

int nextTwinPrime(int n){
    int next = n+1;
    while(isTwinPrime(next) == false){
        next++;
    }
    return next;
}


int largestTwinPrime(int a, int b){
    int largest = -1;
    for(int i = a; i < b+1; i++){
        if(isTwinPrime(i)){
            largest = i;   
        }
    }
    return largest;
}

int main(){

    return 0;
}