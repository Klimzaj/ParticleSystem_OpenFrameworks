#include <particle.h>

Particle::Particle() {}

Particle::Particle(int _m = 1, int _r = 0, ofVec3f _pos = ofVec3f(0,0,0), int _tMin = 0, int _tMax = 0) {
    m = _m;
    r = _r;
    pos = _pos;
    t = clock();
    endTime = ofRandom(_tMin,_tMax);

    tMinR = _tMin;
    tMaxR = _tMax;
    posR = _pos;
    isExplode = false;
    sphere.setRadius(r);
    
}

ofVec3f Particle::getPos()
{
    return pos;
}

void Particle::setPos(ofVec3f _pos = ofVec3f(0,0,0))
{
    pos = _pos;
}

void Particle::setPosX(int _x = 0)
{
    pos = ofVec3f(_x,pos.y,pos.z);
}

int Particle::getRadius()
{
    return r;
}

float Particle::getX()
{
    return pos.x;
}

float Particle::getY()
{
    return pos.y;
}
float Particle::getZ()
{
    return pos.z;
}
void Particle::moveByPos(ofVec3f _pos)
{
    pos += _pos;
}

clock_t Particle::getTime()
{
    return t;
}
void Particle::restart(double _x, double _y, double _z)
{
    pos = posR;
    F = ofVec3f(_x,_y,_z);  //F.y jest w tym przypadkiem siłą ciążenia czy jakąs tam siłą
    V = ofVec3f(0,0,0);
    endTime = ofRandom(tMinR,tMaxR);
    isExplode = false;
    t = clock();

}
void Particle::addForce(double _x, double _y, double _z)
{
    F = F + ofVec3f(_x,_y,_z);
}
void Particle::setForce(double _x, double _y, double _z, double _dt)
{
    F =  ofVec3f(_x,_y,_z);
    dt = _dt;
}
void Particle::moveByForce()
{
    pos = pos + ofVec3f(V.x*dt,V.y*dt,V.z*dt);
    V = V + ofVec3f(F.x/m*dt,F.y/m*dt,F.z/m*dt);
}
float Particle::getEndTime()
{
    return endTime;
}
double Particle::countPotentialEnergy()
{
    return (double)(m*10*pos.distance(posR)*0.6); //m*g*h
}
void Particle::explode()
{
    isExplode = true; 
}
bool Particle::getExplode()
{
    return isExplode;
}
void Particle::setV(double _x,double _y,double _z)
{
    V = ofVec3f(_x,_y,_z);
}
ofVec3f Particle::getV()
{
    return V;
}
void Particle::addV(ofVec3f _v)
{
    V = V + _v;
}
void Particle::collision(Particle _b)
{
    float dR =  r +_b.getRadius();
    if(pos.distance(_b.getPos()) <= dR)
    {                     
        float _x = (pos.x*_b.getRadius()+_b.getX()*r)/dR;
        float _y = (pos.y*_b.getRadius()+_b.getY()*r)/dR;
        float _z = (pos.z*_b.getRadius()+_b.getZ()*r)/dR;
        ofVec3f collisionPoint = ofVec3f(_x,_y,_z);

        ofVec3f normalVector = _b.getPos() - collisionPoint;
        normalVector = normalVector/(_b.getPos().distance(collisionPoint));
        
        ofVec3f _VProsto = normalVector * V;
        float VProsto = _VProsto.x + _VProsto.y + _VProsto.z;

        ofVec3f _Vp = normalVector * VProsto;
        ofVec3f _Vr = V - _Vp;
        ofVec3f _V = _Vr -(_Vp*2);

        F = ofVec3f(0,0,0);
        V = _V;                    
    }
}
void Particle::setColor(int _i)
{
    ofColor k;
    if(_i == 1)
    {
        k = ofColor(230,50,70);
    }
    else if(_i == 2)
    {
        ofColor(255,255,0);
    }
    else if(_i == 3)
    {
        ofColor(0,255,255);
    }
    else
    {
        ofColor(235,235,235);
    }
    ofSetColor(k,40);
}