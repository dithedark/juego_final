#include "enemigo_2.h"

enemigo_2::enemigo_2()
{
    walkE2=new QTimer;
    configuracion(enemigo2,true,0,10,432,40);
    CAMbloque(3);
    connect(walkE2, SIGNAL (timeout()),this, SLOT(disparoE2()));
    setPos(16*(largo-4)*scale_sprite,16*(ancho-(3.7))*scale_sprite);
    walkE2->start(200);
}

enemigo_2::~enemigo_2()
{
    delete walkE2;
}

void enemigo_2::cambioE2()
{
    select_bloc(cambioE2_sprite*48,0,48,43,false,48*1.7,48*1.2,giro2);
    if(cambioE2_sprite<cambioE2_spriteD)
    {
        cambioE2_sprite++;
    }
    else
    {
        cambioE2_sprite=0;
    }
    if(pausa2==1)
    {
        if (posF2==false)
            {
            setPos(x()-10,y());
            if (x()==((largo-27)/2)*scale_sprite)
                {
                posF2=true;
                giro2=false;
                }
            }
        else if (posF2==true)
            {
            setPos(x()+10,y());
            if (x()==16*(largo-4)*scale_sprite)
                {
                posF2=false;
                giro2=true;
                }
            }
    }
}

void enemigo_2::disparoE2()
{
    if(cambioE2_sprite==cambioE2_spriteD and pausa2==0)
    {
        configuracion(enemigo2,true,0,8,432,40);
        pausa2=1;
        cambioE2_spriteD=3;
        cambioE2_sprite=0;

    }
    else if (cambioE2_sprite==cambioE2_spriteD and pausa2==1)
    {
        configuracion(enemigo2D,true,0,8,432,40);
        pausa2=2;
        cambioE2_spriteD=3;
        cambioE2_sprite=0;
        notificar();
    }
    else if(cambioE2_sprite==cambioE2_spriteD and pausa2==2)
    {
        configuracion(enemigo_quieto,true,0,8,432,40);
        pausa2=0;
        cambioE2_spriteD=3;
        cambioE2_sprite=0;

    }
    cambioE2();
}

void enemigo_2::agregar_observador(Observer *obs){
    observador = obs;
}

void enemigo_2::remover_observador(){
    observador = NULL;
}

void enemigo_2::notificar(){
    observador->notificacion_enemigo(2, x(), y(), giro2);
}
