#ifndef ENEMIGO_3_H
#define ENEMIGO_3_H

#include "base.h"
#include "Sujeto.h"

class enemigo_3:public QObject , public base,public Subject
{
Q_OBJECT

public:
    //Constructores
    enemigo_3();

    //Destructores
    ~enemigo_3();

    //Metodos
    void agregar_observador(Observer *obs) override;
    void remover_observador() override;
    void notificar() override;
    void recibir_disparo();
    void terminar();

    enemigo_3(bool posicionInicial);
    enemigo_3(bool posicionInicial, int vidas);

    int obtener_total_vidas();

private:

     void estado_inicial();

    QString enemigo3D=":/sprites/enemigos robots y drones con armas y animaciones sprites/5/Attack.png";
    QString enemigo3=":/sprites/enemigos robots y drones con armas y animaciones sprites/5/Walk.png";
    QString enemigo_quieto=":/sprites/enemigos robots y drones con armas y animaciones sprites/5/Idle.png" ;
    QString enemigo_muerte=":/sprites/enemigos robots y drones con armas y animaciones sprites/5/Death.png";

    QTimer *t_caminar;
    QTimer *t_mostrar_muerte;



    int cambioE3_sprite=0;
    int cambioE3_spriteD=0;

    bool giro3=true;
    int pausa3=0;
    bool posF3=false;
    int punto3=85;
    int punto_contrario3=2;
    int vidastotales=3;
    Observer *observador;


public slots:
    void disparoE3();
    void cambioE3();
    void muerte();



};

#endif // ENEMIGO_3_H
