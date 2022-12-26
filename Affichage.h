/*!
* \file Affichage.h
* \author Clara Layus <layusclara@cy-tech.fr>
* \version 0.1
* \date 26/12/2022
* \brief ensemble des fonctions d'affichage
* \remarks None
* 
* 
* 
*/


// fichier Affichage.h
#ifndef _AFFICHAGE_H_
#define _AFFICHAGE_H_

/*! Importation des librairies*/
#include "Main.h"
#include "Structure.h"
#include "Calculs.h"

/*!
* \def CROUGE
* Description couleur 1
*/
#define CROUGE 1
/*!
* \def CNOIR
* Description couleur 2
*/
#define CNOIR 2
/*!
* \def CBLANC
* Description couleur 3
*/
#define CBLANC 3
/*!
* \def EBLANC
* Description couleur 4
*/
#define EBLANC 4
/*!
* \def EBLEU
* Description couleur 5
*/
#define EBLEU 5
/*!
* \def EROUGE
* Description couleur 6
*/
#define EROUGE 6
/*!
* \def CBLEU
* Description couleur 7
*/
#define CBLEU 7

/*!
* \fn void effacerPlateau()
* \author Clara Layus <layusclara@cy-tech.fr>
* \version 0.1
* \date  12/12/2022
* \brief la fonction efface l'interrieur du plateau en appelant la fonction affacerZone avec les bonnes dimentions 
* \remarks None
*/
void effacerPlateau();

/*!
* \fn void effacerZone(int int_x1, int int_y1, int int_x2, int int_y2)
* \author Clara Layus <layusclara@cy-tech.fr>
* \version 0.1
* \date  12/12/2022
* \brief la fonction efface le rectangle entre le point (int_x1,int_y1) et le point (int_x2,int_y2)
* \remarks None
* \param int_x1 abcisse du point 1
* \param int_y1 ordonnée du point 1
* \param int_x2 abcisse du point 2
* \param int_y2 ordonnée du point 1
*/
void effacerZone(int int_x1, int int_y1, int int_x2, int int_y2);

/*!
* \fn void initCouleur()
* \author Clara Layus <layusclara@cy-tech.fr>
* \version 0.1
* \date  26/12/2022
* \brief la fonction initialise les couleurs utiliser avec ncurses
* \remarks None
*/
void initCouleur();

/*!
* \fn void affichageDosCarte( int int_x, int int_y)
* \author Clara Layus <layusclara@cy-tech.fr>
* \version 0.1
* \date  09/12/2022
* \brief la procédure affiche le dos d'une carte à partir de la position (int_x,int_y)
* \remarks None
* \param int_y ordonnée du point de départ
* \param int
*/
void affichageDosCarte( int int_x, int int_y);

/*!
* \fn void affichageCarte(sCarte sCarte_carte, int int_x, int int_y, int int_enJeu)
* \author Clara Layus <layusclara@cy-tech.fr>
* \version 0.1
* \date  09/12/2022
* \brief la procédure affiche la carte passé en paramètre à partir de la position (int_x,int_y)
* \remarks None
* \param sCarte_carte carte à afficher
* \param int_x abcisse du point de départ
* \param int_y ordonnée du point de départ
* \param int_enJeu précise si la carte appartient à un joueur encore en jeu ou non
*/
void affichageCarte(sCarte sCarte_carte, int int_x, int int_y, int int_enJeu);

/*!
* \fn void affichageInfoJoueur(sJoueur sJoueur_joueur,int int_x, int int_y)
* \author Clara Layus <layusclara@cy-tech.fr>
* \version 0.1
* \date  26/12/2022
* \brief la fonction affiche les information du joueur (cartes, nom, mise et argent)
* \remarks None
* \param sJoueur_joueur info du joueur
* \param int_x abcisse du point de départ
* \param int_y ordonnée du point de départ
*/
void affichageInfoJoueur(sJoueur sJoueur_joueur,int int_x, int int_y);

/*!
* \fn void affichageCroupier(PileCarte* pPilecarte_carteCroupier, int int_x, int int_y, int int_carteCroupierVisible)
* \author Clara Layus <layusclara@cy-tech.fr>
* \version 0.1
* \date  26/12/2022
* \brief la fonction affiche les carte du croupier
* \remarks None
* \param pPilecarte_carteCroupier cartes du croupier
* \param int_x abcisse du point de départ
* \param int_y ordonnée du point de départ
* \param int_carteCroupierVisible si toutes les cartes du croupier sont visible ou non
*/
void affichageCroupier(PileCarte* pPilecarte_carteCroupier, int int_x, int int_y, int int_carteCroupierVisible);

/*!
* \fn void affichageJeu(sTabJoueur sTabJoueur_tabJoueurs, PileCarte* pPileCarte_carteCroupier, int int_carteCroupierVisible)
* \author Clara Layus <layusclara@cy-tech.fr>
* \version 0.1
* \date  26/12/2022
* \brief la fonction gère l'affichage complet du plateau de jeu avec le placement de chaque joueur et du croupier
* \remarks None
* \param sTabJoueur_tabJoueurs info des joueurs
* \param pPileCarte_carteCroupier cartes du croupier
* \param int_carteCroupierVisible précise si les cartes du croupier doivent être visible ou non
*/
void affichageJeu(sTabJoueur sTabJoueur_tabJoueurs, PileCarte* pPileCarte_carteCroupier, int int_carteCroupierVisible);

/*!
* \fn WINDOW * interfaceGlobal()
* \author Clara Layus <layusclara@cy-tech.fr>
* \version 0.1
* \date  08/12/2022
* \brief Fonction qui affiche l'interface générale (titre et plateau)
* \remarks None
* \return un pointeur vers la fenêtre correspondant au plateau
*/
WINDOW * interfaceGlobal();

/*!
* \fn void classement(sTabJoueur sTabJoueur_tabJoueurs)
* \author Clara Layus <layusclara@cy-tech.fr>
* \version 0.1
* \date  26/12/2022
* \brief la fonction qui affiche le classement final
* \remarks None
* \param sTabJoueur_tabJoueurs info des joueurs
*/
void classement(sTabJoueur sTabJoueur_tabJoueurs);

#endif