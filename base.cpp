#include "base.h"

base::base()
{

    img = new QPixmap;
    im_blq = new QPixmap;
}

base::~base()
{
    delete img;
    delete im_blq;
}

void base::configuracion(QString nombre,bool copia, int x,int y ,int Ancho,int Alto)
{
    img->load(nombre);

    if(copia)
    {
        *img = img->copy(x,y,Ancho,Alto);
    }

}

void base::select_bloc(int x,int y, int Ancho  ,int Alto ,bool defecto ,int sx, int sy,bool rotar )
{


    *im_blq = img->copy(x,y,Ancho,Alto);
    //else im_blq->load(":/fondo.png");
    if(defecto)
    {
        *im_blq = im_blq->scaled(im_blq->width(),im_blq->height());
    }
    else
    {
        *im_blq = im_blq->scaled(sx,sy);
    }

    if(rotar)
    {
        *im_blq = rotation(im_blq);
    }

    setPixmap(*im_blq);

}



int base::MOSbloque()
{
    return type_block;
}

void base::CAMbloque(int Tipo_bloque)
{
    if(type_block != -1)
    {
        type_block=Tipo_bloque;
    }
}

QPixmap base::rotation(QPixmap *img)
{
    QTransform o;
    QPixmap img2;
    o = o.rotate(180,Qt::YAxis);
    img2 = img->transformed(o);

    return img2;
}
