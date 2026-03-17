/*
Author: Shahnewaz Azad
Course: CSCI-135
Assignment: Lab10
 
Implementing functions minutesSinceMidnight, minutesUntil, addMinutes, printTimeSlot, scheduleAfter, timeOverlap

*/


#include <iostream>

using namespace std;


enum Genre {ACTION, COMEDY, DRAMA, ROMANCE, THRILLER};

class Movie { 
public: 
    string title;
    Genre genre;     // only one genre per movie
    int duration;    // in minutes
};

class Time { 
public:
    int h;
    int m;
};


class TimeSlot { 
public: 
    Movie movie;     // what movie
    Time startTime;  // when it starts
};




int minutesSinceMidnight(Time time){
    Time mtime = time;
    int min = 0;
    min += mtime.h * 60;
    min += mtime.m;
    return min;

}

int minutesUntil(Time earlier, Time later){
    Time ftime = earlier;
    Time stime = later;
    int fmin = minutesSinceMidnight(ftime);
    int smin = minutesSinceMidnight(stime);
    int inter;
    inter = smin - fmin;
    return inter;
}

Time addMinutes(Time time0, int min){
    Time ntime;
    if (min+time0.m >= 60){
        ntime.h = (min + time0.m)/60 + time0.h;
        ntime.m = (min + time0.m)%60;
    }
    else{
        ntime.h = time0.h;
        ntime.m = time0.m + min;
    }
    return ntime;
}

void printTime(Time time) {
    cout << time.h << ":" << time.m;
}

void printMovie(Movie mv){
    string g;
    switch (mv.genre) {
        case ACTION   : g = "ACTION"; break;
        case COMEDY   : g = "COMEDY"; break;
        case DRAMA    : g = "DRAMA";  break;
        case ROMANCE  : g = "ROMANCE"; break;
        case THRILLER : g = "THRILLER"; break;
    }
    cout << mv.title << " " << g << " (" << mv.duration << " min)";
}

void printTimeSlot(TimeSlot ts){
    printMovie(ts.movie);
    cout << " [starts at ";
    printTime(ts.startTime);
    cout << ", ends by ";
    printTime(addMinutes(ts.startTime,ts.movie.duration));
    cout << "]" << endl;
}

TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie){
    TimeSlot nts;
    nts.movie = nextMovie;
    nts.startTime = addMinutes(ts.startTime, ts.movie.duration);
    return nts;

}

bool timeOverlap(TimeSlot ts1, TimeSlot ts2){
    if(minutesUntil(addMinutes(ts1.startTime, ts1.movie.duration), ts2.startTime) >= 0){
        return false;
    }
    else if(minutesUntil(addMinutes(ts2.startTime, ts2.movie.duration), ts1.startTime) >= 0){
        return false;
    }
    else {
        return true;
    }

}

int main(){

    
    Movie movie1 = {"The Batman", ACTION, 156};
    Movie movie2 = {"The Batman 2", ACTION, 100};
    TimeSlot morning = {movie1, {9, 15}};
    TimeSlot daytime = {movie1, {12, 15}}; 
    TimeSlot evening = {movie1, {16, 45}};
    TimeSlot noon = {movie1, {12, 0}};
    TimeSlot night = {movie1, {10, 30}};    

    printTimeSlot(morning);
    printTimeSlot(scheduleAfter(morning, movie2));

    return 0;

}