#ifndef ENEMIGO_2_H
#define ENEMIGO_2_H

#include "base.h"
#include "Sujeto.h"

class enemigo_2:public QObject , public base, public Subject
{
Q_OBJECT

public:
    //constructores
    enemigo_2();
    enemigo_2(bool posicionInicial);
    enemigo_2(bool posicionInicial,int vidas);

    ~enemigo_2();

    // Metodos del Sujeto
    void agregar_observador(Observer *obs) override;
    void remover_observador() override;
    void notificar() override;

    // Propiedades
    int obtener_total_vidas2();

    // Metodos
    void recibir_disparo2();


private:
    void estado_inicial();




    QString enemigo2D=":/sprites/enemigos robots y drones con armas y animaciones sprites/6/Attack.png";
    QString enemigo2=":/sprites/enemigos robots y drones con armas y animaciones sprites/6/Walk.png";
    QString enemigo2M="";
    QString enemigo_quieto=":/sprites/enemigos robots y drones con armas y animaciones sprites/6/Idle.png";

    QTimer *walkE2;
    QTimer *secuencia_muerte;

    int cambioE2_sprite=0,
    cambioE2_spriteD=0;

    bool giro2=true;
    unsigned pausa2=1;
    bool posF2=false;
    int punto2=85;
    int punto_contrario2=2;
    int vidastotales=3;
    Observer *observador;


    int punto2=85;
    int punto_contrario2=2;




private slots:
     void estado_inicial2();
     void cambioE2();
     void disparoE2();
     void muerte2();
};

#endif // ENEMIGO_2_H
