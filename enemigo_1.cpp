#include "enemigo_1.h"

enemigo_1::enemigo_1()
{
    animacionE1=new QTimer;
    configuracion(enemigo1,true,0,8,432,40);
    CAMbloque(3);
    connect(animacionE1, SIGNAL (timeout()),this, SLOT(cambioE1()));

    setPos(16*(largo-4)*scale_sprite,16*(ancho-(3.7))*scale_sprite);
    animacionE1->start(100);
}

enemigo_1::~enemigo_1()
{
    delete animacionE1;
}

void enemigo_1::cambioE1()
{
    select_bloc(cambioE1_sprit*48,0,48,43,false,48*1.3,48*1.2);
    if(cambioE1_sprit<8)
    {
        cambioE1_sprit++;
    }
    else
    {
        cambioE1_sprit=5;
    }


}
