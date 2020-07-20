/*
 *  Création : Francis Bourdeau
 *  Fichier  : liste.c
 *
 *
 *  Ce module contient des fonctions utilitaires permettant de manipuler une
 *  liste générique. Ceci implique que le contenu d'un élément est nécessairement un 
 *  pointeur générique (void*).
 *
 */
#include "t_liste.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/******************************************************************************/
/*                  DEFINITIONS DE TYPES ET DE CONSTANTES                     */
/******************************************************************************/

// Une case non-utilisée.
#define CASE_VIDE  NULL

struct t_liste {
	int		nb_donnees;
	int		capacite;
	void** donnee;
};

/******************************************************************************/
/*                  DÉCLARATION DES FONCTIONS PRIVÉES                         */
/******************************************************************************/

//
// Permet de décaller les éléments du tableau lors de l'ajout ou le retrait d'un
// élément.
//
static void decaller_droite(ptr_liste une_liste, int indice_depart);
static void decaller_gauche(ptr_liste une_liste, int indice_depart, int indice_fin);



/******************************************************************************/
/*          IMPLÉMENTATIONS DES FONCTIONS PUBLIQUES ET PRIVÉES                */
/******************************************************************************/

//
// Cette fonction permet d'allouer la mémoire d'une liste et de l'initialiser comme
// étant vide.
//
ptr_liste creer_liste(int capacite)
{
	// On crée la liste
	ptr_liste nouvelle_liste = (ptr_liste) malloc(sizeof(struct t_liste));
    if(nouvelle_liste != NULL)
    {
    
		// On crée le tableau de données
		nouvelle_liste->donnee = (void**) malloc(capacite * sizeof(void*));
        if( nouvelle_liste->donnee != NULL)
        {
            nouvelle_liste->capacite    = capacite;
            nouvelle_liste->nb_donnees  = 0;
			memset(nouvelle_liste->donnee, CASE_VIDE, capacite * sizeof(void*));
        }
    }
    return nouvelle_liste;
}


//
// Cette fonction libère la mémoire de tous les elements d'une liste et
// libère la liste elle - même.
//
void detruire_liste(ptr_liste une_liste)
{
    free(une_liste->donnee);
    free(une_liste);
}

//
// Cette fonction retourne le nombre d'éléments utilisées dans la liste.
//
int obtenir_nb_elements(ptr_liste une_liste)
{
	return une_liste->nb_donnees;
}



//
// Cette fonction ajoute un element au début de la liste.
//
void ajouter_debut(ptr_liste une_liste, void* element)
{
	//On vérifie s'il y a sufisament d'espace dans la liste.
    if(une_liste->nb_donnees < une_liste->capacite)
    {
		//On crée une case libre pour le nouvel element.
        decaller_droite(une_liste, 0);

		//On ajoute le nouvel element.
        une_liste->donnee[0] = element;
        une_liste->nb_donnees++;
    }
}

//
// Cette fonction ajoute un element en fin de la liste.
//
void ajouter_fin(ptr_liste une_liste, void* element)
{
	//On vérifie s'il y a sufisament d'espace dans la liste.
    if(une_liste->nb_donnees < une_liste->capacite)
    {
		//On ajoute le nouvel element.
        une_liste->donnee[une_liste->nb_donnees] = element;
        une_liste->nb_donnees++;
    }
}

// 
// Cette fonction ajoute un element dans la liste à la position désirée
// 
void ajouter_ieme_position(ptr_liste une_liste, void* element, int position)
{
	//On vérifie s'il y a sufisament d'espace dans la liste.
    if(une_liste->nb_donnees < une_liste->capacite && 
       0 <= position && position <= une_liste->nb_donnees)
    {
		//On crée une case libre pour le nouvel element.
        decaller_droite(une_liste, position);

		//On ajoute le nouvel element.
        une_liste->donnee[position] = element;
        une_liste->nb_donnees++;
    }
}


//
// Cette fonction retourne l'element dans la liste à la position désirée
// sans le retiré.
//
void* consulter_ieme_element(ptr_liste une_liste, int position)
{
	return une_liste->donnee[position];
}


//
// Cette fonction retirer un element au début de la liste.
//
void* retirer_debut(ptr_liste une_liste)
{
    void* element = une_liste->donnee[0];
    decaller_gauche(une_liste, 1, une_liste->nb_donnees-1);
    une_liste->nb_donnees--;

    return element;
}



//
// Cette fonction retirer un element en fin de la liste.
//
void* retirer_fin(ptr_liste une_liste)
{
    int indice_fin;
	void* element;

    indice_fin = une_liste->nb_donnees - 1;
    element = une_liste->donnee[indice_fin];

    une_liste->donnee[indice_fin] = CASE_VIDE;
    une_liste->nb_donnees--;

    return element;
}


//
// Cette fonction retirer un element à la position voulue.
//
void* retirer_ieme_position(ptr_liste une_liste, int position)
{
	void* element = une_liste->donnee[position];
    decaller_gauche(une_liste, position + 1, une_liste->nb_donnees-1);
    une_liste->nb_donnees--;
    return element;
}



//
// Permet de décaller les éléments du tableau lors de l'ajout ou le retrait d'un
// élément.
//
static void decaller_droite(ptr_liste une_liste, int indice_depart)
{
    int i_ecriture;
    int i_lecture;
    for(i_ecriture = une_liste->nb_donnees; i_ecriture >= indice_depart + 1; i_ecriture--)
    {
        i_lecture = i_ecriture - 1;
        une_liste->donnee[i_ecriture] = une_liste->donnee[i_lecture];
    }
}

static void decaller_gauche(ptr_liste une_liste, int indice_depart, int indice_fin)
{
    int i_ecriture;
    int i_lecture;
    for(i_lecture = indice_depart; i_lecture <= une_liste->nb_donnees - 1; i_lecture++)
    {
        i_ecriture = i_lecture - 1;
        une_liste->donnee[i_ecriture] = une_liste->donnee[i_lecture];
    }

    une_liste->donnee[indice_fin] = CASE_VIDE;
}

