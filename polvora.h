#ifndef POLVORA_H
#define POLVORA_H

#include "base.h"
#include "operaciones.h"

class polvora:public QObject , public base
{
public:
    //Constructores
    polvora();

    //Destructores
    ~polvora();

    //Metodos
    void Iparametros(QString nombre ,float px,float py,float ax=0,float ay=0,float vx=0,float vy=0 ,float mass=0,bool vuelta =true,float dimension=scale_sprite*5);
    void fisicas(float px=0,float py=0, float masa=0);




    operaciones *matematicas;


};

#endif // POLVORA_H
