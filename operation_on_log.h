#ifndef OPERATION_ON_LOG_H_INCLUDED
#define OPERATION_ON_LOG_H_INCLUDED

typedef struct error ERROR;
void lecture_fichier_log(FILE *);
void affichage( ERROR );
void affiche_tout();
char * saisir_chaine();
void recherche_par_code();
void recherche_par_date();
void recherche_par_nom_fichier();
void recherche_par_heure();
void recherche_par_nom_fonction();
void operation_on_log_Menu();

#endif // OPERATION_ON_LOG_H_INCLUDED
