/*!
* \file Main.c
* \author Clara Layus <layusclara@cy-tech.fr>
* \version 0.1
* \date 30/11/2022
* \brief Programme qui implémente un blackJack
* \remarks None
* 
* 
* 
*/


/*! Importation des librairies*/
#include "Main.h"


/*!void effacerZone(int int_x1, int int_y1, int int_x2, int int_y2)
* \fn int main(int argc, char** argv )
* \author Clara Layus <layusclara@cy-tech.fr>
* \version 0.1
* \date 30/11/2022
* \brief Fonction principale (Main) du programme
* \remarks None
* \param argc nombre d'arguments donnés en entrée
* \param argv valeur des arguments donnés en entrée
* \return 0 si tout s'est bien passé
*/
int main(int argc, char** argv ){

    //Commande qui permets de passer l'affichage des chaine de caractère en uft-8
    setlocale(LC_ALL, "");
    
    // Initialise la structure WINDOW et autres paramètres pour l'affichage
    initscr();

    srand(time(NULL));

    //Affichage de l'interface globale (titre et plateau) et récupération du pointeur vers l'élément plateau
    interfaceGlobal();

    //Récupérer les infos des joueurs et créer la pile de carte pour le croupier
    sTabJoueur sTabJoueur_tabJoueurs = ecranConfig();
    PileCarte* pPileCarte_carteCroupier = newPileCarte();

    //Initialisation des couleurs
    initCouleur();

    //Initialisation des variables int_numManche et int_verifArgent
    int int_numManche = 1;
    int int_verifArgent = 1;

    //Initialisation de la variable qui va contenir les messages à afficher
    char* pchar_msgPerdant = malloc(100*sizeof(char));
    sprintf(pchar_msgPerdant," ");
    int int_entree = 0;
    
    do
    {
        //Lancer la manche
        gestionManche(sTabJoueur_tabJoueurs,pPileCarte_carteCroupier,int_numManche);

        //On parcours tous les joueurs pour vérifier si ils ont encore de l'argent
        for (int i = 0; i < sTabJoueur_tabJoueurs.int_nbr; i++)
        {
            if (sTabJoueur_tabJoueurs.psJoueur_joueurs[i].int_argent == 0) //Si le joueur n'a plus d'argent
            {
                int_verifArgent = 0;
                if(strcmp(pchar_msgPerdant," ") == 0){ //Si c'est le premier 
                    sprintf(pchar_msgPerdant,"%s n'a plus d'argent !",sTabJoueur_tabJoueurs.psJoueur_joueurs[i].char_nom);
                } else { //Si d'autres joueurs n'ont plus d'argent
                    sprintf(pchar_msgPerdant,"Plusieurs joueurs n'ont plus d'argent !");
                }
            }
        }
        
        //Si aucun joueur n'est à cours d'argent
        if(int_verifArgent == 1) {

            //Message pour demander au joueur s'ils veulent continuer ou arrêter
            attron(COLOR_PAIR(CROUGE));
            mvprintw(18,COLS/2-strlen(" FIN DE LA MANCHE ")/2," FIN DE LA MANCHE ");
            attron(COLOR_PAIR(EROUGE)); 
            mvprintw(19,COLS/2-strlen("Appuyez sur Entrée pour continuer à jouer")/2,"Appuyez sur Entrée pour continuer à jouer");
            mvprintw(20,COLS/2-strlen("Appuyez sur Echap pour arrêter de jouer")/2,"Appuyez sur Echap pour arrêter de jouer");
            attron(A_NORMAL);

            move(LINES-1,COLS-1);

            //Récupération de leur choix
            do
            {
                int_entree = getch();
            } while (10 != int_entree && 27 != int_entree);
        } else {

            //Message pour annoncer au joueur la fin du jeu et leur demander de taper sur entrée
            attron(COLOR_PAIR(CROUGE));
            mvprintw(18,COLS/2-strlen(" FIN DU JEU ")/2," FIN DU JEU ");
            attron(COLOR_PAIR(EROUGE)); 
            mvprintw(19,COLS/2-strlen(pchar_msgPerdant)/2,pchar_msgPerdant);
            mvprintw(20,COLS/2-strlen("Appuyez sur Entrée pour voir le classement")/2,"Appuyez sur Entrée pour voir le classement");
            attron(A_NORMAL);

            move(LINES-1,COLS-1);

            //Récupération de l'entrée
            do
            {
                int_entree = getch();
            } while (10 != int_entree);
        }

        //On efface le plateau et on passe à la manche suivante ou à l'affichage du classement
        effacerPlateau();
        int_numManche++;
    } while (int_verifArgent == 1 && int_entree == 10); //Si tous les joueurs ont encore de l'argent et qu'ils veulent continuer

    //Affichage du classement
    classement(sTabJoueur_tabJoueurs);

    //Affichage du message pour quitter
    attron(COLOR_PAIR(EROUGE)); 
    mvprintw(LINES-20,COLS/2-strlen("Appuyez sur n'importe quel touche pour quitter !")/2,"Appuyez sur n'importe quel touche pour quitter !");
    attron(A_NORMAL);

    free(pchar_msgPerdant);

    //Fin du jeu
    move(LINES-1,COLS-1);
    getch();
    endwin();
    
    return 0;
}