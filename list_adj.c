//
// Created by julie on 20/10/2025.
//

#include "list_adj.h"
#include <stdlib.h>
#include <stdio.h>

t_list CreateEmptyList(){
  t_list list;
  list.head = NULL;
  return list;
}

void AddCellToList(t_list *list, t_cell *new_cell) {
  if (!list || !new_cell)
    return;

  new_cell->next = NULL;

  if (!list->head) {
    list->head = new_cell;
    return;
  }

  t_cell *current = list->head;
  while (current->next)
    current = current->next;

  current->next = new_cell;
}


void PrintList(t_list list){
  printf("[head @]");

  t_cell *cell;
  cell = list.head;
  while (cell != NULL){
    printf(" -> (%d, %f)", cell->summit_arrival, cell->proba);
    cell = cell->next;
  }
}

t_adj CreateEmptyAdj(int taille) {
  t_adj adj;
  if (taille <= 0) {
    adj.lenght = 0;
    adj.leaving_edge = NULL;
    return adj;
  }

  adj.lenght = taille;

  adj.leaving_edge = malloc((taille + 1) * sizeof(t_list));
  if (adj.leaving_edge == NULL) {
    perror("malloc failed in CreateEmptyAdj");
    exit(EXIT_FAILURE);
  }

  for (int i = 0; i <= taille; ++i) {
    adj.leaving_edge[i] = CreateEmptyList();
  }

  return adj;
}


void PrintAdj(t_adj adj){
  printf("\n");
  for (int i = 1; i <= adj.lenght; i++){
    printf("Liste pour le sommet %d :", i);
    PrintList(adj.leaving_edge[i]);
    printf("\n");
  }
}


t_adj readGraph(const char *filename) {
  FILE *file = fopen(filename, "rt");
  int nbvert, depart, arrivee;
  float proba;

  t_adj adj;

  if (file==NULL) {
    perror("Could not open file for reading");
    exit(EXIT_FAILURE);
  }

  if (fscanf(file, "%d", &nbvert) != 1) {
    perror("Could not read number of vertices");
    exit(EXIT_FAILURE);
  }

  adj = CreateEmptyAdj(nbvert);

  while (fscanf(file, "%d %d %f", &depart, &arrivee, &proba) == 3) {
    t_cell *cell = createCell(arrivee, proba);
    //printf("%d %f", cell->summit_arrival, cell->proba);
    AddCellToList(&(adj.leaving_edge[depart]), cell);
  }
  fclose(file);
  return adj;
}

void verify_markov_graph(t_adj adj) {

  for (int i = 1; i <= adj.lenght; i++) {
    t_cell *cell = adj.leaving_edge[i].head;
    float cpt = 0.0f;

    while (cell != NULL) {
      cpt += cell->proba;
      cell = cell->next;
    }

    if (cpt != 1.0f) {
      printf("Le graphe n'est pas un graphe de Markov.\n");
      printf("Somme des probabilités du sommet %d : %.3f\n", i, cpt);
      return;
    }
  }
  printf("Le graphe est un graphe de Markov.\n");
}
