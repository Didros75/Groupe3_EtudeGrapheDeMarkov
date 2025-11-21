#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hasse.h"
#include "tarjan.h"
#include "utils.h"

char *getID(int i)
{
    // translate from 1,2,3, .. ,500+ to A,B,C,..,Z,AA,AB,...
    static char buffer[10];
    char temp[10];
    int index = 0;

    i--; // Adjust to 0-based index
    while (i >= 0)
    {
        temp[index++] = 'A' + (i % 26);
        i = (i / 26) - 1;
    }

    // Reverse the string to get the correct order
    for (int j = 0; j < index; j++)
    {
        buffer[j] = temp[index - j - 1];
    }
    buffer[index] = '\0';

    return buffer;
}

int IsLonely(t_class class) {
    return (class.nb_summit==1);
}

int IsReducible(t_stock_class partition) {
    return (partition.nb_t_class == 1);
}

int IsTransient(t_link_array linksList,char * className) {
    for (int i=0;i<linksList.log_size;i++) {
        if (linksList.links[i].from==className)
            return 1;
    }
    return 0;
}

void printTarjanInfos(t_adj t) {
    char *array_class[t.lenght];
    t_stock_class partition = tarjan(t);
    tarjanToArray(array_class, partition);
    t_link_array links;
    hasse(array_class, t, &links);
    print_t_stock_class(partition);
    printf("\n\n");
    for (int i=0; i<partition.nb_t_class;i++) {
        t_class class = partition.tab_t_class[i];
        printf("%s",class.name);
        if (IsTransient(links, class.name)) {
            printf("La classe %s est transitoire ",class.name);
            if (IsLonely(class)) {
                printf("- l'etat %d est transitoire ",class.tab_summit[0].id);
            }else{
                printf("- les etats ");
                for (int j=0;j<class.nb_summit-1;j++) {
                    printf("%d et ",class.tab_summit[j].id);
                }
                printf("%d ",class.tab_summit[class.nb_summit-1].id);
                printf("sont transitoires ");
            }
        }else {
            printf("La classe %s est persistante ",class.name);
            if (IsLonely(class)) {
                printf("- l'etat %d est persitant ",class.tab_summit[0].id);
                printf("- l'etat %d est absorbant ",class.tab_summit[0].id);
            }else {
                printf("- les etats ");
                for (int j=0;j<class.nb_summit-1;j++) {
                    printf("%d et ",class.tab_summit[j].id);
                }
                printf("%d ",class.tab_summit[class.nb_summit-1].id);
                printf("sont persistants ");
            }
        }
        printf(";\n");
    }
    if (IsReducible(partition)) {
        printf("Le graphe de markov est irreductible\n");
    }else {
        printf("Le graphe de Markov n'est pas irreductible\n");
    }
}

