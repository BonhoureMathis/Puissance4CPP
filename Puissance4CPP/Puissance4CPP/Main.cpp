#include <iostream>
#include "puissance4.h"
//#include "jeu1.h"

int main() {
    int choix;

    std::cout << "Choisissez un jeu:\n";
    std::cout << "1. Jeu 1 \n";
    std::cout << "2. Jeu de Puissance 4 \n";
    std::cout << "Entrez le num�ro du jeu (1 ou 2): ";
    std::cin >> choix;

    switch (choix) {
    case 1:
        //    jouerJeu1();
        //         break;
    case 2:
        jouerPuissance4();
            break;
    default:
        std::cout << "Choix invalide.\n";
        break;
    }

    return 0;
}