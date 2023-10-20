#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "LSTPRIM_MSG.h"
#include "ELTPRIM_MSG.h"
#include "ELTMSG.h"
#include "LST_MSG.h"

NOEUD_MSG noeud_msgCreer(ELEMENT_MSG e)
{
  NOEUD_MSG n;
  n =(NOEUD_MSG)malloc(sizeof(structNoeudMSG));
  if(!n)
    printf ("\nPlus d'espace");
  else
  {
    element_msgAffecter(&n->info, e);
    n->suivant = NULL;
    n->precedent = NULL;
  }
 return n;
}


void noeud_msgDetruire(NOEUD_MSG n)
{
  element_msgDetruire(n->info);
  free(n);
}


int inserer_msg (LISTE_MSG L, ELEMENT_MSG e, int pos)
{
   int succee=1;
   int i;
   NOEUD_MSG n, p, q; /* c’est des pointeurs sur des neouds c’est équivalent à: structNoeud * n */
   if (est_msgSaturee(L))
   {
     printf ("\nListe saturée");
     succee=0;}
   else
   {
        if ((pos < 1) || (pos > L->lg + 1))
        {
         printf ("\nPosition invalide");
         succee=0;
        }
        else
        {
         n=noeud_msgCreer (e); /*on est sûr que la  réservation va se faire car la mémoire n'est pas saturée*/
            if (L->lg == 0) /* la liste est vide */
            {
             L->tete = n;
             L->queue = n;
            }
            else
            {
                if (pos == 1) /*insertion en tête de liste*/
                {
                 L->tete->precedent = n;
                 n->suivant=L->tete;
                 L->tete = n;
                }
                else
                {
                     if (pos == (L->lg +1)) /* ajout à la fin */
                    {
                     L->queue->suivant = n;
                     n->precedent = L->queue;
                     L->queue = n;
                    }
                    else
                    {
                     q= L->tete;
                        for (i=1; i<pos; i++)
                        {
                         p = q;
                         q = q->suivant;
                        }
                     /* q désigne l’élément de rang pos et p son prédécesseur*/
                     p->suivant=n;
                     n->precedent =p;
                     n->suivant=q;
                     q->precedent =n;
                    }
                }
            }
         (L->lg)++;
        }
    }
 return succee;
}


int supprimer_msg (LISTE_MSG L, int pos )
{
    int i;
    int succee=1;
    NOEUD_MSG p, q;
    if (est_msgVide(L))
    {
     printf ("\nListe vide");
     succee=0;}
    else
    {
        if ((pos < 1) || (pos > L->lg))
        {
            printf ("\nPosition invalide");
            succee=0;
        }
        else
        {
            if (L->lg ==1) /* un seul element donc pos == 1*/
            {
                q=L->tete;
                L->tete = NULL;
                L->queue = NULL;
            }
            else
            {
                if (pos == 1) /*suppression en tête de liste*/
                {
                    q=L->tete;
                    L->tete=L->tete->suivant;
                    L->tete->precedent = NULL;
                }
                else
                {
                    if (pos == L->lg)
                    {
                        q=L->queue;
                        L->queue = L->queue->precedent;
                        L->queue->suivant = NULL;
                    }
                    else
                    {
                        q= L->tete;
                        for (i=1; i<pos; i++)
                        { p = q; q = q->suivant; }
                        /*q désigne l’élément de rang pos et p son prédécesseur*/
                        q->suivant->precedent = p;
                        p->suivant=q->suivant;
                    }
                }
            }
        noeud_msgDetruire(q);
        (L->lg)--;
        }
    }
  return succee;
}


int est_msgVide(LISTE_MSG L)
{
    return (L->lg == 0);
}

int est_msgSaturee(LISTE_MSG L)
{
    NOEUD_MSG temp;
    int saturee = 1; /* on suppose mémoire saturée */
    temp = (NOEUD_MSG)malloc(sizeof(structNoeudMSG));
    if (temp != NULL)
    {
        saturee = 0; /* mémoire non saturée */
        free(temp);
    }
    return saturee;
}

int liste_msgTaille(LISTE_MSG L)
{
    return (L->lg);
}


ELEMENT_MSG recuperer_msg(LISTE_MSG L, int pos)
{
    /* s'il ya une erreur on affiche un message et on
    retourne un element vide */
    ELEMENT_MSG elt = element_msgCreer();
    int i;
    NOEUD_MSG p;
    if (est_msgVide(L))
        printf("\nListe vide");
    else
    {
        if ((pos < 1) || (pos > L->lg))
            printf("\n Position invalide");
        else
        {
            p = L->tete;
            for (i = 1; i < pos; i++)
                p = p->suivant;
            element_msgAffecter(&elt, p->info);
        }
    }
    return (elt);
}

LISTE_MSG liste_msgCreer(void)
{
  LISTE_MSG  L;
    L = (LISTE_MSG)malloc(sizeof(laStructMSG));
    if (!L)
        printf("\nProblème de mémoire");
    else
    {
        L->lg = 0;
        L->tete = NULL; /* initialiser la tête */
    }
    return (L);
}

void liste_msgDetruire(LISTE_MSG L)
{
    int i;
    NOEUD_MSG p, q;
    q = L->tete;
    for (i = 1; i <= L->lg; i++)
    {
        p = q;
        q = q->suivant;
        noeud_msgDetruire(p);
    }
    free(L);
}

void liste_msgAfficher(LISTE_MSG L)
{
    int i = 1;
    NOEUD_MSG p;
    p = L->tete;
    for (i = 1; i <= L->lg; i++)
    {
        element_msgAfficher(p->info);
        p = p->suivant;
    }
}

LISTE_MSG liste_msgCopier(LISTE_MSG L)
{
    LISTE_MSG LR = liste_msgCreer();
    int i;
    ELEMENT_MSG elt;
    for (i = 1; i <= L->lg; i++)
    {
        elt = element_msgCreer();
        element_msgCopier(&elt, recuperer_msg(L, i));
        inserer_msg(LR, elt, i);
    }
    return LR;
}

int liste_msgComparer(LISTE_MSG L1, LISTE_MSG L2)
{
    int test = 1;
    int i = 1;
    if (liste_msgTaille(L1) != liste_msgTaille(L2))
        test = 0;
    while ((i <= liste_msgTaille(L1)) && (test))
    {
        if (element_msgComparer(recuperer_msg(L1, i), recuperer_msg(L2, i)) != 0)
            test = 0;
        i++;
    }
    return test;
}



