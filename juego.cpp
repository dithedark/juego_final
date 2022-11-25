#include "juego.h"
#include "enemigo_1.h"
#include "enemigo_2.h"
#include "enemigo_3.h"

//Constructores
juego::juego()
{
    srand(time(NULL));
    setSceneRect(0,0,16*scale_sprite*largo,16*scale_sprite*ancho);
    mapa();
}

//Destructores
juego::~juego()
{
    for(int i=0;i<largo;i++){
        for(int j=0;j<2;j++) delete bl[i][j];
    }
    for (unsigned var = 0; var < dispa; ++var)
    {
        delete cartuchoprota[var];
    }
    delete personaje;
    delete caida;
    delete t_disparo_protagonista;
    delete movimiento_drones;

}


//Metodos
void juego::iniciar_juego(){
    this->clear();
    mapa();

    nivel_etiqueta = new base;
    QString imagen = ":/sprites/interfaz/1.png";
    nivel_etiqueta->configuracion(imagen);
    nivel_etiqueta->select_bloc(0,0,32,36,false,largo*2,(ancho)*2);
    nivel_etiqueta-> setPos(16*4*scale_sprite,16*(ancho-1)*scale_sprite);
    addItem(nivel_etiqueta);

    personaje= new jugador;
    addItem(personaje->mano);
    addItem(personaje->pistola);
    addItem(personaje);

    t_disparo_protagonista=new QTimer;
    caida= new QTimer;
    movimiento_drones=new QTimer;
    Disparo_enemigos=new QTimer;
    invencible=new QTimer;

    connect(invencible, SIGNAL (timeout()),this, SLOT(parpadeo()));
    connect(caida, SIGNAL (timeout()),this, SLOT(movimien()));
    connect(t_disparo_protagonista, SIGNAL (timeout()),this, SLOT(disparo_protagonista()));
    connect(Disparo_enemigos, SIGNAL (timeout()),this, SLOT(disparoEnemigos()));

    // Carga Enemigos Aleatoriamente
    t_cargar_enemigos = new QTimer;
    connect(t_cargar_enemigos, SIGNAL (timeout()), this, SLOT(cargar_enemigos()));
    t_cargar_enemigos -> start(t_enemigos);

    movimiento_drones->start(150);
    Disparo_enemigos->start(10);

    trampolin =new objetivo ;
    trampolin->parametros(":/sprites/zona sprites/3 Objects/Fire-extinguisher1.png",scale_sprite*16*largo*0.5,scale_sprite*16*ancho*0.5);

    addItem(trampolin);

}

void juego::mapa()
{
    fondo =new base;
    fondo->configuracion(":/sprites/zona sprites/2 Background/Background.png");

    fondo->select_bloc(0,0,576,324,false,largo*32,(ancho-2)*32);
    addItem(fondo);

    QString s_puntaje_total = QStringLiteral("%1").arg(puntaje_total, 5, 10, QLatin1Char('0'));
    QGraphicsTextItem* puntaje_pad = new QGraphicsTextItem(s_puntaje_total);
    QFont puntajeFont("comic sans",15);
    puntaje_pad->setFont(puntajeFont);
    int txPos = 130;
    int tyPos = 22;
    puntaje_pad->setPos(txPos,tyPos);
    addItem(puntaje_pad);


    nivel = new base;
    nivel->configuracion(":/sprites/interfaz/LEVEL-removebg-preview.png");

    puntaje = new base;
    puntaje->configuracion(":/sprites/interfaz/SCORE-removebg-preview.png");

    for(int i=0;i<largo;i++)
    {

            bl[i][0] = new bloques;
            bl[i][0]->configuracion(":/sprites/zona sprites/1 Tiles/IndustrialTile_05.png");
            bl[i][0]->select_bloc(0);
            bl[i][0]->setPos(16*i*scale_sprite,16*(ancho-2)*scale_sprite);
            addItem(bl[i][0]);

    }

    for(int i=0;i<largo;i++)
    {

            QString sprint ;
            sprint=char(49+( rand() % (7  )) );
            QString nom=":/sprites/zona sprites/1 Tiles/IndustrialTile_1"+sprint + ".png";

            bl[i][1] = new bloques;

            bl[i][1]->configuracion(nom);
            bl[i][1]->select_bloc(0);
            bl[i][1]->setPos(16*i*scale_sprite,16*(ancho-1)*scale_sprite);
            addItem(bl[i][1]);

    }
    nivel->select_bloc(0,0,320,40,false,largo*3,(ancho)*1);
    nivel-> setPos(16*1*scale_sprite,16*(ancho-1)*scale_sprite);
    addItem(nivel);

    puntaje->select_bloc(0,0,320,40,false,largo*3,(ancho)*1);
    puntaje-> setPos(16*1*scale_sprite,16*(ancho-14)*scale_sprite);
    addItem(puntaje);

}

void juego::notificacion_enemigo(int tipo_enemigo, int x, int y, bool giro){
    int v;
    if(giro)
        {v = 1;}
    else
        {v = -1;}
    polvora *p = new polvora();
    polvora *s;
    switch(tipo_enemigo){
        case 1:
            p->Iparametros(":/sprites/armas y movimientos sprites/5 Bullets/4_1.png",
                           x+10,y+10,0,0,v*scale_sprite*10,0,0,giro);
        break;


        case 2:
            p->Iparametros(":/sprites/armas y movimientos sprites/5 Bullets/3.png",
                       x+((20.4*scale_sprite)),y+(14.4*scale_sprite),0,40,v*50,-90,0,false,10*scale_sprite);
            s=new polvora();


            s->Iparametros(":/sprites/armas y movimientos sprites/5 Bullets/3.png",
                       x+((20.4*scale_sprite)),y+(14.4*scale_sprite),0,40,v*50,-45,0,false,10*scale_sprite);
            cartuchoEnemigos.push_back(s);
            dronesbalas++;
            addItem(s);
        break;
        case 3:
              p->Iparametros(":/sprites/armas y movimientos sprites/5 Bullets/1.png",x+(13*scale_sprite),y+(28.8*scale_sprite),0,10,0,10,40,false,10*scale_sprite);
        break;

    }
    cartuchoEnemigos.push_back(p);
    dronesbalas++;
    addItem(p);
}

void juego::disparo_protagonista()
{
    bool exit = false;
    if(dispa > 0){
        for (unsigned var = 0; var < dispa; ++var)
        {
            cartuchoprota[var]->fisicas();
            QList<QGraphicsItem *> items = collidingItems(cartuchoprota[var], Qt::ItemSelectionMode::IntersectsItemShape);
            foreach (QGraphicsItem * i, items) {
                enemigo_1 * e1 = dynamic_cast<enemigo_1 *>(i);
                if(e1){
                    e1->recibir_disparo();
                    removeItem(cartuchoprota[var]);
                    cartuchoprota.remove(var);
                    dispa--;
                    if(e1->obtener_total_vidas() > 0){
                        exit = true;
                        break;
                    }
                    else{
                        this -> removeItem(i);
                        total_enemigos1--;
                    }
                }
                enemigo_2 * e2 = dynamic_cast<enemigo_2 *>(i);
                if(e2){
                    e2->recibir_disparo();
                    removeItem(cartuchoprota[var]);
                    cartuchoprota.remove(var);
                    dispa--;
                    if(e2->obtener_total_vidas() > 0){
                        exit = true;
                        break;
                    }
                    else{
                        this -> removeItem(i);
                        total_enemigos2--;
                    }
                }
                enemigo_3 * e3 = dynamic_cast<enemigo_3 *>(i);
                if(e3){
                    e3->recibir_disparo();
                    removeItem(cartuchoprota[var]);
                    cartuchoprota.remove(var);
                    if(e3->obtener_total_vidas() > 0){
                        exit = true;
                        dispa--;
                        break;
                     }                    else{
                        this -> removeItem(i);
                        total_enemigos3--;
                    }
                }
            }
            if(exit) break;
        }
    } else {
        t_disparo_protagonista->stop();
    }
}

void juego::disparoEnemigos()
{
    unsigned balasenemigos=dronesbalas;
        for (unsigned var = 0; var < balasenemigos; ++var)
        {
            cartuchoEnemigos[var]->fisicas(personaje->x()+((x_jugador/2)*scale_sprite),personaje->y()+((y_jugador/2)*scale_sprite),personaje->calculo->getmasa());
            if(( (cartuchoEnemigos[var]->x()<=0) or (cartuchoEnemigos[var]->x()>=largo*scale_sprite*16)) or (cartuchoEnemigos[var]->y()<0) or (cartuchoEnemigos[var]->y()>ancho*16*scale_sprite))
            {
                removeItem(cartuchoEnemigos[var]);
                cartuchoEnemigos.remove(var);
                balasenemigos--;
                dronesbalas--;
            }
            else if(cartuchoEnemigos[var]->collidesWithItem(personaje))
            {
                if(estado_invencible)
                {
                    personaje->recibir_disparo();
                    estado_invencible=!estado_invencible;
                    invencible->start(200);

                    if(personaje->mostrar_vidas()==0){
                        detener();
                    }
                }

            }
        }
         trampolin->Msen();
}

void juego::detener(){
    t_disparo_protagonista->stop();
    caida->stop();
    movimiento_drones->stop();
    Disparo_enemigos->stop();
    invencible->stop();
    t_cargar_enemigos->stop();
    for(unsigned i = 0; i < dronesbalas;i++){
        removeItem(cartuchoEnemigos[i]);
    }

    for(unsigned i = 0; i < dispa;i++){
        removeItem(cartuchoprota[i]);
    }
    dronesbalas = 0;
    dispa = 0;
    puntaje = 0;
    mapa();
    iniciar_juego();
    iniciar();
}

void juego::iniciar(){
    t_disparo_protagonista->start();
    caida->start();
    movimiento_drones->start();
    Disparo_enemigos->start();
    invencible->start();
    t_cargar_enemigos->start();
}

void juego::cargar_enemigos(){
    puntaje_total++;
    if((total_enemigos1 % 10) == 0 && total_enemigos1 > 10){
        if(t_enemigos > 300)
            t_enemigos -= 200;
        e1_vidas += 3;
        nivel_activo++;
        QString imagen = ":/sprites/interfaz/"+QString::number(nivel_activo)+".png";
        nivel_etiqueta->configuracion(imagen);
        nivel_etiqueta->select_bloc(0,0,22,36,false,largo*2,(ancho)*2);
    }

    enemigo_1 *enemigo1 = new enemigo_1(aleatorio(), e1_vidas);
    enemigo1->agregar_observador(this);
    addItem(enemigo1);
    total_enemigos1++;

    if(total_enemigos2 < 0){
        enemigo_2 *enemigo2 = new enemigo_2(aleatorio(), e1_vidas);
        enemigo2->agregar_observador(this);
        addItem(enemigo2);
        total_enemigos2++;
    }

    if(total_enemigos3 < 0){
        enemigo_3 *enemigo3 = new enemigo_3(aleatorio(), e1_vidas);
        enemigo3->agregar_observador(this);
        addItem(enemigo3);
        total_enemigos3++;
    }
}

void juego::parpadeo()
{
    if(prendido)
    {
        removeItem(personaje);
        removeItem(personaje->mano);
        removeItem(personaje->pistola);
    }
    else
    {
        addItem(personaje);
        addItem(personaje->mano);
        addItem(personaje->pistola);

    }
    prendido=!prendido;
    Iparpadeo++;
    if(Cparpadeo==Iparpadeo)
    {
        estado_invencible= !estado_invencible;
        invencible->stop();
        addItem(personaje);
        addItem(personaje->mano);
        addItem(personaje->pistola);
        Iparpadeo=0;
        prendido=true;

    }

}

bool juego::aleatorio()
{
    return rand()<=p*(RAND_MAX+1)-1;
}

void juego::movimien()
{
    personaje->movimientoY();
    for(int i=0;i<largo;i++)
    {
        if(bl[i][0]->collidesWithItem(personaje))
        {
            personaje->calculo->setAY(0);
            personaje->setPos(personaje->x(),bl[i][0]->y()-(48*1.2)-0.22);            
            personaje->cargaCorrer();
            permisoO=true;
            caida->stop();
        }
    }
}

void juego::keyPressEvent(QKeyEvent *i)
{
    const int e=i->key();

    if(e == Qt::Key_I)
    {
        if(personaje->collidesWithItem(trampolin))
        {
            permisoO=true;
        }
        if(permisoO)
        {
            permisoO=false;
            personaje->saltar();
            personaje->calculo->setAY(40);
            personaje->calculo->setVY(-80);
            caida->start(10);
        }
    }
    if(e == Qt::Key_P)
    {
        personaje->direccion();
    }
    if(e == Qt::Key_O)
    {
        int v;
        dispa++;
        personaje->cargarDisparo();
        cartuchoprota.push_back(new polvora);

        if(personaje->getvuelta())
        {v=1;}
        else
        { v=-1;}
        cartuchoprota[dispa-1]->Iparametros(":/sprites/armas y movimientos sprites/5 Bullets/4_1.png",personaje->mano->x(),personaje->mano->y(),0,0,v*scale_sprite*40,0,0,personaje->getvuelta());
        addItem(cartuchoprota[dispa-1]);
        t_disparo_protagonista -> start(10);
    }
}
