//
// Created by morin on 10/11/2025.
//

#ifndef STACK_H
#define STACK_H


typedef struct s_stack_int{
    int *data;      // Tableau d'entiers (indices de sommets)
    int top;        // Indice du sommet courant de la pile
    int size;       // Taille maximale
} t_stack_int;

#endif //STACK_H
