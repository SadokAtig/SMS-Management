#ifndef LSTCON_H_INCLUDED
#define LSTCON_H_INCLUDED
#include "ELTCON.h"
typedef struct structNoeudCONT
{
ELEMENT_CONT info;
struct structNoeudCONT * suivant;
}
structNoeudCONT, * NOEUD_CONT;
typedef struct
{
NOEUD_CONT tete;
int lg;
}
laStructCONT,*LISTE_CONT;


#endif // LSTCON_H_INCLUDED
