#include <stdio.h>
#include <stdlib.h>
#include "Cell.h"
#include "List_Adj.h"
#include "export.h"
#include "tarjan.h"
#include "hasse.h"

int main() {
    //t_adj t=readGraph("C:/Users/chaig/CLionProjects/Groupe3_EtudeGrapheDeMarkov/data/exemple2.txt");
    //t_adj t=readGraph("C:/Users/julie/CLionProjects/Groupe3_EtudeGrapheDeMarkov/data/exemple2.txt");
    t_adj t=readGraph("C:/Users/morin/CLionProjects/Groupe3_EtudeGrapheDeMarkov/data/exemple2.txt");

    //export_adj(t, "test.txt");
    /*int array_class[100];
    t_stock_class partition = tarjan(t);
    print_t_stock_class(partition);

    tarjanToArray(&array_class, partition);
    for (int i = 0; i < 10; i++) {
        printf("%s\n", array_class[i]);
    }*/
    t_stock_class partition = tarjan(t);
    print_t_stock_class(partition);
    return 0;
}