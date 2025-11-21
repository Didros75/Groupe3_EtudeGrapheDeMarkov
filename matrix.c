//
// Created by julie on 21/11/2025.
//

#include "matrix.h"
#include <stdlib.h>
#include <stdio.h>
void matrix0(float **matrix, int n){
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      matrix[i][j] = 0;
    }
  }
}

float **createMatrix(t_adj t){
  int n = t.lenght;
  float **matrix = malloc(n * sizeof(float *));
  for (int i = 0; i < n; i++){
    matrix[i] = malloc(n * sizeof(float));
  }
  matrix0(matrix, n);
  for (int i = 0; i < t.lenght+1; i++){
    t_cell *current = t.leaving_edge[i].head;
    while (current != NULL){
      matrix[i-1][current->summit_arrival-1] = current->proba;
      current = current->next;
    }
  }
  return matrix;
}

void printMatrix(float **matrix, int n){
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      printf("%.2f\t", matrix[i][j]);
    }
    printf("\n");
  }
}

float **copyMatrix(float **matrix, int n){
  float **copy = malloc(n * sizeof(float *));
  for(int i = 0; i < n; i++){
    copy[i] = malloc(n * sizeof(float));
    for(int j = 0; j < n; j++){
      copy[i][j] = matrix[i][j];
    }
  }
  return copy;
}

float **multiplyMatrix(float **A, float **B, int n){
  float **C = malloc(n * sizeof(float *));
  for(int i = 0; i < n; i++){
    C[i] = malloc(n * sizeof(float));
    for(int j = 0; j < n; j++){
      C[i][j] = 0;
      for(int k = 0; k < n; k++){
        C[i][j] += A[i][k] * B[k][j];
      }
    }
  }
  return C;
}

float diffMatrix(float **M, float **N, int n){
  float sum = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      float d = M[i][j] - N[i][j];
      if(d < 0) d = -d;
      sum += d;
    }
  }
  return sum;
}

float **subMatrix(float **matrix, t_stock_class part, int compo_index){
  t_class compo = part.tab_t_class[compo_index];
  int n = compo.nb_summit;
  float **sub = malloc(n * sizeof(float *));
  for (int i = 0; i < n; i++) {
    sub[i] = malloc(n * sizeof(float));
  }
  for (int i = 0; i < n; i++) {
    int row = compo.tab_summit[i].id-1;

    for (int j = 0; j < n; j++) {
      int col = compo.tab_summit[j].id-1;
      printf("%d %d, ", row, col);
      sub[i][j] = matrix[row][col];
    }
  }
  return sub;
}
