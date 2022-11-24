#include "enemigo_2.h"
#include <time.h>

//Constructores
enemigo_2::enemigo_2()
{
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



enemigo_2::~enemigo_2()
{
    delete walkE2;
}


void enemigo_2::estado_inicial()
{
    walkE2=new QTimer;
    secuencia_muerte= new QTimer;
    t_caminar2 = new QTimer;
    t_mostrar_muerte2 = new QTimer;
    configuracion(enemigo2,true,0,10,432,40);
    CAMbloque(3);
    connect(t_caminar2, SIGNAL (timeout()),this, SLOT(disparoE2()));
    setPos(16*(largo-4)*scale_sprite,16*(ancho-(3.7))*scale_sprite);
    t_caminar2->start(200);
}

// Propiedades
int enemigo_2::obtener_total_vidas2(){
    return totalVidas2;
}
//Destructores
enemigo_2::~enemigo_2()
{
    delete t_caminar2;
}


//Metodos
void enemigo_2::estado_inicial2(){
    t_caminar2 = new QTimer;
    t_mostrar_muerte2 = new QTimer;
    configuracion(enemigo2,true,0,10,432,40);

    CAMbloque(3);

    // Conectar timers con los slots
    connect(t_caminar2, SIGNAL (timeout()),this, SLOT(disparoE2()));
    connect(t_mostrar_muerte2, SIGNAL(timeout()), this, SLOT(muerte2()));

    // Establece la dirección inical
    if(posF2)
        setPos(16*scale_sprite,16*(ancho-(3.7))*scale_sprite);
    else
        setPos(16*(largo-4)*scale_sprite,16*(ancho-(3.7))*scale_sprite);

    // Iniciar movimiento
    t_caminar2->start(100);

}

void enemigo_2::cambioE2()
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
void enemigo_2::recibir_disparo2(){
    totalVidas2--;
    if(totalVidas2 == 0){
        delete t_caminar2;
        configuracion(enemigo2M,true,0,0,288,48);
        cambioE2_sprite = 0;
        t_mostrar_muerte2 -> start(100);
    }
}

void enemigo_2::muerte2(){
    select_bloc(cambioE2_sprite*48,0,48,48,false,48*1.6,48*1.2,posF2);
    cambioE2_sprite++;
    if(cambioE2_sprite == 6){
        delete t_mostrar_muerte2;
        remover_observador();
    }
}


void enemigo_2::agregar_observador(Observer *obs){
    observador = obs;
}

void enemigo_2::remover_observador(){
    observador = NULL;
}

void enemigo_2::notificar(){
    observador->notificacion_enemigo(2, x(), y(), posF2);
}

