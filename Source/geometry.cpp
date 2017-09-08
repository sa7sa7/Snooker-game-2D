#include "geometry.h"


float distCarre(vecteur point1, vecteur point2)
{
    return (point1.x-point2.x)*(point1.x-point2.x)+(point1.y-point2.y)*(point1.y-point2.y);
}

float norme(vecteur v)
{
    return sqrt( v.x*v.x+v.y*v.y);
}

float prodScal(vecteur u, vecteur v)
{
    return u.x*v.x+u.y*v.y;
}
