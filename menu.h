#ifndef MENU_H
#define MENU_H

#define WELCOME_MSG_1 "Bienvenue dans le menu !\nIci vous pourrez naviguer a travers toutes les fonctionnalitees du projet.\nPour naviguer dans le menu c'est facile ! Il suffit de saisir un caractere quand vous verrez un message de ce genre \n\"[INPUT] y -> oui / n -> non :\"\nTu as bien compris ?\n"
#define WELCOME_MSG_2 "Super ! tu maitrises l'outil ;)\nCe projet a pour but de nous familiariser avec les graphes probabilistes de Markov.\nMais pas que, c'est aussi l'occassion d'ameliorer et d'approfondir nos connaissance en C et surtout en gestion des structures de donnees !\n\n"
#define WELCOME_MSG_3 "Ce projet vous est presente par -> Julie Sieux / Arthur Morinaux / Melvin Chaigneaux / Elliot Langermman !\n"
#define BASIC_NAV_MSG "Vous etes dans le menu de navigation, il vous permettra de naviguer parmis chaque etape du projet.\nVous pouvez selectionner la partie du projet que vous souhaitez consulter :\n"

#define PROFIL_CHAIG "data/"
#define PROFIL_JULIE "C:/Users/julie/CLionProjects/Groupe3_EtudeGrapheDeMarkov/data/"
#define PROFIL_MORIN "C:/Users/morin/CLionProjects/Groupe3_EtudeGrapheDeMarkov/data/"
#define PROFIL_BOBAN "C:/Users/boban/CLionProjects/Groupe3_EtudeGrapheDeMarkov_prj/data/"


void enableVTMode();
void setBuffer();
void initWriter();
void clearCmd();
void loading(char *text,int loadingTime);
void printwr(const char *txt, int delay_us);
void printwd(const char *txt);


void createInput(int choicesNb,char **choices);
char * fileByProfil(char *profil,char *filename);
char * userChoice(char *exercice);

void exo1();
void exo2();
void exo3();
void exo4();
void exo5();
void exo6();
void exo7();
void exo8();
void exo9();

void welcome();
void start();
void nav();
void navP1();
void navP2();
void navP3();

#endif //MENU_H
