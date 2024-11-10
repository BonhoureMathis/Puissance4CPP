#include <iostream>
#include <string>

constexpr int number_letter = 3;
int Bull = 0;
int Cow = 0;
std::string word_propose;
std::string guess_word;

void Introduction() {
    std::cout << "Bienvenue dans mon jeu Bull and Cow." << std::endl;
    std::cout << "Peux-tu deviner un mot de " << number_letter << " lettres ?" << std::endl;
    std::cout << "Maitre du jeu, choisis le mot a deviner : ";
}

void MotADeviner() {
    std::cin >> word_propose;
    while (word_propose.length() != number_letter) {
        std::cout << "Reessaye, tu dois choisir un mot de la bonne taille (" << number_letter << " lettres) : ";
        std::cin >> word_propose;
    }
    std::cout << "A vous de deviner !" << std::endl;
}

void DevinerLeMot() {
    std::cin >> guess_word;
    while (guess_word.length() != number_letter) {
        std::cout << "Reessaye avec un mot de " << number_letter << " lettres : ";
        std::cin >> guess_word;
    }
}

void BullCowMecanic() {
    Bull = 0;
    Cow = 0;

    for (int i = 0; i < word_propose.length(); i++) {
        if (guess_word[i] == word_propose[i]) {
            Bull++;
        }
        else if (word_propose.find(guess_word[i]) != std::string::npos) {
            Cow++;
        }
    }

    std::cout << "Il y a " << Bull << " bonne(s) lettre(s) bien placee(s) et " << Cow << " bonne(s) lettre(s) mal placee(s)." << std::endl;
}

void EndGame() {
    if (guess_word == word_propose) {
        std::cout << "Bravo, c'est gagné !" << std::endl;
    }
}

void jouerBullAndCow() {
    Introduction();
    MotADeviner();

    while (guess_word != word_propose) {
        DevinerLeMot();
        BullCowMecanic();

        if (guess_word == word_propose) {
            EndGame();
            break;
        }
    }
}
