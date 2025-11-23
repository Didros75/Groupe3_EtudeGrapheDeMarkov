#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "list_adj.h"
#include "export.h"
#include "utils.h"
#include "matrix.h"

#include <windows.h>

void enableVTMode() {
  HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
  DWORD dwMode = 0;
  GetConsoleMode(hOut, &dwMode);
  dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
  SetConsoleMode(hOut, dwMode);
}
void setBuffer() {
  setvbuf(stdout, NULL, _IONBF, 0);
}
void initWriter() {
  enableVTMode();
  setBuffer();
}

void clearCmd(){
  for (int i=0;i<20;i++) {
    printf("\n");
  }
}



void loading(char * text,int loadingTime) {
  const char *frames[] = {".  ", ".. ", "..."};  // 3 chars toujours
  int i = 0;

  while (i < loadingTime*3) {
    printf("\r%s%s   ", text,frames[i%3]);  // <-- les 3 espaces assurent l'effacement
    fflush(stdout);
    usleep(500000);
    i++;
  }
}


//print writer (printwr)
void printwr(const char *txt, int delay_us) {
  for (int i = 0; txt[i] != '\0'; i++) {
    putchar(txt[i]);
    fflush(stdout);
    usleep(delay_us);  // délai entre chaque lettre
  }
}

//print writer default (printwd)
void printwd(const char *txt) {
  printwr(txt, 10000);
}

void createInput(int choicesNb,char **choices) {
  printf("[INPUT] ");
  for (int i = 0; i < choicesNb; i++) {
    printf("%s", choices[i]);
    if (i != choicesNb-1) {
      printf(" / ");
    }
  }
  printf(" : ");
}
char * fileByProfil(char *profil,char *filename) {
  char *path=malloc(255);
  path[0]='\0';
  strcat(path,profil);
  strcat(path,filename);
  return path;
}

void welcome() {
  printwd(WELCOME_MSG_1);
  printf("Alors ?\n");
  char *choices[2]={"y->j'ai compris !","n->Je crois que j'ai compris"};
  createInput(2,choices);
  char verif='x';
  scanf(" %c",&verif);
  while (verif!='y' && verif!='n') {
    printf("Reessaye ! Il faut ecrire y ou n, l'un des deux choix.\n");
    scanf(" %c",&verif);
  }
  printwd(WELCOME_MSG_2);
  printwd(WELCOME_MSG_3);
  loading("0ptimisation des graphismes",1);
  loading("Lancement de l'application",2);
}

void nav() {
  clearCmd();
  printwd(BASIC_NAV_MSG);
  char *choices[4]={"1->Partie 1","2->Partie 2","3->Partie 3","0->Quitter le programme"};
  createInput(4,choices);
  int inp=0;
  scanf(" %d",&inp);
  if (inp==1) {
    printwd("La partie 1 va se charger :\n");
    loading("Chargement",1);
    clearCmd();
    navP1();
  }else if (inp==2) {
    printwd("La partie 2 va se charger :\n");
    loading("Chargement",1);
    clearCmd();
    navP2();
  }else if (inp==3) {
    printwd("La partie 3 va se charger :\n");
    loading("Chargement",1);
    clearCmd();
    navP3();
  }else {
    printf("Quitter le programme\n");
  }
}

char * userChoice(char * exercice) {
  printwd("Qui est l'utilisateur ? : ");
  char *choices[5]={"1->Professeur","2->Julie","3->Arthur","4->Elliot","5->Autre..."};
  createInput(5,choices);
  int inp=0;
  scanf(" %d",&inp);
  if (inp==1) {
    char *path=fileByProfil(PROFIL_CHAIG,exercice);
    return path;
  }else if (inp==2) {
    char *path=fileByProfil(PROFIL_JULIE,exercice);
    return path;
  }else if (inp==3) {
    char *path=fileByProfil(PROFIL_MORIN,exercice);
    return path;
  }else if (inp==4) {
    char *path=fileByProfil(PROFIL_BOBAN,exercice);
    return path;
  }else {
    printf("Veuillez saisir le chemin d'acces vers ce code : ");
    char tmppath[255];
    scanf("%s",tmppath);
    char *path =fileByProfil(tmppath,exercice);
    return path;
  }
}

void exo1() {
  printwd("Vous pouvez afficher la liste d'adjacence d'un graphe à partir d'un fichier texte !\n");
  char *choices[5]={"1->exemple1.txt","2->exemple2.txt","3->exemple3.txt","4->Retour","5->Quitter le programme"};
  createInput(5,choices);
  int inp=0;
  scanf(" %d",&inp);
  if (inp==1) {
    char *path=userChoice("exemple1.txt");
    PrintAdj(readGraph(path));
    printwd("Le graphe de exemple1.txt a ete affiche...\n");
    free(path);
    exo1();
  }else if (inp==2) {
    char *path=userChoice("exemple2.txt");
    PrintAdj(readGraph(path));
    printwd("Le graphe de exemple2.txt a ete affiche...\n");
    free(path);
    exo1();
  }else if (inp==3) {
    char *path=userChoice("exemple3.txt");
    PrintAdj(readGraph(path));
    printwd("Le graphe de exemple3.txt a ete affiche...\n");
    free(path);
    exo1();
  }else if (inp==4) {
    printwd("Retour...\n");
    navP1();
  }else {
    printf("Quitter le programme");
  }

}

void exo2() {
  printwd("Vous pouvez verifier qu'un fichier contient bien un graphe de Markov !\n");
  char *choices[5]={"1->exemple1.txt","2->exemple2.txt","3->exemple3.txt","4->Retour","5->Quitter le programme"};
  createInput(5,choices);
  int inp=0;
  scanf(" %d",&inp);
  if (inp==1) {
    char *path=userChoice("exemple1.txt");
    verify_markov_graph(readGraph(path));
    printwd("Le graphe de exemple 1 a ete affiche...\n");
    free(path);
    exo2();
  }else if (inp==2) {
    char *path=userChoice("exemple2.txt");
    verify_markov_graph(readGraph(path));
    printwd("Le graphe de exemple 2 a ete affiche...\n");
    free(path);
    exo2();
  }else if (inp==3) {
    char *path=userChoice("exemple3.txt");
    verify_markov_graph(readGraph(path));
    printwd("Le graphe de exemple 1 a ete affiche...\n");
    free(path);
    exo2();
  }else if (inp==4) {
    printwd("Retour...");
    navP1();
  }else {
    printf("Quitter le programme");
  }

}

void exo3() {
  printwd("Vous pouvez exporter un graphe de markov en fichier exploitable pour mermaid !\n");
  char *choices[5]={"1->exemple1.txt","2->exemple2.txt","3->exemple3.txt","4->Retour","5->Quitter le programme"};
  createInput(5,choices);
  int inp=0;
  scanf(" %d",&inp);
  if (inp==1) {
    char * path=userChoice("exemple1.txt");
    export_adj(readGraph(path),"exemple1_export.txt");
    printwd("Vous trouverez votre export dans le dossier Exports\n");
    free(path);
    exo3();
  }else if (inp==2) {
    char *path=userChoice("exemple2.txt");
    export_adj(readGraph(path),"exemple2_export.txt");
    printwd("Vous trouverez votre export dans le dossier Exports\n");
    free(path);
    exo3();
  }else if (inp==3) {
    char *path=userChoice("exemple3.txt");
    export_adj(readGraph(path),"exemple3_export.txt");
    printwd("Vous trouverez votre export dans le CMake\n");
    free(path);
    exo3();
  }else if (inp==4) {
    printwd("Retour...\n");
    navP1();
  }else {
    printf("Quitter le programme");
  }
}

void navP1() {
  clearCmd();
  printwd("PARTIE 1 :\n");
  char *choices[5]={"1->Exercice 1","2->Exercice 2","3->Exercice 3","4->Revenir en arrière","0->Quitter le programme"};
  createInput(5,choices);
  int inp=0;
  scanf(" %d",&inp);
  if (inp==1) {
    loading("Chargement",1);
    clearCmd();
    exo1();
  }else if (inp==2) {
    loading("Chargement",1);
    clearCmd();
    exo2();
  }else if (inp==3) {
    loading("Chargement",1);
    clearCmd();
    exo3();
  }else if (inp==4) {
    loading("Chargement",1);
    clearCmd();
    nav();
  }else {
    printf("Quitter le programme\n");
  }
}

void exo4() {
  loading("Chargement",1);
  printwd("Vous pouvez afficher les classes d'un graphe !\n");
  char *choices[5]={"1->exemple1.txt","2->exemple2.txt","3->exemple3.txt","4->Retour","5->Quitter le programme"};
  createInput(5,choices);
  int inp=0;
  scanf(" %d",&inp);
  if (inp==1) {
    char * path=userChoice("exemple1.txt");
    print_t_stock_class(tarjan(readGraph(path)));
    printwd("Les classes du graphes exemple1.txt ont ete affiche\n");
    free(path);
    exo4();
  }else if (inp==2) {
    char *path=userChoice("exemple2.txt");
    print_t_stock_class(tarjan(readGraph(path)));
    printwd("Les classes du graphes exemple2.txt ont ete affiche\n");
    free(path);
    exo4();
  }else if (inp==3) {
    char *path=userChoice("exemple3.txt");
    print_t_stock_class(tarjan(readGraph(path)));
    printwd("Les classes du graphes exemple3.txt ont ete affiche\n");
    free(path);
    exo4();
  }else if (inp==4) {
    printwd("Retour...\n");
    navP2();
  }else {
    printf("Quitter le programme");
  }
}

void exo5() {
  loading("Chargement",1);
  printwd("Vous pouvez voir et exporter un Hasse issue des graphes !\n");
  char *choices[5]={"1->exemple1.txt","2->exemple2.txt","3->exemple3.txt","4->Retour","5->Quitter le programme"};
  createInput(5,choices);
  int inp=0;
  scanf(" %d",&inp);
  if (inp==1) {
    char * path=userChoice("exemple1.txt");
    t_adj t = readGraph(path);
    printwd("Affichage du Hasse\n");
    free(path);
    char *array_class[t.lenght];
    t_stock_class partition = tarjan(t);
    tarjanToArray(array_class, partition);
    printf("\n");
    t_link_array links;
    hasse(array_class, t, &links);
    //Affichage des liens
    printf("Liens du Hasse :\n");
    for (int i = 0; i < links.log_size; i++) {
      printf("%s -> %s\n", links.links[i].from, links.links[i].to);
    }
    char * file="hasse_export.txt";
    void export_hasse(links, file);
    printwd("Un export du hasse pour mermaid a ete fait, il se trouve dans le CMake\n");
    exo5();
  }else if (inp==2) {
    char * path=userChoice("exemple2.txt");
    t_adj t = readGraph(path);
    printwd("Affichage du Hasse\n");
    free(path);
    char *array_class[t.lenght];
    t_stock_class partition = tarjan(t);
    tarjanToArray(array_class, partition);
    printf("\n");
    t_link_array links;
    hasse(array_class, t, &links);
    //Affichage des liens
    printf("Liens du Hasse :\n");
    for (int i = 0; i < links.log_size; i++) {
      printf("%s -> %s\n", links.links[i].from, links.links[i].to);
    }
    char * file="hasse_export.txt";
    void export_hasse(links, file);
    printwd("Un export du hasse pour mermaid a ete fait, il se trouve dans le CMake\n");
    exo5();
  }else if (inp==3) {
    char * path=userChoice("exemple3.txt");
    t_adj t = readGraph(path);
    printwd("Affichage du Hasse\n");
    free(path);
    char *array_class[t.lenght];
    t_stock_class partition = tarjan(t);
    tarjanToArray(array_class, partition);
    printf("\n");
    t_link_array links;
    hasse(array_class, t, &links);
    //Affichage des liens
    printf("Liens du Hasse :\n");
    for (int i = 0; i < links.log_size; i++) {
      printf("%s -> %s\n", links.links[i].from, links.links[i].to);
    }
    loading("Chargement",1);
    char * file="hasse_export.txt";
    void export_hasse(links, file);
    printwd("Un export du hasse pour mermaid a ete fait, il se trouve dans le CMake\n");
    exo5();
  }else if (inp==4) {
    printwd("Retour...\n");
    navP2();
  }else {
    printf("Quitter le programme");
  }
}

void exo6() {
  loading("Chargement",1);
  printwd("Vous pouvez afficher les caracteristiques d'un graphe (via l'etude du tarjan) !\n");
  char *choices[5]={"1->exemple1.txt","2->exemple2.txt","3->exemple3.txt","4->Retour","5->Quitter le programme"};
  createInput(5,choices);
  int inp=0;
  scanf(" %d",&inp);
  if (inp==1) {
    char * path=userChoice("exemple1.txt");
    t_adj t = readGraph(path);
    free(path);
    printTarjanInfos(t);
    printwd("Les informations du tarjan ont ete affiche\n");
    exo6();
  }else if (inp==2) {
    char * path=userChoice("exemple2.txt");
    t_adj t = readGraph(path);
    free(path);
    printTarjanInfos(t);
    printwd("Les informations du graphe ont ete affiche\n");
    exo6();
  }else if (inp==3) {
    char * path=userChoice("exemple3.txt");
    t_adj t = readGraph(path);
    free(path);
    printTarjanInfos(t);
    printwd("Les informations du graphe ont ete affiche\n");
    exo6();
  }else if (inp==4) {
    printwd("Retour...\n");
    navP2();
  }else {
    printf("Quitter le programme");
  }
}


void navP2() {
  clearCmd();
  printwd("PARTIE 2 :\n");
  char *choices[5]={"1->Exercice 1 - Tarjan","2->Exercice 2 - Driagramme de Hasse","3->Exercice 3 - caracteristique graphe","4->Revenir en arrière","0->Quitter le programme"};
  createInput(5,choices);
  int inp=0;
  scanf(" %d",&inp);
  if (inp==1) {
    loading("Chargement",1);
    clearCmd();
    exo4();
  }else if (inp==2) {
    loading("Chargement",1);
    clearCmd();
    exo5();
  }else if (inp==3) {
    loading("Chargement",1);
    clearCmd();
    exo6();
  }else if (inp==4) {
    loading("Chargement",1);
    clearCmd();
    nav();
  }else {
    printf("Quitter le programme\n");
  }
}


void exo7() {
  char * path=userChoice("exemple_meteo.txt");
  t_adj t = readGraph(path);
  printwd("Affichage des matrices :\n");
  free(path);
  t_stock_class part = tarjan(t);
  print_t_stock_class(part);
  float **M = createMatrix(t);
  float **S = subMatrix(M, part, 0);
  float **C = stableMatrix(S, part.tab_t_class[0].nb_summit, 0.01);
  printwd("Matrice :\n");
  printMatrix(M, t.lenght);
  printf("\n");
  printf("\n");
  printwd("Sub-matrice :\n");
  printMatrix(S, part.tab_t_class[0].nb_summit);
  printf("\n");
  printf("\n");
  printwd("Matrice Stable :\n");
  printMatrix(C, part.tab_t_class[0].nb_summit);
  printf("\n");
  printf("\n");
  printf("\n");
  printwd("Les matrices ont ete affiche !\n");

  char *choices[2]={"1->Retour","2->Quitter le programme"};
  createInput(2,choices);
  int inp=0;
  scanf(" %d",&inp);
  if (inp==1) {
    loading("Retour",1);
    navP3();
  }else {
    printf("Quitter le programme");
  }
}
void exo8() {
  char * path=userChoice("exemple_valid_step3.txt");
  t_adj t = readGraph(path);
  printwd("Affichage des matrices :\n");
  free(path);

  t_stock_class part = tarjan(t);
  print_t_stock_class(part);
  allStableMatrix(t, part);
  printwd("Les informations ont ete affiche !\n");

  char *choices[2]={"1->Retour","2->Quitter le programme"};
  createInput(2,choices);
  int inp=0;
  scanf(" %d",&inp);

  if (inp==1) {
    printwd("Retour...\n");
    navP3();
  }else {
    printf("Quitter le programme");
  }
}


void exo9() {
  char * path=userChoice("exemple_valid_step3.txt");
  t_adj t = readGraph(path);
  printwd("Affichage des matrices :\n");
  free(path);
  periodicity(t);
  printwd("Les informations ont ete affiche !\n");

  char *choices[2]={"1->Retour","2->Quitter le programme"};
  createInput(2,choices);
  int inp=0;
  scanf(" %d",&inp);

  if (inp==1) {
    printwd("Retour...\n");
    navP3();
  }else {
    printf("Quitter le programme");
  }
}

void navP3() {
  clearCmd();
  printwd("PARTIE 3 :\n");
  printwd("L'exercice 1 se basera sur le fichier meteo.txt et les exercices 2 et 3 sur exemple_valide_step3.\n");
  char *choices[5]={"1->Exercice 1","2->Exercice 2","3->Exercice 3 (Bonus)","4->Revenir en arrière","0->Quitter le programme"};
  createInput(5,choices);
  int inp=0;
  scanf(" %d",&inp);
  if (inp==1) {
    loading("Chargement",1);
    clearCmd();
    exo7();
  }else if (inp==2) {
    loading("Chargement",1);
    clearCmd();
    exo8();
  }else if (inp==3) {
    loading("Chargement",1);
    clearCmd();
    exo9();
  }else if (inp==4) {
    loading("Chargement",1);
    clearCmd();
    nav();
  }else {
    printf("Quitter le programme\n");
  }
}


void start(){
  initWriter();
  welcome();
  nav();
}
