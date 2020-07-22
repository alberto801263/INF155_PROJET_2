/*****************************************************************************
	Par        :	David Beaulieu et Hugues Saulnier
	Revise le  :	juin 2020
	Fichier    :	R3.c
	Objectifs  :	Librairie qui permet de mod�liser un point dans l'espace
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
#define PI 3.141592653
#define PI2 6.283185305

/****************************************************************************/
/*							DEFINITIONS DES TYPES							*/
/****************************************************************************/
// Un t_R3 a classiquement trois composantes en rectangulaire
// qui repr�sente un point dans l'espace
struct ptr_point2d
{
	double x;
	double y;
};
typedef struct ptr_point2d* ptr_position;
/****************************************************************************/
/*							DECLARATION DES FONCTIONS PRIV�ES				*/
/****************************************************************************/
/*
	REEL_ALEA
	Fonction qui retourne un nombre r�el a�altoire compris
	entre [0,1].

	Param�tre : Aucun
	Retour : Un r�el al�atoire (TYPE: double)
*/
static double reel_alea(void);


/****************************************************************************/
/*							D�FINITION DES FONCTIONS PUBLIQUES				*/
/****************************************************************************/

/*
	NOM	:			t_point2d
	DEF :			Fonction constructeur qui permet de cr�er un nouveau point
					Selon les valeurs donn�e en param�tre
	PARAMETRES :	Aucun
	RETOUR :		l'adresse du point cr�er
	SP�CIFICATION :
*/
ptr_point2d t_point2d(double x, double y) 
{

	ptr_point2d point;

	// Allocation m�moire de la structure.
	ptr_position point = (ptr_position)malloc(sizeof(struct ptr_point2d));


	point.x = x;
	point.y = y;
	

	return point;
}
