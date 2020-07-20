/*****************************************************************************
Par			: Frederick Henri
Adaptation	: Francis Bourdeau
Révision	: Pierre Bélisle
Révision E20  : David Beaulieu - Encapsulation de la structure
Complété par : VOTRE NOM ICI

Ce module implémente un graphe permettant de generer un diagramme de
voronoi.	

*****************************************************************************/
#ifndef __T_GRAPHE__
#define __T_GRAPHE__

#include "t_point2d.h"
#include "t_segment.h"

#include "t_liste.h"
#include "t_erreur.h"

/************************************************************************
                          DEFINITIONS DE TYPES ET DE CONSTANTES                      
*************************************************************************/



/***************************************************************************/
/*								DECLARATIONS DE FONCTIONS			   	   */
/***************************************************************************/




/*
	Fonction qui permet d'écrire l'état d'un graphe dans un fichier texte
	Cette fonction est utile pour débuger votre travail.

	PARAMETRES :
		- ptr_graphe : Le graphe ou l'on ajoute le point.
 */
void imprimer_graphe(ptr_graphe un_graphe);

#endif