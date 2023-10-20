#ifndef ELTMSG_H_INCLUDED
#define ELTMSG_H_INCLUDED
#include "ELT_SMS.h"
#include "LST_SMS.h"
typedef struct
{
 int jour;
 int mois;
 int annee ;
}
DATE;                                // date et heure on stockage direct acces avec le  .
typedef struct
{
int heure;
int minute;
int seconde;
}
HEURE;
typedef struct
{
char recepeteur[9];
LISTE_SMS msg;
float prix;
 DATE date_envoi ;
HEURE heure_envoi;
}
MESSAGE,*ELEMENT_MSG;


#endif // ELTMSG_H_INCLUDED
