/*!
* \file FonctionsJeu.c
* \author Clara Layus <layusclara@cy-tech.fr>
* \version 0.1
* \date 26/12/2022
* \brief ensemble des fonctions lié au jeu (initialisation d'une manche, recup des mise, gestion de manche, recup choix du joueur)
* \remarks None
* 
* 
* 
*/


// fichier FonctionsJeu.h
#ifndef _FONCTIONSJEU_H_
#define _FONCTIONSJEU_H_

/*! Importation des librairies*/
#include "Main.h"
#include "Structure.h"
#include "Affichage.h"
#include "Autres.h"
#include "Calculs.h"

/*!
* \fn void initManche(sTabJoueur sTabJoueur_tabJoueurs,PileCarte* ppileCarte_pile, PileCarte* pPileCarte_carteCroupier)
* \author Clara Layus <layusclara@cy-tech.fr>
* \version 0.1
* \date  26/12/2022
* \brief la fonction initialise la manche en distribuant 2 cartes à chaque joueur et au croupier
* \remarks None
* \param sTabJoueur_tabJoueurs info joueurs
* \param ppileCarte_pile pile de carte
* \param pPileCarte_carteCroupier carte du croupier
*/
void initManche(sTabJoueur sTabJoueur_tabJoueurs,PileCarte* ppileCarte_pile, PileCarte* pPileCarte_carteCroupier);

/*!
* \fn void recupMise(sTabJoueur sTabJoueur_tabJoueurs, int int_numManche)
* \author Clara Layus <layusclara@cy-tech.fr>
* \version 0.1
* \date  26/12/2022
* \brief la fonction demande au joueur et récupère le choix de leurs mises
* \remarks None
* \param sTabJoueur_tabJoueurs info joueurs
* \param int_numManche numéro de la manche
*/
void recupMise(sTabJoueur sTabJoueur_tabJoueurs, int int_numManche);

/*!
* \fn int recupChoix(sJoueur sJoueur_joueur)
* \author Clara Layus <layusclara@cy-tech.fr>
* \version 0.1
* \date  26/12/2022
* \brief la fonction récupère le choix du joueur pendant la manche (piocher ou finir son tour)
* \remarks None
* \param sJoueur_joueur info des joueurs
* \return retourne le choix du joueur (1 si fin de tour, 2 si nouvelle carte)
*/
int recupChoix(sJoueur sJoueur_joueur);

/*!
* \fn void gestionManche(sTabJoueur sTabJoueur_tabJoueurs,PileCarte* pPileCarte_carteCroupier, int int_numManche)
* \author Clara Layus <layusclara@cy-tech.fr>
* \version 0.1
* \date  26/12/2022
* \brief la fonction gère une manche du début à la fin
* \remarks None
* \param sTabJoueur_tabJoueurs info joueurs
* \param pPileCarte_carteCroupier carte du croupier
* \param int_numManche numéro de la manche
*/
void gestionManche(sTabJoueur sTabJoueur_tabJoueurs,PileCarte* pPileCarte_carteCroupier, int int_numManche);

#endif