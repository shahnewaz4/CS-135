/*
Author: Shahnewaz Azad
Course: CSCI-135
Assignment: Lab6B

Program takes line and shifts characters to encrypt using Vigenere cipher
*/

#include <iostream>
#include <cctype>

char shiftChar(char c, int rshift){
    if((int)c >64 && (int)c < 91){
        if(c+rshift > 91){
            return c+rshift-26;
        }
        else{
            return c+rshift;
        }
    }
    else if((int)c >96 && (int)c < 123){
        if(c+rshift > 123){
            return c+rshift-26;
        }
        else{
            return c+rshift;
        }
    }
    else{
        return c;
    }
}

std::string encryptVigenere(std::string plaintext, std::string keyword){
    int keyind = 0;
    for(int i = 0; i < plaintext.length(); i ++){
        if((plaintext[i] >64 && plaintext[i] < 91)||(plaintext[i] >96 && plaintext[i] < 123)){
            plaintext[i] = shiftChar(plaintext[i], (int)keyword[keyind]-97);
            keyind++;
            if(keyind==keyword.length()){
                keyind=0;
            }
        }
        
        
    }
    return plaintext;
}

int main(){


    return 0;
}