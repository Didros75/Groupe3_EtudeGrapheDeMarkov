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
  if (!new_cell) return;
  new_cell->next = NULL;

  t_cell **ptr = &list->head;
  while (*ptr) ptr = &((*ptr)->next);
  *ptr = new_cell;
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
  // allouer un tableau de t_list de taille "taille"
  adj.leaving_edge = (t_list *)malloc(taille * sizeof(t_list));
  if (adj.leaving_edge == NULL) {
    perror("malloc failed in CreateEmptyAdj");
    exit(EXIT_FAILURE);
  }

  // initialiser chaque liste (head = NULL)
  for (int i = 0; i < taille; ++i) {
    adj.leaving_edge[i].head = NULL;
  }

  return adj;
}


void PrintAdj(t_adj adj){
  for (int i = 0; i < adj.lenght; i++){
    printf("Liste pour le sommet %d :", i);
    PrintList(adj.leaving_edge[i]);
    printf("\n");
  }
}

t_adj readGraph(const char *filename) {
  FILE *file = fopen(filename, "rt"); // read-only, text
  int nbvert, depart, arrivee;
  float proba;

  //declarer la variable pour la liste d’adjacence
  t_adj adj;

  if (file==NULL) {
    perror("Could not open file for reading");
    exit(EXIT_FAILURE);
  }

  // first line contains number of vertices
  if (fscanf(file, "%d", &nbvert) != 1) {
    perror("Could not read number of vertices");
    exit(EXIT_FAILURE);
  }

  // Initialiser une liste d’adjacence vide à partir du nombre de sommets
  adj = CreateEmptyAdj(nbvert);

  while (fscanf(file, "%d %d %f", &depart, &arrivee, &proba) == 3) {
    // on obtient, pour chaque ligne du fichier les valeurs
    // depart, arrivee, et proba

    //Ajouter l’arête qui va de ‘depart’ à ‘arrivée’ avec la probabilité ‘proba’ dans la liste d’adjacence
    printf("ccc");
    t_cell *cell = createCell(arrivee, proba);
    printf("ddd");
    AddCellToList(&(adj.leaving_edge[depart]), cell);
    printf("eee");
  }
  fclose(file);
  return adj;
}

void verify_markov_graph(t_adj adj){
  for (int i = 0; i < adj.lenght; i++){
    t_cell *cell = adj.leaving_edge[i].head;
    float cpt = 0;
    while (cell != NULL){
      cpt += cell->proba;
      cell = cell->next;
    }
    if (cpt<0.99 || cpt>1.00){
      printf("Le graphe n’est pas un graphe de Markov");
      printf("La somme des probabilités du sommet %d est %f", cell->summit_arrival, cpt);
      return;
    }
  }
  printf("Le graphe est un graphe de Markov");
}