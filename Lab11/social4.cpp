/*
Author: Shahnewaz Azad
Course: CSCI-135
Assignment: Lab11D

Implementing following feature users can create posts and print out timeline of users
*/

#include <iostream>
using namespace std;


struct Post{
  string username;
  string message;
};

class Profile {
private:
    string username;
    string displayname;
public:
    // Profile constructor for a user (initializing 
    // private variables username=usrn, displayname=dspn)
    Profile(string usrn, string dspn){
        username = usrn;
        displayname = dspn;
    }
    // Default Profile constructor (username="", displayname="")
    Profile(){
        username = "";
        displayname = "";
    }
    // Return username
    string getUsername(){
        return username;
    }
    // Return name in the format: "displayname (@username)"
    string getFullName(){
        return displayname + " (@" + username + ")";
    }
    // Change display name
    void setDisplayName(string dspn){
        displayname = dspn;
    }
    string printUsername(){
        return "\"@" + username + "\"";
    }
};

class Network {
private:
    static const int MAX_USERS = 20; // max number of user profiles
    int numUsers;                    // number of registered users
    Profile profiles[MAX_USERS];     // user profiles array:
                                   // mapping integer ID -> Profile

    // Returns user ID (index in the 'profiles' array) by their username
    // (or -1 if username is not found)
    int findID (string usrn){
        for (int i = 0; i < numUsers; i++) {
        if (profiles[i].getUsername() == usrn) {
            return i;
            }
        }
        return -1;
    }
    bool following[MAX_USERS][MAX_USERS];  // friendship matrix:
    // following[id1][id2] == true when id1 is following id2

    static const int MAX_POSTS = 100;
    int numPosts;
    Post posts[MAX_POSTS];
public:
    // Constructor, makes an empty network (numUsers = 0)
    Network(){
        numUsers = 0;
        numPosts = 0;
        for(int i = 0; i < MAX_USERS; i++){
            for(int j =0; j < MAX_USERS; j++){
                following[i][j] = false;
            }
        }
    }
    // Attempts to sign up a new user with specified username and displayname
    // return true if the operation was successful, otherwise return false
    bool addUser(string usrn, string dspn){
        if (usrn == "") {
        return false;
        }
        if (numUsers < MAX_USERS && findID(usrn) == -1) {
            for (int i = 0; i < usrn.length(); i++) {
                if (!isalnum(usrn[i])) {
                return false;
                }
            }
            Profile p(usrn, dspn);
            profiles[numUsers] = p;
            numUsers++;
            return true;
        }    
        else {
            return false;
        }
    }
    // Make 'usrn1' follow 'usrn2' (if both usernames are in the network).
    // return true if success (if both usernames exist), otherwise return false
    bool follow(string usrn1, string usrn2){
        int id1 = findID(usrn1);
        int id2 = findID(usrn2);

        if (id1 != -1 && id2 != -1) {
            following[id1][id2] = true;
            return true;
        }     
        else {
            return false;
        } 
    }

    // Print Dot file (graphical representation of the network)
    void printDot(){
        cout << "digraph {" << endl;
        for (int i = 0; i < numUsers; i++) {
        cout << profiles[i].printUsername() << endl;
        }
        cout << endl;
        for (int i = 0; i < numUsers; i++) {
            for (int j = 0; j < numUsers; j++) {
                if (following[i][j] == true) {
                    cout << profiles[i].printUsername() << " -> ";
                    cout << profiles[j].printUsername() << endl;
                }
            }
        }
        cout << "}" << endl;
    }

    bool writePost(string usrn, string msg){
        if(findID(usrn) != -1){
            posts[numPosts].username = usrn;
            posts[numPosts].message = msg;
            numPosts++;
            return true;
        }
        return false;
    }

    bool printTimeline(string usrn){
        int ind = -1;
        for(int i = 0; i < numUsers; i++){
            if(profiles[i].getUsername() == usrn){
                ind = i;
                break;
            }
            
        }
        if(ind == -1){
            return false;
        }
        for(int i = numPosts-1; i > -1; i--){
            int postauth = findID(posts[i].username);
            if(posts[i].username == usrn || following[ind][postauth]){
                int profid = findID(posts[i].username);
                cout << profiles[profid].getFullName() << ": " << posts[i].message << endl;
            }
            
        }
        return true;
    }
};



int main() {
  Network nw;
  // add three users
  nw.addUser("mario", "Mario");
  nw.addUser("luigi", "Luigi");
  nw.addUser("yoshi", "Yoshi");
   
  nw.follow("mario", "luigi");
  nw.follow("luigi", "mario");
  nw.follow("luigi", "yoshi");
  nw.follow("yoshi", "mario");

  // write some posts
  nw.writePost("mario", "It's a-me, Mario!");
  nw.writePost("luigi", "Hey hey!");
  nw.writePost("mario", "Hi Luigi!");
  nw.writePost("yoshi", "Test 1");
  nw.writePost("yoshi", "Test 2");
  nw.writePost("luigi", "I just hope this crazy plan of yours works!");
  nw.writePost("mario", "My crazy plans always work!");
  nw.writePost("yoshi", "Test 3");
  nw.writePost("yoshi", "Test 4");
  nw.writePost("yoshi", "Test 5");

  cout << endl;
  cout << "======= Mario's timeline =======" << endl;
  nw.printTimeline("mario");
  cout << endl;

  cout << "======= Yoshi's timeline =======" << endl;
  nw.printTimeline("yoshi");
  cout << endl;
  return 0;
}