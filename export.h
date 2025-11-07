#ifndef EXPORT_H
#define EXPORT_H
#include "list_adj.h"

#define DEFAULT_MERMAID_HEADER "---\nconfig:\n\tlayout: elk\n\ttheme: neo\n\tlook: neo\n---"
#define FLOWCHART "flowchart LR"
#define DEFAULT_FILE_NAME "default.txt"
#define A_INIT_SIZE 7
#define LINK_SIZE 50
#define ASCII_START 65
#define TEMP_LIST 2255
#define CHAR_PROBA_SIZE 4

int create_file(const char *filename);
void add_text_on_file(const char *filename, const char *text);
void add_text_spacer(const char *filename);

void parcours_adj(t_adj adj,char *file_name);
void export_adj(t_adj adj,char *file_name);

#endif //EXPORT_H
