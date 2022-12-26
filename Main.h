/*!
* \file Main.h
* \author Clara Layus <layusclara@cy-tech.fr>
* \version 0.1
* \date 08/12/2022
* \brief Programme qui implémente un blackJack
* \remarks None
* 
* 
*/


// fichier Main.h
#ifndef _MAIN_H_
#define _MAIN_H_

/*! Importation des librairies*/
#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <ncurses.h>
#include <locale.h>
#include "Affichage.h"
#include "EcranConfig.h"
#include "Structure.h"
#include "Mecanismes.h"
#include "FonctionsJeu.h"
#include "Autres.h"
#include "Calculs.h"

/*!
* \fn int main(int argc, char** argv )
* \author Clara Layus <layusclara@cy-tech.fr>
* \version 0.1
* \date 08/12/2022
* \brief Fonction principale (Main) du programme
* \remarks None
* \param argc nombre d'arguments donnés en entrée
* \param argv valeur des arguments donnés en entrée
* \return 0 si tout s'est bien passé
*/
int main(int argc, char** argv );


#endif