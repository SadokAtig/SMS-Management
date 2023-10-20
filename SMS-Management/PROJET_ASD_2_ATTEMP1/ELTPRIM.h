#ifndef ELTPRIM_H_INCLUDED
#define ELTPRIM_H_INCLUDED
#include "ELT_SMS.h"
ELEMENT_SMS element_smsCreer (void);   // tabdel asami les prim lil sms expl : element_smsdetruire  ........
void element_smsDetruire (ELEMENT_SMS );
void element_smsAffecter(ELEMENT_SMS * , ELEMENT_SMS );
void element_smsCopier(ELEMENT_SMS * , ELEMENT_SMS );
void element_smsLire(ELEMENT_SMS * );
void element_smsAfficher(ELEMENT_SMS );
int element_smsComparer(ELEMENT_SMS , ELEMENT_SMS );


#endif // ELTPRIM_H_INCLUDED
