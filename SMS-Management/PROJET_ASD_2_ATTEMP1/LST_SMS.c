#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "ELTPRIM.h"
#include "LSTPRIM.h"
#include "ELT_SMS.h"
#include "LST_SMS.h"
#include <string.h>
LISTE_SMS liste_smsCreer(void) {
LISTE_SMS L;
L = (LISTE_SMS) malloc(sizeof(laStructSMS));
if(!L) {
printf(" \nProbleme de memoire") ;
exit(0) ;
}
L->lg = 0;
return(L);
}
//-------------------------------------
void liste_smsDetruire(LISTE_SMS L){
int i;
for(i = 1;i <= L->lg; i++)
element_smsDetruire(L->elements[i]);
free(L);
}
//--------------------------------------
int inserer_sms (LISTE_SMS L, ELEMENT_SMS e, int pos) {
int i;
int succee=1;
if (est_smsSaturee(L)){
printf ("\n liste saturee");
succee=0;}
else {
if ((pos < 1) || (pos > L->lg + 1)) {
printf ("\nPosition invalide");
succee=0;
}
else {
for(i = L->lg; i>= pos; i--)
element_smsAffecter(&L->elements[i+1],
L->elements[i]);
element_smsAffecter(&L->elements[pos], e);
(L->lg)++;
}
}
return(succee);
}
//-------------------------------------------
int supprimer_sms (LISTE_SMS L, int pos ) {
int i;
int succee=1;
if (est_smsVide(L)) {
printf ("\n Liste vide");
succee=0;}
else {
if ((pos < 1) || (pos > L->lg)) {
printf ("Position invalide");
succee=0;}
else {
element_smsDetruire(L->elements[pos]);
for(i=pos;i<=L->lg;i++)
element_smsAffecter(&L->elements[i],
L->elements[i+1]);
(L->lg)--;
}
}
return(succee);
}
//------------------------------------------------
ELEMENT_SMS recuperer_sms(LISTE_SMS L, int pos) {
ELEMENT_SMS elt= element_smsCreer();
if (est_smsVide(L))
printf (" \n Liste vide");
else {
if ((pos < 1) || (pos > L->lg))
printf (" \n Position invalide");
else
elt=(L->elements[pos]);
}
return(elt);
}
//--------------------------------------------------
LISTE_SMS liste_smsCopier(LISTE_SMS L){
LISTE_SMS LR = liste_smsCreer();
int i;
ELEMENT_SMS elt;
for(i = 1;i <= L->lg; i++) {
elt=element_smsCreer();
element_smsCopier(&elt, recuperer_sms(L,i));
inserer_sms(LR, elt, i);
}
return LR;
}
//-------------------------------------------------------
int liste_smsComparer (LISTE_SMS L1,LISTE_SMS L2 )
{
int test= 1;
int i=1;
if (liste_smsTaille(L1) != liste_smsTaille(L2)) test= 0;
while ((i<=liste_smsTaille(L1)) && (test)) {
if (element_smsComparer(recuperer_sms(L1,i),recuperer_sms(L2,i))!=0)
test=0;
i++;
}
return test;
}
//----------------------------------------------------------
void liste_smsAfficher(LISTE_SMS L) {
int i;
for(i = 1; i <= L->lg; i++){
element_smsAfficher(L->elements[i]);}
}
//-----------------------------------------------------------
int est_smsVide(LISTE_SMS L) {
return (L->lg == 0);
}
//----------------------------------------------

int est_smsSaturee(LISTE_SMS L) {
return (L->lg == LongMax);
}
//------------------------------------------------
int liste_smsTaille(LISTE_SMS L) {
return (L->lg);
}
//--------------------------------------------------
int sms_caractere_stand(LISTE_SMS s , char *ch){

// --------------------------------------- CARACTERE STANDARDS --------------------------**-------------

    if(strlen(ch)<=1224 && strlen(ch)>1071){

        return 8 ;
    }

    //--------------------------------------------
    else if (strlen(ch)<=1071 && strlen(ch)>918){

        return 7;

    }

    //------------------------------------------------
     else if (strlen(ch)<=918 && strlen(ch)>756){

        return 6;

    }
    //--------------------------------------------------
     else if (strlen(ch)<=756 && strlen(ch)>612){

        return 5;

    }
    //-------------------------------------------------------
     else if (strlen(ch)<=612 && strlen(ch)>459){

        return 4;

    }
    //--------------------------------------------------------
     else if (strlen(ch)<=459 && strlen(ch)>306){

        return 3;

    }
    //-----------------------------------------------

 else if (strlen(ch)<=306 && strlen(ch)>153){

        return 2;

    }
    //-----------------------------------------------
     else  {

        return 1;

    }
    //-------------------------------------------

}
//-------------------------------------------------------------------
int sms_caractere_spec(LISTE_SMS s,char *sh){


 // --------------------------------------- CARACTERE SPECIALES --------------------------**-------------



    if(strlen(sh)<=536 && strlen(sh)>469){

        return 8 ;
    }

    //--------------------------------------------
    else if (strlen(sh)<=469 && strlen(sh)>402){

        return 7;

    }

    //------------------------------------------------
     else if (strlen(sh)<=402 && strlen(sh)>335){

        return 6;

    }
    //--------------------------------------------------
     else if (strlen(sh)<=335 && strlen(sh)>268){

        return 5;

    }
    //-------------------------------------------------------
     else if (strlen(sh)<=268 && strlen(sh)>201){

        return 4;

    }
    //--------------------------------------------------------
     else if (strlen(sh)<=201 && strlen(sh)>134){

        return 3;
        // element sms cree
        // puisque ...

    }
    //-----------------------------------------------

 else if (strlen(sh)<=134 && strlen(sh)>70){

        return 2;

    }
    //-----------------------------------------------
     else {

        return 1;

    }










}

