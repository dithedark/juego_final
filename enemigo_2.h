#ifndef ENEMIGO_2_H
#define ENEMIGO_2_H

#include "base.h"

class enemigo_2:public QObject , public base
{
Q_OBJECT

public:
    enemigo_2();
    ~enemigo_2();
   void disparoE2();

private:
    QString enemigo2D=":/sprites/enemigos robots y drones con armas y animaciones sprites/6/Attack.png";

    QString enemigo2=":/sprites/enemigos robots y drones con armas y animaciones sprites/6/Walk.png";
    QString enemigo_quieto=":/sprites/enemigos robots y drones con armas y animaciones sprites/6/Idle.png";

    QTimer *walkE2;

    int cambioE2_sprite=0,
    cambioE2_spriteD=0;

    bool giro2=true;
    unsigned pausa2=1;
    bool posF2=false;
    int punto2=85;
    int punto_contrario2=2;

private slots:

     void cambioE2();

};

#endif // ENEMIGO_2_H
