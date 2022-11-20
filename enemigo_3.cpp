#include "enemigo_3.h"

enemigo_3::enemigo_3()
{
    flyE3=new QTimer;
    configuracion(enemigo3,true,0,10,432,40);
    CAMbloque(3);
    connect(flyE3, SIGNAL (timeout()),this, SLOT(disparoE3()));

    setPos(16*(largo-4)*scale_sprite,16*(ancho*1/12)*scale_sprite);

}

enemigo_3::~enemigo_3()
{
    delete flyE3;
}

int enemigo_3::fase()
{
    cout<<pausa3<<endl;
    return pausa3;

}

void enemigo_3::cambioE3()
{
    select_bloc(cambioE3_sprite*48,0,48,43,false,40.8*scale_sprite,28.8*scale_sprite,giro3);
    if(cambioE3_sprite<cambioE3_spriteD)
    {
        cambioE3_sprite++;
    }
    else
    {
        cambioE3_sprite=0;
    }
    if(pausa3)
    {
        if (posF3==false)
            {
            setPos(x()-10,y());
            if (x()==((largo-27)/2)*scale_sprite)
                {
                posF3=true;
                giro3=false;
                }
            }
        else if (posF3==true)
            {
            setPos(x()+10,y());
            if (x()==16*(largo-4)*scale_sprite)
                {
                posF3=false;
                giro3=true;
                }
            }
    }
}
void enemigo_3::disparoE3()
{
    if(cambioE3_sprite==cambioE3_spriteD and pausa3==0)
    {
        configuracion(enemigo3D,true,0,8,432,40);
        pausa3=1;
        cambioE3_spriteD=3;
        cambioE3_sprite=0;

    }
    else if (cambioE3_sprite==cambioE3_spriteD and pausa3==1)
    {
        configuracion(enemigo3,true,0,8,432,40);
        pausa3=2;
        cambioE3_spriteD=3;
        cambioE3_sprite=0;
    }
    else if(cambioE3_sprite==cambioE3_spriteD and pausa3==2)
    {
        configuracion(enemigo_quieto,true,0,8,432,40);
        pausa3=0;
        cambioE3_spriteD=3;
        cambioE3_sprite=0;

    }

    cambioE3();
}

