/*
Author: Shahnewaz Azad
Course: CSCI-135
Assignment: Project 1D

Takes a maze input and traverses file for multiple inputs to see if we have made it out of the maze
*/


#include <iostream>
#include <string>
using namespace std;

int main(){

    int start_r, start_c;
    int end_r, end_c;

    int maze[10][10];
    string junk;
   
    

    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            cin >> maze[i][j];
        }
    }
    
    cin >> start_r >> start_c >> end_r >> end_c;

    
    getline(cin, junk, ';');
 
    int c;
    int r;
    r = start_r;
    c = start_c;
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
        if (r == end_r && c == end_c){
            cout << "You got out of the maze." << endl;
            r = start_r;
            c = start_c;

        }
        else{
            cout << "You are stuck in the maze." << endl;
            r = start_r;
            c = start_c;
        }
    }
    return 0;
}

