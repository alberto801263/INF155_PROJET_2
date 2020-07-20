/*******************************************************************************
   Ce module implémente les sous-programmes pour charger les points 
   correspondant aux sites d'un diagramme de Voronoi à dessiner et pour 
   l'affichage du diagramme et d'un chemin.

   Par		: Pierre Bélisle
   Révision : Francis Bourdeau
   Révision E20  : David Beaulieu - Encapsulation des modélisations

*******************************************************************************/
#ifndef __M_INTERFACE__
#define __M_INTERFACE__


#include "t_erreur.h"
#include "t_graphe.h"
#include "t_liste.h"

/*******************************************************************************
                          DEFINITIONS DE TYPES ET DE CONSTANTES                 
*******************************************************************************/

// Constantes pour la gestion de l'affichage.
#define COULEUR_SITE    YELLOW
#define COULEUR_LIGNE   WHITE

// La couleur des segments du chemin dans le graphe.
#define COULEUR_CHEMIN  GREEN

/*******************************************************************************
                            DECLARATIONS DE FONCTIONS                           
*******************************************************************************/
/*
    CHARGER_GRAPHE
    
    Cette fonction charge les donnees du fichier dans le graphe reçu.

    Paramètres :
        ptr_graphe [sortie] : Le graphe dans lequels les sites lues seront
                              ajoutées.

    Retour :
        En cas de succes, elle retourne SUCCES, sinon elle retourne une des
        code d'erreurs de l'enum t_erreur.
*/
t_erreur charger_graphe(ptr_graphe graphe, const char* nom_fichier);


/*
    AFFICHER_GRAPHE
   
    Fonction qui affiche le diagramme de voronoi associe au graphe.

    Paramètres :
        - ptr_graphe [entrée] : Le graphe a afficher.

    Retour :
        Aucune.
*/
void afficher_graphe(ptr_graphe graphe);

#endif
