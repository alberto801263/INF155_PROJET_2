/*******************************************************************************
   Ce module implémente les sous-programmes pour charger les points
   correspondant aux sites d'un diagramme de Voronoi à dessiner et pour
   l'affichage du diagramme et d'un chemin.

   Par		: Pierre Bélisle
   Révision : Francis Bourdeau
   Révision E20  : David Beaulieu - Encapsulation des modélisations

*******************************************************************************/
#include <stdio.h>

#include "m_interface.h"
#include "t_orthocentre.h"
#include "t_segment.h"

#include "winBGIm.h"
/*
   Cette fonction charge les sites du diagramme de Voronoi.
*/
t_erreur charger_graphe(ptr_graphe graphe, const char* nom_fichier)
{
	t_erreur retour = SUCCES;   //Le succès ou le code d'erreur retourné.

	FILE* fichier;             //Le fichier dans lesquels les sites seront lus.

	ptr_point2d un_point;        //Le point lu sur chaque ligne du fichier.

	double x;
	double y;

	//On tente d'ouvrir le fichier contenant les points.
	fopen_s(&fichier, nom_fichier, "rt");

	if (fichier)
	{
		//Lorsque l'ouverture fonctionne,
		//On recupère tous les points contenus dans le fichier, et, 
		//On tente de les ajouter au graphe.
		while (!feof(fichier))
		{
			fscanf_s(fichier, "%lf%lf", &x, &y);

			un_point = initialiser_point(x, y);
			ajouter_site(graphe, un_point);

		}
		fclose(fichier);

	}

	// L'ouverture n'a pas fonctionné, on ignore réellement pourquoi mais 
	// c'est probablement qu'il est absent du répertoire courant.
	else
	{
		retour = ERREUR_OUVERTURE_FICHIER;
	}



	return retour;
}



static void afficher_sites(ptr_graphe graphe)
{
	t_point2d* un_point;        // Chaque point du graphe.

	int i; // Itérateur;

	int x1;  // (x1,y1) et (x2,y2) en pixels pour l'affichage d'un segment.
	int y1;
	int x2;
	int y2;

	int nb_pts;  // Le nombre de points dans la liste.

	setcolor(COULEUR_SITE);
	setfillstyle(SOLID_FILL, COULEUR_SITE);

	nb_pts = obtenir_nb_elements(getListeSites(graphe));

	for (i = 0; i < nb_pts; ++i)
	{
		// On obtient les données du site courant.
		un_point = (t_point2d*)consulter_ieme_element(getListeSites(graphe), i);

		x1 = (int) getX(un_point);
		y1 = (int) getY(un_point);

		x2 = (int) getX(un_point) + 5;
		y2 = (int) getY(un_point) + 5;

		// On affiche le site courant (un petit carré).
		bar(x1, y1, x2, y2);
	}

}

/*
	Priocédure locale qui affiche un segment de droite.
*/
void afficher_un_segment(const ptr_segment segment)
{
	int x1;  // (x1,y1) et (x2,y2) en pixels pour l'affichage d'un segment.
	int y1;
	int x2;
	int y2;


	// On affiche le segment courant.
	x1 = (int) getX(getPt1(segment));
	y1 = (int) getY(getPt1(segment));
	x2 = (int) getX(getPt2(segment));
	y2 = (int) getY(getPt2(segment));

	line(x1, y1, x2, y2);
}

/*
	Priocédure locale qui affiche tous les segments d'un graphe de la même couleur.
*/
static void afficher_segments(ptr_graphe graphe)
{


	ptr_segment un_segment;    // Obtenir chaque segment du graphe.
	int i;						// Itérateur;
	int nb_segs;				// Le nombre de segments dans la liste.

	setcolor(COULEUR_LIGNE);

	nb_segs = obtenir_nb_elements(getListeSegments(graphe));

	for (i = 0; i < nb_segs; ++i)
	{
		// On obtient les données du segments courant.
		un_segment = (ptr_segment)consulter_ieme_element(getListeSegments(graphe), i);
		afficher_un_segment(un_segment);
	}
}
/*

	Cette procédure dessine le diagramme de Voronoi voir
	tous les sites et les segments.

	Pour enlever du code à lire, nous avons enlevé le code qui génère
	un fichier en sortie tel que demandé dans tp2.

	Vous devez appeler cette procédure pour afficher le graphe.
*/
void afficher_graphe(ptr_graphe graphe)
{
	cleardevice();

	//On dessine le contour.
	setcolor(COULEUR_LIGNE);
	rectangle((int) getXmin(graphe),
		(int) getYmin(graphe),
		(int) getXmax(graphe),
		(int) getYmax(graphe));

	// On affiche tous les sites du graphe.
	afficher_sites(graphe);



	// On affiche tous les segments du graphe.
	afficher_segments(graphe);


}