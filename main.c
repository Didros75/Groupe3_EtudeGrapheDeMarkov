#include <stdio.h>
#include <stdlib.h>
#include "Cell.h"
#include "List_Adj.h"

int main() {
    t_adj t=readGraph("C:/Users/chaig/CLionProjects/Groupe3_EtudeGrapheDeMarkov/data/exemple2.txt");
    PrintAdj(t);
    verify_markov_graph(t);

    return 0;
}
