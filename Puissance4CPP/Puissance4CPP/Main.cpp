#include <iostream>
#include <string>

int main() {
    const int rows = 6;  // Le jeu a généralement 6 lignes
    const int cols = 7;  // 7 colonnes
    char board[rows][cols];  // Le tableau de jeu

    // Initialisation du tableau avec des points (cases vides)
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            board[i][j] = '.';
        }
    }

    // Déclaration des variables pour les prénoms des joueurs
    std::string player1_name, player2_name;
    char player1_initial, player2_initial;

    // Demander les prénoms des joueurs
    std::cout << "Entrez le prenom du premier joueur: ";
    std::getline(std::cin, player1_name);
    std::cout << "Entrez le prenom du deuxième joueur: ";
    std::getline(std::cin, player2_name);

    // Récupérer la première lettre des prénoms
    player1_initial = player1_name[0];  // Première lettre du prénom du joueur 1
    player2_initial = player2_name[0];  // Première lettre du prénom du joueur 2

    // Afficher les informations des joueurs
    std::cout << "Le premier joueur est " << player1_name << " (" << player1_initial << ")\n";
    std::cout << "Le deuxième joueur est " << player2_name << " (" << player2_initial << ")\n\n";

    // Fonction pour afficher le tableau
    auto afficherTableau = [&]() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << board[i][j];
                if (j < cols - 1) std::cout << " | ";  // Ajouter le séparateur "|" sauf pour le dernier élément
            }
            std::cout << std::endl;
            if (i < rows - 1) {
                for (int j = 0; j < cols; ++j) {
                    std::cout << "---";
                }
                std::cout << std::endl;
            }
        }

        // Afficher les numéros de colonnes (1 à 7)
        for (int j = 0; j < cols; ++j) {
            std::cout << j + 1;
            if (j < cols - 1) std::cout << "   ";  // Espacement pour que ça soit bien aligné
        }
        std::cout << std::endl;
        };

    // Affichage du tableau initial
    afficherTableau();

    // Variables pour gérer les tours de jeu
    int col;  // Colonne choisie par le joueur
    bool joueur1Tour = true;  // Détermine quel joueur doit jouer

    // Boucle du jeu
    bool jeuTermine = false;
    while (!jeuTermine) {
        // Demander au joueur de choisir une colonne
        char currentPlayerInitial = joueur1Tour ? player1_initial : player2_initial;
        std::cout << "Joueur " << currentPlayerInitial << ", choisissez une colonne (1 à " << cols << "): ";
        std::cin >> col;

        // Validation de l'entrée
        if (col < 1 || col > cols) {
            std::cout << "Colonne invalide. Essayez encore.\n";
            continue;
        }
        col -= 1;  // Ajuster pour les indices du tableau (0-based)

        // Trouver la première ligne vide de la colonne choisie
        bool placementReussi = false;
        for (int i = rows - 1; i >= 0; --i) {
            if (board[i][col] == '.') {
                board[i][col] = currentPlayerInitial;
                placementReussi = true;
                break;
            }
        }

        if (!placementReussi) {
            std::cout << "La colonne est pleine. Essayez une autre colonne.\n";
            continue;
        }

        // Afficher le tableau après le coup
        afficherTableau();

        // Changer de joueur
        joueur1Tour = !joueur1Tour;

        // Vérification des conditions de victoire (simplifiée pour cet exemple)
        // Ici, on peut vérifier si un joueur a aligné 4 symboles.
        // Vous pouvez ajouter cette logique plus tard pour un jeu complet.
    }

    return 0;
}
