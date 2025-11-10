//
// Created by morin on 10/11/2025.
//

#ifndef TARJAN_H
#define TARJAN_H
#include "list_adj.h"
#include "stack.h"

typedef struct s_tarjan_vertex {
  int id;
  int num;
  int num_access;
  int indicator_bool;
  } t_tarjan_vertex;

typedef struct s_class {
  char *name;
  t_tarjan_vertex *tab_summit;
  int nb_summit;
} t_class;

typedef struct s_stock_class {
  int nb_t_class;
  t_class *tab_t_class;
}t_stock_class;

typedef struct s_stack{
  t_tarjan_vertex *data;
  int top;
  int size;
}t_stack;

t_tarjan_vertex* graph_to_tab(t_adj);

#endif //TARJAN_H
