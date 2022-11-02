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

    void direccion();

    void movimientoY();
    void saltar();

    void cargaCorrer();

    void cargarDisparo();

    operaciones *calculo;

    base *mano,*pistola;

private:
    QString punk=":/sprites/armas y movimientos sprites/1 Characters/2 Punk/Idle1.png",
    manoPunk=":/sprites/armas y movimientos sprites/3 Hands/2 Punk/1_.png",
    salto=":/sprites/armas y movimientos sprites/1 Characters/2 Punk/Jump1_",
    correr=":/sprites/armas y movimientos sprites/1 Characters/2 Punk/Run1_",
    armaB=":/sprites/armas y movimientos sprites/2 Guns/3_",
    reves="I",png=".png";

    QTimer *animacion,*andar;
    int short cambio_sprit=0,cantidad_sprint=3,velocidad=23,posmanoX,posmanoY;
    bool vuelta=1 ;




private slots:
    void escena();
    void movimientoX();
};

#endif // JUGADOR_H
