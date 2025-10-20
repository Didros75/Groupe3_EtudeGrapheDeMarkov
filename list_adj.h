//
// Created by julie on 20/10/2025.
//

#ifndef LIST_ADJ_H
#define LIST_ADJ_H
#include "Cell.h"

// Définition des types liste et liste d'adjacence

typedef struct s_list {
  t_cell *head;
} t_list;

typedef struct s_adj {
  int lenght;
  t_list *leaving_edge;
} t_adj;

// Définition des fonctions utiles pour les opérations sur les listes

t_list CreateEmptyList();
void AddCellToList(t_list *list, t_cell *cell);
void PrintList(t_list list);
t_adj CreateEmptyAdj(int taille);
void PrintAdj(t_adj adj);

t_adj readGraph(const char *filename);

//Définition de la fonction qui vérifie si le graphe est un graphe de Markov

void verify_markov_graph(t_adj adj);

#endif //LIST_ADJ_H
