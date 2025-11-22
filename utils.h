#ifndef __UTILS_H__
#define __UTILS_H__

#include "hasse.h"

/* Retourne l'identifiant correspondant au sommet i dans l'alphabet.
 *
 * Paramètres :
 *  - i : indice du sommet dans le graphe.
 *
 * Retour :
 *  - Une chaîne de caractères représentant l'identifiant(A, B, C...).
 */
char *getID(int i);


/* Détermine si une classe est transiente dans le graphe des liens.
 *
 * Paramètres :
 *  - linksList : tableau contenant les liens orientés entre classes.
 *  - className : nom de la classe à tester.
 *
 * Retour :
 *  - 1 si la classe est transiente.
 *  - 0 sinon.
 */
int IsTransient(t_link_array linksList,char * className);


/* Détermine si une partition de classes est réductible.
 *
 * Paramètres :
 *  - partition : structure représentant la partition issue de Tarjan.
 *
 * Retour :
 *  - 1 si la partition est réductible.
 *  - 0 sinon.
 */
int IsReducible(t_stock_class partition);


/* Vérifie si une classe est isolée.
 *
 * Paramètres :
 *  - class : classe à examiner.
 *
 * Retour :
 *  - 1 si la classe est isolée.
 *  - 0 sinon.
 */
int IsLonely(t_class class);


/* Affiche les classes transitoires, réductibles et isolées.
 *
 * Paramètres :
 *  - t : structure d'adjacence (graphe).
 *
 * Retour :
 *  - Aucun.
 */
void printTarjanInfos(t_adj t);

#endif