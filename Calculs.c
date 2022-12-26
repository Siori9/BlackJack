/*!
* \file Calculs.c
* \author Clara Layus <layusclara@cy-tech.fr>
* \version 0.1
* \date 26/12/2022
* \brief ensemble des fonctions qui gère le score des cartes
* \remarks None
* 
* 
* 
*/


/*! Importation des librairies*/
#include "Calculs.h"

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
int totalCarte(PileCarte* pPileCarte_cartes){

    //On initialise les variables qui vont me permettre de parcourir les cartes et de stocker le score
    psObjetPileCarte psObjetPileCarte_carteLu = pPileCarte_cartes->tete;
    int int_total = 0;
    int int_nbrAce = 0;

    //On parcours les cartes
    for (int i = 0; i < pPileCarte_cartes->taille; i++)
    {
        //Si c'est un ace, on ajoute 1 à la variable int_nbrAce
        if(psObjetPileCarte_carteLu->sCarte_carte.int_valeur == 1){
            int_nbrAce++;
        //Si c'est une carte dont le valeur est en dessous de 10, on aditionne sa valeur au total
        } else if (psObjetPileCarte_carteLu->sCarte_carte.int_valeur < 10)
        {
            int_total = int_total+ psObjetPileCarte_carteLu->sCarte_carte.int_valeur;
        //Sinon on ajoute 10 au total (10 et têtes)
        } else {
            int_total = int_total+10;
        }
        psObjetPileCarte_carteLu = psObjetPileCarte_carteLu->ppileCarte_carteSuivante; //Carte suivante
    }

    //On parcours les ace 
    for (int i = 0; i < int_nbrAce; i++)
    {
        if(int_total+11 > 21){ // Si le total +11 est inférieur à 21, alors on ajoute 11
            int_total++;
        } else { // Sinon on ajoute 1
            int_total= int_total+11;
        }
    }
    
    //Si le total est égale à 22 avec seulement 2 carte, il s'agit du meilleur score donc il passe à 22
    if (int_total == 21 && pPileCarte_cartes->taille == 2)
    {
        int_total = 22;

    //Sinon si le total est supérieur à 21, le score passe à 0
    } else if (int_total > 21)
    {
        int_total = 0;
    }

    //On retourne le total
    return int_total;
}

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
void calculScore(sTabJoueur sTabJoueur_tabJoueurs,PileCarte* pPileCarte_carteCroupier){

    //Récupération du score du croupier
    int int_scoreCroupier = totalCarte(pPileCarte_carteCroupier);

    //On parcours chaque joueur
    for (int i = 0; i < sTabJoueur_tabJoueurs.int_nbr; i++)
    {
        if (sTabJoueur_tabJoueurs.psJoueur_joueurs[i].int_enJeu == 0) //Si le joueur n'est plus en jeu
        {
            //On diminue son argent de sa mise et on repasse la mise à 0
            sTabJoueur_tabJoueurs.psJoueur_joueurs[i].int_argent = sTabJoueur_tabJoueurs.psJoueur_joueurs[i].int_argent - sTabJoueur_tabJoueurs.psJoueur_joueurs[i].int_mise;
            sTabJoueur_tabJoueurs.psJoueur_joueurs[i].int_mise = 0;
        } else { //Sinon, si le joueur est toujours en jeu

            //On calcul le score du joueur
            int int_scoreJoueur = totalCarte(sTabJoueur_tabJoueurs.psJoueur_joueurs[i].pPileCarte_cartes);

            if( int_scoreJoueur > int_scoreCroupier){ //Si le joueur a un meilleur score que le croupier

                //On ajoute à l'argent du joueur sa mise et on repasse la mise à 0
                sTabJoueur_tabJoueurs.psJoueur_joueurs[i].int_argent = sTabJoueur_tabJoueurs.psJoueur_joueurs[i].int_argent + sTabJoueur_tabJoueurs.psJoueur_joueurs[i].int_mise;
                sTabJoueur_tabJoueurs.psJoueur_joueurs[i].int_mise = 0;
            } else if (int_scoreJoueur == int_scoreCroupier) //Si le joueur a le même score que le croupier
            {
                //On repasse simplement sa mise à 0
                sTabJoueur_tabJoueurs.psJoueur_joueurs[i].int_mise = 0;
            } else { //Si le joueur a un moins bon score que le croupier

                //On diminue son argent de sa mise et on repasse la mise à 0
                sTabJoueur_tabJoueurs.psJoueur_joueurs[i].int_argent = sTabJoueur_tabJoueurs.psJoueur_joueurs[i].int_argent - sTabJoueur_tabJoueurs.psJoueur_joueurs[i].int_mise;
                sTabJoueur_tabJoueurs.psJoueur_joueurs[i].int_mise = 0;
            }
        } 
    }
}
