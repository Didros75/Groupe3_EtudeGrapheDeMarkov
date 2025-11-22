//
// Created by julie on 20/10/2025.
//

#ifndef LIST_ADJ_H
#define LIST_ADJ_H
#include "Cell.h"

/* Structure représentant une liste chaînée de cellules.
 * head : pointeur vers la première cellule de la liste.
 */
typedef struct s_list {
  t_cell *head;
} t_list;


/* Structure représentant une structure d'adjacence.
 * lenght       : nombre total de sommets du graphe.
 * leaving_edge : tableau de listes représentant les arêtes sortantes
 *                de chaque sommet.
 */
typedef struct s_adj {
  int lenght;
  t_list *leaving_edge;
} t_adj;


/* Crée et retourne une liste vide.
 *
 * Retour :
 *  - Une structure t_list initialisée à vide.
 */
t_list CreateEmptyList();


/* Ajoute une cellule à la fin de la liste chaînée.
 *
 * Paramètres :
 *  - list : pointeur vers la liste cible.
 *  - cell : cellule à insérer.
 *
 * Retour :
 *  - Aucun.
 */
void AddCellToList(t_list *list, t_cell *cell);


/* Affiche le contenu d'une liste chaînée (sommet d'arrivée et probabilité de chaque cellule).
 *
 * Paramètres :
 *  - list : la liste à afficher.
 *
 * Retour :
 *  - Aucun.
 */
void PrintList(t_list list);


/* Crée une structure d'adjacence vide contenant 'taille' sommets.
 * Chaque liste d'adjacence est initialisée à vide.
 *
 * Paramètres :
 *  - taille : nombre de sommets du graphe.
 *
 * Retour :
 *  - Une structure t_adj initialisée.
 */
t_adj CreateEmptyAdj(int taille);


/* Affiche une structure d'adjacence : pour chaque sommet, affiche la liste
 * de ses arêtes sortantes et les probabilités associées.
 *
 * Paramètres :
 *  - adj : structure d'adjacence à afficher.
 *
 * Retour :
 *  - Aucun.
 */
void PrintAdj(t_adj adj);


/* Lit un fichier de description du graphe et construit la structure d'adjacence.
 *
 * Paramètres :
 *  - filename : nom du fichier à lire.
 *
 * Retour :
 *  - Une structure t_adj remplie à partir du fichier.
 */
t_adj readGraph(const char *filename);


/* Vérifie qu'un graphe est un graphe de Markov :
 *  - Les probabilités sortantes de chaque sommet doivent former une somme = 1.
 *  - Peut afficher des erreurs si la structure n'est pas conforme.
 *
 * Paramètres :
 *  - adj : graphe d'adjacence à vérifier.
 *
 * Retour :
 *  - Aucun.
 */
void verify_markov_graph(t_adj adj);

#endif //LIST_ADJ_H
