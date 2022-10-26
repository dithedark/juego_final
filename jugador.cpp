#include "jugador.h"

jugador::jugador()
{
    animacion=new QTimer;


    configuracion(punk,true,0,14,192,34);
    CAMbloque(2);
    connect(animacion, SIGNAL (timeout()),this, SLOT(esena()));



    setPos(16*scale_sprite,16*(ancho-(3.7))*scale_sprite);
    calculo= new operaciones (x(),y(),0,0,0,0);
    //calculo->Maceleracion(40);
    //setPos(0,0);
    animacion->start(100);

}

jugador::~jugador()
{
    delete animacion;

    delete calculo;
}

void jugador::direccion()
{
    animacion->start(100);
    cantidad_sprint=5;
    if(vuelta)
    {
        vuelta=0;
        configuracion(correr+reves+png,true,24,14,264,34);

    }
    else
    {
        vuelta=1;
        configuracion(correr+png,true,0,14,288,34);
    }


}

void jugador::movimientoY()
{

    calculo->actualizarY((0.06666));
    setPos(x(),calculo->getPY());


}

void jugador::saltar()
{
    cantidad_sprint=3;
    animacion->start(150);
    configuracion(salto,true,0,8,192,46);
    calculo->setPY(y());
}

void jugador::esena()
{
    select_bloc((cambio_sprit*48),0,26,48,false,48,48*1.2);

    if(vuelta)
    {
        if(cambio_sprit<cantidad_sprint)
        {
            cambio_sprit++;
        }
        else
        {
            cambio_sprit=0;
        }
    }
    else
    {
        if(cambio_sprit > 0)
        {
            cambio_sprit--;
        }
        else
        {
            cambio_sprit=cantidad_sprint;
        }

    }

}


