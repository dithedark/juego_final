#ifndef JUGADOR_H
#define JUGADOR_H


#include "base.h"
#include "operaciones.h"

class jugador:public QObject , public base
{
Q_OBJECT

public:
    jugador();
    ~jugador();

    void formula();

    // para cambio de dirreccion
    // si esta viendo a la izquierda lo pone a ver a la derecha
    void direccion();

    //hace que cuando lo llamen vaya cambiando la posicion en Y
    void movimientoY();

    //cambia los sprint de caminar a saltar
    //y tambien si el jugador esta mirando hacia un lado el salto tambien
    void saltar();

    void cargaCorrer();

    void cargarDisparo();

    operaciones *calculo;

    base *mano,*pistola;

private:
    QString punk=":/sprites/armas y movimientos sprites/1 Characters/2 Punk/Idle1.png",
    manoPunk=":/sprites/armas y movimientos sprites/3 Hands/2 Punk/2_.png",
    salto=":/sprites/armas y movimientos sprites/1 Characters/2 Punk/Jump1_",
    correr=":/sprites/armas y movimientos sprites/1 Characters/2 Punk/Run1_",
    armaB=":/sprites/armas y movimientos sprites/2 Guns/3_",
    reves="I",png=".png";

    QTimer *animacion,*andar;
    int short cambio_sprit=0,cantidad_sprint=3,velocidad=scale_sprite*(23/2),posmanoX,posmanoY,pospistolaX,pospistolaY,signo;
    bool vuelta=1 ;




private slots:
    void escena();
    void movimientoX();
};

#endif // JUGADOR_H
