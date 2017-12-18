#include <particles.h>

Particles::Particles() {}

Particles::Particles(std::vector<Particle>& _AllMess)
{
    AllMess = _AllMess;
}
Particles::Particles(int _N)
{
    double _x = ofRandom(-500,500);
    double _y = ofRandom(-350,-300);
    double _z = ofRandom(0,0);
    highEnergy = ofRandom(1500,8000);
    fireForce = ofVec3f(ofRandom(5,5),40,ofRandom(-5,5));

    for(int i = 0; i < _N;i++)
    {
        AllMess.push_back(Particle(2,10,ofVec3f(_x,_y,_z),70,70));
    }
}

void Particles::draw()
{
    for (auto& p: AllMess)
    {
        p.sphere.draw();
    }
}
void Particles::setPosition()
{
    for(auto& p: AllMess)
    {
        p.sphere.setPosition(p.getX(),p.getY(),p.getZ());
    }
}

void Particles::addToMess(std::vector<Particle>& _obj1)
{
    AllMess = _obj1;
}

std::vector<Particle> Particles::getMess()
{
    return AllMess;
}

void Particles::moveAllByPos(ofVec3f _pos)
{
    for(auto& p: AllMess)
    {
        p.moveByPos(_pos);
    }
}
void Particles::checkTime()
{
    clock_t _t = clock();
    for(auto& p: AllMess)
    {   
        if((float)(_t-p.getTime())/1000000 >= p.getEndTime())
        {
            p.restart(0,0,0);  
        }
    }
}
void Particles::setAllForces(double Fx = 0, double Fy = 0, double Fz = 0, double dt = 0)
{
    for(auto& p: AllMess)
    {
        p.setForce(Fx,Fy,Fz,dt);
    }
}
void Particles::addAllForces(double Fx = 0, double Fy = 0, double Fz = 0)
{
    for(auto& p: AllMess)
    {
        p.addForce(Fx,Fy,Fz);
    }
}
void Particles::moveAllByForce()
{
    for(auto& p: AllMess)
    {
        p.moveByForce();
    }
}
void Particles::addAllXForce(double _x)
{
     for(auto& p: AllMess)
    {
        p.addForce(_x,0,0);
    }
}
void Particles::shotAllMess()  //to może byc w setup lub na nacisniecie klawisza
{
    for(auto& p: AllMess)
    {
        if(!p.getExplode())
        {
            p.setForce(fireForce.x,fireForce.y,fireForce.z,0.02);
        }
    }
}
void Particles::explode()
{
    for(auto& p: AllMess)
    {
        if(!p.getExplode())
        {
            if(p.countPotentialEnergy() >= highEnergy)
            {
                p.setForce(ofRandom(-5,5),ofRandom(-5,5),ofRandom(-5,5),0.03);
                p.setV(0,0,0);
                p.explode();
            }
        }
    }
}
void Particles::moveByCollision(Particle _b)
{
    for(auto& a: AllMess)
    {
        Particle b = _b; 
        float dR =  a.getRadius()+b.getRadius();
        if(a.getPos().distance(b.getPos()) <= dR)
        {                     
            float _x = (a.getX()*b.getRadius()+b.getX()*a.getRadius())/dR;
            float _y = (a.getY()*b.getRadius()+b.getY()*a.getRadius())/dR;
            float _z = (a.getZ()*b.getRadius()+b.getZ()*a.getRadius())/dR;
            ofVec3f collisionPoint = ofVec3f(_x,_y,_z);

            ofVec3f normalVector = b.getPos() - collisionPoint;
            normalVector = normalVector/(b.getPos().distance(collisionPoint));
            
            ofVec3f _VProsto = normalVector * a.getV();
            float VProsto = _VProsto.x + _VProsto.y + _VProsto.z;

            ofVec3f _Vp = normalVector * VProsto;
            ofVec3f _Vr = a.getV() - _Vp;

            ofVec3f _V = _Vr -(_Vp*2);

            a.setForce(0,0,0,0.1);
            a.addV(_V);
            // a.setColor(3);
        }
    }
}
void Particles::moveAllByCollision(Particle _a, Particle _b)
{
    float dR =  _a.getRadius()+_b.getRadius();
    if(_a.getPos().distance(_b.getPos()) <= dR)
    {                     
        float _x = (_a.getX()*_b.getRadius()+_b.getX()*_a.getRadius())/dR;
        float _y = (_a.getY()*_b.getRadius()+_b.getY()*_a.getRadius())/dR;
        float _z = (_a.getZ()*_b.getRadius()+_b.getZ()*_a.getRadius())/dR;
        ofVec3f collisionPoint = ofVec3f(_x,_y,_z);

        ofVec3f normalVector = _b.getPos() - collisionPoint;
        normalVector = normalVector/(_b.getPos().distance(collisionPoint));
        
        ofVec3f _VProsto = normalVector * _a.getV();
        float VProsto = _VProsto.x + _VProsto.y + _VProsto.z;

        ofVec3f _Vp = normalVector * VProsto;
        ofVec3f _Vr = _a.getV() - _Vp;
        ofVec3f _V = _Vr -(_Vp*2);

        _a.setForce(0,0,0,0.01);
        _a.addV(_V/3);
        _a.setColor(3);
    }
}
void Particles::setColor(int _i)
{
    for(auto& p: AllMess)
    {
        p.setColor(_i);
    }
}