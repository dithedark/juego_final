#ifndef ENEMIGO_1_H
#define ENEMIGO_1_H

#include "base.h"

class enemigo_1:public QObject , public base
{
Q_OBJECT

public:
    enemigo_1();
    enemigo_1(bool initPos);
    ~enemigo_1();


private:

    QString enemigo1D= ":/sprites/enemigos robots y drones con armas y animaciones sprites/2/Attack.png";
    QString enemigo1= ":/sprites/enemigos robots y drones con armas y animaciones sprites/2/Walk.png";
    QString enemigo1I=":/sprites/enemigos robots y drones con armas y animaciones sprites/2/Idle.png";
    QTimer *walkE1;
    bool dobl=false;
    int cambioE1_sprite=0;
    int cambioE1_spriteD=0;
    int cambioE1_spriteI=0;
    bool giro=true;
    bool pausa=true;
    bool posF=false;




private slots:
    void initState();
    void disparo();
    void cambioE1();
};

#endif // ENEMIGO_1_H
