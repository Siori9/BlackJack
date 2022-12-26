/*!
* \file Autres.c
* \author Clara Layus <layusclara@cy-tech.fr>
* \version 0.1
* \date 26/12/2022
* \brief ensemble de fonction de saisi
* \remarks None
* 
* 
* 
*/


/*! Importation des librairies*/
#include "Autres.h"

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
int saisieEntier(int int_min, int int_max, int* pint_decalage){

    //Déclaration de la variable qui contiendra l'entier 
    int int_n;

    //Déclaration de la variable de vérification
    int int_valid = 1;

    //Déclaration de la variable qui permettra de calculer la ligne sur laquelle sera afficher les info
    int int_i = 1;

    //Déclaration et initialisation de la variable contenant le message d'erreur
    char* pchar_msg = malloc(100*sizeof(char));
    sprintf(pchar_msg,"La saisie est invalide, entrez un entier entre %d et %d: ",int_min,int_max);

    //On recommence tant que la saisie n'est pas valide
    while (int_valid)
    {
        
        //L'utilisateur va entrer un entier et la confition vérifira si il n'y a pas eu d'erreur
        if(scanw("%d",&int_n)){

            //On test si la saisie est bien entre le min et le max
            if(int_n<=int_max && int_n >= int_min){
                int_valid = 0; /*La saisie est correcte*/
            } else {
                //Notifie une erreur
                mvprintw(*pint_decalage+int_i*2, (COLS / 2) - (strlen(pchar_msg) / 2 ), pchar_msg);
            }
        } else {
            //Notifie une erreur
            mvprintw(*pint_decalage+int_i*2, (COLS / 2) - (strlen(pchar_msg) / 2), pchar_msg);
        }
        int_i++;
    }

    //Mise à jour du décalage en confonction de la dernière ligne utilisée
    *pint_decalage = *pint_decalage + int_i-1;
    
    //Libération de l'espace utilisé pour stocker le message d'erreur
    free(pchar_msg);

    //On retourne l'entier saisie
    return int_n;
}

/*!
* \fn void saisieChaine(char* tchar_tab) 
* \author Clara Layus <layusclara@cy-tech.fr>
* \version 0.1
* \date  07/12/2022
* \brief Procédure qui récupère l'entrées de l'utilisateur pour compléter le tableau de caractère
* \remarks None
* \param tchar_tab un pointeur vers une chaine de caractère
*/
void saisieChaine(char* tchar_tab) {

    char* pchar_msg = "Saisie invalide !";

    int int_i = 1;

    int verif;
    do 
    {

        // getchar(); /*On vide le buffer avant de faire le scanf*/
        verif = scanw("%[^\n]",tchar_tab); /*Récupération de la saisi jusqu'au symbole de fin de ligne (sinon il s'arrête au premier espace)*/

        if (verif != 1)
        {
            mvprintw(LINES/4+16+int_i*2, (COLS / 2) - (strlen(pchar_msg) / 2 ), pchar_msg);
        }
        int_i++;
        
    } while (verif != 1); //Recommencer tant que la saisie n'est pas valide
}