#include <SDL/SDL.h>
#define LARGEUR_ECRAN 637
#define HAUTEUR_ECRAN 372
#define FROTTEMENT 0.995
#define EPAISSEUR 43
#define V_MINI 0.1
#define NOMBRE_DE_BOULES 22
#define COEF_VITESSE 0.05

typedef struct vecteur
{
    float x,y;
}  vecteur;
typedef struct tBoule
{
    vecteur coord,vitesse;
    SDL_Surface* img;
} tBoule;
