#include "jugador.h"

jugador::jugador()
{
    animacion=new QTimer;


    configuracion(punk,true,0,14,192,34);
    CAMbloque(2);
    connect(animacion, SIGNAL (timeout()),this, SLOT(cambio()));



    setPos(16*scale_sprite,16*(ancho-(3.7))*scale_sprite);
    calculo= new operaciones(x(),y(),0,0,0,0);
    //calculo->Maceleracion(40);
    //setPos(0,0);
    animacion->start(100);

}

jugador::~jugador()
{
    delete animacion;

    delete calculo;
}

void jugador::movimiento()
{
    calculo->actualizar((0.06666));
    setPos(x(),calculo->getPY());


}

void jugador::saltar()
{
        configuracion(salto,true,0,8,192,46);
        calculo->setPY(y());
}

void jugador::cambio()
{
    select_bloc(cambio_sprit*48,0,48,43,false,48*1.3,48*1.2);
    if(cambio_sprit<3)
    {
        cambio_sprit++;
    }
    else
    {
        cambio_sprit=0;
    }


}


