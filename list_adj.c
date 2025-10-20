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

t_adj *CreateEmptyAdj(int taille){
  t_adj *adj = malloc(sizeof(t_adj));
  adj->lenght = taille;
  adj->leaving_edge = malloc(taille*sizeof(t_list));
  return adj;
}

void PrintAdj(t_adj adj){
  for (int i = 0; i < adj.lenght; i++){
    printf("Liste pour le sommet %d :", i);
    PrintList(adj.leaving_edge[i]);
    printf("\n");
  }
}