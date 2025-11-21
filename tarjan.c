//
// Created by morin on 10/11/2025.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tarjan.h"
#include "list_adj.h"
#include "stack.h"


t_tarjan_vertex* graph_to_tab(t_adj adj)
{
    int n = adj.lenght;
    t_tarjan_vertex *tab = malloc((n + 1) * sizeof(t_tarjan_vertex));
    if (!tab) {
        fprintf(stderr, "Erreur d'allocation du tableau de sommets Tarjan\n");
        return NULL;
    }

    for (int i = 0; i <= n; i++) {
        tab[i].id = i;
        tab[i].num = -1;
        tab[i].num_access = -1;
        tab[i].indicator_bool = 0;
    }

    return tab;
}

static int min_int(int a, int b)
{
    return (a < b) ? a : b;
}


static void tarjan_parcours(int v, t_adj *adj, t_tarjan_vertex *tab, t_stack_int *stack, int *p_num, t_stock_class *partition)
{
    tab[v].num = *p_num;
    tab[v].num_access = *p_num;
    (*p_num)++;

    push_int(stack, v);
    tab[v].indicator_bool = 1;

    t_cell *courant = adj->leaving_edge[v].head;
    while (courant != NULL) {
        int w = courant->summit_arrival;

        if (tab[w].num == -1) {
            tarjan_parcours(w, adj, tab, stack, p_num, partition);
            tab[v].num_access = min_int(tab[v].num_access, tab[w].num_access);
        }
        else if (tab[w].indicator_bool) {
            tab[v].num_access = min_int(tab[v].num_access, tab[w].num);
        }

        courant = courant->next;
    }

    if (tab[v].num_access == tab[v].num) {
        int class_index = partition->nb_t_class;

        partition->tab_t_class = realloc(partition->tab_t_class,(partition->nb_t_class + 1) * sizeof(t_class));
        if (!partition->tab_t_class) {
            fprintf(stderr, "Erreur de realloc pour les classes Tarjan\n");
            return;
        }

        t_class *new_class = &partition->tab_t_class[class_index];
        new_class->name = NULL;
        new_class->tab_summit = NULL;
        new_class->nb_summit = 0;

        int capacity = 0;
        int w;
        int first = 1;
        int min_id_in_class = -1;

        do {
            w = pop_int(stack);
            tab[w].indicator_bool = 0;

            if (first) {
                min_id_in_class = w;
                first = 0;
            } else {
                if (w < min_id_in_class)
                    min_id_in_class = w;
            }

            if (new_class->nb_summit == capacity) {
                capacity = (capacity == 0) ? 4 : capacity * 2;
                t_tarjan_vertex *tmp = realloc(new_class->tab_summit,capacity * sizeof(t_tarjan_vertex));
                if (!tmp) {
                    fprintf(stderr, "Erreur de realloc pour les sommets d'une classe\n");
                    free(new_class->tab_summit);
                    new_class->tab_summit = NULL;
                    new_class->nb_summit  = 0;
                    break;
                }
                new_class->tab_summit = tmp;
            }

            new_class->tab_summit[new_class->nb_summit] = tab[w];
            new_class->nb_summit++;

        } while (w != v);

        {
            char buffer[32];
            snprintf(buffer, sizeof(buffer), "C%d", class_index + 1);
            new_class->name = malloc(strlen(buffer) + 1);
            if (new_class->name != NULL) {
                strcpy(new_class->name, buffer);
            }
        }

        partition->nb_t_class++;
    }
}


t_stock_class tarjan(t_adj adj)
{
    t_stock_class partition;
    partition.nb_t_class  = 0;
    partition.tab_t_class = NULL;

    int n = adj.lenght;

    t_tarjan_vertex *tab = graph_to_tab(adj);
    if (!tab) {
        fprintf(stderr, "Erreur dans graph_to_tab\n");
        return partition;
    }

    t_stack_int *pile = create_stack_int(n);
    if (!pile) {
        fprintf(stderr, "Erreur lors de la création de la pile\n");
        free(tab);
        return partition;
    }

    int num = 0;

    for (int v = 1; v <= n; v++) {
        if (tab[v].num == -1) {
            tarjan_parcours(v, &adj, tab, pile, &num, &partition);
        }
    }

    free(pile->data);
    free(pile);
    free(tab);

    return partition;
}

void print_t_stock_class(t_stock_class partition)
{
    printf("Nombre de classes fortement connexes : %d\n", partition.nb_t_class);

    for (int i = 0; i < partition.nb_t_class; i++) {
        t_class c = partition.tab_t_class[i];
        printf("Classe %s", c.name);

        printf(" (taille %d) : ", c.nb_summit);

        for (int j = 0; j < c.nb_summit; j++) {
            printf("%d ", c.tab_summit[j].id);
        }
        printf("\n");
    }
}