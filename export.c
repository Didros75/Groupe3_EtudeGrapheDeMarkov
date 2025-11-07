#include <stdio.h>
#include <stdlib.h>
#include "export.h"

#include <string.h>

#include "utils.h"

#include "list_adj.h"


// Fonction gestion fichier
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

//gestion structure Lines

str_adj * createLines() {
  str_adj* lines = (str_adj *) (sizeof(str_adj));
  lines->size = 0;
  lines->Lines=(char **) malloc(TEMP_LIST);
}

char * setLines(char* add_text) {
  char * text = (char*) malloc(strlen(add_text) + 1);
  strcpy(text, add_text);
  return text;
}

void freeLines(str_adj *lines) {
  if (lines == NULL) return;
  for (int i = lines->size - 1; i >= 0; i--) {
    free(lines->Lines[i]);
  }

  free(lines->Lines);

  free(lines);
}

void parcours_adj(t_adj adj,char *file_name) {
  str_adj * f_lines = createLines();
  for (int i=0; i<adj.lenght; i++) {
    // écriture ligne d'initialisation résultat demandé pour le sommet 1 : A((1))
    char * ascii_letter = getID(i+1);
    int ascii_number = i+1;
    char ascii_init[A_INIT_SIZE];
    sprintf(ascii_init, "%s((%d))", ascii_letter, ascii_number);
    add_text_on_file(file_name, ascii_init);
    //-------
    t_list summit = adj.leaving_edge[i];
    t_cell * cell = summit.head;
    while (cell != NULL) {
      int arrival = cell->summit_arrival;
      float proba =  cell->proba;
      char ascii_link[LINK_SIZE];
      sprintf(ascii_link, "%s-->|%d|%s", ascii_letter, ascii_number,getID(arrival));
      f_lines->Lines[f_lines->size] = setLines(ascii_link);
      f_lines->size++;
      cell = cell->next;
    }
  }
  for (int i=0; i<f_lines->size; i++) {
    add_text_on_file(file_name, f_lines->Lines[i]);
  }
  freeLines(f_lines);
}

void export_adj(t_adj adj,char *file_name) {
  create_file(file_name);
  add_text_on_file(file_name, DEFAULT_MERMAID_HEADER);
  parcours_adj(adj,file_name);

}

void main(){}