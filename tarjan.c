//
// Created by morin on 10/11/2025.
//

#include "tarjan.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

static int min_int(int a, int b)
{
    return (a < b) ? a : b;
}

static void tarjan_parcours(int v,
                            t_adj *adj,
                            t_tarjan_vertex *vertices,
                            t_stack_int *stack,
                            int *current_num,
                            t_stock_class *stock)
{
    // Initialisation du sommet v
    vertices[v].num        = *current_num;
    vertices[v].num_access = *current_num;
    (*current_num)++;

    push_int(stack, v);
    vertices[v].indicator_bool = 1;    // v est dans la pile

    // Parcours de tous les successeurs w de v
    t_cell *cur = adj->leaving_edge[v].head;
    while (cur != NULL) {

        // ⚠️ CORRECTION ICI : utiliser le champ "sommet" (ou équivalent),
        // pas "proba"
        int w = cur->summit_arrival;   // <-- adapte le nom à ta struct t_cell

        if (vertices[w].num == -1) {
            // w non visité
            tarjan_parcours(w, adj, vertices, stack, current_num, stock);
            vertices[v].num_access =
                min_int(vertices[v].num_access, vertices[w].num_access);
        }
        else if (vertices[w].indicator_bool) {
            // w encore dans la pile
            vertices[v].num_access =
                min_int(vertices[v].num_access, vertices[w].num);
        }

        cur = cur->next;
    }

    // Si v est racine d'une CFC
    if (vertices[v].num_access == vertices[v].num) {
        t_class new_class;
        new_class.nb_summit  = 0;
        new_class.tab_summit = NULL;
        new_class.name       = NULL;

        int w;
        do {
            w = pop_int(stack);
            vertices[w].indicator_bool = 0;   // w sort de la pile

            // Ajout de vertices[w] dans la composante new_class
            t_tarjan_vertex *tmp = realloc(
                new_class.tab_summit,
                (new_class.nb_summit + 1) * sizeof(t_tarjan_vertex)
            );
            if (!tmp) {
                fprintf(stderr, "Erreur realloc tab_summit\n");
                free(new_class.tab_summit);
                return;
            }
            new_class.tab_summit = tmp;

            new_class.tab_summit[new_class.nb_summit] = vertices[w];
            new_class.nb_summit++;

        } while (w != v);

        // Donner un nom à la classe, par exemple "C0", "C1", ...
        char buffer[32];
        sprintf(buffer, "C%d", stock->nb_t_class);
        new_class.name = malloc(strlen(buffer) + 1);
        if (!new_class.name) {
            fprintf(stderr, "Erreur allocation name de classe\n");
            free(new_class.tab_summit);
            return;
        }
        strcpy(new_class.name, buffer);

        // Ajouter cette classe au stock
        t_class *tmp_class = realloc(
            stock->tab_t_class,
            (stock->nb_t_class + 1) * sizeof(t_class)
        );
        if (!tmp_class) {
            fprintf(stderr, "Erreur realloc tab_t_class\n");
            free(new_class.name);
            free(new_class.tab_summit);
            return;
        }

        stock->tab_t_class = tmp_class;
        stock->tab_t_class[stock->nb_t_class] = new_class;
        stock->nb_t_class++;
    }
}


t_stock_class tarjan(t_adj adj)
{
    t_stock_class partition;
    partition.nb_t_class  = 0;
    partition.tab_t_class = NULL;

    int n = adj.lenght;

    /* 1) Création et initialisation des t_tarjan_vertex */
    t_tarjan_vertex *tab = graph_to_tab(adj);
    if (!tab) {
        fprintf(stderr, "Erreur allocation sommets Tarjan\n");
        return partition;
    }

    /* 2) Création de la pile vide */
    t_stack_int pile;
    pile.data = malloc(n * sizeof(int));
    if (!pile.data) {
        fprintf(stderr, "Erreur pile\n");
        free(tab);
        return partition;
    }
    pile.size = n;
    pile.top  = -1;

    /* 3) Initialisation du compteur num */
    int num = 0;

    /* 4) Pour chaque sommet, si non visité → lancer parcours() */
    for (int v = 0; v < n; v++) {
        if (tab[v].num == -1) {  // num == -1 → jamais visité
            tarjan_parcours(v, &adj, tab, &pile, &num, &partition);
        }
    }

    free(pile.data);
    free(tab);
    return partition;
}

void print_t_stock_class(t_stock_class partition)
{
    for (int i = 0; i < partition.nb_t_class; i++)
    {
        t_class c = partition.tab_t_class[i];

        // Numéro de composante : C1, C2, ...
        printf("Composante C%d: {", i + 1);

        for (int j = 0; j < c.nb_summit; j++)
        {
            // On suppose que v.id est un indice 0..n-1, donc on affiche id+1
            int sommet_affiche = c.tab_summit[j].id + 1;

            if (j > 0)
                printf(",");

            printf("%d", sommet_affiche);
        }

        printf("}\n");
    }
}