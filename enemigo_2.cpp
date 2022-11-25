#include "enemigo_2.h"
#include <time.h>

//Constructores
enemigo_2::enemigo_2(){
    estado_inicial();
}

enemigo_2::enemigo_2(bool posicionInicial)
{
    posF2=posicionInicial;
    estado_inicial();
}

enemigo_2::enemigo_2(bool posicionInicial, int vidas)
{
    posF2=posicionInicial;
    vidastotales=vidas;
    estado_inicial();
}




// Propiedades
int enemigo_2::obtener_total_vidas(){
    return vidastotales;
}
//Destructores
enemigo_2::~enemigo_2()
{
    delete t_caminar;
}


//Metodos
void enemigo_2::estado_inicial(){
    t_caminar = new QTimer;
    t_mostrar_muerte= new QTimer;
    configuracion(enemigo2,true,0,10,432,40);

    CAMbloque(3);

    // Conectar timers con los slots
    connect(t_caminar, SIGNAL (timeout()),this, SLOT(disparoE()));
    connect(t_mostrar_muerte, SIGNAL(timeout()), this, SLOT(muerte()));

    // Establece la dirección inical
    if(posF2)
        setPos(0,16*(ancho-(3.7))*scale_sprite);
    else
        setPos(16*(largo)*scale_sprite,16*(ancho-(3.7))*scale_sprite);

    // Iniciar movimiento
    t_caminar->start(500);

}

void enemigo_2::cambioE()
{
    select_bloc(cambioE2_sprite*48,0,48,43,false,48*1.6,48*1.2,!posF2);
    if(cambioE2_sprite < cambioE2_spriteD)
        cambioE2_sprite++;
    else
        cambioE2_sprite=0;
    if(pausa2){
        if(posF2){
            setPos(x()+10,y());
            if(x() >= ((16 * (largo-4)) * scale_sprite)){
                giro2 = false;
                posF2 = !posF2;
            }
        } else {
            setPos(x()-10,y());
            if(x() <= (((largo-27)/2) * scale_sprite)){
                giro2 = true;
                posF2 = !posF2;
            }
        }
    }
}

void enemigo_2::disparoE()
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
    cambioE();
}
void enemigo_2::recibir_disparo(){
    vidastotales--;
    if(vidastotales == 0){
        delete t_caminar;
        configuracion(enemigo2M,true,0,0,288,48);
        cambioE2_sprite = 0;
        t_mostrar_muerte -> start(200);
    }
}

void enemigo_2::terminar(){
    muerte();
}

void enemigo_2::muerte(){
    remover_observador();
}


void enemigo_2::agregar_observador(Observer *obs){
    observador = obs;
}

void enemigo_2::remover_observador(){
    observador = NULL;
}

void enemigo_2::notificar(){
    if(observador)
        observador->notificacion_enemigo(2, x(), y(), posF2);
}

