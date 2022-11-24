#ifndef ENEMIGO_2_H
#define ENEMIGO_2_H

#include "base.h"
#include "Sujeto.h"

class enemigo_2:public QObject , public base, public Subject
{
Q_OBJECT

public:
    enemigo_2();
    ~enemigo_2();

    // Metodos del Sujeto
    void agregar_observador(Observer *obs) override;
    void remover_observador() override;
    void notificar() override;

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
    Observer *observador;

private slots:

     void cambioE2();
     void disparoE2();

};

#endif // ENEMIGO_2_H
