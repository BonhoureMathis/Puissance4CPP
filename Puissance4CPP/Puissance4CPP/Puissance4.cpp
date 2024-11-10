#include "puissance4.h"

// Fonction pour afficher le tableau
void afficherTableau(char board[rows][cols]) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << board[i][j];
            if (j < cols - 1) std::cout << " | ";
        }
        std::cout << std::endl;
        if (i < rows - 1) {
            for (int j = 0; j < cols; ++j) {
                std::cout << "---";
            }
            std::cout << std::endl;
        }
    }

    // Afficher les numéros de colonnes
    for (int j = 0; j < cols; ++j) {
        std::cout << j + 1;
        if (j < cols - 1) std::cout << "   ";
    }
    std::cout << std::endl;
}

// Fonction pour vérifier la victoire
bool verifierVictoire(char board[rows][cols], char joueur) {
    // Vérification horizontale
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols - 3; ++j) {
            if (board[i][j] == joueur && board[i][j + 1] == joueur && board[i][j + 2] == joueur && board[i][j + 3] == joueur) {
                return true;
            }
        }
    }

    // Vérification verticale
    for (int j = 0; j < cols; ++j) {
        for (int i = 0; i < rows - 3; ++i) {
            if (board[i][j] == joueur && board[i + 1][j] == joueur && board[i + 2][j] == joueur && board[i + 3][j] == joueur) {
                return true;
            }
        }
    }

    // Vérification diagonale descendante
    for (int i = 0; i < rows - 3; ++i) {
        for (int j = 0; j < cols - 3; ++j) {
            if (board[i][j] == joueur && board[i + 1][j + 1] == joueur && board[i + 2][j + 2] == joueur && board[i + 3][j + 3] == joueur) {
                return true;
            }
        }
    }

    // Vérification diagonale montante
    for (int i = 3; i < rows; ++i) {
        for (int j = 0; j < cols - 3; ++j) {
            if (board[i][j] == joueur && board[i - 1][j + 1] == joueur && board[i - 2][j + 2] == joueur && board[i - 3][j + 3] == joueur) {
                return true;
            }
        }
    }

    return false;
}

// Fonction pour vérifier si le tableau est plein
bool tableauPlein(char board[rows][cols]) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (board[i][j] == '.') {
                return false;
            }
        }
    }
    return true;
}

// Fonction pour jouer au jeu de Puissance 4
void jouerPuissance4() {
    char board[rows][cols];

    // Initialisation du tableau avec des points (cases vides)
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            board[i][j] = '.';
        }
    }

    std::string player1_name, player2_name;
    char player1_initial, player2_initial;

    // Ignorer les caractères résiduels dans le flux d'entrée (par exemple, '\n' après une précédente entrée)
    std::cin.ignore();  // Cela nettoie le flux d'entrée

    // Demander les prénoms des joueurs
    std::cout << "Entrez le prenom du premier joueur: ";
    std::getline(std::cin, player1_name);  // Lire le prénom du premier joueur
    std::cout << "Entrez le prenom du deuxième joueur: ";
    std::getline(std::cin, player2_name);  // Lire le prénom du deuxième joueur

    // Récupérer les initiales des joueurs
    player1_initial = player1_name[0];
    player2_initial = player2_name[0];

    std::cout << "Le premier joueur est " << player1_name << " (" << player1_initial << ")\n";
    std::cout << "Le deuxième joueur est " << player2_name << " (" << player2_initial << ")\n\n";

    bool joueur1Tour = true;
    bool jeuTermine = false;
    int col;

    while (!jeuTermine) {
        afficherTableau(board);
        char currentPlayerInitial = joueur1Tour ? player1_initial : player2_initial;

        std::cout << "Joueur " << currentPlayerInitial << ", choisissez une colonne (1 à " << cols << "): ";
        std::cin >> col;
        if (col < 1 || col > cols) {
            std::cout << "Colonne invalide. Essayez encore.\n";
            continue;
        }
        col -= 1;

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

        if (verifierVictoire(board, currentPlayerInitial)) {
            std::cout << "Félicitations, Joueur " << currentPlayerInitial << " a gagné !\n";
            jeuTermine = true;
            continue;
        }

        if (tableauPlein(board)) {
            std::cout << "Match nul ! Le tableau est plein et aucun joueur n'a gagne.\n";
            jeuTermine = true;
            continue;
        }

        joueur1Tour = !joueur1Tour;
    }
}
