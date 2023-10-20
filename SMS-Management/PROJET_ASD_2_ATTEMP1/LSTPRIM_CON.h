#ifndef LSTPRIM_CON_H_INCLUDED
#define LSTPRIM_CON_H_INCLUDED
#include "LSTCON.h"
#include "ELTCON.h"
NOEUD_CONT noeud_contCreer(ELEMENT_CONT);
void noeud_contDetruire(NOEUD_CONT);
int est_contVide(LISTE_CONT);
int est_contSaturee(LISTE_CONT);
int liste_contTaille(LISTE_CONT);
int inserer_cont (LISTE_CONT, ELEMENT_CONT, int);
int supprimer_cont (LISTE_CONT, int );
ELEMENT_CONT recuperer_cont(LISTE_CONT, int );
//----------------------------------------
LISTE_CONT liste_contCreer(void);
void liste_contDetruire(LISTE_CONT );
void liste_contAfficher(LISTE_CONT );
LISTE_CONT liste_contCopier(LISTE_CONT );
int liste_contComparer (LISTE_CONT ,LISTE_CONT );



#endif // LSTPRIM_CON_H_INCLUDED
