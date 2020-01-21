#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
struct studente
{
    char nome[20];
    int matricola;
};

item createItem(char *nome, int matricola)
{
    item stud=malloc(sizeof(struct studente));
    strcpy(stud->nome, nome);
    stud->matricola=matricola;
    return stud;
}

int eq(item x, item y)
{
    if (strcmp(x->nome, y->nome) == 0 && x->matricola == y->matricola)
        return 1;
    return 0;
}

item input_item()
{
    int matricola;
    char nome[20];
    printf("Dammi un nome:\n");
    scanf("%s",nome);
    printf("inserisci la matricola\n");
    scanf("%d",&matricola);
    return createItem(nome,matricola);
}

void output_item(item x)
{
    printf("nome: %s\tmatr: %d\n",x->nome,x->matricola);
}

//Ciao