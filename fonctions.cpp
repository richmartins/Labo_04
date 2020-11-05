//
// Created by Richard Tenorio on 05.11.20.
//

#include <cmath>
#include "cmake-build-debug/fonctions.h"

using namespace std;

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
   int chiffre              = 0;
   int calculnbreArmstrong  = 0;
   int copie_valeur         = valeur;
   while (valeur > 0){
      chiffre = valeur % 10;
      valeur /= 10;
      calculnbreArmstrong += pow(chiffre, 3);
   }
   return copie_valeur == calculnbreArmstrong;
}