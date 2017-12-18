#include <fireworks.h>

Fireworks::Fireworks() {}

Fireworks::Fireworks(int _fire, int _N)
{
    for (int i = 0; i < _fire; i++)
    {
        Particles a = Particles(_N);
        std::vector<Particle> _a = a.getMess();
        // std::cout<<_a.size()<<std::endl;
        AllPart.insert(AllPart.end(),_a.begin(),_a.end());
        AllMess.push_back(a);
        // AllMess.push_back(Particles(_N));

    }
}

void Fireworks::draw()
{
    for(auto& p: AllMess)
    {   
        p.draw();
    }
}
void Fireworks::setPosition()
{
    for(auto& p: AllMess)
    {
        p.setPosition();
    }
}
void Fireworks::moveAllByForce()
{
    for(auto& p: AllMess)
    {
        p.moveAllByForce();
    }
}
void Fireworks::explode()
{
    for(auto& p: AllMess)
    {
        p.explode();
    }
}
void Fireworks::checkTime()
{
    for(auto& p: AllMess)
    {
        p.checkTime();
    }
}
void Fireworks::shotAllMess()
{
    for(auto& p: AllMess)
    {
        p.shotAllMess();
    }
}
std::vector<Particle> Fireworks::getMess()
{
    return AllPart;
}
void Fireworks::moveAllByCollision()
{
    // napewno nie zadziala do poprawy!
    for(int i = 0; i <= AllPart.size();i++)
    {
        for(int j = 0; j <= AllPart.size();j++)
        {
            if(i != j)
            {
                Particle _a = AllPart[i];
                Particle _b = AllPart[j];

                float dR =  _a.getRadius()+_b.getRadius();
                if(_a.getPos().distance(_b.getPos()) <= dR)
                {                     
                    float _x1 = (_a.getX()*_b.getRadius()+_b.getX()*_a.getRadius())/dR;
                    float _y1 = (_a.getY()*_b.getRadius()+_b.getY()*_a.getRadius())/dR;
                    float _z1 = (_a.getZ()*_b.getRadius()+_b.getZ()*_a.getRadius())/dR;
                    ofVec3f collisionPoint1 = ofVec3f(_x1,_y1,_z1);

                    float _x2 = (_b.getX()*_a.getRadius()+_a.getX()*_b.getRadius())/dR;
                    float _y2 = (_b.getY()*_a.getRadius()+_a.getY()*_b.getRadius())/dR;
                    float _z2 = (_b.getZ()*_a.getRadius()+_a.getZ()*_b.getRadius())/dR;
                    ofVec3f collisionPoint2 = ofVec3f(_x2,_y2,_z2);

                    ofVec3f normalVector1 = _b.getPos() - collisionPoint1;
                    normalVector1 = normalVector1/(_b.getPos().distance(collisionPoint1));

                    ofVec3f normalVector2 = _a.getPos() - collisionPoint2;
                    normalVector2 = normalVector2/(_a.getPos().distance(collisionPoint2));
                    
                    ofVec3f _VProsto1 = normalVector1 * _a.getV();
                    float VProsto1 = _VProsto1.x + _VProsto1.y + _VProsto1.z;

                    ofVec3f _VProsto2 = normalVector2 * _b.getV();
                    float VProsto2 = _VProsto2.x + _VProsto2.y + _VProsto2.z;

                    ofVec3f _Vp1 = normalVector1 * VProsto1;
                    ofVec3f _Vr1 = _a.getV() - _Vp1;
                    ofVec3f _V1 = _Vr1 -(_Vp1*2);

                    ofVec3f _Vp2 = normalVector2 * VProsto2;
                    ofVec3f _Vr2 = _b.getV() - _Vp2;
                    ofVec3f _V2 = _Vr2 -(_Vp2*2);

                    _a.setForce(0,0,0,0.1);
                    _a.addV(_V1);

                    _b.setForce(0,0,0,0.1);
                    _b.addV(_V2);
                }
            }
        }
    }   
}
void Fireworks::moveByCollision(Particle _b)
{
    for(auto& p: AllMess)
    {
        p.moveByCollision(_b);
    }
}
void Fireworks::setColor(int _i)
{
    for(auto& p: AllMess)
    {
        p.setColor(_i);
    }
}