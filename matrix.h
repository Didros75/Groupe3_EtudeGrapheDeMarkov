//
// Created by julie on 21/11/2025.
//

#ifndef MATRIX_H
#define MATRIX_H
#include "list_adj.h"
#include "tarjan.h"

/* Crée la matrice de transition associée à un graphe d'adjacence.
 *
 * Paramètres :
 *  - t : structure d'adjacence représentant le graphe.
 *
 * Retour :
 *  - Une matrice carrée (float**) de taille t.lenght × t.lenght.
 */
float ** createMatrix(t_adj t);


/* Initialise une matrice à 0.
 *
 * Paramètres :
 *  - matrix : matrice à initialiser.
 *  - n      : taille de la matrice (n x n).
 *
 * Retour :
 *  - Aucun.
 */
void matrix0(float ** matrix, int n);


/* Affiche une matrice carrée de taille n.
 *
 * Paramètres :
 *  - matrix : matrice à afficher.
 *  - n      : dimension de la matrice.
 *
 * Retour :
 *  - Aucun.
 */
void printMatrix(float ** matrix, int n);


/* Affiche la distribution stationnaire lue dans la matrice
 * (selon le format choisi dans l’implémentation).
 *
 * Paramètres :
 *  - matrix : matrice contenant la distribution.
 *  - n      : taille de la distribution.
 *
 * Retour :
 *  - Aucun.
 */
void printDistribution(float ** matrix, int n);


/* Crée une copie d'une matrice carrée.
 *
 * Paramètres :
 *  - matrix : matrice d'origine.
 *  - n      : dimension de la matrice.
 *
 * Retour :
 *  - Une nouvelle matrice copiée depuis l’originale.
 */
float **copyMatrix(float **matrix, int n);


/* Multiplie deux matrices carrées A et B.
 *
 * Paramètres :
 *  - A : première matrice.
 *  - B : seconde matrice.
 *  - n : dimension des matrices.
 *
 * Retour :
 *  - Une nouvelle matrice représentant le produit A × B.
 */
float **multiplyMatrix(float **A, float **B, int n);


/* Calcule la différence entre deux matrices (somme(i, j) de A(ij)-B(ij)).
 *
 * Paramètres :
 *  - M : première matrice.
 *  - N : seconde matrice.
 *  - n : dimension des matrices.
 *
 * Retour :
 *  - Un flottant indiquant la différence entre M et N.
 */
float diffMatrix(float **M, float **N, int n);


/* Calcule la matrice^p.
 *
 * Paramètres :
 *  - matrix : matrice à exponentier.
 *  - n      : dimension de la matrice.
 *  - p      : puissance souhaitée.
 *
 * Retour :
 *  - Une matrice correspondant à matrix^p.
 */
float **powerMatrix(float **matrix, int n, int p);


/* Recherche la matrice stable obtenue en multipliant A par elle-même
 * jusqu'à convergence, selon une marge epsilon.
 *
 * Paramètres :
 *  - A       : matrice initiale.
 *  - n       : dimension de la matrice.
 *  - epsilon : seuil pour la convergence.
 *
 * Retour :
 *  - La matrice stable obtenue.
 */
float **stableMatrix(float **A, int n, float epsilon);


/* Calcule la matrice stable pour chaque classe du graphe et affiche les résultats.
 *
 * Paramètres :
 *  - t    : graphe d'adjacence initial.
 *  - part : partition des classes (issue de Tarjan).
 *
 * Retour :
 *  - Aucun.
 */
void allStableMatrix(t_adj t, t_stock_class part);

void periodicity(t_adj graph);
int getPeriod(float **sub_matrix,int n);
int gcd(int *vals, int nbvals);


/* Extrait une sous-matrice correspondant à une classe particulière
 * d'une partition des classes.
 *
 * Paramètres :
 *  - matrix      : matrice complète.
 *  - part        : partition contenant les classes.
 *  - compo_index : index de la classe à extraire.
 *
 * Retour :
 *  - Une sous-matrice carrée isolant la classe désirée.
 */
float **subMatrix(float **matrix, t_stock_class part, int compo_index);

#endif //MATRIX_H