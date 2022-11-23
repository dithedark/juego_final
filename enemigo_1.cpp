#include "enemigo_1.h"
#include <time.h>

// Constructores
enemigo_1::enemigo_1(){
    estado_inicial();
}

enemigo_1::enemigo_1(bool posicionInicial)
{
    posF = posicionInicial;
    estado_inicial();
}

enemigo_1::enemigo_1(bool posicionInicial, int vidas){
    posF = posicionInicial;
    totalVidas = vidas;
    estado_inicial();
}

enemigo_1::~enemigo_1()
{
    delete walkE1;
}

// Propiedades
int enemigo_1::obtener_total_vidas(){
    return totalVidas;
}
// Metodos

void enemigo_1::estado_inicial(){
    walkE1=new QTimer;
    t_mostrar_muerte = new QTimer;
    configuracion(enemigo1,true,0,10,432,40);
    CAMbloque(3);
    connect(walkE1, SIGNAL (timeout()),this, SLOT(disparo()));
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
    totalVidas--;
    if(totalVidas == 0){
        delete walkE1;
        configuracion(enemigo1M,true,0,0,288,48);
        cambioE1_sprite = 0;
        t_mostrar_muerte -> start(100);
    }
}

void enemigo_1::mostrar_muerte(){
    select_bloc(cambioE1_sprite*48,0,48,48,false,48*1.6,48*1.2,posF);
    cambioE1_sprite++;
    if(cambioE1_sprite == 6)
        delete t_mostrar_muerte;
}
