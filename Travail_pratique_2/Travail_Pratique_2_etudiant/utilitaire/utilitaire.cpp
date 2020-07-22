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

int sont_egaux(double valeur_1, double valeur_2)
{
	double diffVal = 0;
	diffVal = fabs(valeur_1 - valeur_2); //Calcule de difference de Valeur1 et Valeur2 (Valeur absolue)****
	if (diffVal < 0.00001)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
