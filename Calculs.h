/*!
* \file Calculs.h
* \author Clara Layus <layusclara@cy-tech.fr>
* \version 0.1
* \date 26/12/2022
* \brief ensemble des fonctions qui gère le score des cartes
* \remarks None
* 
* 
* 
*/


// fichier Calculs.h
#ifndef _CALCULS_H_
#define _CALCULS_H_

/*! Importation des librairies*/
#include "Main.h"
#include "Structure.h"

/*!
* \fn int totalCarte(PileCarte* pPileCarte_cartes)
* \author Clara Layus <layusclara@cy-tech.fr>
* \version 0.1
* \date  26/12/2022
* \brief la fonction retourne le score du joueur à partir de ses cartes
* \remarks None
* \param pPileCarte_cartes cartes du joueur
* \return retourne le score du joueur (et 0 si ça dépasse 21)
*/
int totalCarte(PileCarte* pPileCarte_cartes);

/*!
* \fn void calculScore(sTabJoueur sTabJoueur_tabJoueurs,PileCarte* pPileCarte_carteCroupier)
* \author Clara Layus <layusclara@cy-tech.fr>
* \version 0.1
* \date  26/12/2022
* \brief la fonction vérifie si les victoire et défaite des joueurs
* \remarks None
* \param sTabJoueur_tabJoueurs info des joueurs
* \param pPileCarte_carteCroupier cartes du croupier
*/
void calculScore(sTabJoueur sTabJoueur_tabJoueurs,PileCarte* pPileCarte_carteCroupier);

#endif