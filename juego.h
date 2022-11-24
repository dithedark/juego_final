#ifndef JUEGO_H
#define JUEGO_H

#include <QGraphicsScene>

#include <QKeyEvent>
#include <stdlib.h>
#include "bloques.h"
#include <cstdlib>
#include <time.h>
#include "jugador.h"
#include "enemigo_3.h"
#include "polvora.h"
#include "objetivo.h"
#include "Observador.h"

class juego : public QGraphicsScene, public Observer
{
Q_OBJECT
public:
    juego();
    ~juego();

    void mapa();
    void ver_menu();

    void keyPressEvent(QKeyEvent *i) override;
    virtual void notificacion_enemigo(int tipo_enemigo, int x, int y, bool giro) override;

private:
    int select_bloc(int i, int j);
    bool aleatorio(),permisoO=true;

    unsigned dispa=0;
    unsigned dronesEnemigos=0,dronesbalas=0,limiteDrones;
    unsigned total_enemigos1 = 0;
    unsigned total_enemigos2 = 0;



    float p = 0.3;
    objetivo *trampolin;
    bloques *bl[largo][2];
    base *fondo;
    base *level;
    base *number_level;
    jugador *personaje;

    //enemigo_2 *tanque;
    int t_enemigos = 2000;
    int e1_vidas = 3;

    QTimer *caida
    ,*t_disparo_protagonista,
    *movimiento_drones,
    *Disparo_enemigos,
    *t_cargar_enemigos;

    QVector<polvora*> cartuchoprota;
    QVector<polvora*> cartuchoEnemigos;

    QVector<enemigo_3*> drones;

public slots:

    void iniciar_juego();

    //movimiento personaje
    void movimien();

    // fisicas disparos
    void disparo_protagonista();
    void disparoEnemigos();


    // inteligencia enemigos
    void inteligencia_drones();

    void cargar_enemigos();

};

#endif // JUEGO_H
