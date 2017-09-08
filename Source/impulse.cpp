#include "impulse.h"



// choisit une boule (clic)
// et lui donne une vitesse ( tirer / lacher)
// seule la vitesse de la boule cliquée est modifiée
// retourne 0 si l'initialisation n'a pas pu se faire

int impulsion(tBoule *liste,int nbrBoules,SDL_Surface *ecran)
{

    float rayonCarre;
    int x,y,numBouleChoisie;
    vecteur coordSouris;

    // attend le clic
    int attend=1;
    SDL_Event event;

    while (attend)
    {
        SDL_WaitEvent(&event); // Récupèration de l'évènement dans event
        switch(event.type) // Test du type d'évènement
        {
            case SDL_QUIT : // Si c'est un évènement de type "Quitter"
                return 0;
                attend=0;
            break;

            // en cas de clic chercher la boule cliquée
            case SDL_MOUSEBUTTONDOWN :
                // récupère les coordonnées du point de clic
                SDL_GetMouseState(&x,&y);
                coordSouris.x=x;
                coordSouris.y=y;
                // cherche si une des boules est à moins d'un rayon du clic

                    rayonCarre=liste[21].img->h/2;
                    rayonCarre*=rayonCarre;
                    if (distCarre(liste[21].coord,coordSouris)<=rayonCarre)
                    {
                        numBouleChoisie=21;
                        attend=0;
                    }

            break;
        }
    }


    // étire en attendant le lacher
    attend=1;
    SDL_Surface *boule,*tamponBoule;
    boule=liste[numBouleChoisie].img;


    SDL_Rect tailleBoule,dstBoule,origine;
    SDL_GetClipRect(boule, &tailleBoule);
    tamponBoule = SDL_CreateRGBSurface(SDL_HWSURFACE, tailleBoule.w, tailleBoule.h, 32, 0, 0, 0, 0);
    dstBoule.x=x- boule->w/2;
    dstBoule.y=y- boule->h/2;
    dstBoule.h=boule->h;
    dstBoule.w=boule->w;

   // met en tampon le dessous de la boule
    SDL_BlitSurface(ecran,&dstBoule,tamponBoule,NULL);


    while (attend)
    {
        SDL_WaitEvent(&event);
        switch (event.type)
        {
            case SDL_QUIT:
                attend=0;
                return 1;
            break;
            // boutton relaché
            case SDL_MOUSEBUTTONUP :
                SDL_GetMouseState(&x,&y);
                liste[21].vitesse.x=(liste[21].coord.x-x)*COEF_VITESSE;
                liste[21].vitesse.y=(liste[21].coord.y-y)*COEF_VITESSE;
                attend=0;
            break;
            case SDL_MOUSEMOTION :
                    // force à rester dans le billard
                    SDL_GetMouseState(&x,&y);
                    if (x- boule->w/2<EPAISSEUR)
                    {
                        x=EPAISSEUR+boule->w/2;
                    }
                    if (x+boule->w/2+EPAISSEUR>LARGEUR_ECRAN)
                    {
                        x=LARGEUR_ECRAN-EPAISSEUR-boule->w/2;
                    }
                    if (y- boule->h/2<EPAISSEUR)
                    {
                        y=EPAISSEUR+boule->h/2;
                    }

                    if (y+boule->h/2+EPAISSEUR>HAUTEUR_ECRAN)
                    {
                        y=HAUTEUR_ECRAN-EPAISSEUR-boule->h/2;
                    }
                    // repose le tampon
                    SDL_BlitSurface(tamponBoule,NULL,ecran,&dstBoule);

                    // met en tampon
                    dstBoule.x=x- boule->w/2;
                    dstBoule.y=y- boule->h/2;
                    dstBoule.h=boule->h;
                    dstBoule.w=boule->w;

                    origine.x=0;
                    origine.y=0;

                    SDL_BlitSurface(ecran,&dstBoule,tamponBoule,&origine);
                    // colle la boule
                    SDL_BlitSurface(boule, NULL, ecran, &dstBoule);
                    SDL_Flip(ecran);

                break;
        }
    }
    return 1;
}
