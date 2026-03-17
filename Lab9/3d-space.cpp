/*
Author: Shahnewaz Azad
Course: CSCI-135
Assignment: Lab9
 
Use of pointers and structs to calculate length in a 3D space and calculate position after a certain time

*/


#include <iostream>
#include <cmath>

class Coord3D {
public:
    double x;
    double y;
    double z;
};

Coord3D* createCoord3D(double x, double y, double z){
    Coord3D *nnew = new Coord3D;
    nnew->x = x;
    nnew->y = y;
    nnew->z = z;
    return nnew;
}

void deleteCoord3D(Coord3D *p){
    delete p;
}

double length(Coord3D *p){
    return sqrt((p->x * p->x) + (p->y * p->y) + (p->z * p->z));
}

Coord3D * fartherFromOrigin(Coord3D *p1, Coord3D *p2){
    if(length(p1) > length(p2)){
        return p1;
    }
    else{
        return p2;
    }
}

void move(Coord3D *ppos, Coord3D *pvel, double dt){
    ppos->x += pvel->x * dt;
    ppos->y += pvel->y * dt;
    ppos->z += pvel->z * dt;

}



int main() {
    double x, y, z;
    std::cout << "Enter position: ";
    std::cin >> x >> y >> z;
    Coord3D *ppos = createCoord3D(x,y,z);
    
    std::cout << "Enter velocity: ";
    std::cin >> x >> y >> z;
    Coord3D *pvel = createCoord3D(x,y,z);

    move(ppos, pvel, 10.0);

    std::cout << "Coordinates after 10 seconds: " 
         << (*ppos).x << " " << (*ppos).y << " " << (*ppos).z << std::endl;

    deleteCoord3D(ppos); // release memory
    deleteCoord3D(pvel);
}
