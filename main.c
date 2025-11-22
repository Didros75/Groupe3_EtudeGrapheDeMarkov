#include <matrix.h>
#include <stdio.h>
#include <stdlib.h>
#include "Cell.h"
#include "List_Adj.h"
#include "export.h"
#include "tarjan.h"
#include "hasse.h"
#include "utils.h"

int main() {
    t_adj t=readGraph("C:/Users/chaig/CLionProjects/Groupe3_EtudeGrapheDeMarkov/data/exemple_valid_step3.txt");
    //t_adj t=readGraph("C:/Users/boban/CLionProjects/Groupe3_EtudeGrapheDeMarkov_prj/data/exemple3.txt");
    //t_adj t=readGraph("C:/Users/morin/CLionProjects/Groupe3_EtudeGrapheDeMarkov/data/exemple2.txt");

    //export_adj(t, "test.txt");
    /*
    char *array_class[t.lenght];
    t_stock_class partition = tarjan(t);
    tarjanToArray(array_class, partition);
    printf("\n");
    t_link_array links;
    hasse(array_class, t, &links);
    //Affichage des liens
    printf("Liens du Hasse :\n");
    for (int i = 0; i < links.log_size; i++) {
        printf("%s -> %s\n", links.links[i].from, links.links[i].to);
    }



    t_stock_class part = tarjan(t);
    print_t_stock_class(part);
    float **M = createMatrix(t);
    float **S = subMatrix(M, part, 0);
    float **C = stableMatrix(S, part.tab_t_class[0].nb_summit, 0.01);
    printMatrix(M, t.lenght);
    printf("\n");
    printMatrix(S, part.tab_t_class[0].nb_summit);
    printf("\n");
    printMatrix(C, part.tab_t_class[0].nb_summit);
    */
    //t_stock_class part = tarjan(t);
    //export_adj(t, "test.txt");
    //print_t_stock_class(part);
    periodicity(t);
    return 0;
}
