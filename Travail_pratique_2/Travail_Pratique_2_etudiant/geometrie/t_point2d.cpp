/*****************************************************************************
	Par        :	David Beaulieu et Hugues Saulnier
	Revise le  :	juin 2020
	Fichier    :	R3.c
	Objectifs  :	Librairie qui permet de modéliser un point dans l'espace
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
// qui représente un point dans l'espace
struct ptr_point2d
{
	double x;
	double y;
};
typedef struct ptr_point2d* ptr_position;
/****************************************************************************/
/*							DECLARATION DES FONCTIONS PRIVÉES				*/
/****************************************************************************/
/*
	REEL_ALEA
	Fonction qui retourne un nombre réel aéaltoire compris
	entre [0,1].

	Paramètre : Aucun
	Retour : Un réel aléatoire (TYPE: double)
*/
static double reel_alea(void);


/****************************************************************************/
/*							DÉFINITION DES FONCTIONS PUBLIQUES				*/
/****************************************************************************/

/*
	NOM	:			t_point2d
	DEF :			Fonction constructeur qui permet de créer un nouveau point
					Selon les valeurs donnée en paramètre
	PARAMETRES :	Aucun
	RETOUR :		l'adresse du point créer
	SPÉCIFICATION :
*/
ptr_point2d t_point2d(double x, double y) 
{

	ptr_point2d point;

	// Allocation mémoire de la structure.
	ptr_position point = (ptr_position)malloc(sizeof(struct ptr_point2d));


	point.x = x;
	point.y = y;
	

	return point;
}
