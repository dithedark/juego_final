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
    enemigo_2(bool posicionInicial2);
    enemigo_2(bool posicionInicial2, int vidas2);

    //Destructores
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
    QString enemigo2D=":/sprites/enemigos robots y drones con armas y animaciones sprites/6/Attack.png";
    QString enemigo2=":/sprites/enemigos robots y drones con armas y animaciones sprites/6/Walk.png";
    QString enemigo2M="";
    QString enemigo_quieto=":/sprites/enemigos robots y drones con armas y animaciones sprites/6/Idle.png";
    QTimer *t_caminar2;
    QTimer *t_mostrar_muerte2;
    int cambioE2_sprite=0;
    int cambioE2_spriteD=0;
    int cambioE2_spriteI=0;
    bool giro2=true;
    unsigned pausa2=1;
    bool posF2=false;
    int totalVidas2=5;

    Observer *observador;







private slots:
     void estado_inicial2();
     void cambioE2();
     void disparoE2();
     void muerte2();
};

#endif // ENEMIGO_2_H
