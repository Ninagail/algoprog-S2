#include <iostream>

using namespace std;

struct Noeud{
    int donnee;
    Noeud* suivant;
};

struct Liste{
    Noeud* premier;
    
};

struct DynaTableau{
    int* donnees;
    int capacite;
    int taille;
    
};


void initialise(Liste* liste)
{
    liste = new Liste;
    Noeud *noeud = new Noeud;
    noeud ->donnee =0;
    noeud->suivant = NULL;
    liste->premier = noeud;
}

bool est_vide(const Liste* liste)
{
    if (liste->premier == nullptr){
        return true;
    }
    else {
        return false;
    }
    
}

void ajoute(Liste* liste, int valeur)
{
    Noeud *newNoeud = new Noeud;
    newNoeud->donnee = valeur;

    if (liste== NULL || newNoeud == NULL){
        exit(EXIT_FAILURE);
    } 
    
    newNoeud->suivant = liste->premier;
    liste->premier=newNoeud;
    
        
    
}

void affiche(const Liste* liste)
{
   Noeud *actuel = liste->premier;
   while (actuel != NULL){

    cout << actuel->donnee << endl;
    actuel= actuel->suivant;
   } 
}

int recupere(const Liste* liste, int n)
{
    int place =0;
    Noeud *actuel = liste->premier;
    while(actuel->suivant!=nullptr && place < n){
        actuel = actuel ->suivant;
        place ++;
    }
    return actuel->donnee;
}

int cherche(const Liste* liste, int valeur)
{
    int place = 0;
    Noeud *actuel = liste->premier;
    while (actuel->suivant!= nullptr){
        if (actuel->donnee==valeur){
            return place;
        }
        actuel = actuel ->suivant;
        place ++;
    }
    return place +1;
}

void stocke(Liste* liste, int n, int valeur)
{
    int place = 0;
    Noeud *actuel = liste->premier;
    while (actuel->suivant!=nullptr && place < n){
        actuel = actuel->suivant;
        place++;
    }
    actuel->donnee = valeur;

}

void ajoute(DynaTableau* tableau, int valeur)
{
    if (tableau->capacite < tableau->taille+1)
    {
        tableau->capacite+=5;
        int *newTab = new int[tableau->capacite];
        for (int i=0; i<tableau->taille; i++){
            newTab[i]= tableau->donnees[i];
        }
        tableau->donnees=newTab;
    }

    tableau->donnees[tableau->taille] = valeur;
    tableau->taille += 1;
    
}


void initialise(DynaTableau* tableau, int capacite)
{   
    tableau->capacite = capacite;
    tableau->taille =0;
    tableau->donnees= new int[capacite];

}

bool est_vide(const DynaTableau* liste)
{
    if (liste->taille==0){
        return true;
    }
    else{
        return false;
    }
    
}

void affiche(const DynaTableau* tableau)
{
    for(int i=0; i<tableau->taille; i++){
        cout << tableau->donnees[i] << endl;
    }
}

int recupere(const DynaTableau* tableau, int n)
{
    if ((tableau->taille > n))
    {
        return tableau->donnees[n];
    }
    else{
        cout << "le tableau ne contient pas la case n" << endl;
    }
    return 0;
}

int cherche(const DynaTableau* tableau, int valeur)
{
    for (int i=0; i<tableau->taille; i++){
        if (tableau->donnees[i]== valeur){
            return i;
        }
    }
    return -1;
}

void stocke(DynaTableau* tableau, int n, int valeur)
{
    if (tableau->taille>n){
        tableau->donnees[n]=valeur;
    }
    
}

//void pousse_file(DynaTableau* liste, int valeur)
void pousse_file(Liste* liste, int valeur)
{
    Noeud *newNoeud = new Noeud;
    if (liste == NULL || newNoeud == NULL)
    {
        exit(EXIT_FAILURE);
    }

    newNoeud->donnee = valeur;
    newNoeud->suivant = NULL;

    if (liste->premier != NULL){
        Noeud *actuel = liste->premier;
        // on va à la fin de la file
        while (actuel->suivant != NULL){
            actuel = actuel->suivant;
        }
        actuel ->suivant = newNoeud;
    }
    else{
        liste->premier= newNoeud;
    }

}

//int retire_file(Liste* liste)
int retire_file(Liste* liste)
{
    int defilage = 0;
    
    if (liste->premier!=NULL){
        Noeud *noeudDefil = liste->premier;
        defilage = noeudDefil->donnee;
        liste->premier=noeudDefil->suivant;
        free(noeudDefil);
    }

    return defilage;
}

//void pousse_pile(DynaTableau* liste, int valeur)
void pousse_pile(Liste* liste, int valeur)
{
    Noeud *newNoeud = new Noeud;
    newNoeud->donnee = valeur;
    newNoeud ->suivant = liste ->premier;
    liste->premier= newNoeud;
}

//int retire_pile(DynaTableau* liste)
int retire_pile(Liste* liste)
{
    int depilage;
    Noeud *noeudDepil = liste->premier;
    if(liste == nullptr){
        exit(EXIT_FAILURE);
    }
    else if(liste != nullptr && liste->premier != nullptr){
        depilage = noeudDepil->donnee;
        liste->premier = noeudDepil->suivant;
        free(noeudDepil);
    }
    return depilage;
}


int main()
{
    Liste liste;
    initialise(&liste);
    DynaTableau tableau;
    initialise(&tableau, 5);

    if (!est_vide(&liste))
    {
        std::cout << "Oups y a une anguille dans ma liste" << std::endl;
    }

    if (!est_vide(&tableau))
    {
        std::cout << "Oups y a une anguille dans mon tableau" << std::endl;
    }

    for (int i=1; i<=7; i++) {
        ajoute(&liste, i*7);
        ajoute(&tableau, i*5);
    }

    if (est_vide(&liste))
    {
        std::cout << "Oups y a une anguille dans ma liste" << std::endl;
    }

    if (est_vide(&tableau))
    {
        std::cout << "Oups y a une anguille dans mon tableau" << std::endl;
    }

    std::cout << "Elements initiaux:" << std::endl;
    affiche(&liste);
    affiche(&tableau);
    std::cout << std::endl;

    std::cout << "5e valeur de la liste " << recupere(&liste, 4) << std::endl;
    std::cout << "5e valeur du tableau " << recupere(&tableau, 4) << std::endl;

    std::cout << "21 se trouve dans la liste à " << cherche(&liste, 21) << std::endl;
    std::cout << "15 se trouve dans la liste à " << cherche(&tableau, 15) << std::endl;

    stocke(&liste, 4, 7);
    stocke(&tableau, 4, 7);

    std::cout << "Elements après stockage de 7:" << std::endl;
    affiche(&liste);
    affiche(&tableau);
    std::cout << std::endl;

    Liste pile; // DynaTableau pile;
    Liste file; // DynaTableau file;

    initialise(&pile);
    initialise(&file);

    for (int i=1; i<=7; i++) {
        pousse_file(&file, i);
        pousse_pile(&pile, i);
    }

    int compteur = 10;
    while(!est_vide(&file) && compteur > 0)
    {
        std::cout << retire_file(&file) << std::endl;
        compteur--;
    }

    if (compteur == 0)
    {
        std::cout << "Ah y a un soucis là..." << std::endl;
    }

    compteur = 10;
    while(!est_vide(&pile) && compteur > 0)
    {
        std::cout << retire_pile(&pile) << std::endl;
        compteur--;
    }

    if (compteur == 0)
    {
        std::cout << "Ah y a un soucis là..." << std::endl;
    }

    return 0;
}
