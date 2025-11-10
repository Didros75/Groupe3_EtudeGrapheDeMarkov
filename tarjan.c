//
// Created by morin on 10/11/2025.
//

#include "tarjan.h"
#include <stdio.h>
#include <stdlib.h>

t_tarjan_vertex* graph_to_tab(t_adj adj){
  t_tarjan_vertex* tab = malloc(sizeof(t_tarjan_vertex)*adj.lenght);
  for (int i=1; i<adj.lenght+1; i++){
    tab[i].id = i;
    tab[i].num = -1;
    tab[i].num_access = -1;
    tab[i].indicator_bool = 0;
  }
  return tab;
}

t_stack* create_stack(int size) {
  t_stack *stack = malloc(sizeof(t_stack));
  if (!stack) {
    perror("Erreur d’allocation de la pile");
    exit(EXIT_FAILURE);
  }

  stack->data = malloc(size * sizeof(t_tarjan_vertex));

  stack->top = -1;
  stack->size = size;

  return stack;
}

int is_empty(t_stack *stack) {
  return stack->top == -1;
}

void push(t_stack *stack, t_tarjan_vertex vertex) {
  if (stack->top >= stack->size - 1) {
    fprintf(stderr, "Erreur : pile pleine\n");
    return;
  }
  stack->data[++stack->top] = vertex;
}

t_tarjan_vertex pop(t_stack *stack) {
  t_tarjan_vertex vide = {-1, -1, -1, 0}; // Valeur par défaut en cas d’erreur
  if (is_empty(stack)) {
    fprintf(stderr, "Erreur : pile vide\n");
    return vide;
  }
  return stack->data[stack->top--];
}

t_tarjan_vertex peek(t_stack *stack) {
  t_tarjan_vertex vide = {-1, -1, -1, 0};
  if (is_empty(stack)) return vide;
  return stack->data[stack->top];
}

