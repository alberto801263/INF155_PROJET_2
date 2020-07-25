/*****************************************************************************
	Par        :	Alberto,Habib
	Revise par :	Mitch
	Fichier    :	TP2.c
	Objectifs  :	TP2
	Note	   :	NA
*****************************************************************************/

#include "t_segment.h"
#include "t_point2d.h"

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<math.h>

/*Les nôtres*/
#include"minunit.h"


/****************************************************************************/
/*							DEFINITIONS DES CONSTANTES						*/
/****************************************************************************/

/****************************************************************************/
/*							DEFINITIONS DES TYPES							*/
/****************************************************************************/
// Un t_R3 a classiquement trois composantes en rectangulaire
// qui représente un point dans l'espace
struct t_segment
{
	t_point2d (*p1);
	t_point2d (*p2);
};
/*
	NOM	:	inititaliser_segment			
	DEF :	Ce sous programme publique initilaise un segment de fdroite avec 
			les coordonnées des deux points.
					
	PARAMETRES :	-Coordonnée en x du premier points du segments de droite
					-Coordonnée en y du premier points du segments de droite
					-Coordonnée en x du 2e points du segments de droite
					-Coordonnée en y du 2e points du segments de droite
	RETOUR :		Un pointeur vers le nouveau segment.
	SPÉCIFICATION : NA
*/

ptr_segment intialiser_segment(double x_s1, double y_s1, double x_s2, double y_s2)
{
	ptr_segment segment = (ptr_segment)malloc(sizeof(struct t_segment));
	
	segment->p1= initialiser_point(x_s1, y_s1);
	segment->p2= initialiser_point(x_s2, y_s2);

	return segment;
		
}
/*
	NOM	:			getP1
	DEF :			Ce sous-programme public de type informateur qui permet
					de consulter le 1e point reçu.
	PARAMETRES :	l'adresse d'un segment de droite
	RETOUR :		L'adresse du premier point
*/
ptr_point2d getPt1(const ptr_segment p)
{
	return	p->p1;
}
/*
	NOM	:			getP2
	DEF :			Ce sous-programme public de type informateur qui permet
					de consulter le 2e point reçu.
	PARAMETRES :	l'adresse d'un segment de droite
	RETOUR :		L'adresse du premier point
*/
ptr_point2d getPt2(const ptr_segment p)
{
	return	p->p2;
}
/*
	NOM	:			setPt1
	DEF :			Ce sous-programme public de type mutateur qui permet de
					modifier le premier point du segment.
	PARAMETRES :	L'adresse d'un segment de droite
					L'adresse du point que l'on veut assigner au segment
					
	RETOUR :		Aucune
*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!11*/
void setPt1(ptr_segment p1,  ptr_point2d p2)
{
	
		p1->p1 = p2;
}
/*
	NOM	:			setPt2
	DEF :			Ce sous-programme public de type mutateur qui permet de
					modifier le premier point du segment.
	PARAMETRES :	L'adresse d'un segment de droite
					L'adresse du point que l'on veut assigner au segment

	RETOUR :		Aucune
*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!11*/
void setPt2(ptr_segment p1, ptr_point2d p2)
{

	p1->p2 = p2;
}
/*
	NOM	:	 segment_est_horinzontal
	DEF :	Ce sous-programme détermeine si ce sement est une ligne horizontale.

	PARAMETRES :	L'adresse d'un segment de droite


	RETOUR :		1 : Lorsque le segment reçu est une ligne horizontale
					0 : Toute autre options
	SPÉCIFICATION : NA
*/
int segment_est_horizontal(ptr_segment p)
{
	ptr_point2d point1 = getPt1(p);
	ptr_point2d point2 = getPt2(p);

	//double y1 = getY(point1);
	//double y1 = getY(point2);
	int resultat = point_sur_la_meme_ligne(point1, point2);
	
	if (resultat == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
	
}
/*
	NOM	:	 segment_est_vertical		
	DEF :	Ce sous-programme détermeine si ce sement est une ligne verticale.		
					
	PARAMETRES :	L'adresse d'un segment de droite
					
					
	RETOUR :		1 : Lorsque le esment reçu est une ligne vddrticale
					0 : Toute autre options
	SPÉCIFICATION : NA
*/
int segment_est_vertical(ptr_segment p)
{
	ptr_point2d point1 = getPt1(p);
	ptr_point2d point2 = getPt2(p);

	//double y1 = getY(point1);
	//double y1 = getY(point2);
	int resultat = point_sur_la_meme_colonne(point1, point2);

	if (resultat == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}

}
void testInitialiserPoint()
{
	ptr_segment segment;

	ptr_segment segmentTEST;

	ptr_point2d point1TEST = initialiser_point(1.00, 1.00);
	ptr_point2d point2TEST = initialiser_point(-1.00, -1.00);
	

	segment = intialiser_segment(1.00, 1.00, -1.00, -1.00);
	
	ptr_point2d retourPt1 = getPt1(segment);
	ptr_point2d retourPt2 = getPt2(segment);
	
	
	points_sont_identiques(retourPt1,point1TEST);

	if (points_sont_identiques(retourPt1, point1TEST) == 1 && points_sont_identiques(retourPt2, point2TEST) == 1)
	{
		//printf("\nSegment 1:\n");
		//affiche_point(segment->p1);
		//printf("Segment 2:\n");
		//affiche_point(segment->p2);
		printf("TEST 1 - initialiser_segment : VERIFIED\n");
		//printf("\nPoint 1:\n");
		//affiche_point(retourPt1);
		//printf("Point 2:\n");
		//affiche_point(retourPt2);
		printf("TEST 2 - getPt1 & getPt2 : VERIFIED\n");
	}

	setPt1(segment, point2TEST);

	if (points_sont_identiques(segment->p1,point2TEST))
	{
		printf("TEST 3 - setPt1 : VERIFIED\n");
	}

	setPt2(segment, point2TEST);
	if (points_sont_identiques(segment->p2, point2TEST))
	{
		printf("TEST 4 - setPt2 : VERIFIED\n");
	}

	if (segment_est_horizontal(segment) == 1)
	{
		printf("TEST 5 - segment_est_horizontale : VERIFIED\n");
	}

	if (segment_est_vertical(segment) == 1)
	{
		printf("TEST 6 - segment_est_vertical : VERIFIED\n");
	}
	system("pause");
	
}


