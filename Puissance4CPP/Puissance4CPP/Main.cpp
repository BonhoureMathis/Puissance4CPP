#include <iostream>

int main() {
    const int rows = 7;
    const int cols = 7;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (i == rows - 1) {
                // Dernière ligne : afficher le numéro de la colonne (j + 1)
                std::cout << j + 1;
            }
            else {
                // Autres lignes : afficher un point
                std::cout << ".";
            }
            // Ajouter le séparateur "|" sauf pour le dernier élément de la ligne
            if (j < cols - 1) {
                std::cout << " | ";
            }
        }
        std::cout << std::endl;
    }

    return 0;
}