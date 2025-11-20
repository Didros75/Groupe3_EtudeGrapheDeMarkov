//
// Created by morin on 10/11/2025.
//

#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

t_stack_int* create_stack_int(int size) {
    t_stack_int *stack = malloc(sizeof(t_stack_int));
    stack->data = malloc(size * sizeof(int));
    stack->top = -1;
    stack->size = size;
    return stack;
}

int is_empty_int(t_stack_int *stack) {
    return stack->top == -1;
}

void push_int(t_stack_int *stack, int value) {
    if (stack->top < stack->size - 1) {
        stack->data[++stack->top] = value;
    }
}

int pop_int(t_stack_int *stack) {
    return stack->data[stack->top--];
}

int peek_int(t_stack_int *stack) {
    return stack->data[stack->top];
}
