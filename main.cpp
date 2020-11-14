/*
-----------------------------------------------------------------------------------
Nom du fichier  : main.cpp
Nom du labo     : Labo 04 Librairie
Auteur(s)       : Nicolas Philipp, Richard Tenorio
Classe          : PRG1-B
Date création   : 05.11.20
Description     : Ce programme utilise le fichier « fonctions.cpp » qui permet d’utiliser 8
                  - Est pair. Détermine si un nombre est pair
                  - sommeChiffres. Calcul la somme des chiffres d’un nombre donné
                  - nbre1er, Détermine si un nombre entrer est un nombre premier
                  - nbreArmstrong, Détermine si un nombre entrer est un nombre d’Armstrong
                  - random, retourne des nombres aléatoire
                  - buffer, traite une chaîne de caractère et détermine la plus petite minuscule, la plus
                    grande majuscule et le nombre de caractère traiter dans la chaîne de caractère
                  - trigo, détermine le sinus, cosinus et la tangente d’un angle en degré entrer.
                  - repondOui, Détermine si l’utilisateur veux quitter le programme ou non

Remarque        : Nous avons juger que les boucles « do while » de vérification de d’intervalle
                  des entrées saisie par les utilisateurs n’ont pas besoin d’être optimisée dans une
                  fonction car elles ne sont pas toutes pareil et donc pas redondante

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
        cout << "\n\nOptions :"                                                                             << endl
             << setw(ESPACE_NBR) << right << "1" << setw(ESPACE_OPTION) << left << " est pair"            << endl
             << setw(ESPACE_NBR) << right << "2" << setw(ESPACE_OPTION) << left << " somme chiffres"      << endl
             << setw(ESPACE_NBR) << right << "3" << setw(ESPACE_OPTION) << left << " nombre 1er"          << endl
             << setw(ESPACE_NBR) << right << "4" << setw(ESPACE_OPTION) << left << " nombre de Armstrong" << endl
             << setw(ESPACE_NBR) << right << "5" << setw(ESPACE_OPTION) << left << " nombre aléatoire"    << endl
             << setw(ESPACE_NBR) << right << "6" << setw(ESPACE_OPTION) << left << " buffer"              << endl
             << setw(ESPACE_NBR) << right << "7" << setw(ESPACE_OPTION) << left << " trigo"               << endl
             << setw(ESPACE_NBR) << right << "0" << setw(ESPACE_OPTION) << left << " quitter"             << endl;


        int choix;

        cout << "votre choix [0 - 7] : "; cin >> choix;

        if(cin.fail()){
            cout << "Erreur de saisie" << endl;
            cin.clear();
            VIDER_BUFFER
            continue;
        }

        switch (Fonctions(choix)) {
            case Fonctions::EST_PAIR : {

                int nbr;

                const int MIN = 0;
                const int MAX = 1000;

                // boucle de vérif. d'interval
                do {
                    VERIF_ET_REPARER_BUFFER
                    VIDER_BUFFER
                    cout << "entrer une valeur : [" << MIN << " - " << MAX << " ] : ";
                    cin  >> nbr;

                    if(nbr < MIN || nbr > MAX || cin.fail()){
                        cout << "/!\\ erreur /!\\" << endl;
                    }

                } while (nbr < MIN || nbr > MAX || cin.fail());

                if(estPair(nbr)){
                    cout << nbr << " est une valeur pair";
                } else {
                    cout << nbr << " est une valeur impair";
                }

                break;
            }
            case Fonctions::SOMME_CHIFFRE: {
                int nbr;

                const int MIN = 0;
                const int MAX = 1000;

                // boucle vérif. interval
                do {
                    VERIF_ET_REPARER_BUFFER
                    VIDER_BUFFER

                    cout << "entrer une valeur : [" << MIN << " - " << MAX << " ] : ";
                    cin >> nbr;

                    if(nbr < MIN || nbr > MAX){
                        cout << "/!\\ erreur /!\\" << endl;
                    }

                } while (nbr < MIN || nbr > MAX);

                cout << "la somme des chiffres de " << nbr << " = " << sommeChiffres(nbr) << endl;

                break;
            }
            case Fonctions::NBRE_1ER: {
                const int MIN_PAR_DEFAUT = 0,
                          MAX_PAR_DEFAUT = 1000;

                int max,
                    min;

                // boucle vérif. interval
                do {

                    min = MIN_PAR_DEFAUT;
                    max = MAX_PAR_DEFAUT;

                    VERIF_ET_REPARER_BUFFER
                    VIDER_BUFFER

                    cout << "Determiner les nombre premiers compris dans un intervalle" << endl;
                    cout << "- debut : [ " << min << " - " << max << " ] : ";
                    cin  >> min;
                    cout << "- fin   : [ " << min << " - " << max << " ] : ";
                    cin  >> max;

                    if(min < MIN_PAR_DEFAUT || max > MAX_PAR_DEFAUT){
                        cout << "/!\\ erreur /!\\" << endl;
                    }

                } while(min < MIN_PAR_DEFAUT || max > MAX_PAR_DEFAUT);

                for(int nbr = min; nbr <= max; ++nbr){
                    if(nbre1er(nbr)) {
                        cout << "le nombre " << nbr << " est un nombre premier" << endl;
                    }
                }

                break;
            }
            case Fonctions::NBRE_ARMSTRONG: {
                const int MIN_PAR_DEFAUT = 0;
                const int MAX_PAR_DEFAUT = 1000;
                int min;
                int max;

                // boucle vérif. interval
                do {
                    min = MIN_PAR_DEFAUT;
                    max = MAX_PAR_DEFAUT;

                    VERIF_ET_REPARER_BUFFER
                    VIDER_BUFFER

                    cout << "Determiner les nombre de Armstrong compris dans un intervalle" << endl;
                    cout << "- debut : [ " << min << " - " << max << " ] : ";
                    cin  >> min;
                    cout << "- fin   : [ " << min << " - " << max << " ] : ";
                    cin  >> max;

                    if(min < MIN_PAR_DEFAUT || max > MAX_PAR_DEFAUT){
                        cout << "/!\\ erreur /!\\" << endl;
                    }

                } while(min < MIN_PAR_DEFAUT || max > MAX_PAR_DEFAUT);

                for(int nbr = min; nbr <= max; ++nbr){
                    if(nbreArmstrong(nbr)){
                        cout << "le nombre " << nbr << " est un nombre d'Armstrong" << endl;
                    }
                }

                break;
            }
            case Fonctions::RANDOM: {
                const int MIN_PAR_DEFAUT =  -100,
                          MAX_PAR_DEFAUT =   100,
                          MIN_NBR_RANDOM =     0,
                          MAX_NBR_RANDOM =   100;

                int min,
                    max,
                    cbNbrRandom;

                // boucle vérif. interval
                do {
                    min         = MIN_PAR_DEFAUT,
                    max         = MAX_PAR_DEFAUT,
                    cbNbrRandom = 1;

                    VERIF_ET_REPARER_BUFFER
                    VIDER_BUFFER

                    cout << "Determiner une serie de nombre aleatoire compris dans un intervalle" << endl
                         << "- debut : [ " << min << " - " << max << " ] : ";
                    cin  >> min;
                    cout << "- fin   : [ " << min << " - " << max << " ] : ";
                    cin  >> max;
                    cout << "- nbre  : [ " << MIN_NBR_RANDOM << " - " << MAX_NBR_RANDOM << " ] : ";
                    cin  >> cbNbrRandom;

                    if((min < MIN_PAR_DEFAUT || max > MAX_PAR_DEFAUT) || (cbNbrRandom < MIN_NBR_RANDOM || cbNbrRandom > MAX_NBR_RANDOM)){
                        cout << "/!\\ erreur /!\\" << endl;
                    }

                } while ((min < MIN_PAR_DEFAUT || max > MAX_PAR_DEFAUT) || (cbNbrRandom < MIN_NBR_RANDOM || cbNbrRandom > MAX_NBR_RANDOM));

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

                if (plusPetiteMinuscule != ' '){
                    cout << "Plus petit minuscule  : " << plusPetiteMinuscule << endl;
                }
                if (plusGrandeMajuscule != ' ') {
                    cout << "Plus grande majuscule : " << plusGrandeMajuscule << endl;
                }
                cout << "Nombre de lettre      : " << nbrLettres          << endl;

                break;
            }
            case Fonctions::TRIGO: {
                int    angle;
                double   sin,
                         cos,
                         tan;

                const double MIN_ANGLE =   0,
                             MAX_ANGLE = 360;

                // boucle vérif. interval
                do {
                    VERIF_ET_REPARER_BUFFER
                    VIDER_BUFFER

                    cout << "entrer un angle en degre : [ " << MIN_ANGLE << " - " << MAX_ANGLE << " ] : "; cin >> angle;

                    if(angle < MIN_ANGLE || angle > MAX_ANGLE){
                        cout << "/!\\ erreur /!\\" << endl;
                    }

                } while (angle < MIN_ANGLE || angle > MAX_ANGLE);

                    trigo(angle, sin, cos, tan);

                    cout << fixed << setprecision(2);
                    cout << "sin(" << angle << ") = " << sin << endl;
                    cout << "cos(" << angle << ") = " << cos << endl;
                    if (angle == 90 or angle == 270){    //tan(90) et tan(270) n'existe pas
                        cout << "tan(" << angle << ") = " << "indetermine" << endl;
                    }
                    else {
                        cout << "tan(" << angle << ") = " << tan << endl;
                    }
                break;
            }
            case Fonctions::REPOND_OUI: {
                char caractere;

                // boucle vérif. saisie
                do {
                    VERIF_ET_REPARER_BUFFER
                    VIDER_BUFFER

                    cout << "Voulez-vous quitter = [o - n] : ";
                    cin >> caractere;

                } while (!repondOui(caractere, statutQuitter));

                break;
            }
            default : {
                cout << "/!\\erreur /!\\" << endl;
                break;
            }
        }
    } while (!statutQuitter);

    return EXIT_SUCCESS;
}