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


/*! Importation des librairies*/
#include "FonctionsJeu.h"

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
void initManche(sTabJoueur sTabJoueur_tabJoueurs,PileCarte* ppileCarte_pile, PileCarte* pPileCarte_carteCroupier){

    //Distribution de 2 cartes à chaque joueurs
    for (int i = 0; i < sTabJoueur_tabJoueurs.int_nbr; i++)
    {
        distribuerCarte(sTabJoueur_tabJoueurs.psJoueur_joueurs[i].pPileCarte_cartes,ppileCarte_pile);
        distribuerCarte(sTabJoueur_tabJoueurs.psJoueur_joueurs[i].pPileCarte_cartes,ppileCarte_pile);
    }

    //Distribution de 2 cartes au croupier
    distribuerCarte(pPileCarte_carteCroupier,ppileCarte_pile);
    distribuerCarte(pPileCarte_carteCroupier,ppileCarte_pile);
}

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
void recupMise(sTabJoueur sTabJoueur_tabJoueurs, int int_numManche){

    int int_ligne = LINES/4;

    //Affichage titre
    char* pchar_msg = malloc(100*sizeof(char));
    sprintf(pchar_msg,"MANCHE %d",int_numManche);
    mvprintw(int_ligne, (COLS / 2) - (strlen(pchar_msg) / 2),pchar_msg);

    //On parcours chaque joueur
    for (int i = 0; i < sTabJoueur_tabJoueurs.int_nbr; i++)
    {
        //Message pour demander la mise
        int_ligne = int_ligne+3;
        sprintf(pchar_msg,"%s, combien misez vous ? (Entre 1 et %d) ",sTabJoueur_tabJoueurs.psJoueur_joueurs[i].char_nom,sTabJoueur_tabJoueurs.psJoueur_joueurs[i].int_argent);
        mvprintw(int_ligne, (COLS / 2) - (strlen(pchar_msg) / 2),pchar_msg);
        
        //récupération de la mise
        int_ligne = int_ligne+2;
        move(int_ligne, (COLS / 2)-1);
        sTabJoueur_tabJoueurs.psJoueur_joueurs[i].int_mise = saisieEntier(1,sTabJoueur_tabJoueurs.psJoueur_joueurs[i].int_argent,&int_ligne);
    }

    //On libère la place prise par la chaine de caratère utilisé pour les différents messages
    free(pchar_msg);

    //Affichage du message pour commencer le jeu
    char tchar_msg[] = "Tapez sur ENTREE pour commencer !";
    mvprintw(int_ligne+4, (COLS / 2) - (strlen(tchar_msg) / 2), tchar_msg);

    while (10 != getch()) {} 

    //Efface le contenue du plateau
    effacerPlateau();

    //Actualisation de la page
    refresh();
}

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
int recupChoix(sJoueur sJoueur_joueur){
    
    //Affichage messages de choix
    char* pchar_msg = malloc(100*sizeof(char));
    sprintf(pchar_msg," Au tour de %s ",sJoueur_joueur.char_nom);

    attron(COLOR_PAIR(CROUGE));
    mvprintw(18,COLS/2-strlen(pchar_msg)/2,pchar_msg);
    attron(COLOR_PAIR(EROUGE));
    mvprintw(19,COLS/2-strlen("Appuyez sur Espace pour demander une carte")/2,"Appuyez sur Espace pour demander une carte");
    mvprintw(20,COLS/2-strlen("Appuyez sur Entrée pour finir votre tour")/2,"Appuyez sur Entrée pour finir votre tour");
    attron(A_NORMAL);

    //Récupération du choix
    int int_entree = 0;
    do
    {
        int_entree = getch();
    } while (10 != int_entree && 32 != int_entree); // On boucle tant que l'entrée n'est pas égale à 10 (entrée) ou 32 (espace)

    if(int_entree == 10){ //Si le joueur a tapé sur entrée, on retourne 1
        return 1;
    } else { //Si il a tapé sur espace, on retourne 2
        return 2;
    }

    //On efface la zone de message
    effacerZone(LINES/2,COLS/2-strlen(pchar_msg)/2,LINES/2+1,COLS/2+strlen(pchar_msg)/2+1);

    free(pchar_msg);
}

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
void gestionManche(sTabJoueur sTabJoueur_tabJoueurs,PileCarte* pPileCarte_carteCroupier, int int_numManche){

    //Initialisation du paquet de carte
    PileCarte* ppileCarte_pile = newPileCarte();
    initJeuCarte(ppileCarte_pile);

    //Tous les joueurs sont remis en jeu
    for (int i = 0; i < sTabJoueur_tabJoueurs.int_nbr; i++)
    {
        sTabJoueur_tabJoueurs.psJoueur_joueurs[i].int_enJeu = 1;
    }
    
    //On récupère les mises
    recupMise(sTabJoueur_tabJoueurs,int_numManche);

    //On initialise la manche (premières distribution de carte)
    initManche(sTabJoueur_tabJoueurs,ppileCarte_pile, pPileCarte_carteCroupier);

    //On affiche le jeu
    affichageJeu(sTabJoueur_tabJoueurs,pPileCarte_carteCroupier,0);

    //Pour chaque joueur
    for (int i = 0; i < sTabJoueur_tabJoueurs.int_nbr; i++)
    {
        int choix = 0; /*On initialise la variable de choix*/
        do
        {
            //On récupère le choix du joueur
            choix = recupChoix(sTabJoueur_tabJoueurs.psJoueur_joueurs[i]);

            //Si le choix du joueur est de prendre une nouvelle carte
            if(choix == 2){

                //On distribue une carte
                distribuerCarte(sTabJoueur_tabJoueurs.psJoueur_joueurs[i].pPileCarte_cartes,ppileCarte_pile);

                //On vérifie le score du joueur pour voir si il est toujours en jeu
                if(totalCarte(sTabJoueur_tabJoueurs.psJoueur_joueurs[i].pPileCarte_cartes) == 0){
                    sTabJoueur_tabJoueurs.psJoueur_joueurs[i].int_enJeu = 0;
                    choix = 1;
                }

                //On efface et on affiche de nouveau le jeu
                effacerPlateau();
                refresh();
                affichageJeu(sTabJoueur_tabJoueurs,pPileCarte_carteCroupier,0);
            }
        } while (choix == 2); //On boucle tant que le joueur pioche de nouvelles cartes
        
    } 

    //On distribue des cartes au croupier tant que son score est inférieur à 17
    while (totalCarte(pPileCarte_carteCroupier) < 17 && 0 < totalCarte(pPileCarte_carteCroupier))
    {
        distribuerCarte(pPileCarte_carteCroupier,ppileCarte_pile);
    }

    //On cérifie les résultat
    calculScore(sTabJoueur_tabJoueurs,pPileCarte_carteCroupier);

    //On affiche de nouveau le jeu actualisé
    effacerPlateau();
    refresh();
    affichageJeu(sTabJoueur_tabJoueurs,pPileCarte_carteCroupier,1);

    //On vide la pile de carte générale et la pile de carte de chaque joueur et du croupier
    free(ppileCarte_pile);
    for (int i = 0; i < sTabJoueur_tabJoueurs.int_nbr; i++)
    {
        viderPile(sTabJoueur_tabJoueurs.psJoueur_joueurs[i].pPileCarte_cartes);
    }
    viderPile(pPileCarte_carteCroupier);

    move(LINES-1,COLS-1);
}