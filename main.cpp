/*
-----------------------------------------------------------------------------------
Nom du fichier  : <à remplir>
Nom du labo     : <à remplir>
Auteur(s)       : Nicolas Philipp
Classe          : PRG1-B
Date création   : <à remplir>
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

#define CLEAR_BUFFER    cin.clear();\
                        cin.ignore(numeric_limits<streamsize>::max(), '\n')

using namespace std;

int main() {


    enum class Fonctions{
        EST_PAIR=1,
        SOMME_CHIFFRE,
        NBRE_1ER,
        NBRE_ARMSTRONG,
        RANDOM,
        BUFFER,
        TRIGO,
        REPOND_OUI
    };

    cout << "Options" << endl;
    // display options
    for(Fonctions fonctions = Fonctions::EST_PAIR;
        fonctions <= Fonctions::REPOND_OUI;
        fonctions = Fonctions((int)fonctions + 1)){

        switch ((int)fonctions) {
            case 1: cout << setw(6) << right << "1" << setw(15) << left << " est pair"            << endl; break;
            case 2: cout << setw(6) << right << "2" << setw(15) << left << " somme chiffres"      << endl; break;
            case 3: cout << setw(6) << right << "3" << setw(15) << left << " nombre 1er"          << endl; break;
            case 4: cout << setw(6) << right << "4" << setw(15) << left << " nombre de Armstrong" << endl; break;
            case 5: cout << setw(6) << right << "5" << setw(15) << left << " nombre aléatoire"    << endl; break;
            case 6: cout << setw(6) << right << "6" << setw(15) << left << " buffer"              << endl; break;
            case 7: cout << setw(6) << right << "7" << setw(15) << left << " trigo"               << endl; break;
            case 8: cout << setw(6) << right << "8" << setw(15) << left << " quitter"             << endl; break;
            default: break;
        }
    }

    int choix;
    cout << "votre choix [0 - 7] : "; cin >> choix;

    switch (choix) {
        case 1: {

            int nbr;

            const int min = 0;
            const int max = 1000;

            do {
                // vérif. si buffer est ok
                if(cin.fail()){
                    cin.clear();
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "entrer une valeur : [" << min << " - " << max << " ] : "; cin >> nbr;

            } while(nbr < min ||nbr > max);

            if(estPair(nbr)){
                cout << nbr << " est une valeur pair";
            } else {
                cout << nbr << " est une valeur impair";
            }

            break;
        }
        case 2: {
            int nbr;

            const int min = 0;
            const int max = 1000;

            do {
                if(cin.fail()){
                    cin.clear();
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "entrer une valeur : [" << min << " - " << max << " ] : "; cin >> nbr;

            }while(nbr < min ||nbr > max);

            cout << "la somme des chiffres de " << nbr << " = " << sommeChiffres(nbr) << endl;

            break;
        }
        case 3: {
            int minParDefaut = 0;
            int maxParDefaut = 1000;
            int min          = minParDefaut;
            int max          = maxParDefaut;

            cout << "Determiner les nombre premiers compris dans un intervalle" << endl
                 << "- debut : [ " << min << " - " << max << " ] : "; cin >> min;

            cout << "Determiner les nombre premiers compris dans un intervalle" << endl
                 << "- debut : [ " << min << " - " << max << " ] : "; cin >> max;

            do {
                if(cin.fail()){
                    cin.clear();
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "Determiner les nombre premiers compris dans un intervalle"        << endl
                     << "- debut : [ " << min << " - " << max << " ] : "; cin >> min; cout << endl
                     << "- fin   : [ " << min << " - " << max << " ] : "; cin >> max;

            } while(min < minParDefaut || max > maxParDefaut);

            for(int nbr = min; nbr <= max; ++nbr){
               if(nbre1er(nbr)) {
                   cout << "le nombre " << nbr << " est un nombre premier" << endl;
               }
            }

            break;
        }
        case 4: {

            int minParDefaut = 0;
            int maxParDefaut = 1000;
            int min          = minParDefaut;
            int max          = maxParDefaut;

            cout << "Determiner les nombre premiers compris dans un intervalle" << endl
                 << "- debut : [ " << min << " - " << max << " ] : "; cin >> min;

            cout << "Determiner les nombre premiers compris dans un intervalle" << endl
                 << "- debut : [ " << min << " - " << max << " ] : "; cin >> max;

            do {
                if(cin.fail()){
                    cin.clear();
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "Determiner les nombre premiers compris dans un intervalle"        << endl
                     << "- debut : [ " << min << " - " << max << " ] : "; cin >> min; cout << endl
                     << "- fin   : [ " << min << " - " << max << " ] : "; cin >> max;

            } while(min < minParDefaut && max > maxParDefaut);

            for(int nbr = min; nbr <= max; ++nbr){
                if(nbreArmstrong(nbr)){
                    cout << "le nombre " << nbr << " est un nombre d'Armstrong" << endl;
                }
            }
            break;
        }
        case 5: {
            const int minParDefaut = -100,
                      maxParDefaut =  100,
                      minNbrRandom =    0,
                      maxNbrRandom =  100;

            int min = minParDefaut,
                max = maxParDefaut,
                cbNbrRandom;

            do {
                if(cin.fail()){
                    cin.clear();
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

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
        case 6: {
            string chaineDeCaractere;
            cout << "entrer un phrase : "; cin >> chaineDeCaractere;
            buffer(chaineDeCaractere);

            break;
        }
        case 7: {
            int       angle;
            double resultat;

            const double minAngle =   0,
                         maxAngle = 360;

            do {
                if(cin.fail()){
                    cin.clear();
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "entrer un angle en degre : [ " << minAngle << " - " << maxAngle << " ] : "; cin >> angle;

            } while (angle < minAngle || angle > maxAngle);

            for(int fonctions = 1; fonctions <= 3; ++ fonctions){
                trigo(angle, resultat);
                cout << resultat << endl; //TODO: meilleur message avec le nom de la fonction
            }
        }
        case 0: {
            char caractere;

            do{
                if(cin.fail()){
                    cin.clear();
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Voulez-vous quitter = [o - n] : "; cin >> caractere;

            } while (!repondOui(caractere));

            break;
        }
        default: break;
    }


   return EXIT_SUCCESS;
}

//ecrire plein de fonction pour tester les fct et une pour demander un nombre en x et y