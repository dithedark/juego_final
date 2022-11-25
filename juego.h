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
    //Constructores
    juego();

    //Destructores
    ~juego();

    //Metodos
    void mapa();
    void keyPressEvent(QKeyEvent *i) override;

    //Parte observador
    virtual void notificacion_enemigo(int tipo_enemigo, int x, int y, bool giro) override;

private:
    int select_bloc(int i, int j);
    bool aleatorio(),permisoO=true;

    unsigned dispa=0;
    unsigned dronesEnemigos=0,dronesbalas=0,limiteDrones;
    int nivel_activo = 1;
    unsigned total_enemigos1 = 0;
    unsigned total_enemigos2 = 0;
    unsigned total_enemigos3 = 0;
    unsigned puntaje_total = 0;



    float p = 0.3;
    objetivo *trampolin;
    bloques *bl[largo][2];
    base *fondo;
    base *nivel;
    base *puntaje;
    base *nivel_etiqueta;
    jugador *personaje;

    int t_enemigos = 4000;
    int e1_vidas = 3;
    int n=1;

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
