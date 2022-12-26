/*!
* \file EcranConfig.c
* \author Clara Layus <layusclara@cy-tech.fr>
* \version 0.1
* \date 13/12/2022
* \brief introduction du jeu 
* \remarks None
* 
* 
* 
*/


/*! Importation des librairies*/
#include "EcranConfig.h"

/*!
* \fn sJoueur* ecranConfig()
* \author Clara Layus <layusclara@cy-tech.fr>
* \version 0.1
* \date  13/12/2022
* \brief cette fonction gère toute la partie introductive du jeu où on récupère le nombre et les noms des joueurs
* \remarks None
* \return un tableau de joueur
*/
sTabJoueur ecranConfig(){

    //Affichage du titre de la partie (en gras et centrer)
    attron(A_BOLD);
    char* pchar_msg = "AVANT DE COMMENCER";
    mvprintw(LINES/4+2, (COLS / 2) - (strlen(pchar_msg) / 2), pchar_msg);
    attron(A_NORMAL);

    //Affichage du message pour demander le nombre de joueur
    pchar_msg = "Entrez le nombre de joueur (de 1 à 5): ";
    mvprintw(LINES/4+4, (COLS / 2) - (strlen(pchar_msg) / 2), pchar_msg);

    //Déclaration de la variable qui contiendra le décalage des lignes 
    int decalage = LINES/4+4;

    //Récupération du nombre de joueur
    int int_nbrJoueur = saisieEntier(1,5,&decalage);

    //Affichage du nombre de joueur en jeu
    pchar_msg = malloc(100*sizeof(char));
    sprintf(pchar_msg,"Nous avons %d dans la compétition !",int_nbrJoueur);
    mvprintw(decalage+2, (COLS / 2) - (strlen(pchar_msg) / 2), pchar_msg);

    //Tableau contenant les joueurs
    sJoueur* tsJoueur_joueurs = malloc(int_nbrJoueur*sizeof(sJoueur));

    decalage = decalage+2; /*On incrémente le décalage*/

    //On parcourt l'ensemble des joueurs 
    for (int i = 0; i < int_nbrJoueur; i++)
    {
        //On récupère le nom du joueur
        sprintf(pchar_msg,"Joueur %d, entrez votre nom: ",i+1);
        mvprintw(decalage+2, (COLS / 2) - (strlen(pchar_msg) / 2 +3), pchar_msg);
        tsJoueur_joueurs[i].char_nom = malloc(200*sizeof(char));
        saisieChaine(tsJoueur_joueurs[i].char_nom);
        

        //On initialise les autres paramètres du joueur
        tsJoueur_joueurs[i].int_argent = 50;
        tsJoueur_joueurs[i].int_enJeu = 1;
        tsJoueur_joueurs[i].int_mise = 0;
        tsJoueur_joueurs[i].pPileCarte_cartes = newPileCarte();
        decalage = decalage+2; /*On incrémente le décalage*/
    }

    decalage = decalage+2;

    //Affichage du message pour préciser l'argent de départ
    pchar_msg = "Chaque joueur commence avec 50 !";
    mvprintw(decalage+2, (COLS / 2) - (strlen(pchar_msg) / 2), pchar_msg);
    decalage = decalage+2;

    //Affichage du message pour commencer le jeu
    pchar_msg = "Tapez sur ENTREE pour commencer !";
    mvprintw(decalage+2, (COLS / 2) - (strlen(pchar_msg) / 2), pchar_msg);

    while (10 != getch()) {} 

    //Actualisation de la page
    refresh();

    //Efface le contenue du plateau
    effacerPlateau();

    sTabJoueur sTabJoueur_tabJoueur;
    sTabJoueur_tabJoueur.int_nbr = int_nbrJoueur;
    sTabJoueur_tabJoueur.psJoueur_joueurs = tsJoueur_joueurs;

    //On retour le tableau de joueur
    return sTabJoueur_tabJoueur;

    //On libère la place prise par la chaine de caratère utilisé pour les différents messages
    free(pchar_msg);

}