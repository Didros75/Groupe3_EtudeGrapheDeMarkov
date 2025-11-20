//
// Created by morin on 10/11/2025.
//

#ifndef STACK_H
#define STACK_H


typedef struct s_stack_int{
    int *data;
    int top;
    int size;
} t_stack_int;

t_stack_int* create_stack_int(int size);
int is_empty_int(t_stack_int *stack);
void push_int(t_stack_int *stack, int value);
int pop_int(t_stack_int *stack);
int peek_int(t_stack_int *stack);

#endif //STACK_H
