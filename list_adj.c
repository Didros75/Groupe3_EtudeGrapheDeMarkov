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

void AddCellToList(t_list *list, t_cell *new_cell){
  t_cell *cell;
  cell = list->head;
  while (cell->next != NULL){
    cell = cell->next;
  }
  cell->next = new_cell;
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

t_adj CreateEmptyAdj(int taille){
  t_adj adj;
  adj.lenght = taille;
  adj.leaving_edge = malloc(taille*sizeof(t_list));
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
    t_cell *cell = createCell(arrivee, proba);
    AddCellToList(&(adj.leaving_edge[depart]), cell);
  }
  fclose(file);
  return adj;
}