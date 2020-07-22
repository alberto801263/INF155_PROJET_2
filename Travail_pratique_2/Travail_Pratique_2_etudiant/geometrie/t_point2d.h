/*****************************************************************************
	Par        :	David Beaulieu et Hugues Saulnier
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

#define __MODULE_POINTS_R3__ 


/****************************************************************************/
/*							DEFINITIONS DES TYPES							*/
/****************************************************************************/
// Pointeur d'un ptr_R3 - pointeur vers un point dans l'espace.
typedef struct t_point2d* ptr_point2d;


/****************************************************************************/
/*							DEFINITIONS DES FONCTIONS						*/
/****************************************************************************/

ptr_point2d initialiser_point(double x, double y);
double getX(const ptr_point2d p);
double getY(const ptr_point2d p);
void R3_setX(ptr_point2d p, double val_X);
void R3_setY(ptr_point2d p, double val_Y);
int point_sur_la_meme_ligne(ptr_point2d p1, ptr_point2d p2);