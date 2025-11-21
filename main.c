#include <stdio.h>
#include <stdlib.h>
#include "Cell.h"
#include "List_Adj.h"
#include "export.h"
#include "tarjan.h"
#include "hasse.h"

int main() {
    //t_adj t=readGraph("C:/Users/chaig/CLionProjects/Groupe3_EtudeGrapheDeMarkov/data/exemple2.txt");
    t_adj t=readGraph("C:/Users/julie/CLionProjects/Groupe3_EtudeGrapheDeMarkov/data/exemple1.txt");
    //t_adj t=readGraph("C:/Users/morin/CLionProjects/Groupe3_EtudeGrapheDeMarkov/data/exemple2.txt");

    //export_adj(t, "test.txt");
    char *array_class[t.lenght];
    t_stock_class partition = tarjan(t);
    tarjanToArray(array_class, partition);
    printf("\n");
    t_link_array links;
    hasse(array_class, t, &links);

    /* Affichage des liens */
    printf("Liens du Hasse :\n");
    for (int i = 0; i < links.log_size; i++) {
        printf("%s -> %s\n", links.links[i].from, links.links[i].to);
    }
    return 0;
}