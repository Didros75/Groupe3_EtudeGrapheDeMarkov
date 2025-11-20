#include <stdio.h>
#include <stdlib.h>
#include "Cell.h"
#include "List_Adj.h"
#include "export.h"
#include "tarjan.h"
#include "hasse.h"

int main() {
    //t_adj t=readGraph("C:/Users/chaig/CLionProjects/Groupe3_EtudeGrapheDeMarkov/data/exemple2.txt");
    t_adj t=readGraph("C:/Users/julie/CLionProjects/Groupe3_EtudeGrapheDeMarkov/data/exemple2.txt");
    //t_adj t=readGraph("C:/Users/morin/CLionProjects/Groupe3_EtudeGrapheDeMarkov/data/exemple2.txt");

    //export_adj(t, "test.txt");
    char *array_class[t.lenght+1];
    t_stock_class partition = tarjan(t);
    tarjanToArray(array_class, partition);

    printf("Classes par sommet :\n");
    for (int i = 1; i < t.lenght+1; i++)
        printf("sommet %d -> classe %s\n", i, array_class[i]);
    return 0;
}