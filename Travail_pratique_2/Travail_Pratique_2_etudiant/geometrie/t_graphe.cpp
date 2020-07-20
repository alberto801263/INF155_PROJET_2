/*****************************************************************************
  Implémentation des méthodes utiles à l'algorithme de voronoi.

  Par: Frederick Henri
  Adaptation et commentaires de stratégie : Francis Bourdeau
  Révision : Pierre Bélisle
  Révision E20  : David Beaulieu - Encapsulation de la structure
  Complété par : VOTRE NOM ICI

Ce module implémente un graphe permettant de generer un diagramme de
voronoi.

*****************************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "t_graphe.h"


#include "t_orthocentre.h"

#include "utilitaire.h"
#include "constantes.h"


/*****************************************************************************
                     DEFINITION DE TYPES ET CONSTANTES
******************************************************************************/


/***************************************************************************
                          DÉCLARATION DE FONCTIONS PRIVEES     
***************************************************************************/
/*
    DISTANCE_SITE_PLUS_PROCHES
	Cette fonction retourne la distance du site le plus proche parmi 
    tous les sites du graphe.

    Paramètres :
        - ptr_graphe    : Le graphe.
        - ptr_point     : Le point de référence.

    Retour :
        Aucun
*/
static double distance_site_plus_proche(ptr_graphe graphe,
                                        ptr_point2d point);


/*
    METTRE_A_JOUR_ORTHOCENTRES

    Cette fonction calcule la liste des orthocentres valides et les ajoute
    au graphe.

    Paramètres :
        - ptr_graphe : Le graphe pour lequel on souhaite ajuster les orthocentres.	

    Retour :
        Aucun
*/
static void mettre_a_jour_orthocentres(ptr_graphe graphe);

/*
    METTRE_A_JOUR_SEGMENTS

    Fonction qui met à jour les segments du diagramme de Voronoi contenu
    dans le graphe.

    Paramètres :
    - ptr_graphe : Le graphe que l'on doit mettre à jour.

    Retour :
        Aucun

    ATTENTION : On suppose que le graphe a déjà été créé.
*/
static void mettre_a_jour_segments(ptr_graphe graphe);

/*
    MEME_COTE_SEGMENT

    Cette fonction vérifie si deux points sont du même côtés
    qu'un segment.

    Paramètres :
    - segment   : Le segment de référence.
    - ptr_p1    : Le premier point à analyser.
    - ptr_p2    : Le second point à analyser.

    Retour :
        Aucun
*/
static int meme_cote_segment(ptr_segment segment, 
                             ptr_point2d ptr_pt1, ptr_point2d ptr_pt2);

/* 
    SITES_DANS_ORTHOCENTRE

    Cette fonction verifie si les deux sites aux indices reçus 
    ont servis à créer un orthocentre.

    PARAMETRES :
        - indices : Les sites d'un orthocentre.
        - pt1     : L'indice du premier site a chercher.
        - pt2     : L'indice du second site a chercher.

    Retour :
        Cette fonction retourne TRUE si l'indice des deux sites reçus 
        appartiennent au tableau d'indices et FALSE sinon.
*/
static int sites_dans_orthocentre(ptr_orthocentre orthocentre, 
                                  int pt1, 
                                  int pt2);




/***************************************************************************
                            DEFINITION DE FONCTIONS PUBLIQUES               
****************************************************************************/


/*
	Fonction qui permet d'écrire l'état d'un graphe dans un fichier texte
	Cette fonction est utile pour débuger votre travail.

	PARAMETRES :
		- ptr_graphe : Le graphe ou l'on ajoute le point.
 */
void imprimer_graphe(ptr_graphe un_graphe)
{
	FILE* f_ortho = fopen("donnees/resultat_orthocentre.txt", "wt");
	FILE* f_arete = fopen("donnees/resultat_aretes.txt", "wt");

	fprintf(f_ortho, "X\t\t\tY\n");
	for (int i = 0; i < obtenir_nb_elements(un_graphe->liste_orthocentres); i++)
	{
		ptr_orthocentre o = (ptr_orthocentre)consulter_ieme_element(un_graphe->liste_orthocentres, i);
		fprintf(f_ortho, "%0.5lf\t%0.5lf\n", getX(getPoint(o)), getY(getPoint(o)));
	}

	fprintf(f_arete, "X1\t\t\tY1\t\t\tX2\t\t\tY2\n");
	for (int i = 0; i < obtenir_nb_elements(un_graphe->liste_segments); i++)
	{
		ptr_segment a = (ptr_segment)consulter_ieme_element(un_graphe->liste_segments, i);
		fprintf(f_arete, "%0.5lf\t%0.5lf\t%0.5lf\t%0.5lf\n", getX(getPt1(a)), getY(getPt1(a)), getX(getPt2(a)), getY(getPt2(a)));
	}

	fclose(f_ortho);
	fclose(f_arete);
}
/*****************************************************************************
                           DEFINITION DE FONCTIONS PRIVEES                    
******************************************************************************/


//
//  Cette fonction retourne la distance du site le plus proche parmi 
//  tous les sites du graphe.
//
static double distance_site_plus_proche(ptr_graphe graphe, 
                                        ptr_point2d  point)
{
    int i;                      // Pour parcourir tous les sites.
    int nb_sites;               // Le nombre de site dans le graphe.

    double distance_minimale;   // La distances entre le point
                                // et le site le plus proche.

    double distance_courante;   // La distances entre le point 
                                // et le chacun des sites.

    // Par defaut, le plus pres est a l'indice 0.
    distance_minimale = distance_entre_points(point, (ptr_point2d) consulter_ieme_element(graphe->liste_sites, 0));

    // On verifie la distance de tous les autres sites.
    nb_sites = obtenir_nb_elements(graphe->liste_sites);
    for (i = 1; i < nb_sites ; ++i)
    {
        distance_courante = distance_entre_points(point, (ptr_point2d) consulter_ieme_element(graphe->liste_sites, i));

        if (distance_courante < distance_minimale)
        { 
            distance_minimale = distance_courante;
        }
    }

    return distance_minimale;
}


//
//  Cette fonction calcule la liste des orthocentres.
//
static void mettre_a_jour_orthocentres(ptr_graphe graphe)
{
    int i, j, k;                    // Les itérateurs pour créer 
                                    // chaque triplets de sites.
    
    int nb_total_sites;             // Sites parmis le graphe.

    ptr_orthocentre un_orthocentre;  // Chacun de orthocentres créer.

    // Pour tous les couples possibles de 3 sites (i, j, k).
    nb_total_sites = obtenir_nb_elements(graphe->liste_sites);
    for (i = 0; i < nb_total_sites; ++i)
        for (j = i + 1; j < nb_total_sites; ++j)
            for (k = j + 1; k < nb_total_sites; ++k)
            {
                //On crée et on calcule la coordonnee de l'orthocentre.


				ptr_point2d p1 = (ptr_point2d) consulter_ieme_element(graphe->liste_sites, i);
				ptr_point2d p2 = (ptr_point2d) consulter_ieme_element(graphe->liste_sites, j);
				ptr_point2d p3 = (ptr_point2d) consulter_ieme_element(graphe->liste_sites, k);

                un_orthocentre = initialiser_orthocentre(i,j,k,p1, p2, p3);

                // Si les sites les plus pres de l'orthocentre sont les trois sites 
                // de l'orthocentre, alors l'orthocentre est valide.
                double d1 = distance_site_plus_proche (graphe, getPoint(un_orthocentre));
                double d2 = distance_entre_points(p1, getPoint(un_orthocentre));

                if (sont_egaux(d1 , d2))
                {
                    // On tente d'ajouter l'orthocentre a la fin de la liste.
                    ajouter_fin(graphe->liste_orthocentres, un_orthocentre);
                }
            }
}

//
//  Cette fonction retourne 1 si deux points sont du même côté d'un segment.
//
static int meme_cote_segment(ptr_segment   segment, 
                             ptr_point2d     ptr_pt1, 
							ptr_point2d     ptr_pt2)
{
    int meme_cote;          // Booleen à retourner.

    // On traite le cas ou le segment est horizontale.
    if (segment_est_horizontale(segment))
    {
        meme_cote = getY(getPt1(segment)) > getY(ptr_pt1) && 
                    getY(getPt1(segment)) > getY(ptr_pt2) ||
                    getY(getPt1(segment)) < getY(ptr_pt1) && 
                    getY(getPt1(segment)) < getY(ptr_pt2);
    }

    // On traite le cas ou le segment est verticale.
    else if (segment_est_verticale(segment))
    {
        meme_cote = getX(getPt1(segment)) > getX(ptr_pt1) && 
					getX(getPt1(segment)) > getX(ptr_pt2) ||
					getX(getPt1(segment)) < getX(ptr_pt1) &&
					getX(getPt1(segment)) < getX(ptr_pt2);
    }

    // On traite le cas ou le segment est une droite.
    else
    {
        // On trouve l'equation du segment à couper.
        double m = pente(getPt1(segment), getPt2(segment));
        double b = getY(getPt1(segment)) - m * getX(getPt1(segment));

        // On projet les deux points sur la droite.
        double y1_sur_segment = m * getX(ptr_pt1) + b;
        double y2_sur_segment = m * getX(ptr_pt2) + b;

        meme_cote = getY(ptr_pt1) < y1_sur_segment && 
					getY(ptr_pt2) < y2_sur_segment ||
					getY(ptr_pt1) > y1_sur_segment &&
					getY(ptr_pt2) > y2_sur_segment;
    }

    return meme_cote;
}

//
// Cette fonction refait la liste des aretes.
// Elle suppose que les orthocentres sont deja valides et a jour.
//
static void mettre_a_jour_segments(ptr_graphe graphe)
{
    int i;      // Pour itérer sur tout les 
    int j;      // couples d'orthocentres.
    int nb_total_orthocentres;

    ptr_orthocentre orthocentre_i;       // Les deux orthocentres utilisés
    ptr_orthocentre orthocentre_j;       // Pour former tous les couples.

    int ij_utilise;         // Pour vérifier si une médiatrice doit être
    int jk_utilise;         // calculée.
    int ik_utilise;
    int ajouter_arete;

    ptr_segment une_arete; // Les arêtes créées et ajoutées au graphe.


    // On parcourt tous les orthocentres pour créer
    // chaque couple d'orthocentre dans le graphe.
    nb_total_orthocentres = obtenir_nb_elements(graphe->liste_orthocentres);

     for (i = 0; i < nb_total_orthocentres; ++i)
    {
        // Au depart, il n'y a aucun cote commun entre le triangle de cet
        // orthocentre et le triangle des autres orthocentres.
        ij_utilise = jk_utilise = ik_utilise = FALSE;

        // On cree les liens entres les orthocentres ayant 2 points sur 3
        // identiques.
        orthocentre_i = (ptr_orthocentre) consulter_ieme_element(graphe->liste_orthocentres, i);

        // On crée les couples avec orthocentre i
        for (j = 0; j < nb_total_orthocentres; ++j)
        {
            if (j != i)
            {
                orthocentre_j = (ptr_orthocentre) consulter_ieme_element(graphe->liste_orthocentres, j);

                // On verifie si les orthocentres ont deux sites communs.
                ajouter_arete = FALSE;

                if (sites_dans_orthocentre(orthocentre_j, 
                                           getI(orthocentre_i), 
                                           getJ(orthocentre_i)))
                    ajouter_arete = ij_utilise = TRUE;

                else if (sites_dans_orthocentre(orthocentre_j, 
                                                getJ(orthocentre_i), 
                                                getK(orthocentre_i)))
                    ajouter_arete = jk_utilise = TRUE;

                else if (sites_dans_orthocentre(orthocentre_j, 
                                                getI(orthocentre_i),
                                                getK(orthocentre_i)))
                    ajouter_arete = ik_utilise = TRUE;

                // On créer l'arrête si nécessaire.
                if (ajouter_arete)
                {
                    une_arete = init_segment(getX(getPoint(orthocentre_i)),
                                             getY(getPoint(orthocentre_i)),
                                             getX(getPoint(orthocentre_j)), 
                                             getY(getPoint(orthocentre_j)));

                    couper_segment_trop_long(graphe, une_arete);
                    
                    if(!points_sont_identiques(getPt1(une_arete), getPt2(une_arete)))
                        ajouter_fin(graphe->liste_segments, une_arete);
                }
            }
        }

        if (!ij_utilise)
            ajouter_une_médiatrice(graphe, 
                                   getPoint(orthocentre_i), 
                                   getI(orthocentre_i), 
                                   getJ(orthocentre_i), 
                                   getK(orthocentre_i));

        if (!jk_utilise)
            ajouter_une_médiatrice(graphe, 
                                   getPoint(orthocentre_i), 
                                   getJ(orthocentre_i), 
                                   getK(orthocentre_i), 
                                   getI(orthocentre_i));

        if (!ik_utilise)
            ajouter_une_médiatrice(graphe, 
                                   getPoint(orthocentre_i), 
                                   getI(orthocentre_i),
                                   getK(orthocentre_i), 
                                   getJ(orthocentre_i));
    }
}


//
// Fonction qui verifie si deux points ont servi à créer un orthocentre.
//
static int sites_dans_orthocentre(ptr_orthocentre orthocentre, int pt1, int pt2)
{
    return (getI(orthocentre) == pt1 || getJ(orthocentre) == pt1 || getK(orthocentre) == pt1) &&
           (getI(orthocentre) == pt2 || getJ(orthocentre) == pt2 || getK(orthocentre) == pt2);
}


