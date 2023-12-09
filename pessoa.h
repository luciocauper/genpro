//arquivo pessoa.h

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include"avp.h"

typedef struct pessoa{
    int id;
    char nome[50];
    Tno * arvore;
    struct pessoa * prox;
}Pessoa;

Pessoa criarPessoa(int id, const char* nome);

Pessoa* inserirNoInicio(Pessoa* lista, int id, const char* nome);

void imprimirPessoa(Pessoa *lista);

void addProcesso(Pessoa* lista,int id, processo b);