/*****************************************************************************
	Par        :	Alberto,Habib
	Revise par :	Mitch
	Fichier    :	TP2.c
	Objectifs  :	TP2
	Note	   :	NA
*****************************************************************************/

/****************************************************************************/
/*							COMMANDES PREPROCESSEUR							*/
/****************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<math.h>

#include"t_point2d.h"

/****************************************************************************/
/*							DEFINITIONS DES CONSTANTES						*/
/****************************************************************************/

/****************************************************************************/
/*							DEFINITIONS DES TYPES							*/
/****************************************************************************/
// Un t_R3 a classiquement trois composantes en rectangulaire
// qui représente un point dans l'espace
struct t_point2d
{
	double x;
	double y;
};


/****************************************************************************/
/*							DECLARATION DES FONCTIONS PRIVÉES				*/
/****************************************************************************/

/****************************************************************************/
/*							DÉFINITION DES FONCTIONS PUBLIQUES				*/
/****************************************************************************/

/*
	NOM	:			initialiser_point
	DEF :			Ce sous-programme public initialise le contenu d'un point
					avec les coordonnées reçues.
	PARAMETRES :	x:La coordonnée en x du point à initialiser.
					y:La coordonnée en y du point à initialiser.
	RETOUR :		ptr_point2d:Un pointeur vers le nouveau point initialisé.
*/
ptr_point2d initialiser_point(double x, double y)
{

	// Allocation mémoire de la structure.
	ptr_point2d point = (ptr_point2d)malloc(sizeof(struct t_point2d));

	point->x = x;
	point->y = y;

	return point;
}

/*
	NOM	:			getX
	DEF :			Ce sous-programme public de type informateur qui permet
					de consulter la valeur de la coordonnée X du point reçu.
	PARAMETRES :	ptr_point2d p:L'adresse d'un point 2D.
	RETOUR :		p->x:La valeur de X.
*/
double getX(const ptr_point2d p)
{
	return	p->x;
}

/*
	NOM	:			getY
	DEF :			Ce sous-programme public de type informateur qui permet
					de consulter la valeur de la coordonnée Y du point reçu.
	PARAMETRES :	ptr_point2d p:L'adresse d'un point 2D.
	RETOUR :		p->y:La valeur de Y.
*/
double getY(const ptr_point2d p)
{
	return p->y;
}

/*
	NOM	:			setX
	DEF :			Ce sous-programme public de type mutateur qui permet de
					modifier la valeur de la coordonnée X du point reçu.
	PARAMETRES :	ptr_point2d p:L'adresse d'un point 2D.
					val_x:La nouvelle valeur de X.
	RETOUR :		N/A
*/
void setX(ptr_point2d p, double val_X)
{
	p->x = val_X;
}

/*
	NOM	:			setY
	DEF :			Ce sous-programme public de type mutateur qui permet de
					modifier la valeur de la coordonnée Y du point reçu.
	PARAMETRES :	ptr_point2d p:L'adresse d'un point 2D.
					val_y:La nouvelle valeur de Y.
	RETOUR :		N/A
*/
void setY(ptr_point2d p, double val_Y)
{
	p->y = val_Y;
}

/*
	NOM	:			point_sur_la_meme_ligne
	DEF :			Ce sous-programme public détermine si deux points sont
					alignés sur une même ligne horizontale.
	PARAMETRES :	ptr_point2d p1:L'adresse d'un premier point 2D.
					ptr_point2d p2:• L'adresse d'un second point 2D.
	RETOUR :		Retourne 1: lorsque les deux points sont sur une même ligne
								horizontale.
					Retourne 0: Sinon on retourne 0.
*/
int point_sur_la_meme_ligne(const ptr_point2d p1, const ptr_point2d p2)
{
	if (fabs(p1->y - p2->y) < 0.00001)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/*
	NOM	:			point_sur_la_meme_colonne
	DEF :			Ce sous-programme public détermine si deux points sont alignés sur
					une même ligne verticale.
	PARAMETRES :	ptr_point2d p1:L'adresse d'un premier point 2D.
					ptr_point2d p2:• L'adresse d'un second point 2D.
	RETOUR :		Retourne 1: lorsque les deux points sont sur une même ligne
								verticale.
					Retourne 0: Sinon on retourne 0.
*/
int point_sur_la_meme_colonne(const ptr_point2d p1, const ptr_point2d p2)
{
	if (fabs(p1->x - p2->x) < 0.00001)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/*
	NOM	:			distance_entre_points
	DEF :			Ce sous-programme public calcule la distance entre deux points.
	PARAMETRES :	ptr_point2d p1:L'adresse d'un premier point 2D.
					ptr_point2d p2:• L'adresse d'un second point 2D.
	RETOUR :		distance:Retourne la distance entre le point1 et le point2.
*/
double distance_entre_points(const ptr_point2d p1, const ptr_point2d p2)
{
	double distance;
	double deltaX_carree;
	double deltaY_carree;

	deltaX_carree = (p2->x - p1->x) * (p2->x - p1->x);
	deltaY_carree = (p2->y - p1->y) * (p2->y - p1->y);
	distance = sqrt(deltaX_carree + deltaY_carree);

	return distance;
}
/*
	NOM	:			points_sont_identiques
	DEF :			Ce sous-programme public détermine si deux points sont considérés
					comme étant identiques.
	PARAMETRES :	ptr_point2d p1:L'adresse d'un premier point 2D.
					ptr_point2d p2:L'adresse d'un second point 2D.
	RETOUR :		Retourne 1:  lorsque les deux coordonnées en x sont considérées
					égales et lorsque les deux coordonnées en y sont considérées égales.
					Retourne 0: Sinon on retourne 0.
*/
int points_sont_identiques(const ptr_point2d p1, const ptr_point2d p2)
{
	if (fabs(p1->y - p2->y) < 0.00001 && fabs(p1->x - p2->x) < 0.00001)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/*
	NOM	:			pente
	DEF :			Ce sous-programme public calcule la pente entre deux points.
	PARAMETRES :	ptr_point2d p1:L'adresse d'un premier point 2D.
					ptr_point2d p2:L'adresse d'un second point 2D.
	RETOUR :		Pente:Retourne la pente entre les deux points.
*/
double pente(const ptr_point2d p1, const ptr_point2d p2)
{
	double pente;
	double deltaX;
	double deltaY;

	deltaX = (p2->x - p1->x);
	deltaY = (p2->y - p1->y);
	pente = deltaX / deltaY;

	return pente;
}

/*
	NOM	:			point_milieu
	DEF :			Ce sous-programme public calcule le point milieu entre deux points.
	PARAMETRES :	ptr_point2d p1:L'adresse d'un premier point 2D.
					ptr_point2d p2:L'adresse d'un second point 2D.
	RETOUR :		 pointMil:Retourne l'adresse du nouveau point milieu.
*/
ptr_pointMil point_milieu(const ptr_point2d p1, const ptr_point2d p2)
{
	ptr_pointMil pointMil = (ptr_point2d)malloc(sizeof(struct t_point2d));


	pointMil->x = (p1->x + p2->x) / 2;
	pointMil->y = (p1->y + p2->y) / 2;

	return pointMil;
}
