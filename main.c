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

    t_link_array link_array;
    hasse(array_class, t, &link_array);
    printf("Liens du Hasse :\n");
    for (int i = 0; i < link_array.log_size; i++) {
        printf("%d", link_array.log_size);
        printf("%s -> %s\n", link_array.links[i].from, link_array.links[i].to);
    }
    return 0;
}