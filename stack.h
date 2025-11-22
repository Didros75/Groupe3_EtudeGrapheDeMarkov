//
// Created by morin on 10/11/2025.
//

#ifndef STACK_H
#define STACK_H

/* Structure représentant une pile.
 * data : tableau contenant les éléments de la pile.
 * top  : indice du sommet de la pile.
 * size : capacité maximale de la pile.
 */
typedef struct s_stack_int{
    int *data;
    int top;
    int size;
} t_stack_int;


/* Crée une pile d'entiers avec une capacité donnée.
 *
 * Paramètres :
 *  - size : nombre maximal d'éléments que la pile pourra contenir.
 *
 * Retour :
 *  - Un pointeur vers une nouvelle pile allouée dynamiquement.
 */
t_stack_int* create_stack_int(int size);


/* Vérifie si la pile est vide.
 *
 * Paramètres :
 *  - stack : pointeur vers la pile à tester.
 *
 * Retour :
 *  - 1 si la pile est vide.
 *  - 0 sinon.
 */
int is_empty_int(t_stack_int *stack);


/* Empile un entier au sommet de la pile.
 *
 * Paramètres :
 *  - stack : pointeur vers la pile.
 *  - value : valeur entière à empiler.
 *
 * Retour :
 *  - Aucun.
 */
void push_int(t_stack_int *stack, int value);


/* Dépile l’élément au sommet de la pile et le retourne.
 *
 * Paramètres :
 *  - stack : pointeur vers la pile.
 *
 * Retour :
 *  - L’entier au sommet de la pile.
 */
int pop_int(t_stack_int *stack);


/* Retourne l’entier au sommet de la pile sans le dépiler.
 *
 * Paramètres :
 *  - stack : pointeur vers la pile.
 *
 * Retour :
 *  - La valeur au sommet de la pile.
 */
int peek_int(t_stack_int *stack);

#endif //STACK_H
