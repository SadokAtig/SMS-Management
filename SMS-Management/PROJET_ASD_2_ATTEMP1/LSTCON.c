#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "ELTPRIM_CON.h"
#include "LSTPRIM_CON.h"
NOEUD_CONT noeud_contCreer(ELEMENT_CONT e)
{
    NOEUD_CONT n;
    n = (NOEUD_CONT)malloc(sizeof(structNoeudCONT));
    if (!n)
        printf("\nPlus d'espace");
    else
    {
        element_contAffecter(&n->info, e);
        n->suivant = NULL;
    }
    return n;
}

void noeud_contDetruire(NOEUD_CONT n)
{
    element_contDetruire(n->info);
    free(n);
}

int est_contVide(LISTE_CONT L)
{
    return (L->lg == 0);
}

int est_contSaturee(LISTE_CONT L)
{
    NOEUD_CONT temp;
    int saturee = 1; /* on suppose m�moire satur�e */
    temp = (NOEUD_CONT)malloc(sizeof(structNoeudCONT));
    if (temp != NULL)
    {
        saturee = 0; /* m�moire non satur�e */
        free(temp);
    }
    return saturee;
}

int liste_contTaille(LISTE_CONT L)
{
    return (L->lg);
}

int inserer_cont(LISTE_CONT L, ELEMENT_CONT e, int pos)
{
    int succee = 1;
    int i;
    NOEUD_CONT n, p, q; // c des pointeurs sur noeud c equivalent �:
    // structNoeud * n
    if (est_contSaturee(L))
    {
        //printf("\n Liste satur�e");
        succee = 0;
    }
    else
    {
        if ((pos < 1) || (pos > L->lg + 1))
        {
           // printf("\n Position invalide");
            succee = 0;
        }
        else
        {
            n = noeud_contCreer(e);
            /*on est s�r que la r�servation va se faire car la m�moire
            n'est pas satur�e*/
            if (pos == 1) /*insertion en t�te de liste*/
            {
                n->suivant = L->tete;
                L->tete = n;
            }
            else /*cas g�n�ral (pos > 1) */
            {
                q = L->tete;
                for (i = 1; i < pos; i++)
                {
                    p = q;
                    q = q->suivant;
                }
                // q d�signe l��l�ment de rang pos et p son pr�d�cesseur
                p->suivant = n;
                n->suivant = q;
            }
            (L->lg)++;
        }
    }
    return succee;
}

int supprimer_cont(LISTE_CONT L, int pos)
{
    int i;
    int succee = 1;
    NOEUD_CONT p, q;
    if (est_contVide(L))
    {
        printf("\nListe vide");
        succee = 0;
    }
    else
    {
        if ((pos < 1) || (pos > L->lg))
        {
            printf("\nPosition invalide");
            succee = 0;
        }
        else
        {
            q = L->tete;
            /*suppression en t�te de liste*/
            if (pos == 1)
                L->tete = L->tete->suivant;
            else
            { /*cas g�n�ral (pos > 1) */
                for (i = 1; i < pos; i++)
                {
                    p = q;
                    q = q->suivant;
                }
                p->suivant = q->suivant;
            }
            // q d�signe l��l�ment de rang pos et p son pr�d�cesseur
            noeud_contDetruire(q);
            (L->lg)--;
        }
    }
    return succee;
}

ELEMENT_CONT recuperer_cont(LISTE_CONT L, int pos)
{
    /* s'il ya une erreur on affiche un message et on
    retourne un element vide */
    ELEMENT_CONT elt = element_contCreer();
    int i;
    NOEUD_CONT p;
    if (est_contVide(L))
        printf("\n Liste vide");
    else
    {
        if ((pos < 1) || (pos > L->lg))
            printf("\n Position invalide");
        else
        {
            p = L->tete;
            for (i = 1; i < pos; i++)
                p = p->suivant;
            element_contAffecter(&elt, p->info);
        }
    }
    return (elt);
}

LISTE_CONT liste_contCreer(void)
{
    LISTE_CONT L;
    L = (LISTE_CONT)malloc(sizeof(laStructCONT));
    if (!L)
        printf("\nProbl�me de m�moire");
    else
    {
        L->lg = 0;
        L->tete = NULL; /* initialiser la t�te */
    }
    return (L);
}

void liste_contDetruire(LISTE_CONT L)
{
    int i;
    NOEUD_CONT p, q;
    q = L->tete;
    for (i = 1; i <= L->lg; i++)
    {
        p = q;
        q = q->suivant;
        noeud_contDetruire(p);
    }
    free(L);
}

void liste_contAfficher(LISTE_CONT L)
{
    int i = 1;
    NOEUD_CONT p;
    p = L->tete;
    for (i = 1; i <= L->lg; i++)
    {
        element_contAfficher(p->info);
        p = p->suivant;
    }
}

LISTE_CONT liste_contCopier(LISTE_CONT L)
{
    LISTE_CONT LR = liste_contCreer();
    int i;
    ELEMENT_CONT elt;
    for (i = 1; i <= L->lg; i++)
    {
        elt = element_contCreer();
        element_contCopier(&elt, recuperer_cont(L, i));
        inserer_cont(LR, elt, i);
    }
    return LR;
}

int liste_contComparer(LISTE_CONT L1, LISTE_CONT L2)
{
    int test = 1;
    int i = 1;
    if (liste_contTaille(L1) != liste_contTaille(L2))
        test = 0;
    while ((i <= liste_contTaille(L1)) && (test))
    {
        if (element_contComparer(recuperer_cont(L1, i), recuperer_cont(L2, i)) != 0)
            test = 0;
        i++;
    }
    return test;
}
