#include <iostream>
#include "fonctions.h"

int main() {
    std::cout << random(1, 100) << std::endl;
    buffer("Bonjour, monsieur");
    trigo(45);
    std::cout << repondOui('n');

    return 0;
}
