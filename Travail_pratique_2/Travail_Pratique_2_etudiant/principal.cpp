/*****************************************************************************
 Ce programme permet de créer un diagramme de Voronoi à partir d'un ensemble de
 points placés dans un fichier.

 Par		: Frederick Henri
 Adaptation	: Francis Bourdeau
 Révision	: Pierre Bélisle
 Révision E20  : David Beaulieu - Encapsulation des concept modélisé

*****************************************************************************/
#define _USE_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

//#include "t_graphe.h"
//#include "t_orthocentre.h"
//#include "t_point2d.h"

/*!!!!!!!!!!!!!!!!!!!!!!!1*/
//#include "winBGim.h"
//#include "m_interface.h"

/*!!!!!!!!!!!!!!!!!!!!1*/
//#include "t_erreur.h"

/*Nos fichier*/

/*POUQUOI*/
#include "geometrie/t_segment.h"

/***************************************************************************
							DEFINITION DE TYPES ET CONSTANTES
****************************************************************************/

// Limites de l'espace alloué au graphe.
#define XMIN    10
#define YMIN    10
#define XMAX    600
#define YMAX    400


// Nom du fichier des points a afficher.
#define NOM_FICHIER          "donnees/points.txt"
//#define NOM_FICHIER        "donnees/points_50.txt"
//#define NOM_FICHIER        "donnees/points_5.txt"
 
/**************************************************************************
									PROTOTYPES DE FONCTIONS
***************************************************************************/


/*
	INITIALISER_MODE_GRAPHIQUE

	Cette fonction demarre le mode graphique et crée la console graphique.

	Paramètre :
		Aucun.

	Valeur de retour :
		En cas de succes, elle retourne SUCCES, sinon elle retourne une des
		code d'erreurs de l'enum t_erreur.
*/
//t_erreur initialiser_mode_graphique(void);



/*************************************************************************/
/*                                PROGRAMME PRINCIPAL                    */
/*************************************************************************/
int main(void)
{
	/*TEST*/
	/********************************************************************/
	testInitialiserPoint();
	

	/********************************************************************/


	/*!!!!!!!!!1*/
	//int retour;             // L'état de succès/d'échec des différentes
							// étapes de l'application.


	//ptr_graphe un_graphe;    // Le diagramme de Voronoi à créer

	// On tente de passer en mode graphique.
	
	  /*!!!!!!!!!!!!!!!!ERREUR!!!!!!!!!!!!!!!!!!!!!*/
	//
	//if ((retour = initialiser_mode_graphique()) != SUCCES)
	//{
	//	printf("%s\n", MESSAGES_ERREURS[retour]);
	//	return EXIT_FAILURE;
	//}
	//
	
	
	
	/*
	// On initialise la taille limite du diagramme de voronoi.
	un_graphe = nouveau_graphe(XMIN, YMIN, XMAX, YMAX);
	if (un_graphe == NULL)
	{
		printf("%s\n", MESSAGES_ERREURS[ERREUR_ALLOCATION_MEMOIRE]);
		return EXIT_FAILURE;
	}
	*/

	/*
	// On tente de charger les données dans le graphe.
	if (retour = charger_graphe(un_graphe, NOM_FICHIER) != SUCCES)
	{
		printf("%s\n", MESSAGES_ERREURS[retour]);
		return EXIT_FAILURE;
	}

	// On démarre la recherche du nouveau chemin optimal.
	else
	{
		// On crée le diagramme de voronoi et on l'affiche.
		//mettre_a_jour_diagramme_voronoi(un_graphe);
		//imprimer_graphe(un_graphe);
		//afficher_graphe(un_graphe);

		// On ferme le graphe lorsque l'utilisateur appuie sur une touche.
		//getch_graph();
		//closegraph();
	}
	*/

	return EXIT_SUCCESS;
}



/*************************************************************************/
/*                                DEFINITIONS DE FONCTIONS               */
/*************************************************************************/

/*!!!!!!!!!!!!!!!ERREUR!!!!!!!!!!!!!!!!!!!!!!!!!1*/

//
// Cette fonction crée la fenêtre dans laquelle le diagramme sera affiché.
//
//t_erreur initialiser_mode_graphique(void)
//{
//	// On initialise le mode graphique.
//	int gdriver = DETECT, gmode;
//	initgraph(&gdriver, &gmode, "");
//
//	// On retourne si l'opération a fonctionné ou non.
//	return (graphresult() == grOk) ? (SUCCES) : (ERREUR_GRAPHIQUE);
//}
