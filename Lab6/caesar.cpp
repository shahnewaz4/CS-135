/*
Author: Shahnewaz Azad
Course: CSCI-135
Assignment: Lab6B

Program takes line and shifts characters to encrypt using Caesar cipher
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

std::string encryptCaesar(std::string plaintext, int rshift){
    for(int i = 0; i < plaintext.length(); i++){
        plaintext[i] = shiftChar(plaintext[i], rshift);
    }
    return plaintext;
}

int main(){

    return 0;
}