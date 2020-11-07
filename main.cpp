/*
-----------------------------------------------------------------------------------
        Nom du fichier  : main.cpp
Nom du labo     : Labo 04 Librairie
Auteur(s)       : Nicolas Philipp, Richard Tenorio
Classe          : PRG1-B
Date création   : 06.11.20
But             : <à remplir>
Remarque(s)     : <à remplir>
Compilateur     : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/

#include <cstdlib>
#include <iostream>
#include <limits>
#include <iomanip>

#include "fonctions.h"

#define VERIF_ET_REPARER_BUFFER if(cin.fail()){ cin.clear(); }
#define VIDER_BUFFER cin.ignore(numeric_limits<streamsize>::max(), '\n');
#define VERIF_ET_REPARER_VIDER_BUFFER if(cin.fail()){ cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); }

using namespace std;

int main() {

    enum class Fonctions{
        EST_PAIR       = 1,
        SOMME_CHIFFRE  = 2,
        NBRE_1ER       = 3,
        NBRE_ARMSTRONG = 4,
        RANDOM         = 5,
        BUFFER         = 6,
        TRIGO          = 7,
        REPOND_OUI     = 0
    };

    // boucle principal du systeme
    bool statutQuitter = false;

    do {
        // display options
        cout << "\n\nOptions"                                                         << endl
             << setw(6) << right << "1" << setw(15) << left << " est pair"            << endl
             << setw(6) << right << "2" << setw(15) << left << " somme chiffres"      << endl
             << setw(6) << right << "3" << setw(15) << left << " nombre 1er"          << endl
             << setw(6) << right << "4" << setw(15) << left << " nombre de Armstrong" << endl
             << setw(6) << right << "5" << setw(15) << left << " nombre aléatoire"    << endl
             << setw(6) << right << "6" << setw(15) << left << " buffer"              << endl
             << setw(6) << right << "7" << setw(15) << left << " trigo"               << endl
             << setw(6) << right << "0" << setw(15) << left << " quitter"             << endl;

        VERIF_ET_REPARER_VIDER_BUFFER
        int choix;

        cout << "votre choix [0 - 7] : "; cin >> choix;

        switch (Fonctions(choix)) {
            case Fonctions::EST_PAIR : {

                int nbr;

                const int min = 0;
                const int max = 1000;

                do {
                    // vérif. si buffer est ok
                    VERIF_ET_REPARER_BUFFER
                    VIDER_BUFFER
                    cout << "entrer une valeur : [" << min << " - " << max << " ] : "; cin >> nbr;

                } while(nbr < min ||nbr > max);

                if(estPair(nbr)){
                    cout << nbr << " est une valeur pair";
                } else {
                    cout << nbr << " est une valeur impair";
                }

                break;
            }
            case Fonctions::SOMME_CHIFFRE: {
                int nbr;

                const int min = 0;
                const int max = 1000;

                do {
                    VERIF_ET_REPARER_BUFFER
                    VIDER_BUFFER

                    cout << "entrer une valeur : [" << min << " - " << max << " ] : "; cin >> nbr;

                }while(nbr < min ||nbr > max);

                cout << "la somme des chiffres de " << nbr << " = " << sommeChiffres(nbr) << endl;

                break;
            }
            case Fonctions::NBRE_1ER: {
                int minParDefaut = 0;
                int maxParDefaut = 1000;
                int min          = minParDefaut;
                int max          = maxParDefaut;

                do {
                    VERIF_ET_REPARER_BUFFER
                    VIDER_BUFFER

                    cout << "Determiner les nombre premiers compris dans un intervalle" << endl;
                    cout << "- debut : [ " << min << " - " << max << " ] : ";
                    cin >> min;
                    cout << "- fin   : [ " << min << " - " << max << " ] : ";
                    cin >> max;

                } while(min < minParDefaut || max > maxParDefaut);

                for(int nbr = min; nbr <= max; ++nbr){
                    if(nbre1er(nbr)) {
                        cout << "le nombre " << nbr << " est un nombre premier" << endl;
                    }
                }

                break;
            }
            case Fonctions::NBRE_ARMSTRONG: {
                const int minParDefaut = 0;
                const int maxParDefaut = 1000;
                int min;
                int max;

                do {
                    min = minParDefaut;
                    max = maxParDefaut;

                    VERIF_ET_REPARER_BUFFER
                    VIDER_BUFFER

                    cout << "Determiner les nombre premiers compris dans un intervalle" << endl;
                    cout << "- debut : [ " << min << " - " << max << " ] : ";
                    cin  >> min;
                    cout << "- fin   : [ " << min << " - " << max << " ] : ";
                    cin  >> max;

                } while(min < minParDefaut || max > maxParDefaut);

                for(int nbr = min; nbr <= max; ++nbr){
                    if(nbreArmstrong(nbr)){
                        cout << "le nombre " << nbr << " est un nombre d'Armstrong" << endl;
                    }
                }
                break;
            }
            case Fonctions::RANDOM: {
                const int minParDefaut =  -100,
                          maxParDefaut =   100,
                          minNbrRandom =     0,
                          maxNbrRandom =   100;

                int min,
                    max,
                    cbNbrRandom;

                do {
                    min         = minParDefaut,
                    max         = maxParDefaut,
                    cbNbrRandom = 1;
                    VERIF_ET_REPARER_BUFFER
                    VIDER_BUFFER

                    cout << "Determiner les nombre premiers compris dans un intervalle"                          << endl
                         << "- debut : [ " << min << " - " << max << " ] : ";                   cin >> min; cout << endl
                         << "- fin   : [ " << min << " - " << max << " ] : ";                   cin >> max; cout << endl
                                                                                                                                                                                                         << "- nbre  : [ " << minNbrRandom << " - " << maxNbrRandom << " ] : "; cin >> cbNbrRandom;

                }while ((min <= minParDefaut || max >= maxParDefaut)
                        && (cbNbrRandom <= minNbrRandom || cbNbrRandom > maxNbrRandom));

                cout << "Voici des valeurs aletoires [ " << min << " - " << max << " ]";
                for(int nbrFois = 1; nbrFois <= cbNbrRandom; ++cbNbrRandom){
                    cout << " " << random(min, max) << ","; // TODO: dectecter quand c'est le dernier et pas mettre la ","
                }

                break;
            }
            case Fonctions::BUFFER: {
                string chaineDeCaractere;
                cout << "entrer un phrase : "; cin >> chaineDeCaractere;
                buffer(chaineDeCaractere);

                break;
            }
            case Fonctions::TRIGO: {
                int       angle;
                double resultat;

                const double minAngle =   0,
                        maxAngle = 360;

                do {
                    VERIF_ET_REPARER_BUFFER
                    VIDER_BUFFER

                    cout << "entrer un angle en degre : [ " << minAngle << " - " << maxAngle << " ] : "; cin >> angle;

                } while (angle < minAngle || angle > maxAngle);

                for(int fonctions = 1; fonctions <= 3; ++ fonctions){
                    trigo(angle, resultat);
                    cout << resultat << endl; //TODO: meilleur message avec le nom de la fonction de trigo
                }

                break;
            }
            case Fonctions::REPOND_OUI: {
                char caractere;

                do {
                    VERIF_ET_REPARER_BUFFER
                    VIDER_BUFFER

                    cout << "Voulez-vous quitter = [o - n] : "; cin >> caractere;

                } while (!repondOui(caractere));
                statutQuitter = true;

                break;
            }
            default : break;
        }
    } while (!statutQuitter);

    return EXIT_SUCCESS;
}

//ecrire plein de fonction pour tester les fct et une pour demander un nombre en x et y