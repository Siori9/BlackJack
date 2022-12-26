/*!
* \file Mecanismes.h
* \author Clara Layus <layusclara@cy-tech.fr>
* \version 0.1
* \date 14/12/2022
* \brief fonctions liés aux piles
* \remarks None
* 
* 
* 
*/


// fichier Affichage.h
#ifndef _MECANISMES_H_
#define _MECANISMES_H_

/*! Importation des librairies*/
#include "Main.h"
#include "Structure.h"

/*!
* \fn PileCarte* newPileCarte() 
* \author Clara Layus <layusclara@cy-tech.fr>
* \version 0.1
* \date  26/12/2022
* \brief la fonction initialise une nouvelle pile de carte
* \remarks None
* \return retourne une nouvelle pile
*/
PileCarte* newPileCarte();

/*!
* \fn void empilerPile(PileCarte* ppileCarte_pile, sCarte sCarte_carte)
* \author Clara Layus <layusclara@cy-tech.fr>
* \version 0.1
* \date  14/12/2022
* \brief la fonction permet d'empiler une nouvelle carte sur une pile
* \remarks None
* \param sCarte_carte carte à empiler
* \param ppileCarte_pile pile sur laquelle la carte doit être empilé
*/
void empilerPile(PileCarte* ppileCarte_pile, sCarte sCarte_carte);

/*!
* \fn sCarte depilerPile(PileCarte* ppileCarte_pile)
* \author Clara Layus <layusclara@cy-tech.fr>
* \version 0.1
* \date  14/12/2022
* \brief la fonction permet de dépiler la première carte d'une pile et de la retourner
* \remarks None
* \param ppileCarte_pile pile dont on veut dépiler une carte
* \return carte dépilé
*/
sCarte depilerPile(PileCarte* ppileCarte_pile);

/*!
* \fn void viderPile(PileCarte* ppileCarte_pile)
* \author Clara Layus <layusclara@cy-tech.fr>
* \version 0.1
* \date  26/12/2022
* \brief la fonction vide complêtement une pile
* \remarks None
* \param ppileCarte_pile pile à vider
*/
void viderPile(PileCarte* ppileCarte_pile);

/*!
* \fn void decalerTab(psCarte* tpsCarte_jeuCarte,int int_indiceTire)
* \author Clara Layus <layusclara@cy-tech.fr>
* \version 0.1
* \date  14/12/2022
* \brief la fonction décale tous les éléments du tableau à l'indice n-1 (n indice initiale de l'élément) à partir de l'index passé en paramètre
* \remarks None
* \param int_indiceTire indice à partir duquel le tableau sera décalé
* \param tpsCarte_jeuCarte tableau à décaler
*/
void decalerTab(psCarte* tpsCarte_jeuCarte,int int_indiceTire);

/*!
* \fn void melangePileCarte(PileCarte* ppileCarte_pile, psCarte* tpsCarte_jeuCarte) 
* \author Clara Layus <layusclara@cy-tech.fr>
* \version 0.1
* \date  14/12/2022
* \brief la fonction empiler les carte d'un tableau de carte dans un ordre aléatoire sur une pile
* \remarks None
* \param ppileCarte_pile pile qui va recevoir les cartes
* \param tpsCarte_jeuCarte tableau qui contient toutes les cartes
*/
void melangePileCarte(PileCarte* ppileCarte_pile, psCarte* tpsCarte_jeuCarte);

/*!
* \fn void initJeuCarte(PileCarte* ppileCarte_pile)
* \author Clara Layus <layusclara@cy-tech.fr>
* \version 0.1
* \date  14/12/2022
* \brief la procédure crée le jeu de carte initiale
* \remarks None
* \param ppileCarte_pile la pile qui va recevoir les cartes
*/
void initJeuCarte(PileCarte* ppileCarte_pile);

/*!
* \fn void distribuerCarte(PileCarte* pPileCarte_carteJoueur,PileCarte* ppileCarte_pile)
* \author Clara Layus <layusclara@cy-tech.fr>
* \version 0.1
* \date  14/12/2022
* \brief la fonction permet de distribuer une carte dans la pile donné
* \remarks None
* \param pPileCarte_carteJoueur la pile de carte du joueur (ou croupier)
* \param ppileCarte_pile la pile de carte générale
*/
void distribuerCarte(PileCarte* pPileCarte_carteJoueur,PileCarte* ppileCarte_pile);

#endif