#include "BallMouvement.h"


void copieBoule(tBoule originale, tBoule *copie)
{
    copie->coord.x=originale.coord.x;
    copie->coord.y=originale.coord.y;
    copie->vitesse.x=originale.vitesse.x;
    copie->vitesse.y=originale.vitesse.y;
    copie->img=originale.img;
}

// deplace la boule de sa vitesse
void deplaceBoule(tBoule *boule)
{
    boule->coord.x+=boule->vitesse.x;
    boule->coord.y+=boule->vitesse.y;
}


void rebondBouleBoule(tBoule incidente1, tBoule incidente2, tBoule *reflechie1, tBoule *reflechie2)
{
    // incidente1->img->h est la haurteur=largeur=diametre de la boule
    if (distCarre(incidente1.coord,incidente2.coord)>=(incidente1.img->h)*(incidente1.img->h))
    {
        copieBoule(incidente1,reflechie1);
        copieBoule(incidente2,reflechie2);
    }
    else
    {
        //  VM : vitesse du (repère) mobile, (u,v) base mobile orthonormal
        vecteur VM,u,v;

        VM.x=(incidente1.vitesse.x+incidente2.vitesse.x)/2;
        VM.y=(incidente1.vitesse.y+incidente2.vitesse.y)/2;

        // direction de réflexion donné  par le centre des boules
        u.x=(incidente1.coord.x-incidente2.coord.x);
        u.y=(incidente1.coord.y-incidente2.coord.y);
        // normalisation de u
        float r=norme(u);
        u.x=u.x/r;
        u.y=u.y/r;

        // quart de tours pour v
        v.x=u.y;
        v.y=-u.x;

        // vitesse incidente de la boule 1 relative au repere mobile
        // celle de la boule 2 est l'oppposée.
        // VIA coordonnées dans le repère absolu
        // VIM coordonnées dans le repère mobile
        // N.B. dans le repère mobile, les vitesses des deux boules restent opposées

        vecteur VIA,VIM;

        VIA.x=incidente1.vitesse.x-VM.x;
        VIA.y=incidente1.vitesse.y-VM.y;

        VIM.x=prodScal(VIA,u);
        VIM.y=prodScal(VIA,v);

        // vitesse réfléchie
        // seule la partie suivant u  est inversée
        // dans le repère mobile, les vitesse des deux boules restent opposées

        reflechie1->vitesse.x=-VIM.x*u.x+VIM.y*v.x + VM.x;
        reflechie1->vitesse.y=-VIM.x*u.y+VIM.y*v.y+ VM.y;
        reflechie1->coord.x=incidente1.coord.x;
        reflechie1->coord.y=incidente1.coord.y;
        reflechie1->img=incidente1.img;


        reflechie2->vitesse.x=VIM.x*u.x-VIM.y*v.x+VM.x;
        reflechie2->vitesse.y=+VIM.x*u.y-VIM.y*v.y+VM.y;
        reflechie2->coord.x=incidente2.coord.x;
        reflechie2->coord.y=incidente2.coord.y;
        reflechie2->img=incidente2.img;
    }
}


void rebondBouleBord(tBoule incidente, tBoule *reflechie)
{
    float r=incidente.img->h/2;
    copieBoule(incidente,reflechie);
    // test l'appartenance à un des pièges

    // rebond à gauche
    if (incidente.coord.x<EPAISSEUR+r && incidente.vitesse.x<0 )
    {
        reflechie->vitesse.x=-incidente.vitesse.x;
    }
    // rebond à droite
    if (incidente.coord.x+r+EPAISSEUR>LARGEUR_ECRAN && incidente.vitesse.x>0)
    {
        reflechie->vitesse.x=-incidente.vitesse.x;
    }
    // rebond en haut
    if (incidente.coord.y<EPAISSEUR+r && incidente.vitesse.y<0)
    {
        reflechie->vitesse.y=-incidente.vitesse.y;
    }
    // rebond en bas
    if (incidente.coord.y+r+EPAISSEUR>HAUTEUR_ECRAN && incidente.vitesse.y>0)
    {
        reflechie->vitesse.y=-incidente.vitesse.y;
    }
}
