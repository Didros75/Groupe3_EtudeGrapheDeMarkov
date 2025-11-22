//
// Created by julie on 21/11/2025.
//

#ifndef MATRIX_H
#define MATRIX_H
#include "list_adj.h"
#include "tarjan.h"

float ** createMatrix(t_adj t);
void matrix0(float ** matrix, int n);
void printMatrix(float ** matrix, int n);
float **copyMatrix(float **matrix, int n);
float **multiplyMatrix(float **A, float **B, int n);
float diffMatrix(float **M, float **N, int n);
float **powerMatrix(float **matrix, int n, int p);
float **stableMatrix(float **A, int n, float epsilon);
void allStableMatrix(t_adj t, t_stock_class part);

float **subMatrix(float **matrix, t_stock_class part, int compo_index);

#endif //MATRIX_H