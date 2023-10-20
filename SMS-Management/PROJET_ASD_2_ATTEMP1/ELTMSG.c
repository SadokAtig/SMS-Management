#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include "ELTPRIM_MSG.h"
#include "ELTMSG.h"
ELEMENT_MSG element_msgCreer (void)
{
    ELEMENT_MSG L;
    L = (ELEMENT_MSG) malloc(sizeof(MESSAGE));
    return L;
}
//-----------------------------------------------
void element_msgDetruire (ELEMENT_MSG L)
{
    free (L);
}
//----------------------------------------------

void element_msgLire(ELEMENT_MSG* elt)
{
    int j;

int x = 0;

do{
     printf(" \n Donnez votre numero svp  :  ");
    fflush(stdin);
    fgets((*elt)->recepeteur,9,stdin);
     if ((*elt)->recepeteur[0] == '5'|| (*elt)->recepeteur[0] == '2'|| (*elt)->recepeteur[0] == '9'){
        x = 1 ;}

}while(strlen((*elt)->recepeteur) != 8  || (x ==0 )); //((*elt)->numero[j]<'a')|| ((*elt)->numero[j]>'z')|| ((*elt)->numero[j]<'A')|| ((*elt)->numero[j]>'Z') ) ;

   LISTE_SMS s1 = liste_smsCreer();
    ELEMENT_SMS s2 = element_smsCreer();
   element_smsLire(&s2);
   inserer_sms(s1,s2,1);
    (*elt)->msg = s1 ;
   liste_smsAfficher((*elt)->msg);

   date_msg(&(*elt)->date_envoi,&(*elt)->heure_envoi);




}

//-----------------------------------------------

void element_msgAfficher(ELEMENT_MSG elt)
{
       int i;
  // ELEMENT_SMS e =elt->msg->elements[i];
    printf("\n recepeteur = %s  ",elt->recepeteur);
    liste_smsAfficher(elt->msg);
     date_afficher(elt->date_envoi,elt->heure_envoi);
}
//-------------------------------------------------

void element_msgAffecter(ELEMENT_MSG* e1, ELEMENT_MSG e2)
{
   *e1 = e2 ;
}
//---------------------------------------------------

void element_msgCopier(ELEMENT_MSG *e1 , ELEMENT_MSG e2)
{
 ((*e1)->prix, e2->prix);

}
//--------------------------------------------------------

int element_msgComparer(ELEMENT_MSG e1, ELEMENT_MSG e2)
{
    return ((e1->prix)-(e2->prix)) ;
}
//--------------------------------------------------------
void date_msg(DATE *d,HEURE *h ){
  time_t now;

  // Renvoie l'heure actuelle
  time(&now);
  now=time(NULL);
  // Convertir au format heure locale
  printf(" \n Aujourd'hui est : %s", ctime(&now));
  struct tm *local = localtime(&now);
  (*h).heure = local->tm_hour;
  (*h).minute = local->tm_min;
  (*h).seconde = local->tm_sec;
  (*d).jour = local->tm_mday;
  (*d).mois = local->tm_mon + 1;
  (*d).annee = local->tm_year + 1900;
  //printf("L'heure : %02d:%02d:%02d\n", h.heure, h.minute, h.seconde);
  // Afficher la date courante
 // printf("La date : %02d/%02d/%d\n", d.jour,d.mois ,d.annee );

}
//------------------------------------------------------------

void date_lire(DATE *d ){


 printf("\n donner le jour :  ");
  scanf("%i",&(*d).jour);
 printf("\n donner le mois :  ");
  scanf("%i",&(*d).mois);
 printf("\n donner l annee : ");
 scanf("%i",&(*d).annee);
}




//----------------------------------------------------------------
void date_afficher(DATE  d , HEURE h ){

  printf(" \n L'heure : %02d:%02d:%02d\n", h.heure, h.minute, h.seconde);
  // Afficher la date courante
 printf(" \n La date : %02d/%02d/%d\n", d.jour,d.mois ,d.annee );

}
//--------------------------------------------------------------------
int comparer_date (DATE d1,DATE d2 ){

int i;
if (d1.annee == d2.annee){

   if (d1.mois == d2.mois){

 if (d1.jour == d2.jour){

    return 0 ;
}
else if (d1.jour > d2.jour){
    return 1 ;
}
    else
        return -1; // com
}
    else if (d1.mois > d2.mois){

        return 1;
    }
     else
        return -1 ;
} else if(d1.annee>d2.annee){

         return 1 ;
}
else
    return -1 ; }
//------------------------------------------------------

