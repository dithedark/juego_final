#include "enemigo_1.h"
#include <time.h>
#include "QThread";

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
    // Remover
    t_muerte = new QTimer;
    t_mostrar_muerte = new QTimer;
    configuracion(enemigo1,true,0,10,432,40);
    CAMbloque(3);
    connect(walkE1, SIGNAL (timeout()),this, SLOT(disparo()));
    // Remover cuando se implemente la muerte
    connect(t_muerte, SIGNAL(timeout()), this, SLOT(muerte()));
    connect(t_mostrar_muerte, SIGNAL(timeout()), this, SLOT(mostrar_muerte()));
    if(posF)
        setPos(16*scale_sprite,16*(ancho-(3.7))*scale_sprite);
    else
        setPos(16*(largo-4)*scale_sprite,16*(ancho-(3.7))*scale_sprite);
    walkE1->start(100);
    // Tiempo de vida
    t_muerte->start(5000);
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

void enemigo_1::muerte(){
    delete walkE1;
    delete t_muerte;
    configuracion(enemigo1M,true,0,0,288,48);
    t_mostrar_muerte -> start(100);
}

void enemigo_1::mostrar_muerte(){
    for(int i = 0; i < 6; i++){
        select_bloc(i*48,0,48,48,false,48*1.6,48*1.2,!posF);
        if(i == 6)
            delete t_mostrar_muerte;
    }
}
