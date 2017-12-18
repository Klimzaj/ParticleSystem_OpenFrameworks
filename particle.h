#pragma once 

#include "ofMain.h"
#include <time.h>
#include <iostream>

class Particle{
    int m;
    float r;
    clock_t t;
    float dt;
    float endTime;
    bool isExplode;
    ofVec3f pos, posR;
    ofVec3f F,V;
    int tMinR, tMaxR;


public:
    Particle();
    Particle(int _m, int _r, ofVec3f _pos,int _tMin, int _tMax);
    
    float getX();
    float getY();
    float getZ();

    ofVec3f getPos();
    ofVec3f getV();
    void setPos(ofVec3f _pos);
    void setPosX(int _x);

    void addV(ofVec3f _v);

    int getRadius();

    void moveByPos(ofVec3f _pos);
    void moveByForce();

    clock_t getTime();
    float getEndTime();
    void restart(double _x, double _y, double _z);

    void setForce(double _x, double _y, double _z, double _dt);
    void addForce(double _x, double _y, double _z);
    void setV(double _x, double _y, double _z);
    double countPotentialEnergy();
    void explode();
    bool getExplode();
    void collision(Particle _b);
    void setColor(int _i);

    ofSpherePrimitive sphere;
};;