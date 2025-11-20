#include <malloc.h>
#include "hasse.h"
#import "tarjan.h"

void tarjanToArray(char *array_class, t_stock_class vertex){
  for (int i = 0; i < vertex.nb_t_class; i++){
    t_class actualClass = vertex.tab_t_class[i];
    for (int j = 0; j < actualClass.nb_summit; j++){
      t_tarjan_vertex actualVertex = actualClass.tab_summit[j];
      array_class[actualVertex.id] = actualClass.name[1];
    }
  }
}

int linkExists(const t_link_array *array, char from, char to)
{
    for (int i = 0; i < array->log_size; i++) {
        if (array->links[i].from == from && array->links[i].to == to)
            return 1;
    }
    return 0;
}

void hasse(char *array_class, t_adj adj, t_link_array *link_array){
  for (int i = 0; i < adj.lenght; i++){
    char Ci = array_class[i];
    t_cell *current = adj.leaving_edge[i].head;
    while (current != NULL){
      char Cj = array_class[current->summit_arrival];
      if (Ci != Cj) {
        if (linkExists(link_array, Ci, Cj)){
          	link_array->log_size++;
         	link_array->links[link_array->log_size].from = Ci;
    		link_array->links[link_array->log_size].to = Cj;
        }
      }
      current = current->next;
    }
  }
}

void removeTransitiveLinks(t_link_array *p_link_array)
{
    int i = 0;
    while (i < p_link_array->log_size)
    {
        t_link link1 = p_link_array->links[i];
        int j = 0;
        int to_remove = 0;
        while (j < p_link_array->log_size && !to_remove)
        {
            if (j != i)
            {
                t_link link2 = p_link_array->links[j];
                if (link1.from == link2.from)
                {
                    // look for a link from link2.to to link1.to
                    int k = 0;
                    while (k < p_link_array->log_size && !to_remove)
                    {
                        if (k != j && k != i)
                        {
                            t_link link3 = p_link_array->links[k];
                            if ((link3.from == link2.to) && (link3.to == link1.to))
                            {
                                to_remove = 1;
                            }
                        }
                        k++;
                    }
                }
            }
            j++;
        }
        if (to_remove)
        {
            // remove link1 by replacing it with the last link
            p_link_array->links[i] = p_link_array->links[p_link_array->log_size - 1];
            p_link_array->log_size--;
        }
        else
        {
            i++;
        }
    }
}