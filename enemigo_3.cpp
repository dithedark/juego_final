#include "enemigo_3.h"

//Constructores
enemigo_3::enemigo_3()
{
    estado_inicial();

}

enemigo_3::enemigo_3(bool posicionInicial)
{
    posF3=posicionInicial;
    estado_inicial();
}

enemigo_3::enemigo_3(bool posicionInicial, int vidas)
{
    posF3=posicionInicial;
    vidastotales=vidas;
    estado_inicial();
}

//Destructores
enemigo_3::~enemigo_3()
{
    delete t_caminar;
    delete t_mostrar_muerte;
}

//Metodos
void enemigo_3::muerte(){
    remover_observador();
}


int enemigo_3::obtener_total_vidas()
{
    return vidastotales;
}

void enemigo_3::estado_inicial()
{
    t_caminar = new QTimer;
    t_mostrar_muerte= new QTimer;
    configuracion(enemigo3,true,0,10,432,40);

    CAMbloque(3);

    // Conectar timers con los slots
    connect(t_caminar, SIGNAL (timeout()),this, SLOT(disparoE3()));
    connect(t_mostrar_muerte, SIGNAL(timeout()), this, SLOT(muerte()));

    // Establece la dirección inical
    if(posF3)
        setPos(0,16*(ancho*2/11)*scale_sprite);
    else
        setPos(16*(largo)*scale_sprite,16*(ancho*2/11)*scale_sprite);

    // Iniciar movimiento
    t_caminar->start(300);
}

void enemigo_3::cambioE3()
{
    select_bloc(cambioE3_sprite*48,0,35,43,false,30*scale_sprite,30*scale_sprite,giro3);
    if(cambioE3_sprite<cambioE3_spriteD)
    {
        cambioE3_sprite++;
    }
    else
    {
        cambioE3_sprite=0;
    }
    if(pausa3==1)
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
        configuracion(enemigo3,true,0,8,432,40);
        pausa3=1;
        cambioE3_spriteD=3;
        cambioE3_sprite=0;

    }
    else if (cambioE3_sprite==cambioE3_spriteD and pausa3==1)
    {
        configuracion(enemigo3D,true,0,8,432,40);
        pausa3=2;
        cambioE3_spriteD=3;
        cambioE3_sprite=0;
        notificar();
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



void enemigo_3::recibir_disparo(){
    vidastotales--;
    if(vidastotales == 0){
        delete t_caminar;
        configuracion(enemigo_muerte,true,0,0,288,48);
        cambioE3_sprite = 0;
        t_mostrar_muerte -> start(500);
    }
}

void enemigo_3::terminar(){
    muerte();
}

void enemigo_3::agregar_observador(Observer *obs){
    observador = obs;
}

void enemigo_3::remover_observador(){
    observador = NULL;
}

void enemigo_3::notificar(){
    if(observador)
        observador->notificacion_enemigo(3, x(), y(), posF3);
}
