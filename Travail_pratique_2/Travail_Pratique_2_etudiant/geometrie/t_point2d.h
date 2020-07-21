/*****************************************************************************
	Par        :	
	Revise le  :	juin 2020
	Fichier    :	R3.h
	Objectifs  :	La création d'un type bien réel : les vecteurs et les points de l'espace
					ordinaire qu'on appelle traditionnellement R3
	Note	   :	UN POINT EST ASSIMILÉ À SON VECTEUR POSITION
					et c'est le type de base à toute implémentation
					de la géométrie élémentaire
*****************************************************************************/

/****************************************************************************/
/*							COMMANDES PREPROCESSEUR							*/
/****************************************************************************/
#ifndef __MODULE_POINTS_R3__
#define __MODULE_POINTS_R3__ 


/****************************************************************************/
/*							DEFINITIONS DES TYPES							*/
/****************************************************************************/
// Pointeur d'un ptr_R3 - pointeur vers un point dans l'espace.
typedef struct Premier_point* ptr_premier;