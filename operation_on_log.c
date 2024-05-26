#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "operation_on_log.h"


// struture contenant les differenets elements selon le model d'enregistrement du fichier
struct error
{
    char * Nom_fichier;
    char * code ;
    char * Date;
    char * Heure;
    char * Nom_fonction;
    char * msg ;

};
typedef struct error ERROR;

//declaration de tableau de type erreur
static ERROR * T = NULL;
static unsigned int NBE = 0,i=0;

/* cette fonction recoit en parametre l'adresse du fichier d'erreur lit les element ligne par ligne et stock chaque element
dans son emplacement correspondant dans le tableau de type erreur*/

void lecture_fichier_log(FILE * F)
{
    int a=0;
    unsigned int c;
    if(F == NULL)
    {
        printf(" \n echec d'ouverture du fichier \n");
        return;
    }
    else
    {
        c=fgetc(F);
        if(c == EOF )
        {
            printf("\n le fichier est vide ");
        }
        else
        {
            T = (ERROR *)realloc(T,sizeof(ERROR)*(++NBE));
            while (c != EOF )
            {
                 T[i].Nom_fichier=NULL;

                while (c != '#')
                {
                    T[i].Nom_fichier=(char*)realloc(T[i].Nom_fichier,sizeof(char)*(a+1));
                    T[i].Nom_fichier[a++]=c;
                    c=fgetc(F);
                }
                T[i].Nom_fichier=(char*)realloc(T[i].Nom_fichier,sizeof(char)*(a+1));
                T[i].Nom_fichier[a]='\0';
                a=0;
                c=fgetc(F);

                T[i].code=NULL;
                while (c != '#')
                {
                    T[i].code=(char*)realloc(T[i].code,sizeof(char)*(a+1));
                    T[i].code[a++]=c;
                    c=fgetc(F);
                }
                T[i].code=(char*)realloc(T[i].code,sizeof(char)*(a+1));
                T[i].code[a]='\0';
                a=0;
                c=fgetc(F);

                T[i].Date=NULL;
                while (c != '#')
                {
                    T[i].Date=(char*)realloc(T[i].Date,sizeof(char)*(a+1));
                    T[i].Date[a++]=c;
                    c=fgetc(F);
                }
                T[i].Date=(char*)realloc(T[i].Date,sizeof(char)*(a+1));
                T[i].Date[a]='\0';
                a=0;
                c=fgetc(F);

                T[i].Heure=NULL;
                while (c != '#')
                {
                    T[i].Heure=(char*)realloc(T[i].Heure,sizeof(char)*(a+1));
                    T[i].Heure[a++]=c;
                    c=fgetc(F);
                }
                T[i].Heure=(char*)realloc(T[i].Heure,sizeof(char)*(a+1));
                T[i].Heure[a]='\0';
                a=0;
                c=fgetc(F);

                T[i].Nom_fonction=NULL;
                while (c != '#')
                {
                    T[i].Nom_fonction=(char*)realloc(T[i].Nom_fonction,sizeof(char)*(a+1));
                    T[i].Nom_fonction[a++]=c;
                    c=fgetc(F);
                }
                T[i].Nom_fonction=(char*)realloc(T[i].Nom_fonction,sizeof(char)*(a+1));
                T[i].Nom_fonction[a]='\0';
                a=0;
                c=fgetc(F);

                T[i].msg=NULL;
                while (c != '\n')
                {
                    T[i].msg=(char*)realloc(T[i].msg,sizeof(char)*(a+1));
                    T[i].msg[a++]=c;
                    c=fgetc(F);
                }
                T[i].msg=(char*)realloc(T[i].msg,sizeof(char)*(a+1));
                T[i].msg[a]='\0';
                a=0;
                c=fgetc(F);

                if(c != EOF)
                {
                    i++;
                    T=(ERROR*)realloc(T,sizeof(ERROR)*(++NBE));
                }
            }
        }
    }

}

/* cette fonction permet d'afficher les differents champs de la structure erreure*/

void affichage( ERROR E)
{
    printf("\n Fichier: %s",E.Nom_fichier);
    printf("\n Code: %s",E.code);
    printf("\n Date: %s",E.Date);
    printf("\n Heure: %s",E.Heure);
    printf("\n Nom_fonction: %s",E.Nom_fonction);
    printf("\n Description: %s\n",E.msg);
}

/* cette fonction affiche tous les elements du tableau d'erreur*/

void affiche_tout()
{
    int j;
    for(j = 0; j < NBE; j++)
    {
        affichage(T[j]);
    }
}

/* cette fonction recupere la chaine entrer par l'utilsateur et la retourne */

char * saisir_chaine()
{
    char *ch = NULL ;
    unsigned int c,nbc=0;
    while ((c = getchar())!= '\n')
    {
        ch=(char*)realloc(ch,(nbc+1)*sizeof(char));
        ch[nbc++]=c;
    }
    ch = (char*) realloc(ch,(nbc+1)*sizeof(char));
    ch[nbc]='\0';
    return ch;
}

// implementation des differentes fonctions de recherche

void recherche_par_code()
{
    int j,k = 0;
    char *code;
    printf( "\n veuillez saisir le code: ");
    code=saisir_chaine();
    for(j = 0; j < NBE; j++)
    {
        if(strcmp(T[j].code,code) == 0)
        {
            affichage(T[j]);
            k++;
        }

    }

    if(k == 0)
    {
        printf("\n il n y'a aucune erreur correspondante \n");
    }


}

void recherche_par_date()
{
    int j,k=0;
    char *date;
    printf("\n entrer la date sous le format jour/mois/annee : ");
    date=saisir_chaine();
     for(j = 0; j < NBE; j++)
    {
        if(strcmp(T[j].Date,date) == 0)
        {
            affichage(T[j]);
            k++;
        }
    }

    if(k == 0)
    {
        printf("\n il n y'a aucune erreur correspondante \n");
    }

}


void recherche_par_nom_fichier()
{
    int j,k=0;
    char *nom_fichier;
    printf("\n entrer le nom du fichier: ");
    nom_fichier=saisir_chaine();
     for(j = 0; j < NBE; j++)
    {
        if(strcmp(T[j].Nom_fichier,nom_fichier) == 0)
        {
            affichage(T[j]);
            k++;
        }
    }

    if(k == 0)
    {
        printf("\n il n y'a aucune erreur correspondante \n");
    }

}


void recherche_par_heure()
{
    int j,k=0;
    char *heure;
    printf("\n entrer l'heure sous le format heure:minute:seconde : ");
    heure=saisir_chaine();
     for(j = 0; j < NBE; j++)
    {
        if(strcmp(T[j].Heure,heure) == 0)
        {
            affichage(T[j]);
            k++;
        }
    }

    if(k == 0)
    {
        printf("\n il n y'a aucune erreur correspondante \n");
    }
}

void recherche_par_nom_fonction()
{
    int j,k=0;
    char *nom_fonction;
    printf("entrer le nom de la fonction: \n");
    nom_fonction=saisir_chaine();
     for(j = 0; j < NBE; j++)
    {
        if(strcmp(T[j].Nom_fonction,nom_fonction) == 0)
        {
            affichage(T[j]);
            k++;
        }
    }

    if(k == 0)
    {
        printf("\n il n y'a aucune erreur correspondante \n");
    }

}


void operation_on_log_Menu()
{
    int choix;
    FILE *F;
 // passage de l'adresse du fichier d'erreur
    F=fopen("C:\\Users\\HP\\Desktop\\FIGI\\SEMESTRE 1\\structure de données et programmation C\\Tds pratique\\Série2\\serie2\\Serie2_log.txt","r");
    lecture_fichier_log(F);

    do
    {
        printf("\n\n\t------- Veuillez faire un choix -------\n\n");
        printf("\n 1) afficher les erreurs \n");
        printf("\n 2) recherche par code erreur \n");
        printf("\n 3) recherche par date\n");
        printf("\n 4) recherche par heure \n");
        printf("\n 5) recherche par nom de fonction \n");
        printf("\n 6) recherche par nom de fichier \n");
        printf("\n 7) quitter \n\n");
        printf("\t choix :-----------> ");
        scanf("%d",&choix);
        getchar();

        switch(choix)
        {
            case 1: printf("\n affichage des erreurs  :\n");
                    affiche_tout();
                    break;
            case 2: recherche_par_code();
                    break;
            case 3: recherche_par_date();
                    break;
            case 4: recherche_par_heure();
                    break;
            case 5: recherche_par_nom_fonction();
                    break;
            case 6: recherche_par_nom_fichier();
                    break;
            case 7: printf("\n Fin du programme \n");
                    break;
            default:printf("\n choix inexistant \n");
                    break;

        }
    }while(choix != 7);
fclose(F);

}




