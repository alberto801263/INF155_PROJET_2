/*****************************************************************************
  Création : Francis Bourdeau
  Révision : David Beaulieu  (Encapsulation de la structure)
  Fichier  : liste.h

  Ce module contient des fonctions utilitaires permettant de manipuler une
  liste doublement chainée générique. Ceci implique que le contenu d'un
  element est nécessairement un pointeur générique (void*).

  Les services offerts sont les suivants:

      - creer_liste				: Permet de créer une nouelle liste vide.
      - detruire_liste			: Permet de détruire tous les elements de la 
								  liste et la liste elle-même.

      - ajouter_debut           : Permet d'ajouter un élément en tête de liste.
	  - ajouter_fin				: Permet d'ajouter un élément en queue de liste.
	  - ajouter_ieme_position	: Permet d'ajouter un élément à la position 
								  voulue dans la liste.

	  - consulter_ieme_position	: Permet de récupérer l'élément à la position 
								  voulue.

	  - obtenir_nb_elements		: Détermine le nombre d'éléments dans la liste.

	  - retirer_debut           : Permet de retirer un élément en tête de liste.
	  - retirer_fin				: Permet de retirer un élément en queue de liste.
	  - retirer_ieme_position	: Permet de retirer un élément à la position 
								  voulue dans la liste.

*******************************************************************************/
#ifndef __INF155_LISTE_STATIQUE__
#define __INF155_LISTE_STATIQUE__



/******************************************************************************/
/*                  DEFINITIONS DE TYPES ET DE CONSTANTES                     */
/******************************************************************************/

//
//Cette liste générique peut contenir l'adresse de n'importe quel objet.
//
typedef struct t_liste* ptr_liste;


/******************************************************************************/
/*                  DÉCLARATION DES FONCTIONS PUBLIQUES                       */
/******************************************************************************/
/*
 *  CREER_LISTE
 *
 *  Cette fonction permet d'allouer la mémoire d'une liste et de l'initialiser comme
 *  étant vide.
 *
 *
 *  Paramètres:
 *      - capacite : Le nombre d'élément pouvant être conservée dans la liste.
 *
 *  Retour :
 *      - Le pointeur vers la nouvelle liste
 */
ptr_liste creer_liste(int capacite);



/*
 *  DETRUIRE_LISTE
 *
 *  Cette fonction libère la mémoire de tous les elements d'une liste et
 *  libère la liste elle-même.
 *
 *  Paramètres:
 *      - une_liste : la liste à supprimer.
 *
 *  Retour :
 *      - Aucun
 */
void detruire_liste(ptr_liste une_liste);


/*
 *  OBTENIR_NB_ELEMENTS
 *
 *  Cette fonction retourne le nombre d'éléments utilisées dans la liste.
 *
 *  Paramètres:
 *      - une_liste : la liste à consulter.
 *
 *  Retour :
 *      - Aucun
 */
int obtenir_nb_elements(ptr_liste une_liste);



/*
 *  AJOUTER_DEBUT
 *
 *  Cette fonction ajoute un element au début de la liste.
 *
 *  Paramètres:
 *      - une_liste : la liste dans laquelle on ajoute un element.
 *      - element   : le contenu conservé dans le nouveau element.
 *
 *  Retour :
 *      - Aucun
 */
void ajouter_debut(ptr_liste une_liste, void* element);


/*
 *  AJOUTER_FIN
 *
 *  Cette fonction ajoute un element en fin de la liste.
 *
 *  Paramètres:
 *      - une_liste : la liste dans laquelle on ajoute un element.
 *      - element   : le contenu conservé dans le nouveau element.
 *
 *  Retour :
 *      - Aucun
 */
void ajouter_fin(ptr_liste une_liste, void* element);


/*
 *  AJOUTER_IEME_POSITION
 *
 *  Cette fonction ajoute un element dans la liste à la position désirée
 *
 *  Paramètres:
 *      - une_liste : la liste dans laquelle on ajoute un element.
 *      - element   : le contenu conservé dans le nouveau element.
 *		- position  : la position où ajouter le nouvel élement.
 *
 *  Retour :
 *      - Aucun
 */
void ajouter_ieme_position(ptr_liste une_liste, void* element, int position);


/*
 *  CONSULTER_IEME_POSITION
 *
 *  Cette fonction retourne l'element dans la liste à la position désirée
 *  sans le retiré.
 *
 *  Paramètres:
 *      - une_liste : la liste dans laquelle on ajoute un element.
 *		- position  : la position où ajouter le nouvel élement.
 *
 *  Retour :
 *      - L'adresse pointant sur l'élément consultée.
 */
void* consulter_ieme_element(ptr_liste une_liste, int position);



/*
 *  RETIRER_DEBUT
 *
 *  Cette fonction retirer un element au début de la liste.
 *
 *  Paramètres:
 *      - une_liste : la liste dans laquelle on retire un element.
 *
 *  Retour :
 *      - le contenu conservé dans l'element retiré.
 */
void* retirer_debut(ptr_liste une_liste);


/*
 *  RETIRER_FIN
 *
 *  Cette fonction retirer un element en fin de la liste.
 *
 *  Paramètres:
 *      - une_liste : la liste dans laquelle on retire un element.
 *
 *  Retour :
 *      - le contenu conservé dans l'element retiré.
 */
void* retirer_fin(ptr_liste une_liste);


/*
 *  RETIRER_IEME_POSITION
 *
 *  Cette fonction retire un element dans la liste à la position désirée
 *
 *  Paramètres:
 *      - une_liste : la liste dans laquelle on retirer un element.
 *		- position  : la position où ajouter le nouvel élement.
 *
 *  Retour :
 *      - le contenu conservé dans l'element retiré.
 */
void* retirer_ieme_position(ptr_liste une_liste, int position);


#endif
