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

/*
	NOM	:			nouveauPoint
	DEF :			Fonction constructeur qui permet de cr�er un nouveau point
					Selon les valeurs donn�e en param�tre
	PARAMETRES :	Aucun
	RETOUR :		l'adresse du point cr�er
	SP�CIFICATION :
*/
Premier_point nouveauPoint(double x, double y) {

	ptr_premier point;

	// Allocation m�moire de la structure.
	point = (ptr_R3)malloc(sizeof(struct t_R3));

	point->x = x;
	point->y = y;
	

	return point;