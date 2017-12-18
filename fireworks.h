#pragma once

#include <ofMain.h>
#include <vector>
#include <iostream>
#include "particle.h"
#include "particles.h"
#include <time.h>

class Fireworks{
    std::vector<Particles> AllMess;
    std::vector<Particle> AllPart;

public:
    Fireworks();
    Fireworks(int _fire, int _N);

    void draw();
    void setPosition();

    void moveAllByForce();
    void explode();
    void checkTime();
    void shotAllMess();
    std::vector<Particle> getMess();
    void moveAllByCollision();
    void moveByCollision(Particle _b);
    void setColor(int _i);
};