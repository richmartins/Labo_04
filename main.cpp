/*
-----------------------------------------------------------------------------------
Nom du fichier  : main.cpp
Nom du labo     : Labo 04 Librairie
Auteur(s)       : Nicolas Philipp, Richard Tenorio
Classe          : PRG1-B
Date création   : 06.11.20
But             : Ce programme a pour but d'utiliser le fichier "fonctions.cpp" qui
                  est une libraire de fonction
Remarque(s)     : <à remplir>
Compilateur     : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/

#include <cstdlib>   // EXIT_SUCCES
#include <iostream>  // flux d'entrer et de sortie
#include <limits>    // numeric_limits
#include <iomanip>   // setw

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

    bool statutQuitter = false;

    const unsigned short ESPACE_NBR    =  7;
    const unsigned short ESPACE_OPTION = 15;

    do {
        // affiche les options
        cout << "\n\nOptions"                                                                             << endl
             << setw(ESPACE_NBR) << right << "1" << setw(ESPACE_OPTION) << left << " est pair"            << endl
             << setw(ESPACE_NBR) << right << "2" << setw(ESPACE_OPTION) << left << " somme chiffres"      << endl
             << setw(ESPACE_NBR) << right << "3" << setw(ESPACE_OPTION) << left << " nombre 1er"          << endl
             << setw(ESPACE_NBR) << right << "4" << setw(ESPACE_OPTION) << left << " nombre de Armstrong" << endl
             << setw(ESPACE_NBR) << right << "5" << setw(ESPACE_OPTION) << left << " nombre aléatoire"    << endl
             << setw(ESPACE_NBR) << right << "6" << setw(ESPACE_OPTION) << left << " buffer"              << endl
             << setw(ESPACE_NBR) << right << "7" << setw(ESPACE_OPTION) << left << " trigo"               << endl
             << setw(ESPACE_NBR) << right << "0" << setw(ESPACE_OPTION) << left << " quitter"             << endl;

        VERIF_ET_REPARER_VIDER_BUFFER

        int choix;

        cout << "votre choix [0 - 7] : "; cin >> choix;

        switch (Fonctions(choix)) {
            case Fonctions::EST_PAIR : {

                int nbr;

                const int min = 0;
                const int max = 1000;

                // boucle de vérif. d'interval
                do {
                    VERIF_ET_REPARER_BUFFER
                    VIDER_BUFFER
                    cout << "entrer une valeur : [" << min << " - " << max << " ] : "; cin >> nbr;

                    if(nbr < min ||nbr > max){
                        cout << "/!\\ erreur /!\\" << endl;
                    }

                } while (nbr < min ||nbr > max);

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

                // boucle vérif. interval
                do {
                    VERIF_ET_REPARER_BUFFER
                    VIDER_BUFFER

                    cout << "entrer une valeur : [" << min << " - " << max << " ] : "; cin >> nbr;

                    if(nbr < min ||nbr > max){
                        cout << "/!\\ erreur /!\\" << endl;
                    }

                } while (nbr < min ||nbr > max);

                cout << "la somme des chiffres de " << nbr << " = " << sommeChiffres(nbr) << endl;

                break;
            }
            case Fonctions::NBRE_1ER: {
                const int minParDefaut = 0,
                          maxParDefaut = 1000;

                int max,
                    min;

                // boucle vérif. interval
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

                    if(min < minParDefaut || max > maxParDefaut){
                        cout << "/!\\ erreur /!\\" << endl;
                    }

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

                // boucle vérif. interval
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

                    if(min < minParDefaut || max > maxParDefaut){
                        cout << "/!\\ erreur /!\\" << endl;
                    }

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

                // boucle vérif. interval
                do {
                    min         = minParDefaut,
                    max         = maxParDefaut,
                    cbNbrRandom = 1;

                    VERIF_ET_REPARER_BUFFER
                    VIDER_BUFFER

                    cout << "Determiner les nombre premiers compris dans un intervalle" << endl
                         << "- debut : [ " << min << " - " << max << " ] : ";
                    cin  >> min;
                    cout << "- fin   : [ " << min << " - " << max << " ] : ";
                    cin  >> max;
                    cout << "- nbre  : [ " << minNbrRandom << " - " << maxNbrRandom << " ] : ";
                    cin  >> cbNbrRandom;

                    if((min < minParDefaut || max > maxParDefaut) || (cbNbrRandom < minNbrRandom || cbNbrRandom > maxNbrRandom)){
                        cout << "/!\\ erreur /!\\" << endl;
                    }

                } while ((min < minParDefaut || max > maxParDefaut) || (cbNbrRandom < minNbrRandom || cbNbrRandom > maxNbrRandom));

                cout << "Voici des valeurs aletoires [ " << min << " - " << max << " ] : " << endl;

                for(int nbrFois = 1; nbrFois <= cbNbrRandom; ++nbrFois){
                    cout << " " << random(min, max);

                    if(nbrFois != cbNbrRandom) {
                        cout << ",";
                    }
                }

                break;
            }
            case Fonctions::BUFFER: {
                string chaineDeCaractere;

                char plusPetiteMinuscule = ' ';
                char plusGrandeMajuscule = ' ';

                // boucle vérif. interval
                do {
                    VERIF_ET_REPARER_BUFFER
                    VIDER_BUFFER

                    cout << "entrer un phrase : ";
                    getline(cin, chaineDeCaractere);


                    if(chaineDeCaractere.length() < 1){
                        cout << "/!\\ erreur /!\\" << endl;
                    }

                } while(chaineDeCaractere.length() < 1);

                unsigned long nbrLettres = buffer(chaineDeCaractere, plusPetiteMinuscule, plusGrandeMajuscule);

                cout << "Plus petit minuscule  : " << plusPetiteMinuscule << endl;
                cout << "Plus grande majuscule : " << plusGrandeMajuscule << endl;
                cout << "Nombre de lettre      : " << nbrLettres          << endl;

                break;
            }
            case Fonctions::TRIGO: {
                int    angle;
                double   sin,
                         cos,
                         tan;

                const double minAngle =   0,
                             maxAngle = 360;

                // boucle vérif. interval
                do {
                    VERIF_ET_REPARER_BUFFER
                    VIDER_BUFFER

                    cout << "entrer un angle en degre : [ " << minAngle << " - " << maxAngle << " ] : "; cin >> angle;

                    if(angle < minAngle || angle > maxAngle){
                        cout << "/!\\ erreur /!\\" << endl;
                    }

                } while (angle < minAngle || angle > maxAngle);

                    trigo(angle, sin, cos, tan);

                    cout << "sin(" << angle << ") = " << sin << endl;
                    cout << "cos(" << angle << ") = " << cos << endl;
                    cout << "tan(" << angle << ") = " << tan << endl;
                break;
            }
            case Fonctions::REPOND_OUI: {
                char caractere;

                // boucle vérif. interval
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