#include "play.h"




// prend l'impulsion et fais bouger les boules jusqu'à l'arret
int jouer(tBoule *liste,int nbrBoules,SDL_Surface *ecran,SDL_Surface *fond)
{

    //tBoule reflechies[NOMBRE_DE_BOULES];
    SDL_Rect origine,dstBoule;
    int i,j,continuer=1;
    Uint32 temps=SDL_GetTicks();
    // attend une impulsion
    while (continuer)
    {
        continuer=impulsion(liste,nbrBoules,ecran);
        if (!continuer)
        {
            return 0;
        }
        // déplace les boules jusqu'à l'arret : toutes < V_MINI
        // s'arrete si SDL_EXIT
        while (continuer)
        {
            continuer=0;
            for (i=0;i<NOMBRE_DE_BOULES;i++)
            {
                // ralenti la boule boule
                liste[i].vitesse.x*=FROTTEMENT;
                liste[i].vitesse.y*=FROTTEMENT;

                if ( fabs(liste[i].vitesse.x)+fabs(liste[i].vitesse.y)>V_MINI )
                {
                    continuer=1;
                }
                else
                {
                    liste[i].vitesse.x=0;
                    liste[i].vitesse.y=0;
                }
                // déplace la boule

                deplaceBoule(&(liste[i]));
                rebondBouleBord(liste[i], &liste[i]);
                for (j=0;j<NOMBRE_DE_BOULES;j++)
                {
                    if (i!=j)
                    {
                        rebondBouleBoule(liste[i],liste[j],&liste[i],&liste[j]);
                    }
                };

            }
            //affiche
            origine.x=0;
            origine.y=0;
            SDL_BlitSurface(fond,NULL,ecran,&origine);
            for (i=0;i<NOMBRE_DE_BOULES;i++)
            {
                dstBoule.x=liste[i].coord.x-liste[i].img->h/2;
                dstBoule.y=liste[i].coord.y-liste[i].img->w/2;
                SDL_BlitSurface(liste[i].img,NULL,ecran,&dstBoule);
            }
            while(SDL_GetTicks()<temps+20){};
            temps=SDL_GetTicks();
            //printf(" %d\n", temps);
            SDL_Flip(ecran);
        };

    }

}
