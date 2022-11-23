#include "enemigo_1.h"


enemigo_1::enemigo_1(){
    initState();
}

enemigo_1::enemigo_1(bool initPos)
{
    posF = initPos;
    initState();
}

enemigo_1::~enemigo_1()
{
    delete walkE1;
}

void enemigo_1::initState(){
    walkE1=new QTimer;
    configuracion(enemigo1,true,0,10,432,40);
    CAMbloque(3);
    connect(walkE1, SIGNAL (timeout()),this, SLOT(disparo()));
    if(posF)
        setPos(16*scale_sprite,16*(ancho-(3.7))*scale_sprite);
    else
        setPos(16*(largo-4)*scale_sprite,16*(ancho-(3.7))*scale_sprite);
    walkE1->start(100);
}

void enemigo_1::cambioE1()
{
    select_bloc(cambioE1_sprite*48,0,48,43,false,48*1.6,48*1.2,!posF);
    if(cambioE1_sprite < cambioE1_spriteD)
        cambioE1_sprite++;
    else
        cambioE1_sprite=0;
    if(pausa){
        if(posF){
            setPos(x()+10,y());
            if(x() >= ((16 * (largo-4)) * scale_sprite)){
                giro = false;
                posF = !posF;
            }
        } else {
            setPos(x()-10,y());
            if(x() <= (((largo-27)/2) * scale_sprite)){
                giro = true;
                posF = !posF;
            }
        }
    }
}

void enemigo_1::disparo()
{
    if(cambioE1_sprite == cambioE1_spriteD){
        if(pausa)
            configuracion(enemigo1D,true,0,8,432,40);
        else
            configuracion(enemigo1,true,0,8,432,40);
        pausa = !pausa;
        cambioE1_spriteD = 3;
        cambioE1_sprite = 0;
    }
    cambioE1();
}
