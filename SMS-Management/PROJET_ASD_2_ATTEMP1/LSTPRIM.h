#ifndef LSTPRIM_H_INCLUDED
#define LSTPRIM_H_INCLUDED
#include "ELT_SMS.h"
#include "LST_SMS.h"
LISTE_SMS liste_smsCreer(void); //tabdel asami les prim lil sms expl : liste_smsdetruire  ........
void liste_smsDetruire(LISTE_SMS);
int est_smsVide(LISTE_SMS);
int est_smsSaturee(LISTE_SMS);
int liste_smsTaille(LISTE_SMS);
ELEMENT_SMS recuperer_sms(LISTE_SMS,int);
int inserer_sms(LISTE_SMS, ELEMENT_SMS,int);
int supprimer_sms(LISTE_SMS, int);
void liste_smsAfficher(LISTE_SMS);
LISTE_SMS liste_smsCopier(LISTE_SMS);
int liste_smsComparer(LISTE_SMS, LISTE_SMS);


#endif // LSTPRIM_H_INCLUDED
