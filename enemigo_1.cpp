#include "enemigo_1.h"

enemigo_1::enemigo_1()
{
    walkE1= new QTimer;
    animacionE1=new QTimer;
    configuracion(enemigo1,true,0,8,432,40);
    CAMbloque(3);
    connect(animacionE1, SIGNAL (timeout()),this, SLOT(cambioE1()));
    connect(walkE1, SIGNAL (timeout()),this, SLOT(correr()));


    setPos(16*(largo-4)*scale_sprite,16*(ancho-(3.7))*scale_sprite);
    animacionE1->start(200);
    walkE1->start(200);
}

enemigo_1::~enemigo_1()
{
    delete animacionE1;
}

void enemigo_1::movimiento()
{

}

void enemigo_1::correr()
{
    if(giro)
    {
      configuracion(enemigo1walk);
    }
    else
    {
      configuracion(enemigo1walk);
    }
}

void enemigo_1::cambioE1()
{
    select_bloc(cambioE1_sprit*48,0,48,43,false,48*1.3,48*1.2,giro);
    if(cambioE1_sprit<5)
    {
        cambioE1_sprit++;
    }
    else
    {
        cambioE1_sprit=0;
    }

    setPos(x()-10,y());


}

