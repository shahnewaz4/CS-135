

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

char deshiftChar(char c, int rshift){

    if (c >= 'a' && c <= 'z'){
        c = ((c - 'a' + 26 - rshift) % 26) + 'a';
    }
    else if (c >= 'A' && c <= 'Z'){
        c = ((c - 'A' + 26 - rshift) % 26) + 'A';
    }
    return c;
    
}

std::string encryptCaesar(std::string plaintext, int rshift){
    for(int i = 0; i < plaintext.length(); i++){
        plaintext[i] = shiftChar(plaintext[i], rshift);
    }
    return plaintext;
}


std::string decryptCaesar(std::string ciphertext, int rshift){
    char l;
    std::string sent = "";
    for (int i = 0; i < ciphertext.length(); i++){
        l = deshiftChar(ciphertext[i], rshift);
        sent += l;
    }
    return sent;
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

std::string decryptVigenere(std::string ciphertext, std::string keyword){
    char s;
    std::string sent = "";
    int r = 0;
    for (int i = 0; i < ciphertext.length(); i++){
        if ((ciphertext[i] >= 'a' && ciphertext[i] <= 'z')||(ciphertext[i] >= 'A' && ciphertext[i] <= 'Z')){
            int k;
            k = (int)keyword[r % keyword.length()] - (int)'a';
            s = deshiftChar(ciphertext[i], k);
            sent += s;
            r++;
        }
        else{
            sent += ciphertext[i];
        }
    }
    return sent;
    return 0;
}

int main(){

    return 0;
}
