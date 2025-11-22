#ifndef EXPORT_H
#define EXPORT_H
#include "list_adj.h"

#define DEFAULT_MERMAID_HEADER "---\nconfig:\n\tlayout: elk\n\ttheme: neo\n\tlook: neo\n---"
#define FLOWCHART "flowchart LR"
#define DEFAULT_FILE_NAME "default.txt"
#define A_INIT_SIZE 7
#define LINK_SIZE 15
#define ASCII_START 65
#define TEMP_LIST 2255
#define CHAR_PROBA_SIZE 4

/* Ouvre le fichier et enlève son contenu.
 *
 * Paramètres :
 *  - filename : nom du fichier à créer.
 *
 * Retour :
 *  - 1 si l'ouverture du fichier a réussi.
 *  - 0 sinon.
 */
int create_file(const char *filename);


/* Ajoute du texte à la fin du fichier spécifié.
 *
 * Paramètres :
 *  - filename : nom du fichier dans lequel écrire.
 *  - text     : texte à ajouter (ne doit pas être NULL).
 *
 * Retour :
 *  - Aucun.
 */
void add_text_on_file(const char *filename, const char *text);



/* Ajoute "" dans le fichier.
 *
 * Paramètres :
 *  - filename : nom du fichier à modifier.
 *
 * Retour :
 *  - Aucun.
 */
void add_text_spacer(const char *filename);


/* Parcourt une structure d'adjacence et écrit son contenu dans un fichier.
 *
 * Paramètres :
 *  - adj       : graphe à parcourir.
 *  - filename : fichier de sortie.
 *
 * Retour :
 *  - Aucun.
 */
void parcours_adj(t_adj adj,char *file_name);


/* Exporte une structure d'adjacence dans un fichier pour le format mermaid
 *
 * Paramètres :
 *  - adj       : structure d'adjacence à exporter.
 *  - file_name : nom du fichier de sortie.
 *
 * Retour :
 *  - Aucun.
 */
void export_adj(t_adj adj,char *file_name);

#endif //EXPORT_H
