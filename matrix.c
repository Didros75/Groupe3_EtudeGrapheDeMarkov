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

float **powerMatrix(float **A, int n, int p){
  if (p == 1)
    return copyMatrix(A, n);
  float **result = copyMatrix(A, n);
  for (int k = 1; k < p; k++) {
    float **tmp = multiplyMatrix(result, A, n);
    for(int i = 0; i < n; i++)
      free(result[i]);
    free(result);

    result = tmp;
  }

  return result;
}


void printMatrix(float **matrix, int n){
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      printf("%.2f\t", matrix[i][j]);
    }
    printf("\n");
  }
}

void printDistribution(float **matrix, int n){
  printf("[");
  for (int i = 0; i < n; i++) {
    printf("%.2f ", matrix[0][i]);
  }
  printf("]\n");
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
      //printf("%d %d, ", row, col);
      sub[i][j] = matrix[row][col];
    }
  }
  return sub;
}

void freeMatrix(float **matrix, int rows) {
  if (matrix == NULL) return;
  for (int i = 0; i < rows; i++) {
    free(matrix[i]);
  }
  free(matrix);
}

float **stableMatrix(float **A, int n, float epsilon) {
  int p = 1;
  float **M_prev = powerMatrix(A, n, p);
  float **M_curr = NULL;

  while (1) {
    p++;
    M_curr = powerMatrix(A, n, p);
    float diff = diffMatrix(M_curr, M_prev, n);

    freeMatrix(M_prev, n);

    if (diff < epsilon) {
      return M_curr;
    }

      if (p>100) {
        printf("Impossible de trouver la distribution stationnaire, approximation :\n");
        return M_curr;

    }

    M_prev = M_curr;
  }
}


void allStableMatrix(t_adj t, t_stock_class part) {
  printf("Matrice initiale :\n");
  float **M = createMatrix(t);
  printMatrix(M, t.lenght);
  printf("\n");

  for (int i = 0; i < part.nb_t_class; i++) {
    int n = part.tab_t_class[i].nb_summit;

    float **S = subMatrix(M, part, i);
    float **C = stableMatrix(S, n, 0.01);

    printf("Matrice de la distribution stationnaire de la classe C%d\n", i + 1);
    printDistribution(C, n);
    printf("\n");

    freeMatrix(S, n);
    freeMatrix(C, n);
  }

  freeMatrix(M, t.lenght);
}

int gcd(int *vals, int nbvals) {
    if (nbvals == 0) return 0;
    int result = vals[0];
    for (int i = 1; i < nbvals; i++) {
        int a = result;
        int b = vals[i];
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        result = a;
    }
    return result;
}


int getPeriod(float **A, int n) {
    if (n == 0 || A == NULL) return 0;

    // classe à un seul sommet
    if (n == 1) {
        return (A[0][0] > 0.0f) ? 1 : 0;
    }

    int *cycle_lengths = malloc((2 * n) * sizeof(int));
    int count = 0;

    float **P = copyMatrix(A, n);  // P = A^1

    // On vérifie les puissances de 1 à 2*n (suffisant pour trouver tous les cycles)
    for (int k = 1; k <= 2 * n; k++) {
        // Vérifie si un élément diagonal est > 0
        for (int i = 0; i < n; i++) {
            if (P[i][i] > 0.0f) {
                cycle_lengths[count++] = k;
                break;  // Un seul élément diagonal suffit pour cette puissance
            }
        }

        // Calcule la puissance suivante : P = P * A
        float **Next = multiplyMatrix(P, A, n);
        freeMatrix(P, n);
        P = Next;
    }

    freeMatrix(P, n);

    int period;
    if (count == 0) {
        period = 0;
    } else {
        period = gcd(cycle_lengths, count);
    }

    free(cycle_lengths);
    return period;
}

void periodicity(t_adj graph) {
    int n = graph.lenght;
    float **FullMatrix = createMatrix(graph);
    t_stock_class partition = tarjan(graph);

    for (int i = 0; i < partition.nb_t_class; i++) {
      t_class cls = partition.tab_t_class[i];

      printf("\nAnalyse de la Class %s (Sommets : ", partition.tab_t_class[i].name);
        for (int v = 0; v < cls.nb_summit; v++) {
            printf("%d ", cls.tab_summit[v].id);
        }
        printf("):\n");
        float **subM = subMatrix(FullMatrix, partition, i);

        int period = getPeriod(subM, cls.nb_summit);
        printf("Period: %d\n", period);

        float **M = createMatrix(graph);
        float **S = subMatrix(M, partition, i);
        printf("Ditribution stationnaire de %s :\n", partition.tab_t_class[i].name);
        float **C = stableMatrix(S, partition.tab_t_class[i].nb_summit, 0.01);

        printDistribution(C, partition.tab_t_class[i].nb_summit);

        freeMatrix(M, partition.tab_t_class[i].nb_summit);
        freeMatrix(S, partition.tab_t_class[i].nb_summit);
        freeMatrix(C, partition.tab_t_class[i].nb_summit);
        freeMatrix(subM, cls.nb_summit);
    }

    freeMatrix(FullMatrix, n);
}