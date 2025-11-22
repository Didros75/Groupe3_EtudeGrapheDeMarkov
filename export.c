#include <stdio.h>
#include <stdlib.h>
#include "export.h"
#include <string.h>
#include "utils.h"
#include "list_adj.h"

int create_file(const char *filename) {
  FILE *file = fopen(filename, "w");
  if (file == NULL) {
    perror("Erreur lors de la création du fichier");
    return 0;
  }
  fclose(file);
  return 1;
}

void add_text_on_file(const char *filename, const char *text) {
  FILE *file = fopen(filename, "a");
  if (file == NULL) {
    perror("Erreur lors de l'ouverture du fichier pour écriture");
    exit(EXIT_FAILURE);
  }

  fprintf(file, "%s\n", text);
  fclose(file);
}

void add_text_spacer(const char *filename) {
  add_text_on_file(filename, "");
}

void parcours_adj(t_adj adj,char *file_name) {
  int t_len = adj.lenght;
  for (int i=0; i<t_len; i++) {
    int ascii_number = i+1;
    char ascii_init[A_INIT_SIZE];
    sprintf(ascii_init, "%s((%d))", getID(ascii_number), ascii_number);
    printf("%s\n", ascii_init);
    add_text_on_file(file_name, ascii_init);
  }
  add_text_spacer(file_name);
  for (int i=0; i<t_len; i++) {
    t_list summit = adj.leaving_edge[i+1];
    t_cell * cell = summit.head;
    while (cell != NULL) {
      char *arrival = getID(cell->summit_arrival);
      float proba =  cell->proba;
      char final_string[LINK_SIZE];
      char rival[sizeof(arrival)];
      strcpy(rival,arrival);
      snprintf(final_string, sizeof(final_string), "%s-->|%.2f|%s",getID(i+1), proba,rival);
      printf("%s\n", final_string);
      add_text_on_file(file_name, final_string);
      cell = cell->next;
    }
  }
}

void export_adj(t_adj adj,char *file_name) {
  create_file(file_name);
  add_text_on_file(file_name, DEFAULT_MERMAID_HEADER);
  add_text_spacer(file_name);
  add_text_on_file(file_name, FLOWCHART);
  parcours_adj(adj,file_name);
}