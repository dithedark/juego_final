#include "polvora.h"


//Constructores
polvora::polvora()
{

}

//Destructores
polvora::~polvora()
{
    delete matematicas;
}


//Metodos
void polvora::Iparametros(QString nombre ,float px,float py,float ax,float ay,float vx,float vy ,float mass,bool vuelta,float dimension)
{
    configuracion(nombre);
    select_bloc(0,0,6,6,false,dimension,dimension,vuelta);
    matematicas=new operaciones(px,py,vx,vy,mass);
    matematicas->setAX(ax);
    matematicas->setAY(ay);
    setPos(px,py);
}

void polvora::fisicas(float px,float py, float masa)
{

    if(masa!=0 and matematicas->getmasa() !=0)
    {
        matematicas->acelerar(px,py,masa);
    }
    matematicas->actualizarX(0.06667);
    matematicas->actualizarY(0.06667);

    setPos(matematicas->getPX(),matematicas->getPY());

}
