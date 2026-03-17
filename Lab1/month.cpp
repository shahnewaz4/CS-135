/*
Author: Shahnewaz Azad
Course: CSCI-135
Assignment: Lab1D

C++ project that prints the days in a month, taking into account if it isa leap year or not
*/

#include <iostream>

std::string leapyear(int n){
    if(n%4 != 0){
        return "Common year";
    }
    else if(n%100 != 0){
        return "Leap year";
    }
    else if(n%400 != 0){
        return "Common year";
    }
    else{
        return "Leap year";

    }

    return 0;
}

int main(){
    int year, month;
    std::cout << "Enter year: ";
    std::cin >> year;
    std::cout << "Enter month: ";
    std::cin >> month;
    if(month == 1||month == 3||month == 5 ||month == 7||month == 8||month == 10||month == 12){
        std::cout << "31 days\n";
    }
    else if(month == 4||month == 6||month == 9||month == 11){
        std::cout << "30 days\n";
    }
    else{
        if(leapyear(year) == "Leap year"){
            std::cout << "29 days\n";
        }
        else{
            std::cout << "28 days\n";
        }
    }
}