#include <stdio.h>
#include <stdlib.h>
#include "Cell.h"
#include "List_Adj.h"
#include "export.h"
#include "tarjan.h"

int main() {
    //t_adj t=readGraph("C:/Users/chaig/CLionProjects/Groupe3_EtudeGrapheDeMarkov/data/exemple2.txt");
    //t_adj t=readGraph("C:/Users/julie/CLionProjects/Groupe3_EtudeGrapheDeMarkov/data/exemple2.txt");
    t_adj t=readGraph("C:/Users/morin/CLionProjects/Groupe3_EtudeGrapheDeMarkov/data/exemple2.txt");

    //export_adj(t, "test.txt");

    t_stock_class partition = tarjan(t);
    print_t_stock_class(partition);
    return 0;
}
