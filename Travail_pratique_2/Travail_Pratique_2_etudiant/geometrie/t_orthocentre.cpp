/*****************************************************************************
Par			: Frederick Henri
Adaptation	: Francis Bourdeau
Révision	: Pierre Bélisle
Révision E20  : David Beaulieu - Encapsulation de la structure
Complété par : VOTRE NOM ICI

Objectifs : Définition d'une fonction qui le point d'un orthocente en 
fonction des indices de trois sites.

*****************************************************************************/
#include "t_orthocentre.h"

#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "utilitaire.h"

/************************************************************************
						  DEFINITIONS DE TYPES ET DE CONSTANTES
*************************************************************************/


/***************************************************************************
							DEFINITION DES FONCTIONS PPRIVÉES
****************************************************************************/
/*
	CALCUL ORTHOCENTRE

	Fonction calcule l'orthocentre des trois points recus.
	Elle retourne le point se situant a une distance egale des trois points recus.

	Paramètres :
		- ptr_point2d p1 : Un des trois points dont on cherche l'orthocentre.
		- ptr_point2d p2 : Un des trois points dont on cherche l'orthocentre.
		- ptr_point2d p3 : Un des trois points dont on cherche l'orthocentre.

	Valeur de retour :
		Un nouveau point 2D représentant l'ordthocentre calculé.

	ATTENTION : Il est INTERDIT de calculer l'orthocentre de 3 points alignes!
				Dans un tel cas, le programme se termine.
*/
static ptr_point2d calcul_orthocentre(ptr_point2d p1, ptr_point2d p2, ptr_point2d p3);

/***************************************************************************
							DEFINITION DE FONCTIONS PUBLIQUES
****************************************************************************/


/***************************************************************************
							DÉCLARATION DES FONCTIONS PPRIVÉES
****************************************************************************/
static ptr_point2d calcul_orthocentre(ptr_point2d ptr_point1, ptr_point2d ptr_point2, ptr_point2d ptr_point3)
{
	double centreX = 0;
	double centreY = 0;

    /// On copie les coordonnees pour simplifier les equations.
    double x1 = getX(ptr_point1), y1 = getY(ptr_point1);
    double x2 = getX(ptr_point2), y2 = getY(ptr_point2);
    double x3 = getX(ptr_point3), y3 = getY(ptr_point3);
    double x1_carre = x1 * x1;
    double y1_carre = y1 * y1;
    double x2_carre = x2 * x2;
    double y2_carre = y2 * y2;
    double x3_carre = x3 * x3;
    double y3_carre = y3 * y3;
    double x1x22 = x1 * x2_carre;
    double x1x32 = x1 * x3_carre;
    double x1y22 = x1 * y2_carre;
    double x1y32 = x1 * y3_carre;
    double x12y2 = x1_carre * y2;
    double x12y3 = x1_carre * y3;
    double x2x12 = x2 * x1_carre;
    double x2x32 = x2 * x3_carre;
    double x2y12 = x2 * y1_carre;
    double x2y32 = x2 * y3_carre;
    double x22y3 = x2_carre * y3;
    double x3x12 = x3 * x1_carre;
    double x3x22 = x3 * x2_carre;
    double x3y12 = x3 * y1_carre;
    double x3y22 = x3 * y2_carre;
    double y1x22 = y1 * x2_carre;
    double y1x32 = y1 * x3_carre;
    double y1y22 = y1 * y2_carre;
    double y1y32 = y1 * y3_carre;
    double y2x32 = y2 * x3_carre;
    double y2y32 = y2 * y3_carre;
    double y12y2 = y1_carre * y2;
    double y12y3 = y1_carre * y3;
    double y22y3 = y2_carre * y3;
    double x1y2 = x1 * y2;
    double x1y3 = x1 * y3;
    double x2y1 = x2 * y1;
    double x2y3 = x2 * y3;
    double x3y1 = x3 * y1;
    double x3y2 = x3 * y2;

    // On calcule les elements du centre du cercle.
    double numerateur_x = x12y2 - x12y3 - y12y3 + y1x32 + x22y3 + y1y32 - 
                          y2x32 - y2y32 - y1x22 + y22y3 - y1y22 + y12y2;

    double numerateur_y = x1x32 + x1y32 + x3x22 + x2x12 + x2y12 - x1x22 - 
                          x2x32 - x2y32 - x3x12 - x3y12 - x1y22 + x3y22;

    double denominateur_x = -x1y3 - x2y1 + x2y3 + x1y2 + x3y1 - x3y2;
    double denominateur_y = -x1y3 - x2y1 + x2y3 + x1y2 + x3y1 - x3y2;

    int trois_points_alignes = sont_egaux(denominateur_x, 0);

    assert(!trois_points_alignes);
	centreX = (numerateur_x/denominateur_x) / 2.0;
	centreY = (numerateur_y/denominateur_y) / -2.0;

	return initialiser_point(centreX, centreY);
}

