#include <iostream>
#include "puissance4.h"
#include "bullAndCow.h"

void jouerBullAndCow();

int main() {
    int choix;

    std::cout << "Choisissez un jeu:\n";
    std::cout << "1. Jeu 1 \n";
    std::cout << "2. Jeu de Puissance 4 \n";
    std::cout << "Entrez le numéro du jeu (1 ou 2): ";
    std::cin >> choix;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //evite l'interverence en le cin du main et du jeu 


    switch (choix) {
    case 1:
            jouerBullAndCow();
                 break;
    case 2:
        jouerPuissance4();
            break;
    default:
        std::cout << "Choix invalide.\n";
        break;
    }

    return 0;
}