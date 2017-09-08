#include "initBallsPositions.h"



//  affecte les boules au tableau
int chargeBoules(tBoule *liste,int nbrBoules)
{
    SDL_Surface* RedBall = SDL_LoadBMP("images/RedBall.bmp");
    if (!RedBall)
    {
        printf("n'a pas pu cherger l'image: %s\n", SDL_GetError());
        return 0;
    }
    SDL_Surface* whiteball = SDL_LoadBMP("images/whiteball.bmp");
    if (!whiteball)
    {
        printf("n'a pas pu cherger l'image: %s\n", SDL_GetError());
        return 0;
    }
    SDL_Surface* BlackBall = SDL_LoadBMP("images/BlackBall.bmp");
    if (!BlackBall)
    {
        printf("n'a pas pu cherger l'image: %s\n", SDL_GetError());
        return 0;
    }
     SDL_Surface* BlueBall = SDL_LoadBMP("images/BlueBall.bmp");
    if (!BlueBall)
    {
        printf("n'a pas pu cherger l'image: %s\n", SDL_GetError());
        return 0;
    }
     SDL_Surface* BrownBall= SDL_LoadBMP("images/BrownBall.bmp");
    if (!BrownBall)
    {
        printf("n'a pas pu cherger l'image: %s\n", SDL_GetError());
        return 0;
    }
     SDL_Surface* GreenBall = SDL_LoadBMP("images/GreenBall.bmp");
    if (!GreenBall)
    {
        printf("n'a pas pu cherger l'image: %s\n", SDL_GetError());
        return 0;
    }
     SDL_Surface* PinkBall = SDL_LoadBMP("images/Pink.bmp");
    if (!PinkBall)
    {
        printf("n'a pas pu cherger l'image: %s\n", SDL_GetError());
        return 0;
    }
     SDL_Surface* YellowBall = SDL_LoadBMP("images/YellowBall.bmp");
    if (!YellowBall)
    {
        printf("n'a pas pu cherger l'image: %s\n", SDL_GetError());
        return 0;
    }
    //rend le blanc transparent
    SDL_SetColorKey(RedBall, SDL_SRCCOLORKEY, SDL_MapRGB(RedBall->format, 255, 255, 255));
    SDL_SetColorKey(whiteball, SDL_SRCCOLORKEY, SDL_MapRGB(whiteball->format, 255, 255, 255));
    SDL_SetColorKey(BlackBall, SDL_SRCCOLORKEY, SDL_MapRGB(BlackBall->format, 255, 255, 255));
    SDL_SetColorKey(BlueBall, SDL_SRCCOLORKEY, SDL_MapRGB(BlueBall->format, 255, 255, 255));
    SDL_SetColorKey(BrownBall, SDL_SRCCOLORKEY, SDL_MapRGB(BrownBall->format, 255, 255, 255));
    SDL_SetColorKey(GreenBall, SDL_SRCCOLORKEY, SDL_MapRGB(GreenBall->format, 255, 255, 255));
    SDL_SetColorKey(PinkBall, SDL_SRCCOLORKEY, SDL_MapRGB(PinkBall->format, 255, 255, 255));
    SDL_SetColorKey(YellowBall, SDL_SRCCOLORKEY, SDL_MapRGB(YellowBall->format, 255, 255, 255));



    // affecte l'image à la boule
        liste[0].img=RedBall;
        liste[0].vitesse.x=0;
        liste[0].vitesse.y=0;
        liste[1].img=RedBall;
        liste[1].vitesse.x=0;
        liste[1].vitesse.y=0;
        liste[2].img=RedBall;
        liste[2].vitesse.x=0;
        liste[2].vitesse.y=0;
        liste[3].img=RedBall;
        liste[3].vitesse.x=0;
        liste[3].vitesse.y=0;
        liste[4].img=RedBall;
        liste[4].vitesse.x=0;
        liste[4].vitesse.y=0;
        liste[5].img=RedBall;
        liste[5].vitesse.x=0;
        liste[5].vitesse.y=0;
        liste[6].img=RedBall;
        liste[6].vitesse.x=0;
        liste[6].vitesse.y=0;
        liste[7].img=RedBall;
        liste[7].vitesse.x=0;
        liste[7].vitesse.y=0;
        liste[8].img=RedBall;
        liste[8].vitesse.x=0;
        liste[8].vitesse.y=0;
        liste[9].img=RedBall;
        liste[9].vitesse.x=0;
        liste[9].vitesse.y=0;
        liste[10].img=RedBall;
        liste[10].vitesse.x=0;
        liste[10].vitesse.y=0;
        liste[11].img=RedBall;
        liste[11].vitesse.x=0;
        liste[11].vitesse.y=0;
        liste[12].img=RedBall;
        liste[12].vitesse.x=0;
        liste[12].vitesse.y=0;
        liste[13].img=RedBall;
        liste[13].vitesse.x=0;
        liste[13].vitesse.y=0;
        liste[14].img=RedBall;
        liste[14].vitesse.x=0;
        liste[14].vitesse.y=0;
        liste[15].img=BlackBall;
        liste[15].vitesse.x=0;
        liste[15].vitesse.y=0;
        liste[16].img=BlueBall;
        liste[16].vitesse.x=0;
        liste[16].vitesse.y=0;
        liste[17].img=BrownBall;
        liste[17].vitesse.x=0;
        liste[17].vitesse.y=0;
        liste[18].img=GreenBall;
        liste[18].vitesse.x=0;
        liste[18].vitesse.y=0;
        liste[19].img=PinkBall;
        liste[19].vitesse.x=0;
        liste[19].vitesse.y=0;
        liste[20].img=YellowBall;
        liste[20].vitesse.x=0;
        liste[20].vitesse.y=0;
        liste[21].img=whiteball;
  return 1;
}


// Saisie à la souris de les positions initiale des la boule (cliquer)
// retourne 1 si les données n'ont pas pu être saisies.
// *liste est la listde NOMBRE_DE_BOULES


int placeBoules(tBoule *liste,int nbrBoules,SDL_Surface *ecran)
{
    SDL_Surface* boule;
    SDL_Rect dstBoule;
    int x,y;
    // replace la souris au centre
    x=LARGEUR_ECRAN/2;
    y=HAUTEUR_ECRAN/2;
    SDL_WarpMouse(x,y);

        boule=liste[0].img;
        dstBoule.x=LARGEUR_ECRAN/4- boule->w/2;
        dstBoule.y=HAUTEUR_ECRAN/2- boule->h/2;
        dstBoule.h=boule->h;
        dstBoule.w=boule->w;
        SDL_BlitSurface(boule,NULL,ecran,&dstBoule);
        SDL_Flip(ecran);
        liste[0].coord.x=LARGEUR_ECRAN/4- boule->w/2;
        liste[0].coord.y=HAUTEUR_ECRAN/2- boule->h/2;

        boule=liste[1].img;
        dstBoule.x=LARGEUR_ECRAN/4- boule->w/2;
        dstBoule.y=HAUTEUR_ECRAN/2- 3*boule->h/2;
        dstBoule.h=boule->h;
        dstBoule.w=boule->w;
        SDL_BlitSurface(boule,NULL,ecran,&dstBoule);
        SDL_Flip(ecran);
        liste[1].coord.x=LARGEUR_ECRAN/4- boule->w/2;
        liste[1].coord.y=HAUTEUR_ECRAN/2- 3*boule->h/2;
         boule=liste[2].img;
        dstBoule.x=LARGEUR_ECRAN/4- boule->w/2;
        dstBoule.y=HAUTEUR_ECRAN/2+ boule->h/2;
        dstBoule.h=boule->h;
        dstBoule.w=boule->w;
        SDL_BlitSurface(boule,NULL,ecran,&dstBoule);
        SDL_Flip(ecran);
        liste[2].coord.x=LARGEUR_ECRAN/4- boule->w/2;
        liste[2].coord.y=HAUTEUR_ECRAN/2+ boule->h/2;
         boule=liste[3].img;
        dstBoule.x=LARGEUR_ECRAN/4- boule->w/2;
        dstBoule.y=HAUTEUR_ECRAN/2- 5*boule->h/2;
        dstBoule.h=boule->h;
        dstBoule.w=boule->w;
        SDL_BlitSurface(boule,NULL,ecran,&dstBoule);
        SDL_Flip(ecran);
        liste[3].coord.x=LARGEUR_ECRAN/4- boule->w/2;
        liste[3].coord.y=HAUTEUR_ECRAN/2- 5*boule->h/2;
         boule=liste[4].img;
        dstBoule.x=LARGEUR_ECRAN/4- boule->w/2;
        dstBoule.y=HAUTEUR_ECRAN/2+ 3*boule->h/2;
        dstBoule.h=boule->h;
        dstBoule.w=boule->w;
        SDL_BlitSurface(boule,NULL,ecran,&dstBoule);
        SDL_Flip(ecran);
        liste[4].coord.x=LARGEUR_ECRAN/4- boule->w/2;
        liste[4].coord.y=HAUTEUR_ECRAN/2+ 3*boule->h/2;
        ///////////////////
        boule=liste[5].img;
        dstBoule.x=LARGEUR_ECRAN/4+boule->w/2;
        dstBoule.y=HAUTEUR_ECRAN/2- 4*boule->h/2;
        dstBoule.h=boule->h;
        dstBoule.w=boule->w;
        SDL_BlitSurface(boule,NULL,ecran,&dstBoule);
        SDL_Flip(ecran);
        liste[5].coord.x=LARGEUR_ECRAN/4+boule->w/2;
        liste[5].coord.y=HAUTEUR_ECRAN/2- 4*boule->h/2;
        boule=liste[6].img;
        dstBoule.x=LARGEUR_ECRAN/4+boule->w/2;
        dstBoule.y=HAUTEUR_ECRAN/2- 2*boule->h/2;
        dstBoule.h=boule->h;
        dstBoule.w=boule->w;
        SDL_BlitSurface(boule,NULL,ecran,&dstBoule);
        SDL_Flip(ecran);
        liste[6].coord.x=LARGEUR_ECRAN/4+boule->w/2;
        liste[6].coord.y=HAUTEUR_ECRAN/2- 2*boule->h/2;
        boule=liste[7].img;
        dstBoule.x=LARGEUR_ECRAN/4+boule->w/2;
        dstBoule.y=HAUTEUR_ECRAN/2;
        dstBoule.h=boule->h;
        dstBoule.w=boule->w;
        SDL_BlitSurface(boule,NULL,ecran,&dstBoule);
        SDL_Flip(ecran);
        liste[7].coord.x=LARGEUR_ECRAN/4+boule->w/2;
        liste[7].coord.y=HAUTEUR_ECRAN/2;
        boule=liste[8].img;
        dstBoule.x=LARGEUR_ECRAN/4+boule->w/2;
        dstBoule.y=HAUTEUR_ECRAN/2+ 2*boule->h/2;
        dstBoule.h=boule->h;
        dstBoule.w=boule->w;
        SDL_BlitSurface(boule,NULL,ecran,&dstBoule);
        SDL_Flip(ecran);
        liste[8].coord.x=LARGEUR_ECRAN/4+boule->w/2;
        liste[8].coord.y=HAUTEUR_ECRAN/2+ 2*boule->h/2;
        ///////////////////////
        boule=liste[9].img;
        dstBoule.x=LARGEUR_ECRAN/4+3*boule->w/2;
        dstBoule.y=HAUTEUR_ECRAN/2- 3*boule->h/2;
        dstBoule.h=boule->h;
        dstBoule.w=boule->w;
        SDL_BlitSurface(boule,NULL,ecran,&dstBoule);
        SDL_Flip(ecran);
        liste[9].coord.x=LARGEUR_ECRAN/4+3*boule->w/2;
        liste[9].coord.y=HAUTEUR_ECRAN/2- 3*boule->h/2;
        boule=liste[10].img;
        dstBoule.x=LARGEUR_ECRAN/4+3*boule->w/2;
        dstBoule.y=HAUTEUR_ECRAN/2-boule->h/2;
        dstBoule.h=boule->h;
        dstBoule.w=boule->w;
        SDL_BlitSurface(boule,NULL,ecran,&dstBoule);
        SDL_Flip(ecran);
        liste[10].coord.x=LARGEUR_ECRAN/4+3*boule->w/2;
        liste[10].coord.y=HAUTEUR_ECRAN/2-boule->h/2;
        boule=liste[11].img;
        dstBoule.x=LARGEUR_ECRAN/4+3*boule->w/2;
        dstBoule.y=HAUTEUR_ECRAN/2+boule->h/2;
        dstBoule.h=boule->h;
        dstBoule.w=boule->w;
        SDL_BlitSurface(boule,NULL,ecran,&dstBoule);
        SDL_Flip(ecran);
        liste[11].coord.x=LARGEUR_ECRAN/4+3*boule->w/2;
        liste[11].coord.y=HAUTEUR_ECRAN/2+boule->h/2;
        boule=liste[12].img;
        dstBoule.x=LARGEUR_ECRAN/4+5*boule->w/2;
        dstBoule.y=HAUTEUR_ECRAN/2- 2*boule->h/2;
        dstBoule.h=boule->h;
        dstBoule.w=boule->w;
        SDL_BlitSurface(boule,NULL,ecran,&dstBoule);
        SDL_Flip(ecran);
        liste[12].coord.x=LARGEUR_ECRAN/4+5*boule->w/2;
        liste[12].coord.y=HAUTEUR_ECRAN/2- 2*boule->h/2;
        boule=liste[13].img;
        dstBoule.x=LARGEUR_ECRAN/4+5*boule->w/2;
        dstBoule.y=HAUTEUR_ECRAN/2;
        dstBoule.h=boule->h;
        dstBoule.w=boule->w;
        SDL_BlitSurface(boule,NULL,ecran,&dstBoule);
        SDL_Flip(ecran);
        liste[13].coord.x=LARGEUR_ECRAN/4+5*boule->w/2;
        liste[13].coord.y=HAUTEUR_ECRAN/2;;
        boule=liste[14].img;
        dstBoule.x=LARGEUR_ECRAN/4+7*boule->w/2;
        dstBoule.y=HAUTEUR_ECRAN/2-boule->h/2;
        dstBoule.h=boule->h;
        dstBoule.w=boule->w;
        SDL_BlitSurface(boule,NULL,ecran,&dstBoule);
        SDL_Flip(ecran);
        liste[14].coord.x=LARGEUR_ECRAN/4+7*boule->w/2;
        liste[14].coord.y=HAUTEUR_ECRAN/2-boule->h/2;
         boule=liste[15].img;
        dstBoule.x=LARGEUR_ECRAN/4-9*boule->w/2;
        dstBoule.y=HAUTEUR_ECRAN/2- boule->h/2;
        dstBoule.h=boule->h;
        dstBoule.w=boule->w;
        SDL_BlitSurface(boule,NULL,ecran,&dstBoule);
        SDL_Flip(ecran);
        SDL_Event event;
        liste[15].coord.x=LARGEUR_ECRAN/4-9*boule->w/2;
        liste[15].coord.y=HAUTEUR_ECRAN/2- boule->h/2;
         boule=liste[16].img;
        dstBoule.x=LARGEUR_ECRAN/2- boule->w/2;
        dstBoule.y=HAUTEUR_ECRAN/2- boule->h/2;
        dstBoule.h=boule->h;
        dstBoule.w=boule->w;
        SDL_BlitSurface(boule,NULL,ecran,&dstBoule);
        SDL_Flip(ecran);
        liste[16].coord.x=LARGEUR_ECRAN/2- boule->w/2;
        liste[16].coord.y=HAUTEUR_ECRAN/2- boule->h/2;
         boule=liste[17].img;
        dstBoule.x=LARGEUR_ECRAN-LARGEUR_ECRAN/3-boule->w/2;
        dstBoule.y=HAUTEUR_ECRAN/2- boule->h/2;
        dstBoule.h=boule->h;
        dstBoule.w=boule->w;
        SDL_BlitSurface(boule,NULL,ecran,&dstBoule);
        SDL_Flip(ecran);
        liste[17].coord.x=LARGEUR_ECRAN-LARGEUR_ECRAN/3-boule->w/2;
        liste[17].coord.y=HAUTEUR_ECRAN/2- boule->h/2;
         boule=liste[18].img;
        dstBoule.x=LARGEUR_ECRAN-LARGEUR_ECRAN/3-boule->w/2;
        dstBoule.y=HAUTEUR_ECRAN/2+ 7*boule->h/2;
        dstBoule.h=boule->h;
        dstBoule.w=boule->w;
        SDL_BlitSurface(boule,NULL,ecran,&dstBoule);
        SDL_Flip(ecran);
        liste[18].coord.x=LARGEUR_ECRAN-LARGEUR_ECRAN/3-boule->w/2;
        liste[18].coord.y=HAUTEUR_ECRAN/2+ 7*boule->h/2;
        boule=liste[19].img;
        dstBoule.x=LARGEUR_ECRAN/4+9.3*boule->w/2;
        dstBoule.y=HAUTEUR_ECRAN/2-boule->h/2;
        dstBoule.h=boule->h;
        dstBoule.w=boule->w;
        SDL_BlitSurface(boule,NULL,ecran,&dstBoule);
        SDL_Flip(ecran);
        liste[19].coord.x=LARGEUR_ECRAN/4+9.3*boule->w/2;
        liste[19].coord.y=HAUTEUR_ECRAN/2-boule->h/2;
        boule=liste[20].img;
        dstBoule.x=LARGEUR_ECRAN-LARGEUR_ECRAN/3-boule->w/2;
        dstBoule.y=HAUTEUR_ECRAN/2- 9*boule->h/2;
        dstBoule.h=boule->h;
        dstBoule.w=boule->w;
        SDL_BlitSurface(boule,NULL,ecran,&dstBoule);
        SDL_Flip(ecran);
        liste[20].coord.x=LARGEUR_ECRAN-LARGEUR_ECRAN/3-boule->w/2;
        liste[20].coord.y=HAUTEUR_ECRAN/2- 9*boule->h/2;
        boule=liste[21].img;
        dstBoule.x=LARGEUR_ECRAN-LARGEUR_ECRAN/5-boule->w/2;
        dstBoule.y=HAUTEUR_ECRAN/2- boule->h/2;
        dstBoule.h=boule->h;
        dstBoule.w=boule->w;
        SDL_BlitSurface(boule,NULL,ecran,&dstBoule);
        SDL_Flip(ecran);
        liste[21].coord.x=LARGEUR_ECRAN-LARGEUR_ECRAN/5-boule->w/2;
        liste[21].coord.y=HAUTEUR_ECRAN/2- boule->h/2;

       /* int attend=1;

         while (attend)
        {
            // met en veille en attendant un événement
            SDL_WaitEvent(&event);
            switch(event.type)
            {
                case SDL_QUIT : // Si c'est un évènement de type "Quitter"
                    return 0;
                break;

    }
    return 1;

} */
}
