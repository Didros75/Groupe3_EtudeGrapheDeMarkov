//
// Created by julie on 21/11/2025.
//

#ifndef MATRIX_H
#define MATRIX_H
#include "list_adj.h"

float ** createMatrix(t_adj t);
void matrix0(float ** matrix, int n);
void printMatrix(float ** matrix, int n);
float **copyMatrix(float **matrix, int n);
float **multiplyMatrix(float **A, float **B, int n);
float diffMatrix(float **M, float **N, int n);

#endif //MATRIX_H