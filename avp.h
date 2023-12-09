#ifndef AVP_H
#define AVP_H

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include"processo.h"

typedef enum {vermelho, preto} Tcor;

typedef struct no{
	processo elemento;
	int cor;

	struct no* esq;
	struct no* dir;

}Tno;


Tno* rotacao_simples_esquerda(Tno *a);
Tno* rotacao_simples_direita(Tno *a);

Tno* criarTno(processo elemento);
Tno* incluir_no(Tno* a, Tno* dado);
Tno* inserir(Tno* a, processo valor);
Tno* procurar(Tno* a, int id);

int cor(Tno* a);
void trocaCor(Tno* a);

void imprime(Tno* a);

#endif


