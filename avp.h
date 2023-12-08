#ifndef AVP_H  // Evita redefinicao
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

//fazer a adptação de int para processo -> acredito que ja fiz todas as necessárias
Tno* rotacao_simples_esquerda(Tno *a);
Tno* rotacao_simples_direita(Tno *a);

Tno* criarTno(processo elemento);
Tno* incluir_no(Tno* a, Tno* dado);
Tno* inserir(Tno* a, processo valor);

int cor(Tno* a);
void trocaCor(Tno* a);

void imprime(Tno* a);

#endif 