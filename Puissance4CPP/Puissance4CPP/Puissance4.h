#pragma once
#ifndef PUISSANCE4_H
#define PUISSANCE4_H

#include <iostream>
#include <string>

// Taille du tableau
const int rows = 6;
const int cols = 7;

// Déclaration des fonctions
void afficherTableau(char board[rows][cols]);
bool verifierVictoire(char board[rows][cols], char joueur);
bool tableauPlein(char board[rows][cols]);
void jouerPuissance4();

#endif // PUISSANCE4_H