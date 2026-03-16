/*
Author: Shahnewaz Azad
Course: CSCI-135
Assignment: Project 1C

Takes a maze in array form and traverses file for multiple inputs to see if we have made it out of the maze
*/


#include <iostream>
#include <string>
using namespace std;

int main(){
    int maze[6][6] = {
       1,0,1,1,1,1,
       1,0,0,0,1,1,
       1,0,1,0,0,1,
       1,0,1,0,1,1,
       1,0,0,0,0,0,
       1,1,1,1,1,1
    };
    
    int r = 0;
    int c = 1;
    string file_input;
    
    while(getline(cin, file_input, ';')){
        for(int i = 0; i < file_input.length(); i++){
            if (file_input[i] == 'D'){
                if (maze[r+1][c] == 0){
                    r = r + 1;
                }
            }
            else if (file_input[i] == 'U'){
                if (maze[r-1][c] == 0){
                    r = r - 1;
                }
            }
            else if (file_input[i] == 'R'){
                if (maze[r][c+1] == 0){
                    c = c + 1;
                }
            }
            else if (file_input[i] == 'L'){
                if (maze[r][c-1] == 0){
                    c = c - 1;
                }
            }

            
        }
        if (r == 4 && c == 5){
            cout << "You got out of the maze." << endl;

        }
        else{
            cout << "You are stuck in the maze." << endl;
        }
    }
    return 0;
}