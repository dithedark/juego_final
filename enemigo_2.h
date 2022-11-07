#ifndef ENEMIGO_2_H
#define ENEMIGO_2_H

#include "base.h"

class enemigo_2:public QObject , public base
{
Q_OBJECT

public:
    enemigo_2();
    ~enemigo_2();

private:
    QString enemigo2D=":/sprites/enemigos robots y drones con armas y animaciones sprites/6/Attack.png";
    QString enemigo2=":/sprites/enemigos robots y drones con armas y animaciones sprites/6/Walk.png";
    QTimer *walkE2;

    int cambioE2_sprite=0;
    int cambioE2_spriteD;
    bool giro2=true;
    bool pausa2=true;
    bool posF2=false;
    int punto2=85;
    int punto_contrario2=2;

private slots:
    void disparoE2();
    void cambioE2();

};

#endif // ENEMIGO_2_H
