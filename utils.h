#ifndef __UTILS_H__
#define __UTILS_H__

char *getID(int i);

int IsTransient(t_link_array linksList,char * className);
int IsReducible(t_stock_class partition);
int IsLonely(t_class class);

void printTarjanInfos(t_adj t);

#endif