//
// Created by julie on 20/10/2025.
//
#include <stdlib.h>
#include "Cell.h"

t_cell *createCell(int summit_arrival , float proba){
    t_cell *new = (t_cell *)malloc(sizeof(t_cell));
    new->summit_arrival = summit_arrival;
    new->proba = proba;
    new->next = NULL;
    return new;
}