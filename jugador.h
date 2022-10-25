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
    void movimiento();

    void saltar();
    operaciones *calculo;



private:
    QString punk=":/sprites/armas y movimientos sprites/1 Characters/2 Punk/Idle1.png",
    manoPonk=":/sprites/armas y movimientos sprites/3 Hands/2 Punk/1.png",
    salto=":/sprites/armas y movimientos sprites/1 Characters/2 Punk/Jump1.png";

    QTimer *animacion;
    int cambio_sprit=0;







private slots:
    void cambio();

};

#endif // JUGADOR_H
