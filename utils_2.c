#include "cube3d.h"

float degToRad(int a) 
{
    return a*M_PI/180.0;
}

int FixAng(int a)
{ 
    if(a>359)
        a-=360;
    if(a<0)
        a+=360;
    return a;
}

float distance(int ax, int ay, int bx, int by, int ang)
{ 
   return cos(degToRad(ang))*(bx-ax)-sin(degToRad(ang))*(by-ay);
}

