#include <malloc.h>
#include "hasse.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


void tarjanToArray(char **array_class, t_stock_class vertex){
    for (int i = 0; i < vertex.nb_t_class; i++){
        t_class actualClass = vertex.tab_t_class[i];
        for (int j = 0; j < actualClass.nb_summit; j++){
            t_tarjan_vertex actualVertex = actualClass.tab_summit[j];
            array_class[actualVertex.id - 1] = actualClass.name;
        }
    }
}

bool link_exists(t_link_array *link_array, char *from, char *to) {
    for (int i = 0; i < link_array->log_size; i++) {
        if (strcmp(link_array->links[i].from, from) == 0 &&
            strcmp(link_array->links[i].to, to) == 0) {
            return true;
            }
    }
    return false;
}

void hasse(char **array_class, t_adj adj, t_link_array *link_array) {
    link_array->log_size = 0;
    for (int summit = 0; summit < adj.lenght; summit++) {
        //printf("Summit value is : %d\n", summit+1);

        char *Ci = array_class[summit];
        t_cell *current = adj.leaving_edge[summit].head;
        while (current != NULL) {


            int arrival = current->summit_arrival;
            char *Cj = array_class[arrival-1];

            //printf("%d - %s\n",current->summit_arrival,Cj);
            if (strcmp(Ci, Cj) != 0) {

                if (!link_exists(link_array, Ci, Cj)) {

                    link_array->links[link_array->log_size].from = Ci;
                    link_array->links[link_array->log_size].to = Cj;

                    link_array->log_size++;

                }
            }
            current = current->next;
        }//printf("Next !\n");

    }//printf("Final Point --------------\n");
    removeTransitiveLinks(link_array);
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