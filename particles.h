#pragma once

#include <ofMain.h>
#include <vector>
#include <math.h>
#include <iostream>
#include "particle.h"
#include <time.h>

class Particles{
    vector<Particle> AllMess;
    int highEnergy;
    ofVec3f fireForce;

public:
    Particles();
    Particles(std::vector<Particle>& _AllMess);
    Particles(int _N);

    void draw();
    void setPosition();

    void addToMess(std::vector<Particle>& _obj1);
    std::vector<Particle> getMess();
    void moveAllByPos(ofVec3f _pos);
    void moveAllByForce();
    void setAllForces(double Fx, double Fy, double Fz,double dt);
    void addAllForces(double Fx, double Fy, double Fz);
    void addAllXForce(double _x);
    void shotAllMess();
    void explode();
    void checkTime();
    void moveByCollision(Particle _b);
    void moveAllByCollision(Particle _a,Particle _b);
    void setColor(int _i);
    
};
