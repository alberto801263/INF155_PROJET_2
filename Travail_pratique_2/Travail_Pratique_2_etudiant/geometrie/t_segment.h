/*****************************************************************************
	Par        :	Alberto,Habib
	Revise par :	Mitch
	Fichier    :	TP2.c
	Objectifs  :	TP2
	Note	   :	NA
*****************************************************************************/
/************************************************************************
						  DEFINITIONS DE TYPES ET DE CONSTANTES
*************************************************************************/
#include"t_point2d.h"


/***************************************************************************/
/*								TYPE								   	   */
/***************************************************************************/
typedef struct t_segment* ptr_segment;

/****************************************************************************/
/*							DEFINITIONS DES FONCTIONS						*/
/****************************************************************************/
ptr_segment intialiser_segment(double x_s1, double y_s1, double x_s2, double y_s2);
ptr_point2d getPt1(const ptr_segment p);
ptr_point2d getPt2(const ptr_segment p);
void setPt1(ptr_segment p1, ptr_point2d p2);
void setPt2(ptr_segment p1, ptr_point2d p2);
int segment_est_horizontal(ptr_segment p);
int segment_est_vertical(ptr_segment p);





/***************************************************************************/
/*								  TEST								   	   */
/***************************************************************************/
void testInitialiserPoint();