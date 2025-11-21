#include <stdio.h>
#include <stdlib.h>
#include "Cell.h"
#include "List_Adj.h"
#include "export.h"
#include "tarjan.h"
#include "hasse.h"
#include "matrix.h"
#include "utils.h"

int main() {
    //t_adj t=readGraph("C:/Users/chaig/CLionProjects/Groupe3_EtudeGrapheDeMarkov/data/exemple2.txt");
    t_adj graph=readGraph("C:/Users/julie/CLionProjects/Groupe3_EtudeGrapheDeMarkov/data/exemple_meteo.txt");
    //t_adj t=readGraph("C:/Users/morin/CLionProjects/Groupe3_EtudeGrapheDeMarkov/data/exemple2.txt");
    //t_adj t=readGraph("C:/Users/boban/CLionProjects/Groupe3_EtudeGrapheDeMarkov_prj/data/exemple3.txt");

    // ===== Chargement du graphe =====
    int n = graph.lenght;

    // ===== Construction de la matrice =====
    float **M = createMatrix(graph);

    printf("Matrice complète :\n");
    printMatrix(M, n);
    printf("\n");

    // ===== Tarjan : récupération des classes =====
    t_stock_class partition = tarjan(graph);   // ta fonction Tarjan

    printf("Le graphe contient %d classes (SCC).\n", partition.nb_t_class);

    // ===== Choix d’une vraie classe =====
    int k = 0;   // on teste simplement la première classe trouvée

    printf("Test subMatrix sur la classe %d (%d sommets)\n",
           k, partition.tab_t_class[k].nb_summit);

    // ===== Extraction =====
    float **S = subMatrix(M, partition, k);

    // ===== Affichage =====
    printf("Sous-matrice de la classe %d :\n", k);
    printMatrix(S, partition.tab_t_class[k].nb_summit);

    return 0;
}

