#ifndef LSTPRIM_MSG_H_INCLUDED
#define LSTPRIM_MSG_H_INCLUDED
#include "ELTMSG.h"
#include "LST_MSG.h"
NOEUD_MSG noeud_msgCreer(ELEMENT_MSG );
void noeud_msgDetruire(NOEUD_MSG );
int est_msgVide(LISTE_MSG );
int est_msgSaturee(LISTE_MSG );
int liste_msgTaille(LISTE_MSG );
int inserer_msg (LISTE_MSG , ELEMENT_MSG , int );
int supprimer_msg (LISTE_MSG , int );
ELEMENT_MSG recuperer_msg(LISTE_MSG, int );
//--------------------------------------
LISTE_MSG liste_msgCreer(void);
void liste_msgDetruire(LISTE_MSG );
void liste_msgAfficher(LISTE_MSG );
LISTE_MSG liste_msgCopier(LISTE_MSG );
int liste_msgComparer (LISTE_MSG ,LISTE_MSG  );


#endif // LSTPRIM_MSG_H_INCLUDED
