#ifndef EXPORT_H
#define EXPORT_H
#include "list_adj.h"

#define DEFAULT_MERMAID_HEADER "---\nconfig:\n\tlayout: elk\n\ttheme: neo\n\tlook: neo\n---\n"
#define FLOWCHART "flowchart LR\n"
#define DEFAULT_FILE_NAME "default.txt"
#define A_INIT_SIZE 7
#define LINK_SIZE 14
#define ASCII_START 65
#define TEMP_LIST 2255

typedef struct adj_str {
    int size;
    char **Lines;
} str_adj;

int create_file(const char *filename);
void add_text_on_file(const char *filename, const char *text);

str_adj * createLines();
char * setLines(char* add_text);
void freeLines(str_adj* lines);

void parcours_adj(t_adj adj,char *file_name);
void export_adj(t_adj adj,char *file_name);

#endif //EXPORT_H
