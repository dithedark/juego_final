#include "objetivo.h"



objetivo::objetivo()
{

}

objetivo::~objetivo()
{

}

void objetivo::parametros(QString nombre, float px, float py)
{
    PX=px;
    PY=py;
    configuracion(nombre);
    select_bloc(0,0,35,50,false,55,40);

}

void objetivo::Msen()
{
    if(multiplicar==0)
    {
        multiplicar=45;
    }
    else if( multiplicar<=45)
    {
        multiplicar--;
    }

    setPos(PX,PY+((sin(pi*(multiplicar/45)))*scale_sprite*2));
}
