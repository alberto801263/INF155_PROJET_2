/*****************************************************************************
 Ce programme permet de cr�er un diagramme de Voronoi � partir d'un ensemble de
 points plac�s dans un fichier.

 Par		: Frederick Henri
 Adaptation	: Francis Bourdeau
 R�vision	: Pierre B�lisle
 R�vision E20  : David Beaulieu - Encapsulation des concept mod�lis�

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

// Limites de l'espace allou� au graphe.
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

	Cette fonction demarre le mode graphique et cr�e la console graphique.

	Param�tre :
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
	//int retour;             // L'�tat de succ�s/d'�chec des diff�rentes
							// �tapes de l'application.


	//ptr_graphe un_graphe;    // Le diagramme de Voronoi � cr�er

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
	// On tente de charger les donn�es dans le graphe.
	if (retour = charger_graphe(un_graphe, NOM_FICHIER) != SUCCES)
	{
		printf("%s\n", MESSAGES_ERREURS[retour]);
		return EXIT_FAILURE;
	}

	// On d�marre la recherche du nouveau chemin optimal.
	else
	{
		// On cr�e le diagramme de voronoi et on l'affiche.
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
// Cette fonction cr�e la fen�tre dans laquelle le diagramme sera affich�.
//
//t_erreur initialiser_mode_graphique(void)
//{
//	// On initialise le mode graphique.
//	int gdriver = DETECT, gmode;
//	initgraph(&gdriver, &gmode, "");
//
//	// On retourne si l'op�ration a fonctionn� ou non.
//	return (graphresult() == grOk) ? (SUCCES) : (ERREUR_GRAPHIQUE);
//}
