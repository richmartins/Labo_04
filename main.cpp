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

#include "fonctions.h"

#define CLEAR_BUFFER    cin.clear();\
                        cin.ignore(numeric_limits<streamsize>::max(), '\n')

using namespace std;

int main() {

//   const string    MSG_ENTREE_FAUSSE = "/!\\ Recommencer\n";
//   int             entreeUtilisateur;
//   do{
//      //Clear cin in case an error occured previously
//      if(cin.fail()){
//         CLEAR_BUFFER;
//      }
//
//      cout << "votre choix [0 - 7] : ";
//      cin >> entreeUtilisateur;
//   }while (( entreeUtilisateur < 0 || entreeUtilisateur > 7 || cin.fail()) && cout << MSG_ENTREE_FAUSSE);
//
//   switch (entreeUtilisateur){
//      case 0 : cout << "0"     << endl; break;
//      case 1 : cout << "1"     << endl; break;
//      case 2 : cout << "2"     << endl; break;
//      case 3 : cout << "3"     << endl; break;
//      case 4 : cout << "4"     << endl; break;
//      case 5 : cout << "5"     << endl; break;
//      case 6 : cout << "6"     << endl; break;
//      case 7 : cout << "7"     << endl; break;
//      default: cout << "prout" << endl; break;
//   }

   return EXIT_SUCCESS;
}

//ecrire plein de fonction pour tester les fct et une pour demander un nombre en x et y