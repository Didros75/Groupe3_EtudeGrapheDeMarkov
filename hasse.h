#ifndef __HASSE_H__
#define __HASSE_H__

#include "list_adj.h"
#include "tarjan.h"
#define T_MAX 100

/* Structure représentant un lien orienté entre deux classes.
 * from : nom de la classe d'origine.
 * to   : nom de la classe de destination.
 */
typedef struct s_link {
  char *from;
  char *to;
} t_link;


/* Tableau stockant un ensemble de liens orientés.
 * links     : tableau fixe contenant les liens.
 * log_size  : nombre de liens utilisés dans le tableau.
 */
typedef struct s_link_array {
    t_link links[T_MAX];
    int log_size;
} t_link_array;


/* Transforme le résultat de Tarjan en un tableau utilisable pour hasse.
 *
 * Paramètres :
 *  - array_class : tableau où sont stockées les classes par indice.
 *  - vertex      : structure contenant les sommets appartenat à chaque classe.
 *
 * Retour :
 *  - Aucun.
 */
void tarjanToArray(char **array_class, t_stock_class vertex);


/* Supprime les liens transitifs dans un diagramme de hasse.
 *
 * Paramètres :
 *  - p_link_array : pointeur vers la structure contenant les liens à filtrer.
 *
 * Retour :
 *  - Aucun.
 */
void removeTransitiveLinks(t_link_array *p_link_array);


/* Construit le diagramme de Hasse à partir du tableau des classes par indice.
 *
 * Paramètres :
 *  - array_class : tableau contenant les classes des sommets.
 *  - adj         : structure d'adjacence du graphe initial.
 *  - link_array  : structure où seront stockés les liens du diagramme de Hasse.
 *
 * Retour :
 *  - Aucun.
 */
void hasse(char **array_class, t_adj adj, t_link_array *link_array);

#endif