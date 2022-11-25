#ifndef OBJETIVO_H
#define OBJETIVO_H

#include "base.h"
#include <cmath>

class objetivo: public base
{


public:
    //Constructor
    objetivo();

    //Destructor
    ~objetivo();

    //Metodos
    void parametros(QString nombre,float px, float py);
    void Msen();

private:
    float PX,PY,distancia,multiplicar=45,pi=3.1416;

};

#endif // OBJETIVO_H
