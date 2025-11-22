//
// Created by morin on 10/11/2025.
//

#ifndef TARJAN_H
#define TARJAN_H
#include "list_adj.h"
#include "stack.h"

/* Structure représentant un sommet utilisé dans l’algorithme de Tarjan.
 * id            : identifiant du sommet.
 * num           : numéro d’ordre lors du parcours (index).
 * num_access    : plus petit numéro accessible depuis ce sommet.
 * indicator_bool: indique si le sommet est actuellement dans la pile.
 */
typedef struct s_tarjan_vertex {
  int id;
  int num;
  int num_access;
  int indicator_bool;
  } t_tarjan_vertex;


/* Représente une classe.
 * name       : nom de la classe.
 * tab_summit : tableau des sommets appartenant à la classe.
 * nb_summit  : nombre de sommets dans la classe.
 */
typedef struct s_class {
  char *name;
  t_tarjan_vertex *tab_summit;
  int nb_summit;
} t_class;


/* Contient toutes les classes par Tarjan.
 * nb_t_class  : nombre total de classes.
 * tab_t_class : tableau des classes.
 */
typedef struct s_stock_class {
  int nb_t_class;
  t_class *tab_t_class;
}t_stock_class;


/* Structure représentant une pile contenant des t_tarjan_vertex.
 * data : tableau contenant les éléments empilés.
 * top  : index du sommet de la pile (-1 si vide).
 * size : capacité maximale de la pile.
 */
typedef struct s_stack{
  t_tarjan_vertex *data;
  int top;
  int size;
}t_stack;


/* Crée une pile destinée à stocker des t_tarjan_vertex.
 *
 * Paramètres :
 *  - size : capacité maximale de la pile.
 *
 * Retour :
 *  - Une nouvelle pile.
 */
t_tarjan_vertex* graph_to_tab(t_adj);
t_stack* create_stack(int);
int is_empty(t_stack*);
void push(t_stack*, t_tarjan_vertex);
t_tarjan_vertex pop(t_stack*);
t_tarjan_vertex peek(t_stack*);


/* Retourne le minimum entre deux entiers.
 *
 * Paramètres :
 *  - a, b : entiers à comparer.
 *
 * Retour :
 *  - Le minimum des deux valeurs.
 */
static int min_int(int, int);


/* Fonction récursive de l'algorithme de Tarjan.
 *
 * Paramètres :
 *  - v              : sommet courant.
 *  - adj            : graphe d'adjacence.
 *  - tab            : tableau des sommets Tarjan.
 *  - stack          : pile utilisée par l'algorithme.
 *  - p_num          : compteur global de numérotation.
 *  - partition      : structure où stocker les classes trouvées.
 *
 * Retour :
 *  - Aucun.
 */
static void tarjan_parcours(int, t_adj*, t_tarjan_vertex*, t_stack_int*, int*, t_stock_class*);


/* Lance l'algorithme de Tarjan.
 *
 * Paramètres :
 *  - t : graphe d'adjacence.
 *
 * Retour :
 *  - Une structure t_stock_class contenant toutes les classes trouvées.
 */
t_stock_class tarjan(t_adj);


/* Affiche les classes du graphe.
 *
 * Paramètres :
 *  - partition : ensemble des classes obtenues après Tarjan.
 *
 * Retour :
 *  - Aucun.
 */
void print_t_stock_class(t_stock_class partition);

#endif //TARJAN_H
