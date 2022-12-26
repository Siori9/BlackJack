/*!
* \file Autres.h
* \author Clara Layus <layusclara@cy-tech.fr>
* \version 0.1
* \date 26/12/2022
* \brief ensemble de fonction de saisi
* \remarks None
* 
* 
* 
*/


// fichier Autres.h
#ifndef _AUTRES_H_
#define _AUTRES_H_

/*! Importation des librairies*/
#include "Main.h"
#include "Structure.h"

/*!
* \fn int saisieEntier(int int_min, int int_max, int* pint_decalage)
* \author Clara Layus <layusclara@cy-tech.fr>
* \version 0.1
* \date  30/11/2022
* \brief Cette fonction retourne l'entier entrée par l'utilisateur
* \remarks None
* \param int_min entier valeur minimum demandé
* \param int_max entier valeur maximum demandé
* \param pint_decalage entier correspondant à la ligne à partir de laquelle la suite pourra être écrite dans le terminale
* \return retourne l'entier entrée par l'utilisateur entre min et max
*/
int saisieEntier(int int_min, int int_max, int* pint_decalage);

/*!
* \fn void saisieChaine(char* tchar_tab)
* \author Clara Layus <layusclara@cy-tech.fr>
* \version 0.1
* \date  07/12/2022
* \brief Procédure qui récupère l'entrées de l'utilisateur pour compléter le tableau de caractère
* \remarks None
* \param tchar_tab un pointeur vers une chaine de caractère
*/
void saisieChaine(char* tchar_tab);

#endif