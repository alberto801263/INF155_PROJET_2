/****************************************************************************************
  Par		: Francis Bourdeau
  Révision	: Pierre Bélisle
 
  Ce module implémente des codes d'erreurs afin d'être utilisés comme 
  valeur de retour.

****************************************************************************************/
#ifndef __T_ERREUR__
#define __T_ERREUR__


/****************************************************************************************
                            DEFINITION DE TYPES ET CONSTANTES                            
****************************************************************************************/

// Les erreurs détectées par l'application et les messages affichés à 
// l'utilisateur.
typedef enum 
{
    SUCCES,
    ERREUR_OUVERTURE_FICHIER,
    ERREUR_ALLOCATION_MEMOIRE,
    ERREUR_GRAPHIQUE,
} t_erreur;


const char * const MESSAGES_ERREURS[] =
{   "",
    "Impossible d'ouvrir le fichier.",
    "Manque de memoire.",
    "Impossible de passer en mode graphique.\n" 
};


#endif
