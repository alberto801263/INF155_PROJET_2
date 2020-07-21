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

/*
	NOM	:			nouveauPoint
	DEF :			Fonction constructeur qui permet de créer un nouveau point
					Selon les valeurs donnée en paramètre
	PARAMETRES :	Aucun
	RETOUR :		l'adresse du point créer
	SPÉCIFICATION :
*/
Premier_point nouveauPoint(double x, double y) {

	ptr_premier point;

	// Allocation mémoire de la structure.
	point = (ptr_R3)malloc(sizeof(struct t_R3));

	point->x = x;
	point->y = y;
	

	return point;