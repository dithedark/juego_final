#include "operaciones.h"

#include <math.h>
#include <cmath>


operaciones::operaciones(float PX_, float PY_, float VX_, float VY_, float mass, float R_)
{
    PX = PX_;
    PY = PY_;
    VX = VX_;
    VY = VY_;
    masa = mass;
    ax = 0;
    ay = 0;
    G = 1;
    R = R_;
}

float operaciones::getPX() const
{
    return PY;
}

float operaciones::getPY() const
{
    return PY;
}

float operaciones::getmasa() const
{
    return masa;
}

float operaciones::getR() const
{
    return R;
}

/*
void operaciones::acelerar(float px2_, float py2_, float mass2)
{
    radio = pow((pow((px2_-PX),2)+pow((py2_-PY),2)),0.5);
    ax = G*mass2*(px2_-PX)/pow(radio,3);
    ay = G*mass2*(py2_-PY)/pow(radio,3);

}
*/

void operaciones::actualizar(float dt)
{
    VX = VX + (ax*dt)/2;
    VY = VY + (ay*dt)/2;
    PX = PX + (VX*dt);
    PY = PY + (VY*dt);
}

void operaciones::setPY(float py)
{
    PY=py;
}

void operaciones::setAY(float _ay)
{
    ay=_ay;
}

void operaciones::setVY(float _vy)
{
    VY=_vy;
}

