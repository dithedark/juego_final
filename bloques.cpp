#include "bloques.h"

bloques::bloques()
{
    /*img = new QPixmap;
    im_blq = new QPixmap;
    img->load(":/NES_-_Bomberman_-_General_Sprites-removebg-preview.png");
    *img = img->copy(48,48,144,16);*/


    CAMbloque(0);


}

bloques::~bloques()
{
    //delete img;
    //delete im_blq;
}


/*
void bloques::select_bloc(int bl)
{
    type_block = bl;
    if(bl!=9) *im_blq = img->copy(16*bl,0,16,16);
    else im_blq->load(":/fondo.png");
    *im_blq = im_blq->scaled(im_blq->width()*scale_sprite,im_blq->height()*scale_sprite);
    setPixmap(*im_blq);
}
*/
