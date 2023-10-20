#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "ELTPRIM.h"
#include <string.h>

ELEMENT_SMS element_smsCreer (void)                          // comme les autres check lstprim
{
    ELEMENT_SMS L;
    L = (ELEMENT_SMS) malloc(sizeof(SMS));
    return L;
}
//-----------------------------------------------
void element_smsDetruire (ELEMENT_SMS L)
{
    free (L);
}
//----------------------------------------------

void element_smsLire(ELEMENT_SMS* elt)
{
int i ;
    printf(" \n ecrire votre sms  svp  :") ;
    fflush(stdin);
    fgets((*elt)->texte, 160, stdin);
    (*elt)->taille=strlen((*elt)->texte)-1;
    }
//-----------------------------------------------

void element_smsAfficher(ELEMENT_SMS elt)
{
    printf("\n texte = %s , \n taille = %i ",elt->texte,elt->taille);
}
//-------------------------------------------------

void element_smsAffecter(ELEMENT_SMS* e1, ELEMENT_SMS e2)
{
   *e1 = e2 ;
}
//---------------------------------------------------

void element_smsCopier(ELEMENT_SMS *e1 , ELEMENT_SMS e2)
{
   strcpy((*e1)->texte, e2->texte);

}
//--------------------------------------------------------

int element_smsComparer(ELEMENT_SMS e1, ELEMENT_SMS e2)
{
    return ((e1->taille)-(e2->taille)) ;
}



