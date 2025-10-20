//
// Created by julie on 20/10/2025.
//
#include <stdlib.h>
#include "Cell.h"

t_cell *createCell(int summit_arrival, float proba) {
    t_cell *c = (t_cell *)malloc(sizeof(t_cell));
    if (c == NULL) {
        perror("malloc failed in createCell");
        exit(EXIT_FAILURE);
    }
    c->summit_arrival = summit_arrival;
    c->proba = proba;
    c->next = NULL;   // IMPORTANT
    return c;
}