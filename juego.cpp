#include "juego.h"

juego::juego()
{
    srand(time(NULL));
    setSceneRect(0,0,16*scale_sprite*largo,16*scale_sprite*ancho);

    personaje= new jugador;
    gangster= new enemigo_1;
    tanque= new enemigo_2;
    dron= new enemigo_3;
    mapa();

    //addItem(dron);
    addItem(gangster);

    addItem(personaje->mano);
    addItem(personaje->pistola);
    addItem(personaje);


    //addItem(gangster);



    //addItem(tanque);

    //addItem(personaje);


    caida= new QTimer;
    DisparoProta=new QTimer;
    connect(caida, SIGNAL (timeout()),this, SLOT(movimien()));
    connect(DisparoProta, SIGNAL (timeout()),this, SLOT(FuncionDisparo()));



}

juego::~juego()
{
    for(int i=0;i<largo;i++){
        for(int j=0;j<2;j++) delete bl[i][j];
    }
    for (unsigned var = 0; var < numbalas; ++var)
    {
        delete cartuchoprota[var];
    }
    delete personaje;
    delete gangster;
    delete caida;
    delete DisparoProta;

}

void juego::mapa()
{
    fondo =new base;
    fondo->configuracion(":/sprites/zona sprites/2 Background/Background.png");


    fondo->select_bloc(0,0,576,324,false,largo*32,(ancho-2)*32);
    addItem(fondo);

    for(int i=0;i<largo;i++){

            bl[i][0] = new bloques;
            bl[i][0]->configuracion(":/sprites/zona sprites/1 Tiles/IndustrialTile_05.png");
            bl[i][0]->select_bloc(0);
            bl[i][0]->setPos(16*i*scale_sprite,16*(ancho-2)*scale_sprite);
            addItem(bl[i][0]);

    }

    for(int i=0;i<largo;i++){

            QString sprint ;
            sprint=char(49+( rand() % (7  )) );
            QString nom=":/sprites/zona sprites/1 Tiles/IndustrialTile_1"+sprint + ".png";

            bl[i][1] = new bloques;

            bl[i][1]->configuracion(nom);
            bl[i][1]->select_bloc(0);
            bl[i][1]->setPos(16*i*scale_sprite,16*(ancho-1)*scale_sprite);
            addItem(bl[i][1]);

    }
}

void juego::FuncionDisparo()
{
    int eliminados=0;
    if(numbalas!=0)
    {

        for (unsigned var = 0; var < numbalas-eliminados; ++var)
        {
            cartuchoprota[var]->fisicas();
            if(cartuchoprota[var]->x()<=0 or cartuchoprota[var]->x()>=largo*scale_sprite*16)
            {
                removeItem(cartuchoprota[var]);
                cartuchoprota.remove(var);
                eliminados++;

            }

        }

    }
    else
    {
        DisparoProta->stop();
    }

    numbalas=numbalas-eliminados;

}



/*int juego::select_bloc(int i, int j)
{
   int bl=9;

   if(j==0 || j==ancho-1 || i==0 || i==largo-1 || (i%2==0 && j%2==0)) bl = 0;
   else if(aleatorio() && !((i==1 && j==1) || (i==2 && j==1) || (i==1 && j==2))) bl = 1;
   return bl;
}*/

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

    if(e == Qt::Key_P)
    {
        if(permisoO)
        {
            permisoO=false;
            personaje->saltar();
            personaje->calculo->setAY(40);
            personaje->calculo->setVY(-80);
            caida->start(10);
        }
    }
    if(e == Qt::Key_O)
    {
        personaje->direccion();
    }
    if(e == Qt::Key_I)
    {
        int v;
        numbalas++;
        cartuchoprota.push_back(new polvora);

        if(personaje->getvuelta())
        {v=1;}
        else
        { v=-1;}
        cartuchoprota[numbalas-1]->Iparametros(":/sprites/armas y movimientos sprites/5 Bullets/4_1.png",personaje->mano->x(),personaje->mano->y(),0,0,v*scale_sprite*20,0,0,personaje->getvuelta());
        addItem(cartuchoprota[numbalas-1]);
        DisparoProta->start(10);

    }
}
