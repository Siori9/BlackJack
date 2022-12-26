/*!
* \file Mecanismes.c
* \author Clara Layus <layusclara@cy-tech.fr>
* \version 0.1
* \date 14/12/2022
* \brief fonctions liés aux piles
* \remarks None
* 
* 
* 
*/


/*! Importation des librairies*/
#include "Mecanismes.h"

/*!
* \fn PileCarte* newPileCarte() 
* \author Clara Layus <layusclara@cy-tech.fr>
* \version 0.1
* \date  26/12/2022
* \brief la fonction initialise une nouvelle pile de carte
* \remarks None
* \return retourne une nouvelle pile
*/
PileCarte* newPileCarte() {

    //initialisation de la nouvelle pile
    PileCarte* pPileCarte_pile = malloc(sizeof(PileCarte));

    //on met le pointeur vers la première carte à null
    pPileCarte_pile->tete = NULL;

    //on met le nombre de carte à 0
    pPileCarte_pile->taille = 0;

    //on retourne la nouvelle pile
    return pPileCarte_pile;
} 

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
void empilerPile(PileCarte* ppileCarte_pile, sCarte sCarte_carte){

    //initialisation de l'objet objetPileCarte
    psObjetPileCarte psObjetPileCarte_element = malloc(1*sizeof(sObjetPileCarte));

    //on donne pour la valeur de la carte de notre objet notre carte à empiler
    psObjetPileCarte_element->sCarte_carte = sCarte_carte;
    
    //on ajoute l'objet à la pile
    psObjetPileCarte_element->ppileCarte_carteSuivante = ppileCarte_pile->tete;
    ppileCarte_pile->tete = psObjetPileCarte_element;

    //On augmente la caractéristique taille de la pile
    ppileCarte_pile->taille++;
}

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
sCarte depilerPile(PileCarte* ppileCarte_pile){

    //On récupère le premier objetPileCarte de la pile
    psObjetPileCarte psObjetPileCarte_element = ppileCarte_pile->tete;

    //On récupère la carte associée
    sCarte sCarte_carte = psObjetPileCarte_element->sCarte_carte;

    //On enlève l'objet de la pile
    ppileCarte_pile->tete = psObjetPileCarte_element->ppileCarte_carteSuivante;

    //On diminue la caractéristique taille de la pile de 1
    ppileCarte_pile->taille--;

    //On libère la mémoire associé à l'objet que l'on a dépilé
    free(psObjetPileCarte_element);

    //On retourne la carte
    return sCarte_carte;
}

/*!
* \fn void viderPile(PileCarte* ppileCarte_pile)
* \author Clara Layus <layusclara@cy-tech.fr>
* \version 0.1
* \date  26/12/2022
* \brief la fonction vide complêtement une pile
* \remarks None
* \param ppileCarte_pile pile à vider
*/
void viderPile(PileCarte* ppileCarte_pile){

    while (ppileCarte_pile->taille != 0) //On boucle tant que la pile n'est pas vide
    {
        depilerPile(ppileCarte_pile); //On dépile l'élément en tête de la pile
    }
}

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
void decalerTab(psCarte* tpsCarte_jeuCarte,int int_indiceTire){

    //On boucle de l'indice donnée à la findu tableau
    for (int i = int_indiceTire; i < 51; i++)
    {
        tpsCarte_jeuCarte[i] = tpsCarte_jeuCarte[i+1]; //On met l'élément d'indice *i+1 dans la case i
    }
} 

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
void melangePileCarte(PileCarte* ppileCarte_pile, psCarte* tpsCarte_jeuCarte) {
    
    //On initialise la variable qui va servir à stocker les index tirés
    int int_indexTire;

    //On boucle 52 fois (nombre de carte)
    for (int i = 0; i < 52; i++)
    {
        //On tire un index au hasard entre 0 et 52-i (correspondant au nombre total de carte moins le nombre de carte déjà tirées)
        int_indexTire = rand() % (52-i);

        //On empile la carte dont l'index est celui tiré
        empilerPile(ppileCarte_pile,*tpsCarte_jeuCarte[int_indexTire]); 

        //On décale les élément à partir de l'index pour ne pas repiocher la même carte
        decalerTab(tpsCarte_jeuCarte,int_indexTire);
    }

}

/*!
* \fn void initJeuCarte(PileCarte* ppileCarte_pile)
* \author Clara Layus <layusclara@cy-tech.fr>
* \version 0.1
* \date  14/12/2022
* \brief la procédure crée le jeu de carte initiale
* \remarks None
* \param ppileCarte_pile la pile qui va recevoir les cartes
*/
void initJeuCarte(PileCarte* ppileCarte_pile){

    //On initialise le tableau qui va contenir les cartes
    psCarte* tpsCarte_jeuCarte = malloc(52*sizeof(psCarte));

    //On initialise la variable qui va correspondre à la valeur de la carte
    int v = 1;

    //On boucle pour créer toutes les cartes, de 4 en 4 jusqu'à 52
    for (int i = 0; i < 52; i=i+4) 
    {

        //Création de la carte coeur de valeur v
        psCarte psCarte_carteCoeur = malloc(1*sizeof(sCarte));
        psCarte_carteCoeur->eCouleur_couleur = Coeur;
        psCarte_carteCoeur->int_valeur = v;
        tpsCarte_jeuCarte[i] = psCarte_carteCoeur;

        //Création de la carte pique de valeur v
        psCarte sCarte_cartePique = malloc(1*sizeof(sCarte));
        sCarte_cartePique->eCouleur_couleur = Pique;
        sCarte_cartePique->int_valeur = v;
        tpsCarte_jeuCarte[i+1] = sCarte_cartePique;

        //Création de la carte trèfle de valeur v
        psCarte sCarte_carteTrefle = malloc(1*sizeof(sCarte));
        sCarte_carteTrefle->eCouleur_couleur = Trefle;
        sCarte_carteTrefle->int_valeur = v;
        tpsCarte_jeuCarte[i+2] = sCarte_carteTrefle;

        //Création de la carte carreau de valeur v
        psCarte sCarte_carteCarreau = malloc(1*sizeof(sCarte));
        sCarte_carteCarreau->eCouleur_couleur = Carreau;
        sCarte_carteCarreau->int_valeur = v;
        tpsCarte_jeuCarte[i+3] = sCarte_carteCarreau;

        v++;
    }
    
    //On mélange les carte et on les mets dans la pile
    melangePileCarte(ppileCarte_pile,tpsCarte_jeuCarte);

    //On libère l'espace utiliser par le tableau
    free(tpsCarte_jeuCarte);
    
}

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
void distribuerCarte(PileCarte* pPileCarte_carteJoueur,PileCarte* ppileCarte_pile){

    //On récupère une carte de la pioche
    sCarte sCarte_carte = depilerPile(ppileCarte_pile);

    //et on l'empile sur la pile du joueur/croupier
    empilerPile(pPileCarte_carteJoueur,sCarte_carte);
}