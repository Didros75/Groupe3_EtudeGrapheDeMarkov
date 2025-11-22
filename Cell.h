//
// Created by julie on 20/10/2025.
//

#ifndef CELL_H
#define CELL_H

/* Structure représentant une cellule de liste chaînée.
 * summit_arrival : indice du sommet d'arrivée.
 * proba          : probabilité associée à l'arête (sommet -> summit_arrival).
 * next           : pointeur vers la cellule suivante de la liste.
 */

typedef struct s_cell {
    int summit_arrival;
    float proba;
    struct s_cell *next;
} t_cell;

/* Crée une cellule t_cell.
 *
 * Paramètres :
 *  - summit_arrival : indice du sommet atteint.
 *  - proba          : probabilité associée à l'arête.
 *
 * Retour :
 *  - Un pointeur vers la cellule nouvellement créée.
 */

t_cell *createCell(int summit_arrival , float proba);

#endif //CELL_H
