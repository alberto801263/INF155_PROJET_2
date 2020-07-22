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

/****************************************************************************/
/*							DEFINITIONS DES TYPES							*/
/****************************************************************************/
// Un t_R3 a classiquement trois composantes en rectangulaire
// qui repr�sente un point dans l'espace
struct t_point2d
{
	double x;
	double y;
};

/****************************************************************************/
/*							DECLARATION DES FONCTIONS PRIV�ES				*/
/****************************************************************************/

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
ptr_point2d initialiser_point(double x, double y) 
{

	// Allocation m�moire de la structure.
	ptr_point2d point = (ptr_point2d)malloc(sizeof(struct t_point2d));

	point-> x = x;
	point-> y = y;	

	return point;
}


//consulter la valeur de la coordonn�e X du point re�u
double getX(const ptr_point2d p)
{
	return	p->x;
}

//consulter la valeur de la coordonn�e Y du point re�u
double getY(const ptr_point2d p)
{
	return p->y;
}

