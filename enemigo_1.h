#ifndef ENEMIGO_1_H
#define ENEMIGO_1_H

#include "base.h"

class enemigo_1:public QObject , public base
{
Q_OBJECT

public:
    enemigo_1();
    ~enemigo_1();

    void movimiento();
    void correr();
private:
   // QString enemigo1= ":/sprites/enemigos robots y drones con armas y animaciones sprites/2/Attack.png";
     QString enemigo1= ":/sprites/enemigos robots y drones con armas y animaciones sprites/2/Walk.png";
    QTimer *animacionE1;
    int cambioE1_sprit=0;

    QString enemigo1walk=":/sprites/enemigos robots y drones con armas y animaciones sprites/2/Walk.png";
    QTimer *walkE1;

    bool giro=true;

private slots:
    void cambioE1();
   // void movimientoX();
    //void correr();
};

#endif // ENEMIGO_1_H
