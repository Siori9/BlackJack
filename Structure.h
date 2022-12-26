/*!
* \file Structure.h
* \author Clara Layus <layusclara@cy-tech.fr>
* \version 0.1
* \date 26/12/2022
* \brief fichier contenant toutes les structures et enum du projet
* \remarks None
* 
* 
* 
*/


// fichier Structure.h
#ifndef _STRUCTURE_H_
#define _STRUCTURE_H_

//Enum des couleur de carte
typedef enum eCouleur 
{
    Coeur = 1,
    Pique = 2,
    Trefle = 3,
    Carreau = 4
} eCouleur;

//Structure d'une carte
typedef struct sCarte
{
    enum eCouleur eCouleur_couleur;
    int int_valeur;
} sCarte;

//Type pointeur vers une carte
typedef sCarte* psCarte;

//Structure d'un objet d'une pile de carte
typedef struct sObjetPileCarte
{
    sCarte sCarte_carte;
    struct sObjetPileCarte* ppileCarte_carteSuivante;
} sObjetPileCarte;

//Type pointeur vers un objet de pile de carte
typedef sObjetPileCarte* psObjetPileCarte;

//Structure de pile de carte
typedef struct {
    psObjetPileCarte tete;
    int taille;
} PileCarte;

//Structure de joueur
typedef struct sJoueur
{
    char* char_nom;
    int int_argent;
    int int_enJeu;
    int int_mise;
    PileCarte* pPileCarte_cartes;
} sJoueur;

//Structure de tableau de joueur
typedef struct sTabJoueur
{
    sJoueur* psJoueur_joueurs;
    int int_nbr;
} sTabJoueur;


#endif