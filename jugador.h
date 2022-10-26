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

    operaciones *calculo;



private:
    QString punk=":/sprites/armas y movimientos sprites/1 Characters/2 Punk/Idle1.png",
    manoPonk=":/sprites/armas y movimientos sprites/3 Hands/2 Punk/1.png",
    salto=":/sprites/armas y movimientos sprites/1 Characters/2 Punk/Jump1.png",
    correr=":/sprites/armas y movimientos sprites/1 Characters/2 Punk/Run1_",
    reves="I",png=".png";

    QTimer *animacion;
    int short cambio_sprit=0,cantidad_sprint=3;
    bool vuelta=1 ;







private slots:
    void esena();

};

#endif // JUGADOR_H
