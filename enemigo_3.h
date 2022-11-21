#ifndef ENEMIGO_3_H
#define ENEMIGO_3_H

#include "base.h"

class enemigo_3:public QObject , public base
{
Q_OBJECT

public:
    enemigo_3();
    ~enemigo_3();
    int fase();
    void muerte();
private:
    QString enemigo3D=":/sprites/enemigos robots y drones con armas y animaciones sprites/5/Attack.png";
    QString enemigo3=":/sprites/enemigos robots y drones con armas y animaciones sprites/5/Walk.png";
    QString enemigo_quieto=":/sprites/enemigos robots y drones con armas y animaciones sprites/5/Idle.png" ;
    QString enemigo_herido=":/sprites/enemigos robots y drones con armas y animaciones sprites/5/Hurt.png";
    QString enemigo_muerte=":/sprites/enemigos robots y drones con armas y animaciones sprites/5/Death.png";
    QTimer *flyE3;

    int cambioE3_sprite=0;
    int cambioE3_spriteD=0;
    bool giro3=true;
    unsigned short pausa3=1,conteopausa=0;
    bool posF3=false;
    int punto3=85;
    int punto_contrario3=2;


public slots:
    void disparoE3();
    void cambioE3();



};

#endif // ENEMIGO_3_H
