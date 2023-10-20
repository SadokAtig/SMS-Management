#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "ELTPRIM_CON.h"
#include "ELTCON.h"
ELEMENT_CONT element_contCreer (void)
{
    ELEMENT_CONT L;
    L = (ELEMENT_CONT) malloc(sizeof(CONTACT));
    return L;
}
//-----------------------------------------------
void element_contDetruire (ELEMENT_CONT L)
{
    free (L);
}
//----------------------------------------------

void element_contLire(ELEMENT_CONT* elt)
{

int test = 0,test1=0,pos=0,pos1=0 ;
int i ;
    printf(" \n Donnez votre nom svp  :") ;
    fflush (stdin);
    fgets((*elt)->nom, 50, stdin);

    int j;

int x = 0;

do{

     printf(" \n Donnez votre numero svp :  ");
    fflush(stdin);
    fgets((*elt)->numero,9,stdin);
     if ((*elt)->numero[0] == '5'|| (*elt)->numero[0] == '2'|| (*elt)->numero[0] == '9'){
        x = 1 ;}

}while(strlen((*elt)->numero) != 8  || (x ==0 )); //((*elt)->numero[j]<'a')|| ((*elt)->numero[j]>'z')|| ((*elt)->numero[j]<'A')|| ((*elt)->numero[j]>'Z') ) ;

    do
   {
    printf(" \n Donnez votre email svp  : ");
    fflush(stdin);
    fgets((*elt)->email,30,stdin);

   for(i=0;i<=strlen((*elt)->email);i++)
   {
       if ((*elt)->email[i] == '@')
       {
           test=1;
           pos=i;
       }
       if ((*elt)->email[i] == '.')
       {
           test1=1;
           pos1=i;
       }

   }

  } while((test ==0 && test1==0)|| (pos>pos1));

}



//-----------------------------------------------

void element_contAfficher(ELEMENT_CONT elt)
{
    printf("\n nom = %s  \n numero = %s  \n email = %s ",elt->nom,elt->numero,elt->email);

}
//----------------------------------------------------

void element_contAffecter(ELEMENT_CONT* e1, ELEMENT_CONT e2)
{
   *e1 = e2 ;
}
//------------------------------------------------------

void element_contCopier(ELEMENT_CONT *e1 , ELEMENT_CONT e2)
{
  strcpy((*e1)->nom, e2->nom);

}
//--------------------------------------------------------

int element_contComparer(ELEMENT_CONT e1, ELEMENT_CONT e2)
{
    return ((e1->numero)-(e2->numero)) ;
}
//--------------------------------------------------
