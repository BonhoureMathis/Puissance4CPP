#pragma once
#ifndef PUISSANCE4_H
#define PUISSANCE4_H

#include <iostream>
#include <string>

// Taille du tableau
const int ligne = 6;
const int colonne = 7;

// Déclaration des fonctions
void afficherTableau(char board[ligne][colonne]);
bool verifierVictoire(char board[ligne][colonne], char joueur);
bool tableauPlein(char board[ligne][colonne]);
void jouerPuissance4();

#endif // PUISSANCE4_H