/*
-----------------------------------------------------------------------------------
Nom du fichier  : fonctions.cpp
Nom du labo     : Labo_04
Auteur(s)       : Nicolas Philipp, Richard Tenorio
Classe          : PRG1-B
Date création   : 05.11.20
But             : Librarie de fonctions
Remarque(s)     : <à remplir>
Compilateur     : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/

#include <iostream> // cout
#include <string>   // type string
#include <cmath>    // trigo

#include "fonctions.h"

bool estPair(int valeur){
    return not(valeur % 2);
}

int sommeChiffres(int valeur){ //valeur négative et à virgule ???
    int sommeChiffres = 0;
    while (valeur > 0){
        sommeChiffres += valeur % 10;
        valeur /= 10;
    }
    return sommeChiffres;
}

bool nbre1er(int valeur){
    for (int i = 2 ; i <= sqrt(valeur) ; ++i){
        if (not(valeur % i)){
            return false;
        }
    }
    return true;
}

bool nbreArmstrong(int valeur){
    int chiffre;
    int calculnbreArmstrong  = 0;
    int copie_valeur         = valeur;
    while (valeur > 0){
        chiffre = valeur % 10;
        valeur /= 10;
        calculnbreArmstrong += (int)pow(chiffre, 3);
    }
    return copie_valeur == calculnbreArmstrong;
}

// source : https://stackoverflow.com/a/7560171
int random(int min, int max){
    static bool premiereFois = true;
    if (premiereFois){
        // Initialisation du générateur aléatoire
        std::srand((unsigned)time(nullptr));
        premiereFois = false;
    }
    return min + std::rand() % (( max + 1 ) - min);
}

void buffer(const std::string& chaineDeCaractere){
    // déclaration de variable
    char plusPetiteMinuscule = ' ';
    char plusGrandeMajuscule = ' ';
    // boucler sur la chaine de caractère
    for(char lettre : chaineDeCaractere){
        // selon la table ascii
        // si la lettre est entre 97 et 122 => minuscule
        // si la lettre est entre 65 et 90 => majuscule
        if(lettre >= 65 && lettre <= 90){
            if(plusGrandeMajuscule == ' '){
               plusGrandeMajuscule = lettre;
            }
            if(lettre > plusGrandeMajuscule){
                plusGrandeMajuscule = lettre;
            }
        } else if (lettre >= 97 && lettre <= 122){
            if(plusPetiteMinuscule == ' '){
                plusPetiteMinuscule = lettre;
            }
            if(lettre < plusPetiteMinuscule){
                plusPetiteMinuscule = lettre;
            }
        }
    }

    std::cout << "Plus petit minuscule:  " << plusPetiteMinuscule        << std::endl;
    std::cout << "Plus grande majuscule: " << plusGrandeMajuscule        << std::endl;
    std::cout << "Nombre de lettre:      " << chaineDeCaractere.length() << std::endl;
}

                         // TODO: retourner les valeur dans result après
void trigo(double angle/*, double& resultat*/){
    const int nbrFonctions = 3;

    for(int calculer = 1; calculer <= nbrFonctions; ++calculer){
       switch(calculer) {
           case 1 : std::cout << sin(angle) << std::endl; break;
           case 2 : std::cout << cos(angle) << std::endl; break;
           case 3 : std::cout << tan(angle) << std::endl; break;
           default: std::cout << "Erreur"   << std::endl; break;
       }
    }
}

bool repondOui(char reponse){
    if(reponse == 'o' || reponse == 'O'){
        return true;
    }
    return false;
}



