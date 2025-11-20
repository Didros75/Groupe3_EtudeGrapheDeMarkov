//
// Created by morin on 10/11/2025.
//

#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

t_stack_int* create_stack_int(int size)
{
    t_stack_int *stack = malloc(sizeof(t_stack_int));
    if (!stack) {
        fprintf(stderr, "Erreur d'allocation pour la pile\n");
        return NULL;
    }

    stack->data = malloc(size * sizeof(int));
    if (!stack->data) {
        fprintf(stderr, "Erreur d'allocation pour les données de la pile\n");
        free(stack);
        return NULL;
    }

    stack->size = size;
    stack->top  = -1;

    return stack;
}

int is_empty_int(t_stack_int *stack)
{
    return (stack->top == -1);
}

void push_int(t_stack_int *stack, int value)
{
    if (stack->top >= stack->size - 1) {
        fprintf(stderr, "Pile pleine, impossible de pousser %d\n", value);
        return;
    }
    stack->data[++(stack->top)] = value;
}

int pop_int(t_stack_int *stack)
{
    if (is_empty_int(stack)) {
        fprintf(stderr, "Pile vide, impossible de dépiler\n");
        return -1;  // valeur sentinelle
    }
    return stack->data[(stack->top)--];
}

int peek_int(t_stack_int *stack)
{
    if (is_empty_int(stack)) {
        fprintf(stderr, "Pile vide, impossible de consulter le sommet\n");
        return -1;  // valeur sentinelle
    }
    return stack->data[stack->top];
}

