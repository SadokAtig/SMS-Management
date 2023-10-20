#include <stdio.h>
#include <stdlib.h>
#include "PROJET_SDD.h"

ELEMENT_CONT lePlusContacte(LISTE_MSG L1, LISTE_CONT L2);
LISTE_CONT jamaisContactes(LISTE_MSG L1, LISTE_CONT L2);
int nb_msg(LISTE_MSG L2 , ELEMENT_CONT e);
LISTE_MSG messages_D1_D2(LISTE_MSG L, DATE D1, DATE D2);
ELEMENT_MSG messageLePlusLong(LISTE_MSG L);
int nb_sms(LISTE_SMS s );
int sms_cost(LISTE_SMS s );
//---------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------
//*-*-*-*-**--*-*-*-*-**--**-*-*--**-*--**-*--*-*-*-*-*-*-*-*-**--*-*-**--*-*-*-*-*-*-*-*

//-------------------------------------------------------------------------------
ELEMENT_CONT lePlusContacte(LISTE_MSG L1, LISTE_CONT L2){
ELEMENT_CONT s = element_contCreer();
ELEMENT_CONT y = element_contCreer();
NOEUD_CONT n  ;
NOEUD_MSG m ;
n=L2->tete;
m = L1->tete;
int i , j;
int max = 0 ;
int max1=0;

for (i=1 ;i<=L2->lg;i++){

    for (j=1 ;j<=L1->lg;j++){

        if(strcmp(recuperer_msg(L1,j)->recepeteur,recuperer_cont(L2,i)->numero) == 0){

                max1++;
              }
              else {
                max1=0;

              }

            if (max1 > max){

                max  = max1 ;
                strcpy(&s->numero,recuperer_cont(L2,i)->numero);
                 strcpy(&s->email,recuperer_cont(L2,i)->email);
                  strcpy(&s->nom,recuperer_cont(L2,i)->nom);
             element_contAfficher(s);

            }
             m=m->suivant;
             }

            n=n->suivant;
            }

return s ;
        }
//-------------------------------------------------------------------------------------
int nb_msg(LISTE_MSG L2 , ELEMENT_CONT e){
        int i , nb = 0  ;
        NOEUD_MSG n ;
        n = L2->tete;
        for(i=1;i<=L2->lg;i++){
        if(strcmp(n->info->recepeteur,e->numero) == 0)    {

             nb=nb+i;

            }

         n = n->suivant;

        }

        return nb;
        }
//------------------------------------------------------------------
int nb_sms(LISTE_SMS s ){
            int i , n=0; // permet de compter le nombre de sms
            for(i=1;i<=s->lg;i++){

               n=n+s->elements[i]->taille;
            }

            return n ;
        }
//-----------------------------------------------------------------------
int sms_cost(LISTE_SMS s ){
 int i , max=0;
 float cost = 0.05;
    for(i=1;i<=s->lg;i++){
        if(nb_sms(s->elements[i]->texte)> max ){

            cost = cost*i;
        }

    }

   return cost;
}

//--------------------------------------------------------------------
LISTE_CONT jamaisContactes(LISTE_MSG L1, LISTE_CONT L2){
   LISTE_CONT no = liste_contCreer();

   int i ;
   for (i=1;i<=L2->lg;i++){

    if ( nb_msg(L1,recuperer_cont(L2,i))==0){

       inserer_cont(no,recuperer_cont(L2,i),1);
    }
   }

return no ;

}
//----------------------------------------------------------------------------
LISTE_MSG messages_D1_D2(LISTE_MSG L, DATE D1, DATE D2){
NOEUD_MSG n ;
LISTE_MSG L1 = liste_msgCreer();
n = L->tete;
DATE d1,d2;
int i , pos = 1 ;
for(i=1;i<=L->lg;i++){

   if(comparer_date(n->info->date_envoi,d1 )== 1 && comparer_date(n->info->date_envoi,d2 )== -1  ){
    inserer_msg(L1,recuperer_msg(L,i),pos);
    pos ++ ;}
// inetrvalle des dates
}
n = n->suivant;
return L1;
}
//-----------------------------------------------------------------------------
ELEMENT_MSG messageLePlusLong(LISTE_MSG L){
ELEMENT_MSG e = element_msgCreer();
int i , j , max=0,n;
for(i=1;i<=L->lg;i++){

    n = nb_sms(recuperer_msg(L,i)->msg); // on faire appel ala fonction nb sms
                                          // permet de calulcer le nombre de sms

    if(n > max ){      // on verifie avec le max

        max = n;
        element_msgAffecter(&e,recuperer_msg(L,i));
    }
}
return e ;
}
//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------
//*-*-*-*-**--*-*-*-*-**--**-*-*--**-*--**-*--*-*-*-*-*-*-*-*-**--*-*-**--*-*-*-*-*-*-*-*
int main()
{
    LISTE_CONT L= liste_contCreer();
    LISTE_MSG L1 = liste_msgCreer();
    ELEMENT_CONT e;
    ELEMENT_MSG e1 ;
    ELEMENT_SMS e2 ;
    LISTE_SMS s = liste_msgCreer();
    DATE D1 , D2 ;
    int x ,y;
    int i ;
     FILE *fpReadFile;
    printf("                                                 ///************//   The SMS messaging service in C   ///************//      ");
    printf(" \n------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
    printf ("----------- welcome to our project don't forget------- ******  ENJOY!!!  ******");
    printf("---------------- press your lucky number to check ower application : ");
    scanf("%i",&x);
 system("cls");



do{
printf("\n");
printf("\n");
printf("\n");
printf("\n");
printf("------**------------------------------------------------------------------------------------------------------------------------------------------------------------------");
printf("\n  ------------------------------------------------- -------------  REPERTOIRE --------- --------------------------------------------------------------------------------");
printf("\n*-*-*-*-*-*-*-**-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-**-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-");
printf("\n");
printf("\n");
printf("\n");
printf("**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**-**--**--**--**--**--**--**--**--**--**--**-");
printf("***   \n  1 - Ajouter un contact  ");
printf("***   \n  2 - Afficher la repertoire  ");
printf(" ***    \n  3 - Afficher le contact  le plus contacter en terme de message  ");
printf(" ****     \n 4 - Liste des contact qui n'ont ete jamais contacter   ");

printf("\n**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**-**--**--**--**-**");
printf("\n");
printf("\n");
printf("------**------------------------------------------------------------------------------------------------------------------------------------------------------------------");
printf("\n ---------- ------------------------------------------------------ BOITE MESSAGERIE ------------------------------ -----------------------------------------------------");
printf("\n*-*-*-*-*-*-*-**-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-**-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-***-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*");
printf(" *** \n  5 - Envoyer un message  ");
printf("***  \n 6 - Afficher boite messagerie ");
printf(" ***  \n  7 - Affichage  tous les messages qui ont ete envoyes dns l'intervalle D1 et D2  ");
printf(" ***   \n  8  - Afficher le message le plus long en terme de caractere  ");
printf("\n**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**-**--**--**-**--**--**--**--**--**--**--**");
printf("\n");
printf("\n");
printf("\n ---------- ------------------------------------------------------  N-GRAMME  ---------------------------- --------------------------------------------------------------");
printf("\n------**----------------------------------------------------------------------------------------------------------------------------------------------------------------");
printf("\n 9 - afficher les unigrames ");
printf("\n  10 - afficher les bigrames ");
printf("\n   11 - afficher le repertoire automatiquement");
printf("\n**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-");
printf("\n");
printf("\n");
printf("\n");
printf("\n pick something please :) :  ");
printf("\n");
 scanf("%i",&i);

 switch(i){
 case 1 : e =  element_contCreer();
          element_contLire(&e);
          inserer_cont(L,e,1);
        break;
case 2 :  liste_contAfficher(L);

       break;
case 3 :  element_contAfficher(lePlusContacte(L1,L));
        break;
case 4 :  liste_contAfficher(jamaisContactes(L1,L));
         break;
case 5 :  e1 =  element_msgCreer();
          element_msgLire(&e1);
          inserer_msg(L1,e1,1);
        break;
case 6 :  liste_msgAfficher(L1);

       break;
case 7 :      printf("\n donner la premiere date svp : ");
              date_lire(&D1);
              printf("\n donner la deuxieme date svp : ");
              date_lire(&D2);
           liste_msgAfficher(messages_D1_D2(L1,D1,D2));
        break;
case 8 :  element_msgAfficher(messageLePlusLong(L1));
       break;
case 9:    printf(" \n le nombre du message est : %i",nb_msg(L1,e));
       break;

case 10 :
       break;
case 11 :
  fpReadFile = fopen("c.txt", "r");
  printf("\n");
  if(fpReadFile)
  {
    printf("\nReading File...\n\n");
    while ((y = getc(fpReadFile)) != EOF)
    putchar(y);
    fclose(fpReadFile);
  }
  else
  {
    printf("\nError: Unable to open the file for Reading.");
  }

 }
break ;
}while(i!=0);

   return 0;
}
