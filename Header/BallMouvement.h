#include "geometry.h"


void copieBoule(tBoule originale, tBoule *copie);
void deplaceBoule(tBoule *boule);
void rebondBouleBoule(tBoule incidente1, tBoule incidente2, tBoule *reflechie1, tBoule *reflechie2);
void rebondBouleBord(tBoule incidente, tBoule *reflechie);
