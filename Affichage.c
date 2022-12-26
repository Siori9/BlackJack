/*!
* \file Affichage.c
* \author Clara Layus <layusclara@cy-tech.fr>
* \version 0.1
* \date 12/12/2022
* \brief ensemble des fonctions d'affichage
* \remarks None
* 
* 
* 
*/

/*! Importation des librairies*/
#include "Affichage.h"

/*!
* \fn void effacerPlateau()
* \author Clara Layus <layusclara@cy-tech.fr>
* \version 0.1
* \date  12/12/2022
* \brief la fonction efface l'interrieur du plateau en appelant la fonction affacerZone avec les bonnes dimentions 
* \remarks None
*/
void effacerPlateau(){
    effacerZone(11,COLS*1/20+1,LINES*3/4+8,COLS*9/10+COLS*1/20-2);
}

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
void effacerZone(int int_x1, int int_y1, int int_x2, int int_y2){

    attron(COLOR_PAIR(EBLANC));
    //On parcours toutes les case et on met des espaces
    for (int i = int_x1; i <= int_x2; i++)
    {
        for (int j = int_y1; j < int_y2; j++)
        {
            //On remplace chaque emplacement par un espace
            mvprintw(i, j, " ");
        }
    }
    attron(A_NORMAL);
}

/*!
* \fn void initCouleur()
* \author Clara Layus <layusclara@cy-tech.fr>
* \version 0.1
* \date  26/12/2022
* \brief la fonction initialise les couleurs utiliser avec ncurses
* \remarks None
*/
void initCouleur(){

    //Initialisation des couleurs
    start_color();
    init_pair(CBLANC, COLOR_WHITE, COLOR_WHITE); /*Ecriture blanche sur fond blanc*/ 
    init_pair(CROUGE, COLOR_RED, COLOR_WHITE); /*Ecriture rouge sur fond blanc*/ 
    init_pair(CNOIR, COLOR_BLACK, COLOR_WHITE); /*Ecriture noir sur fond blanc*/ 
    init_pair(CBLEU, COLOR_BLUE, COLOR_WHITE); /*Ecriture bleu sur fond blanc*/ 
    init_pair(EBLANC, COLOR_WHITE, COLOR_BLACK); /*Ecriture blanche sur fond noir*/ 
    init_pair(EBLEU, COLOR_BLUE, COLOR_BLACK); /*Ecriture bleu sur fond noir*/ 
    init_pair(EROUGE, COLOR_RED, COLOR_BLACK); /*Ecriture red sur fond noir*/ 

}

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
void affichageDosCarte( int int_x, int int_y) {

    //Création d'une carte en déterminant la couleur et en remplisant un rectangle de 3 sur 5
    attron(COLOR_PAIR(CBLANC));
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            mvprintw(int_x+i,int_y+j," ");
        }
        
    }
    attron(A_NORMAL);
}

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
void affichageCarte(sCarte sCarte_carte, int int_x, int int_y, int int_enJeu){

    //Création de la carte
    affichageDosCarte(int_x,int_y);
    

    //Initialisation de la variable qui contiendra la chaine de caractère de la carte
    char* pchar_ecrit = malloc(5*sizeof(char));
    char* pchar_valeur = malloc(3*sizeof(char));

    //Détermination de la valeur en fonction du numéro associé à la carte
    switch (sCarte_carte.int_valeur)
    {
    case 11: //Valet
        pchar_valeur = "J"; 
        break;
    case 12: //Dame
        pchar_valeur = "Q";
        break;
    case 13: //Roi
        pchar_valeur = "K";
        break;
    case 1: //Ace
        pchar_valeur = "A";
        break;
    case 10: //10
        pchar_valeur = "10";
        break;
    default: //Autres valeurs
        sprintf(pchar_valeur, "%d",sCarte_carte.int_valeur);
        break;
    }
    
    //Affichage de la carte
    switch (sCarte_carte.eCouleur_couleur)
    {
    case 1: //Couleur coeur, c'est donc une carte rouge
        if(int_enJeu == 0){ //Si le joueur n'est plus en jeu, l'écriture de la carte passe en bleu
            attron(COLOR_PAIR(CBLEU));
        } else {
            attron(COLOR_PAIR(CROUGE));
        }
        //Création de la carte
        sprintf(pchar_ecrit, "%s♥ ",pchar_valeur);
        break;
    case 2: //Couleur pique, c'est donc une carte noir
        if(int_enJeu == 0){ //Si le joueur n'est plus en jeu, l'écriture de la carte passe en bleu
            attron(COLOR_PAIR(CBLEU));
        } else {
            attron(COLOR_PAIR(CNOIR));
        }
        //Création de la carte
        sprintf(pchar_ecrit, "%s♠ ",pchar_valeur);
        break;
    case 3: //Couleur trèfle, c'est donc une carte noir
        if(int_enJeu == 0){ //Si le joueur n'est plus en jeu, l'écriture de la carte passe en bleu
            attron(COLOR_PAIR(CBLEU));
        } else {
            attron(COLOR_PAIR(CNOIR));
        }
        //Création de la carte
        sprintf(pchar_ecrit, "%s♣ ",pchar_valeur);
        break;
    case 4: //Couleur carreau, c'est donc une carte rouge
        if(int_enJeu == 0){ //Si le joueur n'est plus en jeu, l'écriture de la carte passe en bleu
            attron(COLOR_PAIR(CBLEU));
        } else {
            attron(COLOR_PAIR(CROUGE));
        }
        //Création de la carte
        sprintf(pchar_ecrit, "%s♦ ",pchar_valeur);
        break;
    default:
        break;
    }

    attron(A_NORMAL);

    //Affichage de la carte
    mvprintw(int_x+1,int_y+1,pchar_ecrit);

    free(pchar_ecrit);
}


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
void affichageInfoJoueur(sJoueur sJoueur_joueur,int int_x, int int_y){

    //Variable pour parcourir les cartes du joueur
    psObjetPileCarte psObjetPileCarte_objCarte = sJoueur_joueur.pPileCarte_cartes->tete;

    //Affichage de toutes les cartes du joueur
    for (int i = 0; i < sJoueur_joueur.pPileCarte_cartes->taille; i++)
    {
        affichageCarte(psObjetPileCarte_objCarte->sCarte_carte,int_x,int_y+6*i,sJoueur_joueur.int_enJeu); //Affichage
        psObjetPileCarte_objCarte = psObjetPileCarte_objCarte->ppileCarte_carteSuivante; //Passage à la carte suivante
    }

    //Vérification si le joueur est encore en jeu ou pas
    if (sJoueur_joueur.int_enJeu == 0)
    {
        attron(COLOR_PAIR(EBLEU)); //Joueur plus en jeu, l'écriture sera bleu
    } else {
        attron(COLOR_PAIR(EBLANC)); //Joueur en jeu, l'écriture sera blanche
    }

    //Initialisation de la chaine
    char* pchar_chaine = malloc(200*sizeof(char));

    //Affichage du nom du joueur
    sprintf(pchar_chaine,"%s",sJoueur_joueur.char_nom);
    mvprintw(int_x+4,int_y+(sJoueur_joueur.pPileCarte_cartes->taille*6/2)-strlen(pchar_chaine)/2-1,pchar_chaine);

    //Affichage de la mise du joueur
    if(sJoueur_joueur.int_mise != 0)
    {
        sprintf(pchar_chaine,"Mise: %d",sJoueur_joueur.int_mise); //Si la mise a été déterminé
    }
    else 
    {
        sprintf(pchar_chaine,"Mise: -"); //Si la mise n'a pas été déterminé
    }
    mvprintw(int_x+5,int_y+(sJoueur_joueur.pPileCarte_cartes->taille*6/2)-strlen(pchar_chaine)/2-1,pchar_chaine);

    //Affichage de l'argent du joueur
    sprintf(pchar_chaine,"Argent: %d",sJoueur_joueur.int_argent);
    mvprintw(int_x+6,int_y+(sJoueur_joueur.pPileCarte_cartes->taille*6/2)-strlen(pchar_chaine)/2-1,pchar_chaine);

    attron(A_NORMAL);

    free(pchar_chaine);
}

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
void affichageCroupier(PileCarte* pPilecarte_carteCroupier, int int_x, int int_y, int int_carteCroupierVisible) {

    //Variable pour parcourir les cartes du croupier
    psObjetPileCarte psObjetPileCarte_objCarte = pPilecarte_carteCroupier->tete;

    //Affichage des cartes
    for (int i = 0; i < pPilecarte_carteCroupier->taille; i++)
    {
        if (pPilecarte_carteCroupier->taille == 2 && i==1 && int_carteCroupierVisible == 0) //Si toutes les cartes ne doivent pas être affiché, on vérifie si c'est la dernière carte sur 2
        {
            affichageDosCarte(int_x,int_y+6*i); //On n'affiche pas la valeur de la dernière carte si il n'y en a que 2
        } else {
            affichageCarte(psObjetPileCarte_objCarte->sCarte_carte,int_x,int_y+6*i,1); //Sinon on affiche la carte
        }
        psObjetPileCarte_objCarte = psObjetPileCarte_objCarte->ppileCarte_carteSuivante; //Passage à la carte suivante
    }

    attron(COLOR_PAIR(EBLANC));

    //Affichage du nom "Croupier"
    mvprintw(int_x+4,int_y+(pPilecarte_carteCroupier->taille*6/2)-strlen("Croupier")/2-1,"Croupier");

    attron(A_NORMAL);
}

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
void affichageJeu(sTabJoueur sTabJoueur_tabJoueurs, PileCarte* pPileCarte_carteCroupier, int int_carteCroupierVisible){

    switch (sTabJoueur_tabJoueurs.int_nbr) //l'emplacement des joueurs varie en fonction du nombre de joueur
    {
    case 1: // 1 joueur
        affichageInfoJoueur(sTabJoueur_tabJoueurs.psJoueur_joueurs[0],LINES*3/4,COLS/2-sTabJoueur_tabJoueurs.psJoueur_joueurs[0].pPileCarte_cartes->taille*3);
        break;
    case 2: // 2 joueurs
        affichageInfoJoueur(sTabJoueur_tabJoueurs.psJoueur_joueurs[0],LINES*3/4,COLS/4-sTabJoueur_tabJoueurs.psJoueur_joueurs[0].pPileCarte_cartes->taille*3);
        affichageInfoJoueur(sTabJoueur_tabJoueurs.psJoueur_joueurs[1],LINES*3/4,COLS*3/4-sTabJoueur_tabJoueurs.psJoueur_joueurs[1].pPileCarte_cartes->taille*3);
        break;
    case 3: // 3 joueurs
        affichageInfoJoueur(sTabJoueur_tabJoueurs.psJoueur_joueurs[0],LINES*3/4,COLS/2-sTabJoueur_tabJoueurs.psJoueur_joueurs[0].pPileCarte_cartes->taille*3);
        affichageInfoJoueur(sTabJoueur_tabJoueurs.psJoueur_joueurs[1],LINES*11/20,COLS/4-sTabJoueur_tabJoueurs.psJoueur_joueurs[1].pPileCarte_cartes->taille*3);
        affichageInfoJoueur(sTabJoueur_tabJoueurs.psJoueur_joueurs[2],LINES*11/20,COLS*3/4-sTabJoueur_tabJoueurs.psJoueur_joueurs[2].pPileCarte_cartes->taille*3);
        break;
    case 4: // 4 joueurs
        affichageInfoJoueur(sTabJoueur_tabJoueurs.psJoueur_joueurs[0],LINES/2,COLS/4-sTabJoueur_tabJoueurs.psJoueur_joueurs[0].pPileCarte_cartes->taille*3);
        affichageInfoJoueur(sTabJoueur_tabJoueurs.psJoueur_joueurs[1],LINES/2,COLS*3/4-sTabJoueur_tabJoueurs.psJoueur_joueurs[1].pPileCarte_cartes->taille*3);
        affichageInfoJoueur(sTabJoueur_tabJoueurs.psJoueur_joueurs[2],LINES*3/4,COLS/4-sTabJoueur_tabJoueurs.psJoueur_joueurs[2].pPileCarte_cartes->taille*3);
        affichageInfoJoueur(sTabJoueur_tabJoueurs.psJoueur_joueurs[3],LINES*3/4,COLS*3/4-sTabJoueur_tabJoueurs.psJoueur_joueurs[3].pPileCarte_cartes->taille*3);
        break;
    case 5: // 5 joueurs
        affichageInfoJoueur(sTabJoueur_tabJoueurs.psJoueur_joueurs[0],LINES*16/40,COLS/4-sTabJoueur_tabJoueurs.psJoueur_joueurs[0].pPileCarte_cartes->taille*3);
        affichageInfoJoueur(sTabJoueur_tabJoueurs.psJoueur_joueurs[1],LINES*16/40,COLS*3/4-sTabJoueur_tabJoueurs.psJoueur_joueurs[1].pPileCarte_cartes->taille*3);
        affichageInfoJoueur(sTabJoueur_tabJoueurs.psJoueur_joueurs[2],LINES*12/20,COLS/4-sTabJoueur_tabJoueurs.psJoueur_joueurs[2].pPileCarte_cartes->taille*3);
        affichageInfoJoueur(sTabJoueur_tabJoueurs.psJoueur_joueurs[3],LINES*12/20,COLS*3/4-sTabJoueur_tabJoueurs.psJoueur_joueurs[3].pPileCarte_cartes->taille*3);
        affichageInfoJoueur(sTabJoueur_tabJoueurs.psJoueur_joueurs[4],LINES*31/40,COLS/2-sTabJoueur_tabJoueurs.psJoueur_joueurs[4].pPileCarte_cartes->taille*3);
        break;
    default:
        break;
    }

    //Affichage du croupier et de la pioche
    affichageCroupier(pPileCarte_carteCroupier,12,COLS/2-pPileCarte_carteCroupier->taille*3, int_carteCroupierVisible);
    affichageDosCarte(LINES/2,COLS/2-3);
}


/*!
* \fn WINDOW * interfaceGlobal()
* \author Clara Layus <layusclara@cy-tech.fr>
* \version 0.1
* \date  08/12/2022
* \brief Fonction qui affiche l'interface générale (titre et plateau)
* \remarks None
* \return un pointeur vers la fenêtre correspondant au plateau
*/
WINDOW * interfaceGlobal(){

    //Déclaration des chaine de caractère composant mon titre
    char* pchar_titre1 = "██████  ██       █████   ██████ ██   ██      ██  █████   ██████ ██   ██ ";
    char* pchar_titre2 = "██   ██ ██      ██   ██ ██      ██  ██       ██ ██   ██ ██      ██  ██  ";
    char* pchar_titre3 = "██████  ██      ███████ ██      █████        ██ ███████ ██      █████   ";
    char* pchar_titre4 = "██   ██ ██      ██   ██ ██      ██  ██  ██   ██ ██   ██ ██      ██  ██  ";
    char* pchar_titre5 = "██████  ███████ ██   ██  ██████ ██   ██  █████  ██   ██  ██████ ██   ██ ";
   
    //Affichage du titre à partir de la ligne 2 
    mvprintw(2, (COLS / 2) - (strlen(pchar_titre1)/4), pchar_titre1);
    mvprintw(3, (COLS / 2) - (strlen(pchar_titre1)/4), pchar_titre2);
    mvprintw(4, (COLS / 2) - (strlen(pchar_titre1)/4), pchar_titre3);
    mvprintw(5, (COLS / 2) - (strlen(pchar_titre1)/4), pchar_titre4);
    mvprintw(6, (COLS / 2) - (strlen(pchar_titre1)/4), pchar_titre5);

    //Création d'une sous fenêtre correspondant à mon plateau
    WINDOW *pWindow_plateau;
    pWindow_plateau= subwin(stdscr, LINES*3/4, COLS*9/10, 10, COLS*1/20);

    //Affichage du plateau
    box(pWindow_plateau, ACS_VLINE, ACS_HLINE); // ACS_VLINE et ACS_HLINE sont des constantes qui génèrent des bordures par défaut

    //Retour du pointeur du plateau
    return pWindow_plateau;
}

/*!
* \fn void classement(sTabJoueur sTabJoueur_tabJoueurs)
* \author Clara Layus <layusclara@cy-tech.fr>
* \version 0.1
* \date  26/12/2022
* \brief la fonction qui affiche le classement final
* \remarks None
* \param sTabJoueur_tabJoueurs info des joueurs
*/
void classement(sTabJoueur sTabJoueur_tabJoueurs){

    //Initialisation du tableau de joueur
    sJoueur* tsJoueur_tabClassement = malloc(sTabJoueur_tabJoueurs.int_nbr*sizeof(sJoueur));

    //Remplissage du tableau
    for (int i = 0; i < sTabJoueur_tabJoueurs.int_nbr; i++)
    {
        tsJoueur_tabClassement[i] = sTabJoueur_tabJoueurs.psJoueur_joueurs[i];
    }
    
    //Tri du tableau
    sJoueur sJoueur_temp;
    for (int i=1 ; i <= sTabJoueur_tabJoueurs.int_nbr-1; i++) {
        int j = i;
        while (j > 0 && tsJoueur_tabClassement[j-1].int_argent < tsJoueur_tabClassement[j].int_argent) {
            sJoueur_temp = tsJoueur_tabClassement[j];
            tsJoueur_tabClassement[j] = tsJoueur_tabClassement[j-1];
            tsJoueur_tabClassement[j-1] = sJoueur_temp;
            j--;
        }
    }

    //Affichage titre
    attron(COLOR_PAIR(CROUGE));
    mvprintw(15,COLS/2-strlen(" CLASSEMENT ")/2," CLASSEMENT ");
    attron(COLOR_PAIR(EBLANC));

    //Affichage information joueur
    for (int i = 0; i < sTabJoueur_tabJoueurs.int_nbr; i++)
    {
        char* pchar_msg = malloc(200*sizeof(char));
        sprintf(pchar_msg,"%d- %s [%d]",i+1,tsJoueur_tabClassement[i].char_nom,tsJoueur_tabClassement[i].int_argent); //Joueur + argent
        mvprintw(17+i*2,COLS/2-strlen(pchar_msg)/2,pchar_msg);
        free(pchar_msg);
    }
    attron(A_NORMAL);

    free(tsJoueur_tabClassement);
    
}