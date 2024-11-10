#include "puissance4.h"
#include <limits>
#include <cctype>
#include <iostream>

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

// Fonction pour demander un nom et s'assurer qu'il est valide
std::string demanderNom(const std::string& prompt) {
    std::string nom;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, nom);

        // Vérifier si le nom est non vide et contient uniquement des lettres
        bool nomValide = !nom.empty();
        for (char c : nom) {
            if (!std::isalpha(c)) {  // Vérifie si chaque caractère est une lettre
                nomValide = false;
                break;
            }
        }

        if (nomValide) {
            break;
        }
        else {
            std::cout << "Nom invalide. Veuillez entrer un nom sans chiffres ni caractères spéciaux.\n";
        }
    }
    return nom;
}

// Fonction pour demander une colonne valide
int demanderColonne(int maxCol) {
    int col;
    while (true) {
        std::cout << "Choisissez une colonne (1 à " << maxCol << "): ";
        if (std::cin >> col && col >= 1 && col <= maxCol) {
            break;
        }
        std::cout << "Entrée invalide. Veuillez entrer un nombre entre 1 et " << maxCol << ".\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return col - 1;
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

    // Demander les prénoms des joueurs
    std::string player1_name = demanderNom("Entrez le prenom du premier joueur: ");
    std::string player2_name = demanderNom("Entrez le prenom du deuxième joueur: ");

    // Récupérer les initiales des joueurs
    char player1_initial = player1_name[0];
    char player2_initial = player2_name[0];

    std::cout << "Le premier joueur est " << player1_name << " (" << player1_initial << ")\n";
    std::cout << "Le deuxième joueur est " << player2_name << " (" << player2_initial << ")\n\n";

    bool joueur1Tour = true;
    bool jeuTermine = false;

    while (!jeuTermine) {
        afficherTableau(board);
        char currentPlayerInitial = joueur1Tour ? player1_initial : player2_initial;

        int col = demanderColonne(cols);

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
            afficherTableau(board);
            std::cout << "Félicitations, Joueur " << currentPlayerInitial << " a gagné !\n";
            jeuTermine = true;
            continue;
        }

        if (tableauPlein(board)) {
            afficherTableau(board);
            std::cout << "Match nul ! Le tableau est plein et aucun joueur n'a gagne.\n";
            jeuTermine = true;
            continue;
        }

        joueur1Tour = !joueur1Tour;
    }
}
