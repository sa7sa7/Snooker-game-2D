#include <stdlib.h>
#include <stdio.h>
#include "initBallsPositions.h"




int main ( int argc, char** argv )
{
    // initialise SDL video
    if ( SDL_Init( SDL_INIT_VIDEO|SDL_INIT_TIMER) < 0 )
    {
        printf( "Unable to init SDL: %s\n", SDL_GetError() );
        return 1;
    }

    // s'assure de la bonne fermeture à la fin
    atexit(SDL_Quit);

    // creé la fenetre
    SDL_Surface* ecran = SDL_SetVideoMode(LARGEUR_ECRAN, HAUTEUR_ECRAN, 32,
                                           SDL_HWSURFACE|SDL_DOUBLEBUF);
    SDL_FillRect(ecran, 0, SDL_MapRGB(ecran->format, 255,255,0));
    // donne un nom à la fenêtre
    SDL_WM_SetCaption("", NULL);
    if ( !ecran )
    {
        printf("Unable to set LARGEUR_ECRANxHAUTEUR_ECRAN video: %s\n", SDL_GetError());
        return 1;
    }
    //creation du fond d'ecran
    SDL_Surface* fond=SDL_LoadBMP("images/snookerTableBlue2.bmp");
    // et collage
    SDL_Rect origine;
    origine.x=0;
    origine.y=0;
    SDL_BlitSurface(fond,NULL,ecran,&origine);
    SDL_Flip(ecran);



    // initialisation des boules /////////////////////////////////////
    tBoule liste[NOMBRE_DE_BOULES];
    chargeBoules(liste,NOMBRE_DE_BOULES);
    placeBoules(liste,NOMBRE_DE_BOULES,ecran);



    // boucle de jeu

    while (jouer(liste,NOMBRE_DE_BOULES,ecran,fond))
    {
        ;

    }

    int i=0;
    for (i=0;i<NOMBRE_DE_BOULES;i++)
    {
        SDL_FreeSurface(liste[i].img);
    }

    SDL_FreeSurface(fond);
//    SDL_FreeSurface(boule);
    SDL_FreeSurface(ecran);


    return 0;
    SDL_Quit();

}
