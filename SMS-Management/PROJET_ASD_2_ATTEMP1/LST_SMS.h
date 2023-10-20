#ifndef LST_SMS_H_INCLUDED
#define LST_SMS_H_INCLUDED
#include "ELT_SMS.h"
#define LongMax 8 /* longueur maximale d'une liste de SMS */
typedef struct
{
ELEMENT_SMS elements[LongMax]; /* tableau statique */
int lg; /* taille logique de la liste */
}
laStructSMS,*LISTE_SMS;


#endif // LST_SMS_H_INCLUDED
