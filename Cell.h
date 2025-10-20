//
// Created by julie on 20/10/2025.
//

#ifndef CELL_H
#define CELL_H

typedef struct s_cell {
    int summit_arrival;
    float proba;
    struct s_cell *next;
} t_cell;


t_cell *createCell(int summit_arrival , float proba);

#endif //CELL_H
