/*!
* \file EcranConfig.h
* \author Clara Layus <layusclara@cy-tech.fr>
* \version 0.1
* \date 13/12/2022
* \brief introduction du jeu
* \remarks None
* 
* 
* 
*/


// fichier EcranConfig.h
#ifndef _ECRANCONFIG_H_
#define _ECRANCONFIG_H_

/*! Importation des librairies*/
#include "Main.h"
#include "Structure.h"
#include "Mecanismes.h"
#include "Affichage.h"
#include "Autres.h"

/*!
* \fn sTabJoueur ecranConfig()
* \author Clara Layus <layusclara@cy-tech.fr>
* \version 0.1
* \date  13/12/2022
* \brief cette fonction gère toute la partie introductive du jeu où on récupère le nombre et les noms des joueurs
* \remarks None
* \return un tableau de joueur
*/
sTabJoueur ecranConfig();

#endif