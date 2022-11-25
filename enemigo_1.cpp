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

//Destructores
enemigo_1::~enemigo_1()
{
    delete t_caminar;
}


// Propiedades
int enemigo_1::obtener_total_vidas(){
    return totalVidas;
}

// Metodos
void enemigo_1::estado_inicial(){
    t_caminar = new QTimer;
    t_mostrar_muerte = new QTimer;
    configuracion(enemigo1,true,0,10,432,40);

    CAMbloque(3);

    // Conectar timers con los slots
    connect(t_caminar, SIGNAL (timeout()),this, SLOT(disparo()));
    connect(t_mostrar_muerte, SIGNAL(timeout()), this, SLOT(muerte()));

    // Establece la dirección inical
    if(posF)
        setPos(16*scale_sprite,16*(ancho-(3.7))*scale_sprite);
    else
        setPos(16*(largo-4)*scale_sprite,16*(ancho-(3.7))*scale_sprite);

    // Iniciar movimiento
    t_caminar->start(200);
}

void enemigo_1::muerte(){
    remover_observador();
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
        if(pausa){
            configuracion(enemigo1D,true,0,8,432,40);
            notificar();
        }
        else
            configuracion(enemigo1,true,0,8,432,40);
        pausa = !pausa;
        cambioE1_spriteD = 3;
        cambioE1_sprite = 0;
    }
    cambioE1();
}

void enemigo_1::recibir_disparo(){
    totalVidas--;
    if(totalVidas == 0){
        muerte();
    }
}

void enemigo_1::terminar(){
    muerte();
}


void enemigo_1::agregar_observador(Observer *obs){
    observador = obs;
}

void enemigo_1::remover_observador(){
    observador = NULL;
}

void enemigo_1::notificar(){
    if(observador)
        observador->notificacion_enemigo(1, x(), y(), posF);
}
