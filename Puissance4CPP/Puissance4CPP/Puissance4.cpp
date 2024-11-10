#include "puissance4.h"
#include <limits>
#include <cctype>
#include <iostream>

void afficherTableau(char board[ligne][colonne]) {
    for (int i = 0; i < ligne; ++i) {
        for (int j = 0; j < colonne; ++j) {
            std::cout << board[i][j];
            if (j < colonne - 1) std::cout << " | ";
        }
        std::cout << std::endl;
        if (i < ligne - 1) {
            for (int j = 0; j < colonne; ++j) {
                std::cout << "---";
            }
            std::cout << std::endl;
        }
    }

    // Afficher les numéros en bas des colonnes de jeu
    for (int j = 0; j < colonne; ++j) {
        std::cout << j + 1;
        if (j < colonne - 1) std::cout << "   ";
    }
    std::cout << std::endl;
}


bool verifierVictoire(char board[ligne][colonne], char joueur) {

    // Vérification de victoire horizontale
    for (int i = 0; i < ligne; ++i) {
        for (int j = 0; j < colonne - 3; ++j) {
            if (board[i][j] == joueur && board[i][j + 1] == joueur && board[i][j + 2] == joueur && board[i][j + 3] == joueur) {
                return true;
            }
        }
    }

    // Vérification de victoire verticale
    for (int j = 0; j < colonne; ++j) {
        for (int i = 0; i < ligne - 3; ++i) {
            if (board[i][j] == joueur && board[i + 1][j] == joueur && board[i + 2][j] == joueur && board[i + 3][j] == joueur) {
                return true;
            }
        }
    }

    // Vérification de victoire diagonale descendante
    for (int i = 0; i < ligne - 3; ++i) {
        for (int j = 0; j < colonne - 3; ++j) {
            if (board[i][j] == joueur && board[i + 1][j + 1] == joueur && board[i + 2][j + 2] == joueur && board[i + 3][j + 3] == joueur) {
                return true;
            }
        }
    }

    // Vérification de victoire diagonale montante
    for (int i = 3; i < ligne; ++i) {
        for (int j = 0; j < colonne - 3; ++j) {
            if (board[i][j] == joueur && board[i - 1][j + 1] == joueur && board[i - 2][j + 2] == joueur && board[i - 3][j + 3] == joueur) {
                return true;
            }
        }
    }

    return false;
}

// Fonction pour vérifier si le tableau est plein
bool tableauPlein(char board[ligne][colonne]) {
    for (int i = 0; i < ligne; ++i) {
        for (int j = 0; j < colonne; ++j) {
            if (board[i][j] == '.') {
                return false;
            }
        }
    }
    return true;
}

// demander nom du joueur
std::string demanderNom(const std::string& prompt) {
    std::string nom;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, nom);

        bool nomValide = !nom.empty();
        for (char c : nom) {
            if (!std::isalpha(c)) {  
                nomValide = false;
                break;
                //Verifie que le nom du joueur est bien une chaine de caractere
            }
        }

        if (nomValide) {
            break;
        }
        else {
            std::cout << "Nom invalide. Veuillez entrer un nom sans chiffres ou espace.\n";
            //Si le nom est pas une chaine de caractere alors le joueur doit re choisir un nom
        }
    }
    return nom;
}

// Choisir colonne pour jouer son piont
int choisirColonne(int maxCol) {
    int col;
    while (true) {
        std::cout << "Choisissez une colonne (1 à " << maxCol << "): ";
        if (std::cin >> col && col >= 1 && col <= maxCol) {
            break;
        }
        std::cout << "Entree invalide. Veuillez entrer un nombre entre 1 et " << maxCol << ".\n";  // verifier que la reponse du joueur est bien entre 1 et 7
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return col - 1;
}


void jouerPuissance4() {
    char tableau[ligne][colonne];

    // initialisation du tableau 
    for (int i = 0; i < ligne; ++i) {
        for (int j = 0; j < colonne; ++j) {
            tableau[i][j] = '.';
        }
    }

    // demande des prenoms des joueurs
    std::string player1_name = demanderNom("Entrez le prenom du premier joueur: ");
    std::string player2_name = demanderNom("Entrez le prenom du deuxième joueur: ");

    // garde que la premiere lettre du prenom
    char player1_initial = player1_name[0];
    char player2_initial = player2_name[0];

    std::cout << "Le premier joueur est " << player1_name << " (" << player1_initial << ")\n";
    std::cout << "Le deuxieme joueur est " << player2_name << " (" << player2_initial << ")\n\n";

    bool joueur1Tour = true;
    bool jeuTermine = false;

    // boucle de gameplay
    while (!jeuTermine) {
        afficherTableau(tableau);
        char currentPlayerInitial = joueur1Tour ? player1_initial : player2_initial;
        int col = choisirColonne(colonne);
        //affiche le tableau et dit quelle joueur doit jouer et ou il veut jouer


        bool placementReussi = false;
        for (int i = ligne - 1; i >= 0; --i) {
            if (tableau[i][col] == '.') {
                tableau[i][col] = currentPlayerInitial;
                placementReussi = true;
                break;
                //place le jeton du joueur dans le colonne choisie
            }
        }

        if (!placementReussi) {
            std::cout << "La colonne est pleine. Essayez une autre colonne.\n";
            continue;
        }

        if (verifierVictoire(tableau, currentPlayerInitial)) {
            afficherTableau(tableau);
            std::cout << "Felicitations, Joueur " << currentPlayerInitial << " a gagne !\n";
            jeuTermine = true;
            continue;
            //verifie si le jeton jouer par le joueur lui as donné la victoire
        }

        if (tableauPlein(tableau)) {
            afficherTableau(tableau);
            std::cout << "Match nul ! Le tableau est plein et aucun joueur n'a gagne.\n";
            jeuTermine = true;
            continue;
            //verifie le match nul
        }

        joueur1Tour = !joueur1Tour;
        // passe au prochain tour et laisse l'autre joueur jouer son jeton
    }
}
