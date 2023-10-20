#ifndef ELTPRIM_MSG_H_INCLUDED
#define ELTPRIM_MSG_H_INCLUDED
#include "ELTMSG.h"
ELEMENT_MSG element_msgCreer (void);       // DANS TOUS LES FICHIERS **
void element_msgDetruire (ELEMENT_MSG );
void element_msgAffecter(ELEMENT_MSG * , ELEMENT_MSG );
void element_msgCopier(ELEMENT_MSG * , ELEMENT_MSG );
void element_msgLire(ELEMENT_MSG * );
void element_msgAfficher(ELEMENT_MSG );
int element_msgComparer(ELEMENT_MSG , ELEMENT_MSG );



#endif // ELTPRIM_MSG_H_INCLUDED
