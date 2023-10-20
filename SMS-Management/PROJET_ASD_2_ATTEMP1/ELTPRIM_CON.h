#ifndef ELTPRIM_CON_H_INCLUDED
#define ELTPRIM_CON_H_INCLUDED
#include "ELTCON.h"
ELEMENT_CONT element_contCreer (void);
void element_contDetruire (ELEMENT_CONT );
void element_contAffecter(ELEMENT_CONT * , ELEMENT_CONT );
void element_contCopier(ELEMENT_CONT * , ELEMENT_CONT );
void element_contLire(ELEMENT_CONT * );
void element_contAfficher(ELEMENT_CONT );
int element_contComparer(ELEMENT_CONT , ELEMENT_CONT );

#endif // ELTPRIM_CON_H_INCLUDED
