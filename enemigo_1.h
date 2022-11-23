#ifndef ENEMIGO_1_H
#define ENEMIGO_1_H

#include "base.h"

class enemigo_1:public QObject , public base
{
Q_OBJECT

public:
    // Constructores
    enemigo_1();
    enemigo_1(bool posicionInicial);
    enemigo_1(bool posicionInicial, int vidas);

    // Deestructor
    ~enemigo_1();

    // Propiedades
    int obtener_total_vidas();

    // Metodos
    void recibir_disparo();

private:

    QString enemigo1D= ":/sprites/enemigos robots y drones con armas y animaciones sprites/2/Attack.png";
    QString enemigo1= ":/sprites/enemigos robots y drones con armas y animaciones sprites/2/Walk.png";
    QString enemigo1I=":/sprites/enemigos robots y drones con armas y animaciones sprites/2/Idle.png";
    QString enemigo1M = ":/sprites/enemigos robots y drones con armas y animaciones sprites/2/Death.png";
    QString enemigo1H = ":/sprites/enemigos robots y drones con armas y animaciones sprites/2/Hurt.png";
    QTimer *t_caminar;
    QTimer *t_mostrar_muerte;
    bool dobl=false;
    int cambioE1_sprite=0;
    int cambioE1_spriteD=0;
    int cambioE1_spriteI=0;
    bool giro=true;
    bool pausa=true;
    bool posF=false;
    int totalVidas=3;




private slots:
    void estado_inicial();
    void disparo();
    void cambioE1();
    void muerte();
};

#endif // ENEMIGO_1_H
