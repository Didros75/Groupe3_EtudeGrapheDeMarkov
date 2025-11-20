#ifndef __HASSE_H__
#define __HASSE_H__

#include "list_adj.h"
#define T_MAX 100

typedef struct s_link {
  int from;
  int to;
} t_link;

typedef struct s_link_array {
    t_link links[T_MAX];
    int log_size;
} t_link_array;

void removeTransitiveLinks(t_link_array *p_link_array);
void hasse(int *array_class, t_adj adj, t_link_array *link_array);

/**
 * @brief Creates a link array from the given partition and graph.
 *
 * @param part The partition of the graph.
 * @param graph The adjacency list representation of the graph.
 * @return The created link array.
 */

#endif