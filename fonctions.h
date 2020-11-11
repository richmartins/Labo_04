/*
-----------------------------------------------------------------------------------
Nom du fichier  : fonctionsh.h
Nom du labo     : Labo_04
Auteur(s)       : Nicolas Philipp, Richard Tenorio
Classe          : PRG1-B
Date création   : 05.11.20
But             : Librarie de fonctions
Remarque(s)     : <à remplir>
Compilateur     : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/


#ifndef LABO_04_FONCTIONS_H
#define LABO_04_FONCTIONS_H
    /**
     * @section description
     *
     * retourne vrai si le paramètre valeur est un nombre pair, faux dans le cas contraire
     *
     * @param int valeur
     * @return bool
     */
    bool estPair(int valeur);

    /**
     * @section description
     *
     * additionne tous les chiffres du paramètre valeur et retourne le résultat
     *
     * @param int valeur
     * @return int sommeChiffres
     */
    int sommeChiffres(int valeur);

    /**
     * @section description
     *
     * retourne vrai si le paramètre valeur est un nombre premier, faux dans le cas contraire
     *
     * @param int valeur
     * @return bool
     */
    bool nbre1er(int valeur);

    /**
     * @section description
     *
     * retourne vrai si le paramètre valeur est un nombre d'Armstrong, faux dans le cas contraire
     *
     * @param int valeur
     * @return bool
     */
    bool nbreArmstrong(int valeur);

    /**
     * @section description
     *
     * retourne un nombre aléatoire dans l'interval de min à max passé en paramètre
     *
     * @param int min
     * @param int max
     * @return int
     */
    int random(int min, int max);

    /**
     * @section description
     *
     * vérifie quelle est la majuscule la plus grande et la minuscule la plus petite du paramètre
     * chaineDeCaractere, rend ses informations par paramètre et renvoye le nombre de caractère
     * traité
     *
     * @param const string& chaineDeCaractere
     * @param char& plusPetiteMinuscule
     * @param char& plusGrandeMajuscule
     * @return unsigned long
     */
    unsigned long buffer(const std::string& chaineDeCaractere, char& plusPetiteMinuscule, char& plusGrandeMajuscule);

    /**
     * @section description
     *
     * Calcul les fonctions trigonométrique(sin, cos, tan) du paramètre angle et rend les
     * résultats en parametre
     *
     * @param double angle
     * @param double& sinResultat
     * @param double& cosResultat
     * @param double& tanResultat
     */
    void trigo(double angle, double& sinResultat, double& cosResultat, double& tanResultat);

    /**
     *
     * @section description
     *
     * retourne vrai si le parametre reponse est égale à "o" ou "O", faux dans le cas contraire
     *
     * @param char reponse
     * @return bool
     */
    bool repondOui(char reponse, bool& decision);

#endif //LABO_04_FONCTIONS_H
