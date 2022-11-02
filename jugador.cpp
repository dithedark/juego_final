#include "jugador.h"

jugador::jugador()
{
    animacion=new QTimer;
    andar=new QTimer;

    mano=new base;
    pistola=new base;


    configuracion(punk,true,0,14,192,34);

    CAMbloque(2);
    connect(animacion, SIGNAL (timeout()),this, SLOT(escena()));
    connect(andar, SIGNAL (timeout()),this, SLOT(movimientoX()));



    setPos(16*scale_sprite,16*(ancho-(3.7))*scale_sprite);
    calculo= new operaciones (x(),y(),0,0,0,0);
    //calculo->Maceleracion(40);

    mano->setPos(x()+20,y()+14);
    mano->configuracion(manoPunk);



    animacion->start(100);
    andar->start(10);

}

jugador::~jugador()
{
    delete animacion;
    delete calculo;
    delete andar;

    delete mano;
    delete pistola;

}

void jugador::direccion()
{
    animacion->start(100);
    cantidad_sprint=5;
    if(vuelta)
    {
        vuelta=0;

        calculo->setAX(-20);


    }
    else
    {
        vuelta=1;

        calculo->setAX(20);

    }
    cargaCorrer();

    velocidad=-velocidad;
}

void jugador::movimientoY()
{

    calculo->actualizarY((0.06667));

    setPos(x(),calculo->getPY());


}


void jugador::movimientoX()
{
    calculo->actualizarX(0.06667);

    if((calculo->getVX() > velocidad) and ( calculo->getAX() > 0 ) )
    {
        calculo->setAX(0);
        calculo->setVX(velocidad);
    }
    else if( (calculo->getVX() < velocidad) and (calculo->getAX() < 0)  )
    {
        calculo->setAX(0);
        calculo->setVX(velocidad);

    }


    setPos(calculo->getPX(),y());
    mano->setPos(x()+posmanoX,y()+posmanoY);

}


void jugador::saltar()
{
    cantidad_sprint=3;
    animacion->start(150);
    calculo->setPY(y());
    if(vuelta)
    {
        configuracion(salto+png,true,0,8,192,46);
    }
    else
    {
        configuracion(salto+reves+png,true,23,8,192,46);
    }
    cambio_sprit=0;

}

void jugador::cargaCorrer()
{
    if(vuelta)
    {
        configuracion(correr+png,true,0,14,288,34);

        mano->select_bloc(12,12,13,13,false,24,20*1.2);
        posmanoX=31;
        posmanoY=18;

    }
    else
    {
        configuracion(correr+reves+png,true,23,14,264,34);
        mano->select_bloc(12,12,13,13,false,24,20*1.2,true);
        posmanoX=-8;
        posmanoY=18;
    }


}

void jugador::cargarDisparo()
{
    if(vuelta)
    {

    }
    else
    {

    }

}

void jugador::escena()
{
    select_bloc((cambio_sprit*48),0,26,48,false,scale_sprite*x_jugador,scale_sprite*y_jugador);

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


