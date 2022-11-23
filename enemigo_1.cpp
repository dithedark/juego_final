#include "enemigo_1.h"

//mi rama

enemigo_1::enemigo_1()
{

    walkE1=new QTimer;
    configuracion(enemigo1,true,0,10,432,40);
    CAMbloque(3);
    connect(walkE1, SIGNAL (timeout()),this, SLOT(disparo()));
    setPos(16*(largo-4)*scale_sprite,16*(ancho-(3.7))*scale_sprite);
    walkE1->start(100);
}




enemigo_1::~enemigo_1()
{
    delete walkE1;
}



void enemigo_1::cambioE1()
{
    select_bloc(cambioE1_sprite*48,0,48,43,false,48*1.6,48*1.2,giro);
    if(cambioE1_sprite<cambioE1_spriteD)
    {
        cambioE1_sprite++;
    }
    else
    {
        cambioE1_sprite=0;
    }



    if(pausa)
    {
        if (posF==false)
            {
            setPos(x()-10,y());
            if (x()==((largo-27)/2)*scale_sprite)
                {
                posF=true;
                giro=false;
                }
            }
        else if (posF==true)
            {
            setPos(x()+10,y());
            if (x()==16*(largo-4)*scale_sprite)
                {
                posF=false;
                giro=true;
                }
            }
    }
}



void enemigo_1::disparo()
{

    if(cambioE1_sprite==cambioE1_spriteD and pausa==true)
    {
        configuracion(enemigo1D,true,0,8,432,40);
        pausa=false;
        cambioE1_spriteD=3;
        cambioE1_sprite=0;

    }
    else if (cambioE1_sprite==cambioE1_spriteD and pausa==false)
    {
        configuracion(enemigo1,true,0,8,432,40);
        pausa=true;
        cambioE1_spriteD=3;
        cambioE1_sprite=0;
    }

    cambioE1();
}
