// avp.h

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define vermelho 0
#define preto 1

typedef struct{
	int elemento;
	int cor;
	
	struct Tno* esq;
	struct Tno* dir;

}Tno;

void menu();
Tno* rotacao_simples_esquerda(Tno *a);
Tno* rotacao_simples_direita(Tno *a);

Tno* criarTno(int elemento);
Tno* incluir_no(Tno* a, Tno* dado);
Tno* inserir(Tno* a, int valor);

int cor(Tno* a);
void trocaCor(Tno* a);

void imprime(Tno* a);
